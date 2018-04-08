#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial esp8266(10, 11); // RX, TX
Servo  servoMotor; //servoMotor


#define DEBUG true


void setup() { 
  Serial.begin(9600);
  servoMotor.attach(9);   
  esp8266.begin(9600);

  sendData("AT+RST\r\n", 2000, DEBUG); //reset module
  sendData("AT+CWMODE=1\r\n", 1000, DEBUG); //set station mode
  sendData("AT+CWJAP=\"FLIAJARAMILLOPARRA\",\"Pizarro19\"\r\n", 2000, DEBUG);   //connect wifi network
  while(!esp8266.find("OK")) { //wait for connection
  } 
  sendData("AT+CIFSR\r\n", 1000, DEBUG); //show IP address
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG); //allow multiple connections
  sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG); // start web server on port 80

   
   servoMotor.write(0);
  // Esperamos 1 segundo
  delay(1000);
  
  
  
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  // Esperamos 1 segundo
  delay(1000);
}

void loop() { 
  if (esp8266.available()) {
    Serial.write(esp8266.read());
    
  }
  if (Serial.available()) {
    esp8266.write(Serial.read());
    
  }
  if (esp8266.available())  //check if there is data available on ESP8266
  {
    if (esp8266.find("+IPD,")) //if there is a new command
    {
      String msg;
      esp8266.find("?"); //run cursor until command is found
      msg = esp8266.readStringUntil(' '); //read the message
      String command = msg.substring(0, 3); //command is informed in the first 3 characters. "sr1" = command to servo #1 and "sr2" = command to servo #2
      String valueStr = msg.substring(4);   //next 3 characters inform the desired angle
      int value = valueStr.toInt();         //convert to integer
      if (DEBUG) {
        Serial.println(command);
        Serial.println(value);
      }
      delay(100);

  if(command == "sr1") {
Serial.println("si puedo  entrar");
     servoMotor.write(0);
  // Esperamos 1 segundo
  delay(1000);
  
  // Desplazamos a la posición 90º
  servoMotor.write(90);
  // Esperamos 1 segundo
  delay(1000);
  
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  // Esperamos 1 segundo
  delay(1000);
       
        
      }

    
}
  }}

String sendData(String command, const int timeout, boolean debug)
{
  String response = "";
  esp8266.print(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (esp8266.available())
    {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug)
  {
    Serial.print(response);
  }
  return response;
}
