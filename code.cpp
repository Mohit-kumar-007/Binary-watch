this is the code for your ESP 32 


// ESP32 Binary Watch: 4 LEDs for hours, 6 for minutes

const int hourPins[4]   = {16, 17, 18, 19}; // H0 (LSB) - H3 (MSB)
const int minutePins[6] = {21, 22, 23, 25, 26, 27}; // M0 (LSB) - M5 (MSB)

int hours = 10; // Set the initial hour (0-11 for 12H format)
int minutes = 0; // Set the initial minute (0-59)
unsigned long lastUpdate = 0;

void setup() {
  // Initialize all LED pins as OUTPUT
  for (int i = 0; i < 4; i++)
    pinMode(hourPins[i], OUTPUT);
  for (int i = 0; i < 6; i++)
    pinMode(minutePins[i], OUTPUT);
}

void displayBinary(int number, const int* pins, int numBits) {
  for (int i = 0; i < numBits; i++)
    digitalWrite(pins[i], bitRead(number, i));
}

void loop() {
  // Time update simulation
  if (millis() - lastUpdate >= 60000) { // Update every minute
    lastUpdate += 60000;
    minutes++;
    if (minutes > 59) {
      minutes = 0;
      hours++;
      if (hours > 11) hours = 0; // 12h format
    }
  }

  displayBinary(hours, hourPins, 4);
  displayBinary(minutes, minutePins, 6);
  delay(50); // Stable display
}
