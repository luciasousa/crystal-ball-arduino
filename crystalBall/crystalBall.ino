#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //initialize with the pins it will use

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  //put your setup code here, to run once:
  lcd.begin(16, 2); //size of the screen
  pinMode(switchPin, INPUT); //set up the switch pin as an input
  lcd.print("Ask the");
  lcd.setCursor(0, 1); //first column, second line
  lcd.print("Crystal, Ball!");
}

void loop() {
  //put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin); //put the value of switchPin in switchState variable
  if(switchState != prevSwitchState){ //if switch is in different position than it was previously
    if(switchState == LOW){ //and if it is LOW
      reply = random(8); // t generates a random number between 0 and 7

      lcd.clear(); //clear the screen
      lcd.setCursor(0, 0); //first line
      lcd.print("The ball says...");
      lcd.setCursor(0, 1); //second line
      switch(reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again later");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("Hell no");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
