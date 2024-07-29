#include <LedControl.h>

int DIN = 12;
int CS= 11;
int CLK = 10;
int LED_MAT_NUM = 4;

byte face[8][4] ={
  {B00000000, B00000000, B00000000, B00000000},
  {B00001111, B00000000, B01111000, B00000000},
  {B00001111, B00000000, B01111000, B00000000},
  {B00000000, B00000000, B00000000, B00000000},
  {B00000000, B10000000, B10000000, B00000000},
  {B00000000, B11111111, B10000000, B00000000},
  {B00000000, B00000000, B00000000, B00000000},
  {B00000000, B00000000, B00000000, B00000000}
};

LedControl lc(DIN, CLK, CS, LED_MAT_NUM);

void setup() {

 for (int i = 0; i < LED_MAT_NUM; i++) {
        lc.shutdown(i, false);  // Wake up each matrix
        lc.setIntensity(i, 8);  // Set brightness level for each matrix
        lc.clearDisplay(i);     // Clear each matrix
    }

}

void loop() {
  for (int row = 0; row < 8; row++) {
    for (int matrix = 0; matrix < 4; matrix++) {
      lc.setRow(matrix, row, face[row][matrix]);
    }
  }
}