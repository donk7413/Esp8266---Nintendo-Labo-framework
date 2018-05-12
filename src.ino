#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "myssid";//type your ssid
const char* password = "myPwd";//type your password
int timer = 0;    // temporary variable for reading the button pin status

const char* Button = "http_url_of_action_1"; //URL of a action to perform(for example light control with Jeedom or Domoticz)
const char* Kicker = "http_url_of_action_2"; //URL of a action to perform(for example light control with Jeedom or Domoticz)
const char* Crank = "http_url_of_action_3"; //URL of a action to perform(for example light control with Jeedom or Domoticz)


int x = 0;
int temp = 0;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D5, INPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {

  temp = digitalRead(D5);

  if (temp == HIGH) {
    x = x + 1;

    Serial.println("LED Turned ON");
    Serial.println("X = ");
    Serial.println(x);

    delay(1000);

  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Timer : ");
    delay(1000);
    timer = timer + 1 ;
    Serial.println(timer);

  }

  if (timer > 3)
  { check();
    timer = 0;

    x = 0;
  }


}

void check()
{
  Serial.println("Value of request : ");
  Serial.println(x);
  if (x >= 1 && x <= 2)
  {

    Serial.println("Button Detected !");

    digitalWrite(LED_BUILTIN, LOW);
    WiFiClient test;
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin(Button);  //Specify request destination
    Serial.println("connecting...");
    int httpCode = http.GET();//Send the request
    delay(1000);
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
    }
  }
  
  //Crank Input
  if  (x >= 3 && x <= 4)
  {

    Serial.println("Crank Detected !");

    digitalWrite(LED_BUILTIN, LOW);
    WiFiClient test;
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin(Crank);  //Specify request destination
    Serial.println("connecting...");
    int httpCode = http.GET();//Send the request
    delay(1000);
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
    }
  }
  
  //Kicker Input
  if (x >= 5 && x <= 6)
  {


    Serial.println("Kicker Detected !");

    digitalWrite(LED_BUILTIN, LOW);
    WiFiClient test;
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin(Kicker);  //Specify request destination
    Serial.println("connecting...");
    int httpCode = http.GET();//Send the request
    delay(1000);
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
    }

    http.end();   //Close connection
    x = 0;
    timer = 0;
  }

}
