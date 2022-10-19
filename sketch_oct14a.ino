const int ledPin = 5;   //pin 3 has PWM funtion
const int flexPin = A0; //pin A0 to read analog input
const int heatPin = 13; //pin 13 to heater 
const int motorPin = 8; // Pin 8 to vibrator 


//Variables:
int flexValue; //save analog value
int power = 0; 
int peltier_level;

void setup(){
  
  pinMode(ledPin, OUTPUT);  //Set pin 3 as 'output'
  pinMode(heatPin, OUTPUT); //Set pin 13 as 'output'
  pinMode(motorPin, OUTPUT); //Set pin 8 as 'output'
  Serial.begin(9600);       //Begin serial communication

}

void loop(){
  
  flexValue = analogRead(flexPin);         //Read and save analog value from potentiomete
  flexValue = map(flexValue, 700, 900, 0, 255); 
  Serial.println(flexValue); //Printing the flex value 
  if(flexValue > 404) 
  {
    digitalWrite(heatPin, 500); // toggling heater to heat up 
    digitalWrite(motorPin, HIGH); //Send PWM value to motorPin
    analogWrite(ledPin, HIGH);  //Send PWM value to led
    delay(100);
  }
  else 
  {
    digitalWrite(heatPin, LOW);
    digitalWrite(motorPin, LOW);
    analogWrite(ledPin, LOW);
  }  
}
