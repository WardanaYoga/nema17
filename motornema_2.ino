#include <Stepper.h>

#define SensorMagnet 6
//#define buttonPin 2

bool motorjalan = true;
const int stepsPerRevolution = 200;  // Ubah ini sesuai dengan jumlah langkah per putaran motor Anda

// Inisialisasi perpustakaan stepper pada pin 8 hingga 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// Melacak posisi
long currentPosition = 0;

void setup() {
  // Atur kecepatan pada 60 rpm:
  myStepper.setSpeed(60);
  // Inisialisasi port serial:
  Serial.begin(9600);
  // Inisialisasi pin sensor dan tombol:
  pinMode(SensorMagnet, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Baca nilai dari sensor magnet:
  int nilaiSensor = digitalRead(SensorMagnet);
  // Baca nilai dari tombol:
  int nilaiTombol = digitalRead(buttonPin);

  if (motorjalan) {
    // Jika motor berjalan, putar searah jarum jam:
    Serial.println("Putar Searah jarum jam");
    myStepper.step(stepsPerRevolution);
    currentPosition += stepsPerRevolution;
    Serial.print("Posisi: ");
    Serial.println(currentPosition);
  }

  // Cek kondisi untuk menghentikan motor:
  if (nilaiSensor == LOW) {
    Serial.println("Berhenti! Sensor magnet aktif");
    motorjalan = false;
  }

  // Cek kondisi untuk tombol yang ditekan:
  /**if (nilaiTombol == LOW) {
    Serial.println("Berhenti! Tombol ditekan");
    motorjalan = false;
  }**/
}

void stopMotor() {
  // Tambahkan logika untuk menghentikan motor jika diperlukan
  // Misalnya, atur kecepatan ke nol atau setel ulang posisi
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  myStepper.setSpeed(0);
}
