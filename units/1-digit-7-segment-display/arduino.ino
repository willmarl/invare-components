#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_DP 9
#define COMMON_PIN 10  // Common cathode or anode

void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }
}

void displayNumber(int num) {
  // Define segments for digits 0-9
  byte segments[10][8] = {
    {1,1,1,1,1,1,0,0},  // 0
    {0,1,1,0,0,0,0,0},  // 1
    {1,1,0,1,1,0,1,0},  // 2
    {1,1,1,1,0,0,1,0},  // 3
    {0,1,1,0,0,1,1,0},  // 4
    {1,0,1,1,0,1,1,0},  // 5
    {1,0,1,1,1,1,1,0},  // 6
    {1,1,1,0,0,0,0,0},  // 7
    {1,1,1,1,1,1,1,0},  // 8
    {1,1,1,1,0,1,1,0}   // 9
  };
  
  digitalWrite(SEG_A, segments[num][0]);
  digitalWrite(SEG_B, segments[num][1]);
  digitalWrite(SEG_C, segments[num][2]);
  digitalWrite(SEG_D, segments[num][3]);
  digitalWrite(SEG_E, segments[num][4]);
  digitalWrite(SEG_F, segments[num][5]);
  digitalWrite(SEG_G, segments[num][6]);
  digitalWrite(SEG_DP, segments[num][7]);
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    displayNumber(i);
    delay(500);
  }
}