int gas_input = 4;  

void setup() 
{
  Serial.begin(115200);  
  pinMode(gas_input, INPUT);   //defining gas_input as input
}

void loop() 
{
  int gasAnalogReading = analogRead(gas_input);    //integer to read the sensor values
  Serial.print("Gas Sensor: ");
  Serial.print(gasAnalogReading);                  //prints the values on Serial Monitor
  Serial.print("\t");
  
  if (gasAnalogReading > 200)                      //according to my calibration, this is the value
  {
    Serial.println("Smog detected but situation is out of danger.");
  }
  else if (gasAnalogReading > 350)
  {
    Serial.println("MILD SMOG PRESENT. Be Vigilant!");
  }
  else if (gasAnalogReading > 800)
  {
    Serial.println("HIGH DANGER!! SLOW DOWN AND PARK ASIDE.");
  }
  else
  {
    Serial.println("No Visibility Issues. You are in Safe Zone.");
  }
  delay(1000);
}
