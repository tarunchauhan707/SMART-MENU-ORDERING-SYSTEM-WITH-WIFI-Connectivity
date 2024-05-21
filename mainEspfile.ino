#include <Arduino.h>
#include<SoftwareSerial.h>        //serial communication library
#include <ESP8266WiFi.h>          // esp8266 library
#include <Firebase_ESP_Client.h>  //firebase library



// ................................Wifi Connecting function........................................
// Insert your network credentials
#define WIFI_SSID "wifi_name"
#define WIFI_PASSWORD "wifi_password"
void wifiConnectivity(){
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(1000);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}



// ...................................Firebase function ...........................................
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"


// Insert Firebase project API Key
#define API_KEY "api key"


//RTDB-- REAL TIME DATA BASE
// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "data-base-url"




//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

//declare a bool variable for authenication purpose
bool signupOK = false;



// .........................Main Setup Function ...................................................
void setup() {
// Open serial communications and wait for port to open:
  Serial.begin(9600);
  wifiConnectivity();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
 
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
//declare a variable of string type to store the incomming string data
String data;
void loop() {
  // run over and over
  if (Serial.available()) {
    //read the serially transfered string until '\n' and store it into a variable
    data = Serial.readStringUntil('\n');
    data.remove(data.length()-1, 1);
    Serial.println(data);
    if (Firebase.ready() && signupOK ) {
      if(data == "Call Waiter"){
        //if string is call waiter then update waiter menu section of database
        Firebase.RTDB.setString(&fbdo, "/MENU/WAITER", data);
        Serial.print("CUSTOMER CALLING TO: ");
        Serial.println(data);
      }
      else if(data == "Water"){
        //if string is water then update water menu section of database
        Firebase.RTDB.setString(&fbdo, "/MENU/WATER", data);
        Serial.print("CUSTOMER NEED WATER: ");
        Serial.println(data);
      }
      else {
        //update order menu section of database
        Firebase.RTDB.setString(&fbdo, "/MENU/ORDER", data);
        Serial.print("CUSTOMER ORDER: ");
        Serial.println(data);
      }
    Serial.println("");
  }
  delay(1000);
  }
  //update the database menu of water and waiter to its previous_
  Firebase.RTDB.setString(&fbdo, "/MENU/WATER", "NO NEED WATER");
  Firebase.RTDB.setString(&fbdo, "/MENU/WAITER", "NO CALLING WAITER");

}
