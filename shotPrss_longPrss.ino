int count;
boolean longPressActive = false;
boolean buttonActive = false;
long buttonTimer = 0;
long longPressTime = 3000;

void setup() {     
  Serial.begin(9600);
  pinMode(D3,INPUT);
  count = 0;
}

void loop() {
  checkButtonStatus();
}

void checkButtonStatus() {
  if (digitalRead(D3) == LOW) {
    if (buttonActive == false) {
      buttonActive = true;
      buttonTimer = millis();
    }
    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {
      longPressActive = true;
      count = 0;
      Serial.println("Reset count number !!!");
      delay(200);
    }
  } else {
    if (buttonActive == true) {
      if (longPressActive == true) {
        longPressActive = false;
      } else {
        count += 1;
        Serial.print("Press button count : ");
        Serial.println(count);
        delay(200);
      }
      buttonActive = false;
    }
  }
}
