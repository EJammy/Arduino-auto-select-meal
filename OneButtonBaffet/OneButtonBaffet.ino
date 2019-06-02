#include <Keyboard.h>
const int loadTime = 3000;//change this according to the web page load time
bool button;
void setup() {
  pinMode(8, INPUT);
  Keyboard.begin();
  //delay(5000);
  //Keyboard.write("z");

}

void pressButton(int n, int wait){
  //presses n times of tab and press that button
  for(int i = 0; i < n; i++){
    Keyboard.write(179);
  }
  delay(50);
  Keyboard.write('\n');
  if(wait){ //delay if wait is 1
    delay(loadTime);
  }
}

void loop() {
  button = digitalRead(8);//set the button state
  Serial.println(button);//for debug
  
  if(button){//when button is pressed
    for(int i = 0; i < 5; i++){
      
      pressButton(3 + i, 1);
      //Due to the way the website is set up
      //" + i" is only required when meal is already chosen
      //When meal is not chosen yet
      //delete it and use "pressButton(3, 1);" instead
      
      pressButton(17, 0);//choses the next 17 button, the buffet
      
      //In case there is more than 2 meal that are full,
      //the button would skip and not chose meal
      //This part of the code
      //goes back to chose if the page hasn't loaded yet
      //__might not work__
      delay(50);
      Keyboard.press(129);
      Keyboard.write(179);
      Keyboard.write(179);
      Keyboard.releaseAll();
      Keyboard.write('\n');
      //

      delay(loadTime);
      pressButton(13, 0);//press comfirm
      delay(500);
      Keyboard.write(179);//one extra tab is needed
      delay(500);
    }
    delay(1000);
  }
  delay(10);

}
