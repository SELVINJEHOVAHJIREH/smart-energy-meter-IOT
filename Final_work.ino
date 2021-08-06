#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <PZEM004Tv30.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>
#include <PZEM004Tv30.h>
PZEM004Tv30 pzem(D1,D0);  //RX/TX
PZEM004Tv30 pzem2(D3,D2);  //RX/TX
PZEM004Tv30 pzem3(D5,D4);  //RX/TX


int relay1=D3;
int relay2=D4;
int relay3=D5;
const char* ssid = "admin";//Replace with your network SSID
const char* password = "12345678";//Replace with your network password

ESP8266WebServer server(80);
float voltage,voltage2,voltage3,current,current2,current3,pf,pf2,pf3,frequency,frequency2,frequency3,power,power2,power3;
String page = "";

void setup() {
  Serial.begin(115200);
   Serial.begin(9600);
   lcd.init();
   lcd.setCursor(0,0);
   lcd.backlight();
  pinMode(relay1,INPUT);
  pinMode(relay2,INPUT);
  pinMode(relay3,INPUT);
Serial.begin(115200);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
  {
  delay(500);
  Serial.print(".");
  }
  Serial.println(WiFi.localIP());
  server.on("/", []()
  {
    page = "<html><head><title>Smart Energy Meter using IoT</title></head><style type=\"text/css\"> <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">
    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>
    <link href=\"https://fonts.googleapis.com/css2?family=Josefin+Sans:wght@400;700&display=swap\" rel=\"stylesheet\">";
    page += "table{border-collapse: collapse;}th {background-color:  green ;color: white;}.styled-table {
        border-collapse: collapse;
        margin: 25px 0;
        border-radius: 20px;
        font-size: 1em;
        min-width: 400px;
        box-shadow: 0 0 20px rgba(0, 0, 0, 0.15);
        text-align: center;
    }
    
    .styled-table thead tr {
        background-color: #009879;
        color: #ffffff;
    }
    
    .styled-table tr:first-child {
        font-size: 1.2em;
    }
    
    .styled-table th,
    .styled-table td {
        padding: 12px 15px;
    }
    
    .styled-table tbody tr {
        border-bottom: 1px solid #dddddd;
    }
    
    .styled-table tbody tr:nth-of-type(even) {
        background-color: #f3f3f3;
    }
    
    .styled-table tbody tr:last-of-type {
        border: none;
    };"
    page += "</style><body><center>";
    page += "<h1>Smart Energy Meter using IoT</h1><br><br><table style=\"width: 1200px;height: 450px;\"><tr>";
    page += "<th>Parameters</th><th>Value</th><th>Units</th></tr><tr><td>Voltage</td><td>"+String(voltage)+"</td><td>Volts</td></tr>";
    page += "<tr><td>Current</td><td>"+String(current)+"</td><td>Amperes</td></tr><tr><td>Power Factor</td><td>"+String(pf)+"</td><td>XXXX</td>";
    page += "<tr><td>Power</td><td>"+String(power)+"</td><td>Watts</td></tr><tr>";
    page += "</tr><tr><td>Frequency</td><td>"+String(frequency,1)+"</td><td>Hz</td></tr>";
    page += "<meta http-equiv=\"refresh\" content=\"3\">";
    server.send(240, "text/html", page);
  });
  server.begin();
}


void loop() {
    voltage = pzem.voltage();
    current = pzem.current();
    power = pzem.power();
    frequency = pzem.frequency();
    pf = pzem.pf();
    server.handleClient();

    if((voltage<=240) && (voltage>=220)){
    digitalWrite(relay1,HIGH);
                              }
     else if(voltage<220) && (voltage>240){
    digitalWrite(relay2,HIGH);
  }
    else{
      digitalWrite(relay3,HIGH);
    }


     voltage2 = pzem2.voltage();
    current2 = pzem2.current();
    power2 = pzem2.power();
    frequency2 = pzem2.frequency();
    pf2 = pzem2.pf();
    server.handleClient();

    if((voltage2<=240) && (voltage2 >= 220)){
    digitalWrite(relay2,HIGH);
                              }
     else if(voltage2 <220) && (voltage2>240){
    digitalWrite(relay1,HIGH);
  }
    else{
      digitalWrite(relay3,HIGH);
    }


     voltage3 = pzem3.voltage();
    current3 = pzem3.current();
    power3 = pzem3.power();
    frequency3 = pzem3.frequency();
    pf3 = pzem3.pf();
    server.handleClient();

    if((voltage3 <= 240) && (voltage3 >= 220)){
    digitalWrite(relay3,HIGH);
                              }
     else if(voltage3 < 220) && (voltage3>240){
    digitalWrite(relay1,HIGH);
  }
    else{
      digitalWrite(relay2,HIGH);
    }

