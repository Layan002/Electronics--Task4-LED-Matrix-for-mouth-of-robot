#include <LedControl.h>

int DIN = 12;
int CS= 11;
int CLK = 10;
int LED_MAT_NUM = 1;

byte face[8]={
B00100010,
B01010101,
B00000000,
B00011000,
B01000010,
B01000010,
B00111100,
B00000000
};

LedControl lc(DIN, CLK, CS, LED_MAT_NUM);

void setup() {
  
  lc.shutdown(0, false);  // Wake up each matrix
  lc.setIntensity(0, 8);  // Set brightness level for each matrix
  lc.clearDisplay(0);     // Clear each matrix

}

void loop() {
  for (int row = 0; row < 8; row++) {
     lc.setRow(0, row, face[row]);
    
  }
}
