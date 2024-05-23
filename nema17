#include <Stepper.h>

#define SensorMagnet 6
#define buttonPin 2

bool motorjalan = true;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

//melacak posisi
long currentPosition = 0;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(SensorMagnet, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // step one revolution  in one direction:
  int nilai = digitalRead(SensorMagnet);
  if (motorjalan == 1)
  {
    Serial.println("Putar Searah jarum jam");
    myStepper.step(stepsPerRevolution);
    currentPosition += stepsPerRevolution;
    Serial.println("Posisi : ");
    Serial.print(currentPosition);
  }else if (nilai == LOW )
  {
    Serial.println("Berhenti!");
    motorjalan == false;
    stopMotor();
  }
  /**if(nilai == HIGH)
  {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    currentPosition += stepsPerRevolution;
    delay(500);
    Serial.println("Posisi sekarang : ");
    Serial.print(currentPosition);
  }
  **/
  /**else
  {
    // step one revolution in the other direction:
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(500);
  }**/
}

