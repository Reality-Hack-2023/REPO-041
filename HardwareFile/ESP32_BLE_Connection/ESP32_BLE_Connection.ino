#include <BluetoothSerial.h>
BluetoothSerial BTSerial;

const int vibOutPin = 2; // middle vib. motor
const int vibOutPin1 = 4; // right vib motor
const int vibOutPin2 = 15; // left vib motor


// the setup routine runs on start and once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  BTSerial.begin("HONG-ESP32");
  //pinMode(2, OUTPUT);

  pinMode(vibOutPin, OUTPUT);
  pinMode(vibOutPin1, OUTPUT);
  pinMode(vibOutPin2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //BTSerial.println("this is hong");
  
  if (BTSerial.available() > 0){
    String data = BTSerial.readStringUntil('\n');
    if (data == "0"){
      //digitalWrite(2, LOW);
      analogWrite(vibOutPin1,0);
      analogWrite(vibOutPin,0);
      analogWrite(vibOutPin2,0);
      BTSerial.println("motor Turned Off!");
    }
    else if (data == "1"){
      //digitalWrite(2, HIGH);
          analogWrite(vibOutPin2,175); // ripple 1
    delay(1000);
    analogWrite(vibOutPin2,0);
    delay(100);

    analogWrite(vibOutPin,175); // ripple 2
    analogWrite(vibOutPin2,125);
    delay(1000);
    analogWrite(vibOutPin,0);
    analogWrite(vibOutPin2,0);
    delay(100);

    analogWrite(vibOutPin1,175); // ripple 3
    analogWrite(vibOutPin,125);
    analogWrite(vibOutPin2,0);
    delay(1000);
    analogWrite(vibOutPin1,0);
    analogWrite(vibOutPin,0);
    analogWrite(vibOutPin2,0);
    delay(100);
      BTSerial.println("motor Turned On!");
    }
  }
}
