#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#include <ESP8266WiFi.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


String apiKey = "Q8QZLYC84QKC74QS";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "SKY_DLINK";     // replace with your wifi ssid and wpa2 key
const char *pass =  "Admin@123";
const char* server = "api.thingspeak.com";
WiFiClient client;

#include <PZEM004Tv30.h>

PZEM004Tv30 pzem1(14, 12); // Software Serial pin 11 (RX) & 12 (TX)
PZEM004Tv30 pzem2(13, 15);
PZEM004Tv30 pzem3(2, 0);
void setup() {
   Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  
  Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}

void loop() {
   float voltage1 = pzem1.voltage();
   float voltage2 = pzem2.voltage();
   float voltage3 = pzem3.voltage();
   if(voltage1 != NAN){
       Serial.print("Voltage1: ");
       Serial.print(voltage1);
       Serial.println("V ");
       Serial.print("Voltage2: ");
       Serial.print(voltage2);
       Serial.println("V ");
       Serial.print("Voltage3: ");
       Serial.print(voltage3);
       Serial.println("V ");
       lcd.setCursor(0,0);
       lcd.print("V1:");
       lcd.print(voltage1);
       lcd.println("V ");
       lcd.setCursor(8,0);
       lcd.print("V2:");
       lcd.print(voltage2);
       lcd.println("V ");
       lcd.setCursor(0,1);
       lcd.print("V3:");
       lcd.print(voltage3);
       lcd.println("V ");
       delay(2000);
       
   } else {
       Serial.println("Error reading voltage");
   }

   float current1 = pzem1.current();
   float current2 = pzem2.current();
   float current3 = pzem3.current();
   if(current1 != NAN){
       Serial.print("Current1: ");
       Serial.print(current1);
       Serial.println("A");
       Serial.print("Current2: ");
       Serial.print(current2);
       Serial.println("A");
       Serial.print("Current3: ");
       Serial.print(current3);
       Serial.println("A");
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("C1:");
       lcd.print(current1);
       lcd.println("A ");
       lcd.setCursor(8,0);
       lcd.print("C2:");
       lcd.print(current2);
       lcd.println("A ");
       lcd.setCursor(0,1);
       lcd.print("C3:");
       lcd.print(current3);
       lcd.println("A ");
       delay(2000);
   } else {
       Serial.println("Error reading current");
   }

   float power1 = pzem1.power();
   float power2 = pzem2.power();
   float power3 = pzem3.power();
   if(current1 != NAN){
       Serial.print("Power1: ");
       Serial.print(power1);
       Serial.println("W ");
       Serial.print("Power2: ");
       Serial.print(power2);
       Serial.println("W ");
       Serial.print("Power3: ");
       Serial.print(power3);
       Serial.println("W ");
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("P1:");
       lcd.print(power1);
       lcd.println("W ");
       lcd.setCursor(8,0);
       lcd.print("P2:");
       lcd.print(power2);
       lcd.println("W ");
       lcd.setCursor(0,1);
       lcd.print("P3:");
       lcd.print(power3);
       lcd.println("W ");
       delay(2000);
   } else {
       Serial.println("Error reading power");
   }

   float energy1 = pzem1.energy();
   float energy2 = pzem2.energy();
   float energy3 = pzem3.energy();
   if(current1 != NAN){
       Serial.print("Energy1: ");
       Serial.print(energy1,3);
       Serial.println("kWh");
       Serial.print("Energy2: ");
       Serial.print(energy2,3);
       Serial.println("kWh");
       Serial.print("Energy3: ");
       Serial.print(energy3,3);
       Serial.println("kWh");
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("E1:");
       lcd.print(energy1,3);
       lcd.println("kWh");
       lcd.setCursor(8,0);
       lcd.print("E2:");
       lcd.print(energy2,3);
       lcd.println("kWh");
       lcd.setCursor(0,1);
       lcd.print("E3:");
       lcd.print(energy3,3);
       lcd.println("kWh");
       delay(2000);
   } else {
       Serial.println("Error reading energy");
   }

   float frequency1 = pzem1.frequency();
   float frequency2 = pzem2.frequency();
   float frequency3 = pzem3.frequency();
   if(current1 != NAN){
       Serial.print("Frequency1: ");
       Serial.print(frequency1, 1);
       Serial.println("Hz");
       Serial.print("Frequency2: ");
       Serial.print(frequency2, 1);
       Serial.println("Hz");
       Serial.print("Frequency3: ");
       Serial.print(frequency3, 1);
       Serial.println("Hz");
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("F1:");
       lcd.print(frequency1, 1);
       lcd.println("Hz");
       lcd.setCursor(8,0);
       lcd.print("F2:");
       lcd.print(frequency2, 1);
       lcd.println("Hz");
       lcd.setCursor(0,1);
       lcd.print("F3:");
       lcd.print(frequency3, 1);
       lcd.println("Hz");
delay(2000);
   } else {
       Serial.println("Error reading frequency");
   }

   float pf1 = pzem1.pf();
   float pf2 = pzem2.pf();
   float pf3 = pzem3.pf();
   if(current1 != NAN){
       Serial.print("PF1:");
       Serial.println(pf1);
       
       Serial.print("PF2:");
       Serial.println(pf2);
       
       Serial.print("PF3:");
       Serial.println(pf3);
lcd.clear();
lcd.setCursor(0,0);
       lcd.print("PF1:");
       lcd.println(pf1);
       lcd.print(" ");
       lcd.setCursor(8,0);
       lcd.print("PF2:");
       lcd.println(pf2);
       lcd.print(" ");
       lcd.setCursor(0,1);
       lcd.print("PF3:");
       lcd.println(pf3);
       lcd.print(" ");
       delay(2000);
   } 
   
   else {
       Serial.println("Error reading power factor");
   }

   if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(voltage1);
                             postStr +="&field2=";
                             postStr += String(voltage2);
                             postStr +="&field3=";
                             postStr += String(voltage3);
                             postStr +="&field4=";
                             postStr += String(current1);
                             postStr +="&field5=";
                             postStr += String(current2);
                             postStr +="&field6=";
                             postStr += String(current3);
                             postStr +="&field7=";
                             postStr += String(pf1);
                             postStr +="&field8=";
                             postStr += String(pf2);
                             postStr += "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n\n\n\n\n\n\n");
                             client.print(postStr);
 
                             
                        }
          client.stop();
 
          Serial.println("Waiting...");
           
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);


   Serial.println();
   delay(2000);
}
