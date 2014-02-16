/*
  Yun HTTP Client

 This example for the Arduino Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/HttpClient

 */

#include <Bridge.h>
#include <HttpClient.h>

boolean Local = true;// Set to true if you are working locally on your machine
String IPAddress = "http://192.168.1.10:8080"; //IP address of local development machine
String devicename = "dribblea";

int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED
int data;

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(11, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

}

void loop() {

  // Initialize the client library
  HttpClient client;

if (Local == true){
  client.get(IPAddress + "/write?devicename=" + devicename + "&a0="+ String(analogRead(lightPin)) +"&a1=888");
}
  // Make a HTTP request to Google Cloud Services:
  else{
  client.get("sensorndbstore.appspot.com/write?devicename=dribblea&sensorreading="+ String(analogRead(lightPin)) +"&sensormin=0&sensormax=1023");
  }
  
 digitalWrite(13, HIGH);//heartbeat 
 analogWrite(ledPin, analogRead(lightPin)/4);
 digitalWrite(13, LOW);//heartbeat

  delay(10000);
}


