#include "ESP8266WiFi.h" 
#include <ros.h>
#include "std_msgs/String.h"

const char* ssid = "Santos Ferreira"; //Enter SSID 

const char* password = "34827213"; //Enter Password 

const uint16_t serverPort = 11411;

void message(const std_msgs::String& msg){
  String m = msg.data;
  Serial.println(m);
}

IPAddress server(10,0,0,176);

//They have to be global variables
ros::NodeHandle nh; 
std_msgs::String msg;
ros::Publisher pub("teste_esp",&msg);
ros::Subscriber<std_msgs::String> sub("teste_esp",&message);

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


  nh.getHardware()->setConnection(server,serverPort);
  nh.initNode();


  nh.advertise(pub);
  nh.subscribe(sub);

} 

void loop()  

{ 
  
  if(nh.connected()){
    //msg.data = "Hello World";

    //pub.publish(&msg);
  
  }
  else{
    Serial.println("Not Connected");
  }
  nh.spinOnce();
  delay(100);
} 
