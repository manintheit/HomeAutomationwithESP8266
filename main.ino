
/**
 * Author:    manintheit
 * Created:   10.01.2019
 * https://github.com/esp8266/Arduino
 **/



#include <ESP8266WiFi.h>
const char* ssid = "SSID NAME";
const char* password = "WIFI PASSWORD";
String pin7_st = "off" ;

//No Keep-Alive
String header = String("HTTP/1.1 200 OK\r\n"  
                     "Content-Type: text/html\r\n" 
                     "Connection: close\r\n"  
                     "\r\n" );

//disable GET /favicon.ico HTTP/1.1"

String body = String("<!DOCTYPE html><html>\n" 
                     "<link rel=\"icon\" href=\"data:;base64,=\">" 
                     "<body>\n");   
                                    

WiFiServer server(80);
void setup()
{
 pinMode(D7, OUTPUT);
 digitalWrite(D7, LOW);
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  server.begin();
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
}

//############################################################################################################333


void loop()
{
  WiFiClient client = server.available();
  // wait for a client (web browser) to connect
  if (client)
  {
    Serial.println("\n[Client connected]");
    String content;
    char chr;
    boolean invalid_req = true;
    //String pin7_st = "off";
    while (client.connected())
    {
      // read line by line what the client (web browser) is requesting
      if (client.available())
      {
        //###################################################################
          chr = client.read();
          if (chr == '\n'){
             Serial.println(content);
             Serial.println(content.length());
             if (content.endsWith("/pin7/on HTTP/1.1")) {
                 pin7_st = "on";
                 invalid_req = false;
             }

             if (content.endsWith("/pin7/off HTTP/1.1")) {
                 pin7_st = "off";
                 invalid_req = false;
             } 

             
             if (content.length() == 0){

             if (pin7_st == "on"){
                Serial.println("================ON=======================");
                digitalWrite(D7, HIGH);
              } else if (pin7_st == "off") {
                
                Serial.println("================OFF=======================");
                digitalWrite(D7, LOW);
                }

              
              client.print(header);
              client.print(body);
              if (!invalid_req){
              client.print("<h1>D7 pin is: " + pin7_st + "</h1>\n");
              } else{
                client.print("<br><br>\n");
                client.print("<h3>USAGE:http://&lt[IP|HOSTNAME]&gt/&ltpin number&gt/[on|off]</h3>\n");
                client.print("<br>EX1:http://192.168.1.110&gt/pin7/on</br>\n");
                client.print("<br>EX2:http://192.168.1.110&gt/pin7/off</br>\n");
              }
              client.print("</body>\n");

//                  client.println("HTTP/1.1 200 OK");
//                  client.println("Content-Type: text/html");
//                  client.println("Connection: close");
//                  client.println();
//
//                  client.println("<!DOCTYPE html><html>");
//                  client.println("<body><h1>TEST123</h1>");
//                  client.println("</body></html>");
//                  client.println();
                  break;         
                
              } else {
                  content = "";
                }


             
          } else if ( chr != '\r' ){
              content += chr;
              
          }
          
          
        //###################################################################

      }
  
    }
  
    delay(2); // give the web browser time to receive the data
    // close the connection:
   
     client.flush();
     client.stop();
    Serial.println("[Client disonnected]");
  }
}
