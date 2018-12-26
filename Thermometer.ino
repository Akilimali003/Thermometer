//Variable for the temperature sensor
const int sensorPin = A0;
//variable that holds the baseline of the room
const float baselineTemp = 20.0;

void setup() {
  // open a serial port to display values
  Serial.begin(9600);
  //  set the LED pins as outputs
  //the for() loop saves some extra coding
  for(int x = 2; x < 5; x++){
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }
}

void loop() {
  // read the value on the Analog In pin
  // and store it in a variable
  int sensorVal = analogRead(sensorPin); 
  //send the 10-bit sensor value out the serial port
  Serial.print(sensorVal);  
  Serial.print(" ADC, ");
  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;
  // send the voltage level out the Serial port
  Serial.print(" Volts: ");
  Serial.print(voltage); 
  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.print(temperature);  
  //  using the baseline temperature as a starting point, increase 
  //  the number of LEDs that are on for every than the baseline
  //  if the current temperature is lower than the baseline
  //  turn off all LEDs
    if(temperature < baselineTemp){
       digitalWrite(2, LOW);
       digitalWrite(3, LOW);
       digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4){
       digitalWrite(2, HIGH);
       digitalWrite(3, LOW);
       digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6){
       digitalWrite(2, HIGH);
       digitalWrite(3, HIGH);
       digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp + 6){
       digitalWrite(2, HIGH);
       digitalWrite(3, HIGH);
       digitalWrite(4, HIGH);
    }
    delay(1);
}
