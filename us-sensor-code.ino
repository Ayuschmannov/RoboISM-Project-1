//The code for Ultrasonic sensor is given below
//The board used is ESP WROOM 32
//Compiled and tested on Arduino IDE 1.8.13

const int trigPin = 2;        //defining the Trigger pin number
const int echoPin = 5;        //defining the Echo pin number
// defining the variables: duration, distance
long duration;
int distance;

void setup()
{
pinMode(trigPin, OUTPUT);      // Setting the trigPin as an Output
pinMode(echoPin, INPUT);       // Setting the echoPin as an Input
Serial.begin(115200);          // Starting the serial communication with baud rate as 115200
}
void loop()
{
digitalWrite(trigPin, LOW);     // Clearing the trigPin
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);    // Setting the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);  // Reading the echoPin, returns the sound wave travel time in microseconds
distance= duration*0.034/2;         // Calculating the distance
Serial.print("Distance in cm is: ");      // Printing the distance on the Serial Monitor
Serial.println(distance);
if(distance < 350)
{
  Serial.println("Car is Very Close!! HIGH ALERT");
}
delay(500);
}
