#define SOUND_ANALOG_PIN A0  // Analog output (0-1023)
#define SOUND_DIGITAL_PIN 8  // Digital output (HIGH/LOW)

void setup() {
  Serial.begin(9600);
  pinMode(SOUND_DIGITAL_PIN, INPUT);
  
  Serial.println("KY-037 Sound Sensor Ready");
}

void loop() {
  delay(100);
  
  // Read analog value (sound intensity)
  int soundLevel = analogRead(SOUND_ANALOG_PIN);
  
  // Read digital value (threshold trigger)
  int soundDetected = digitalRead(SOUND_DIGITAL_PIN);
  
  Serial.print("Sound Level: ");
  Serial.print(soundLevel);
  Serial.print(" | Sound Detected: ");
  Serial.println(soundDetected ? "YES" : "NO");
}