#include "ESP8266WiFi.h" 
#include <ros.h>

const char* ssid = "Santos Ferreira"; //Enter SSID 

const char* password = "34827213"; //Enter Password 


ros::NodeHandle nh; 

void setup(void) 

{  

  Serial.begin(115200); 

  // Connect to WiFi 

  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED)  

  { 

     delay(500); 

     Serial.print("*"); 

  } 

   

  Serial.println(""); 

  Serial.println("WiFi connection Successful"); 

  Serial.print("The IP Address of ESP8266 Module is: "); 

  Serial.print(WiFi.localIP());// Print the IP address 

} 

 

void loop()  

{ 

  // EMPTY 

} 
