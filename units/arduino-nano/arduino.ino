bool ledState = false;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);

  if (Serial.available() > 0) {        // Check if data is waiting
    String input = Serial.readStringUntil('\n'); // Read until Enter key
    input.trim();                               // Remove \r\n whitespace
    
    if (input == "on") {
      ledState = true;
    }
    if (input == "off") {
      ledState = false;
    }
    Serial.println("LED is " + String(ledState) + " | you typed: " + input);
  }

}