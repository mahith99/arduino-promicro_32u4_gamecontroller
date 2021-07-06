/* 
  this is protype and u can assign more buttons as u wish.--mahith
  make sure to us pro micro 5v 32u4chipset or any controler with 32u4 like leonardo.
  yes uno will not work with this code.
*/
#include <Mouse.h>
#include <Keyboard.h>
int horzPin = A0;  // Analog output of horizontal joystick pin
int vertPin = A1;  // Analog output of vertical joystick pin
int selPin = 16;  // select button pin of joystick
int selPin1 = 2;
int g1 = 3;
int g2 = 4;
int g3 = 5;
int g4 = 6;
int g5 = 7;
int g6 = 8;
int g7 = 9;
int g8 = 15;
int g9 = 14;


int vertZero, horzZero;  
int vertValue, horzValue;  
const int sensitivity = 60;  
int mouseClickFlag = 0;
int mouseClickFlag1 = 0;

int invertMouse =1;        //Invert joystick based on orientation1
//int invertMouse = -1;         //Noninverted joystick based on orientation

void setup()
{
  pinMode(horzPin, INPUT);  // Set both analog pins as inputs
  pinMode(vertPin, INPUT);
  pinMode(selPin, INPUT_PULLUP);  // set button select pin as input
  pinMode(selPin1, INPUT_PULLUP);
  pinMode(g1, INPUT_PULLUP);
  pinMode(g2, INPUT_PULLUP);
  pinMode(g3, INPUT_PULLUP);
  pinMode(g4, INPUT_PULLUP);
  pinMode(g5, INPUT_PULLUP);
  pinMode(g6, INPUT_PULLUP);
  pinMode(g7, INPUT_PULLUP);
  pinMode(g8, INPUT_PULLUP);
  pinMode(g9, INPUT_PULLUP);
  digitalWrite(selPin, HIGH);  // Pull button select pin high
  delay(1000);  // short delay to let outputs settle
  vertZero = analogRead(vertPin);  // get the initial values
  horzZero = analogRead(horzPin);  // Joystick should be in neutral position when reading these

  Mouse.begin(); //Init mouse emulation
  Keyboard.begin();
  
}
void mo()
{
  

  if ((digitalRead(selPin) == 0) && (!mouseClickFlag))  // if the joystick button is pressed
  {
    mouseClickFlag = 1;
    Mouse.press(MOUSE_LEFT);  // click the left button down
  }
  else if ((digitalRead(selPin)) && (mouseClickFlag)) // if the joystick button is not pressed1122
  {
    mouseClickFlag = 0;
    Mouse.release(MOUSE_LEFT);  // release the left button
  }
  //
   if ((digitalRead(selPin1) == 0) && (!mouseClickFlag1))  // if the joystick button is pressed
  {
    mouseClickFlag1 = 1;
    Mouse.press(MOUSE_RIGHT);  // click the left button down
  }
  else if ((digitalRead(selPin1)) && (mouseClickFlag1)) // if the joystick button is not pressed1122
  {
    mouseClickFlag1 = 0;
    Mouse.release(MOUSE_RIGHT);  // release the left button
  }
}
void ke()
{

if ((digitalRead(g1) == 0))  // if the joystick button is pressed
  {
    
    Keyboard.press('c');  // click the left button down
  }
  else if ((digitalRead(g1)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('c');
  }
//
  if ((digitalRead(g2) == 0))  // if the joystick button is pressed
  {
    
    Keyboard.press('w');  // click the left button down
  }
  else if ((digitalRead(g2)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('w');
  }
  //
  if ((digitalRead(g3) == 0))  // if the joystick button is pressed
  {
    
    Keyboard.press('d');  // click the left button down
  }
  else if ((digitalRead(g3)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('d');
  }
  //
   if ((digitalRead(g4) == 0))  // if the joystick button is pressed
  {
    
    Keyboard.press('a');  // click the left button down
  }
  else if ((digitalRead(g4)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('a');
  }
  //
   if ((digitalRead(g5) == 0))  // if the joystick button is pressed
  {
    
    Keyboard.press('s');  // click the left button down
  }
  else if ((digitalRead(g5)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('s');
  }
  //
   if ((digitalRead(g6) == 0))  // if the joystick button is pressed
  {
    
    Keyboard.press('e');  // click the left button down
  }
  else if ((digitalRead(g6)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('e');
  }
  //
   if ((digitalRead(g7) == 0))  // if the joystick button is pressed
  {
    
    Keyboard.press('q');  // click the left button down
  }
  else if ((digitalRead(g7)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('q');
  }
  //
  if ((digitalRead(g9) == 0))  // if the joystick button is pressed                                                            
  {
    
    Keyboard.press(32);  // click the left button down
  }
  else if ((digitalRead(g9)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release(32);
  }
  //
  if ((digitalRead(g8) == 0))  // if the joystick button is pressed                                                            
  {
    
    Keyboard.press('b');  // click the left button down
  }
  else if ((digitalRead(g8)== 1) ) // if the joystick button is not pressed
  {
    Keyboard.release('b');
  }
 }
void loop()
{
  vertValue = analogRead(vertPin) - vertZero;  // read vertical offset
  horzValue = analogRead(horzPin) - horzZero;  // read horizontal offset

  if (vertValue != 0)
    Mouse.move(0, (invertMouse * (vertValue / sensitivity)), 0); // move mouse on y axis
  if (horzValue != 0)
    Mouse.move((-invertMouse * (horzValue / sensitivity)), 0, 0); // move mouse on x axis
  mo();
  ke(); 
}
