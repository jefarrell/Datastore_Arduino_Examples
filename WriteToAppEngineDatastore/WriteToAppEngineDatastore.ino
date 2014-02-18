/*
  Yun Yun Google App Engine Datastore read/write

 This example writes sensor data to Google App Engine's NDB Datastore via a GET Query string. The 'devicename' is the key used to store all readings put() on the server
 
 For local development set the local boolean to 'true' and start google app engine via the command line with the following

_________________<your_terminal_name>$  dev_appserver.py --host=<Your_Computer's IP address> ndb_store/   _________________________________
The default port is ':8080' which should be appended to the URL.  see: https://developers.google.com/appengine/docs/python/tools/devserver#Python_Running_the_development_web_server for further info



 created by Tom igoe
 
 May 2013

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/HttpClient

 */

#include <Bridge.h>
#include <HttpClient.h>

boolean Local = true;// Set to true if you are working locally on your machine
String IP = "192.168.1.7";
String complete_IPAddress = "http://" + IP + ":8080"; //IP address of local development machine
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
  client.get(complete_IPAddress + "/write?devicename=" + devicename + "&a0="+ String(analogRead(lightPin)) +"&a1=888");
}
  // Make a HTTP request to Google Cloud Services:
  else{
  client.get("sensorndbstore.appspot.com/write?devicename=" + devicename + "&a0="+ String(analogRead(lightPin)));
  }
  
 digitalWrite(13, HIGH);//heartbeat 
 analogWrite(ledPin, analogRead(lightPin)/4);
 digitalWrite(13, LOW);//heartbeat

  delay(10000);
}


