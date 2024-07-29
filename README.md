# What we need
- Arduino Uno.
- LED Matrix "MAX7219 LED".
- Jumber Wires

# What we will get at the end?
Creating a face using LED matrix "MAX7219 LED" of 8*32 type.



# Breaking down the problem
I will start with a simple code to understand the functionality of the led matrix using WOKWI and 8*8 led matrix to display numbers and characters. 


# Simple example 

## Diagram and Simulation
I will rotate the LED- Matrix when I implement the task ( Be careful to DIN and DOUT ) they are different in fanctionality.<br>

![image](https://github.com/user-attachments/assets/5a45510f-3525-4ff8-bf75-f5ae43a87449)


## Code 
Steps: 
- Download the library of LedControl. <br>
![image](https://github.com/user-attachments/assets/c0457a3f-7a54-46a6-9529-942c2bfb18d9)

- Write the following code: <br>

``` CPP
#include <LedControl.h>

int DIN = 12;
int CS= 11;
int CLK = 10;
int LED_MAT_NUM = 4;

LedControl lc(DIN, CLK, CS, LED_MAT_NUM);

void setup() {

lc.shutdown(0, false);
lc.setIntensity(0, 8);
lc.clearDisplay(0);

}

void loop() {
  int ROW = 1;
  int COLUMN = 2;
  lc.setLed(0, ROW, COLUMN, true);

}
```

```
# include <LedControl.h>
```
This is the library that enable us to call the functions related to the LED MATRIX MAX72xx module that we have. <br>

```
int DIN = 12;
int CS= 11;
int CLK = 10;
int LED_MAT_NUM = 1;

LedControl lc(DIN, CLK, CS, LED_MAT_NUM);

```
Defining the variables outside like what I did here is something very helpful in any programming language. THis makes us easily change the variable faster instead of going through the code and change each line which is somethin inprofassional and headache. <br>


```
void setup() {

lc.shutdown(0, false);
lc.setIntensity(0, 8);
lc.clearDisplay(0);

}
```

- lc.shutdown(0, false) -> this function is to shut down the power , '0' means the led matrix that you want to turn offm here because we have just one we will write 0, if we have two, we will have '0' and '1'. 'False' meanse to turn off power <br>
- lc.setIntensity(0, 8) -> '0' means the same for previous function and 8 is the intensity of the lighiness. The range between 0-15, so, I put it in middle. <br>
- lc.clearDisplay(0) -> to clears the display by turning off all the LEDs. <br>


```
}

void loop() {
  int ROW = 1;
  int COLUMN = 2;
  lc.setLed(0, ROW, COLUMN, true);

}
```

The lc.setLed() function usually takes four parameters: <br>

- The number of the device (if you have multiple devices daisy-chained).
- The row of the LED you want to set.
- The column of the LED you want to set.
- A boolean value (true or false) indicating whether to turn the LED on (true) or off (false).


## Troubleshooting:
- I put things at first time in left and there was a difference between DIN and DOUT, with DOUT the LED didn't turn on. <br>
![image](https://github.com/user-attachments/assets/b88dddd4-c937-4939-9ef2-e1a9202de28b)


# Drawing in ONE matrix of 8*32

I used this website to draw the matrix: [Learn on fly](https://www.riyas.org/2013/12/online-led-matrix-font-generator-with.html)

## simulation
![image](https://github.com/user-attachments/assets/5a16e381-7005-4098-8acb-ce8c5688f819)



## Code

```
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
```

# Arduino IDE simulation: 





https://github.com/user-attachments/assets/3f9d083c-c750-4a62-968b-b86c40bcf82c





