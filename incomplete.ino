#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 #include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,14,12);
// Replace with your network credentials
const char* ssid = "Realme 1";
const char* password = "smilinjasper";
 String voltage,voltage2,voltage3,current,current2,current3,pf,pf2,pf3,frequency,frequency2,frequency3,power,power2,power3;
String voltagei() {
  return String(voltage);
  //return String(1.8 * bme.readTemperature() + 32);
}

String poweri() {
  return String(power);
  //return String(1.8 * bme.readTemperature() + 32);
}

String pfi() {
  return String(pf);
}
  
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
double data; 
void setup(void){
 
  pinMode(A0, INPUT);
  
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", [](){
    page = "<html><head><title>Smart Energy Meter using IoT</title></head><style type=\"text/css\"> <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\"><link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin><link href=\"https://fonts.googleapis.com/css2?family=Josefin+Sans:wght@400;700&display=swap\" rel=\"stylesheet\">";
    page += "table{border-collapse: collapse;}th {background-color:  green ;color: white;}.styled-table {border-collapse: collapse;margin: 25px 0;border-radius: 20px;font-size: 1em;min-width: 400px;box-shadow: 0 0 20px rgba(0, 0, 0, 0.15);text-align: center;}.styled-table thead tr {background-color: #009879;color: #ffffff;}.styled-table tr:first-child {font-size: 1.2em;}.styled-table th,.styled-table td {padding: 12px 15px;}.styled-table tbody tr {border-bottom: 1px solid #dddddd;}.styled-table tbody tr:nth-of-type(even) {background-color: #f3f3f3;}.styled-table tbody tr:last-of-type {border: none;};";
    page += "</style><body><center>";
    page += "<h1>Smart Energy Meter using IoT</h1><br><br><table style=\"width: 1200px;height: 450px;\"><tr>";
    page += "<th>Parameters</th><th>Value</th><th>Units</th></tr><tr><td>Voltage</td><td>"+String(voltage)+"</td><td>Volts</td></tr>";
    page += "<tr><td>Current</td><td>"+String(current)+"</td><td>Amperes</td></tr><tr><td>Power Factor</td><td>"+String(pf)+"</td><td>XXXX</td>";
    page += "<tr><td>Power</td><td>"+String(power)+"</td><td>Watts</td></tr><tr>";
    page += "</tr><tr><td>Frequency</td><td>"+String(frequency)+"</td><td>Hz</td></tr>";
    page += "<meta http-equiv=\"refresh\" content=\"3\">";
    server.send(240, "text/html", page);
  });
  
  server.begin();
  Serial.println("Web server started!");
  while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
}
 
void loop(void){
  data = analogRead(A0);
  delay(1000);
  if (Serial.available()) {
Serial.write(Serial.read());
}

        Serial.print(voltage); Serial.println("V");
   
        Serial.print(current); Serial.println("A");
    
        Serial.print("Power: "); Serial.print(power);
        Serial.println("W");
    
        Serial.print("Frequency: "); Serial.print(frequency);
        Serial.println("Hz");
   
        Serial.print("PF: "); 
        Serial.println(pf);
    
        Serial.println();
        
        Serial.print(voltage2); Serial.println("V");
   
        Serial.print(current2); Serial.println("A");
    
        Serial.print("Power: "); Serial.print(power2);
        Serial.println("W");
    
        Serial.print("Frequency: "); Serial.print(frequency2);
        Serial.println("Hz");
   
        Serial.print("PF: "); 
        Serial.println(pf2);
    
        Serial.println();
                
        Serial.print(voltage3); Serial.println("V");
   
        Serial.print(current3); Serial.println("A");
    
        Serial.print("Power: "); Serial.print(power3);
        Serial.println("W");
    
        Serial.print("Frequency: "); Serial.print(frequency3);
        Serial.println("Hz");
   
        Serial.print("PF: "); 
        Serial.println(pf3);
    
        Serial.println();
        delay(500);

// when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
  server.handleClient();
}