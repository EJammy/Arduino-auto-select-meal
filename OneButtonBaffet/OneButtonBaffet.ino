#include <Keyboard.h>
//note: would not work when there is more than 4 full
const int loadTime = 3000;//change this according to the web page load time
bool button;
void setup() {
  pinMode(8, INPUT);
  Keyboard.begin();
  //delay(5000);
  //Keyboard.write("z");

}

void pressButton(int n, int wait){
  for(int i = 0; i < n; i++){
    Keyboard.write(179);
  }
  delay(50);
  Keyboard.write('\n');
  if(wait){
    delay(loadTime);
  }
}

void loop() {
  button = digitalRead(8);
  Serial.println(button);
  if(button){
    for(int i = 0; i < 5; i++){
      pressButton(3 + i, 1);
      //Due to the way the website is set up
      //" + i" is only required when meal is already chosen
      pressButton(17, 0);
      //In case there is more than 2 meal that are full,
      //doesn't work very well
      delay(50);
      Keyboard.press(129);
      Keyboard.write(179);
      Keyboard.write(179);
      Keyboard.releaseAll();
      Keyboard.write('\n');

      delay(loadTime);
      pressButton(13, 0);
      delay(500);
      Keyboard.write(179);
      delay(500);
    }
    delay(1000);
  }
  delay(10);

}
