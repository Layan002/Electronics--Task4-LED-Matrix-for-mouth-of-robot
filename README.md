# What we need
- Arduino nano (or uno, but I will use nano since I have not used it before).
- LED Matrix "MAX7219 LED".
- Jumber Wires

# What we will get at the end?
I will make the mouth open and close while the robot speaking like this: 



https://github.com/user-attachments/assets/9b5c497c-5d75-4e75-8b96-5f70604d64f6 

but this is the eye not the mouth, i will do it by myself.


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


# Troubleshooting:
- I put things at first time in left and there was a difference between DIN and DOUT, with DOUT the LED didn't turn on. <br>
![image](https://github.com/user-attachments/assets/b88dddd4-c937-4939-9ef2-e1a9202de28b)















byte -> is defining a sqedual of all the rows I want in the matrix to turn on, I can set it to int but byte has the range between 0-255 unlike int which has size from 0-8 bits. 




