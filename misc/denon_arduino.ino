#include <Ethernet.h>
#include <SPI.h>

byte mac[] = { 0x90,0xA2,0xDA,0x00,0x55,0x8D};  
EthernetClient client;

int inPin = 8;
int state = HIGH;

char denonIP[ ] = "192.168.1.157";

// Setting up the counter
int reading = 0;

// Timing for polling the encoder
unsigned long currentTime;
unsigned long lastTime;


// Pin definitions
const int pinA = 10;
const int pinB = 9;

// Storing the readings
boolean encA;
boolean encB;
boolean lastA = false;

void setup() {
  // set the two pins as inputs with internal pullups
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(inPin, INPUT);

  // Set up the timing of the polling
  currentTime = millis();
  lastTime = currentTime;
  // Start the serial monitor for debugging
  Serial.begin(9600);
  
  Ethernet.begin(mac);
  delay(1000);
  Serial.println("connecting...");

  // print your local IP address:
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
} 

void volumeUp(){
  
  Serial.println("volumeUp");
  if (client.connect(denonIP,80)) {
      client.println("GET /goform/formiPhoneAppDirect.xml?MVUP HTTP/1.1");
      client.println("Connection: close");
      client.println();
    }

  if (client.connected()) {
     client.stop();
  }
}

void volumeDown(){
  
  Serial.println("volumeDown");
  if (client.connect(denonIP,80)) {
      client.println("GET /goform/formiPhoneAppDirect.xml?MVDOWN HTTP/1.1");
      client.println("Connection: close");
      client.println();
    }

  if (client.connected()) {
     client.stop();
  }
}

void switchON(){
  Serial.println("switchON");
  if (client.connect(denonIP,80)) {
      client.println("GET /goform/formiPhoneAppPower.xml?1+PowerOn HTTP/1.1");
      client.println("Connection: close");
      client.println();
    }

  if (client.connected()) {
     client.stop();
  }
}

void switchOFF(){
  Serial.println("switchOFF");
  if (client.connect(denonIP,80)) {
      client.println("GET /goform/formiPhoneAppPower.xml?1+PowerStandby HTTP/1.1");
      client.println("Connection: close");
      client.println();
    }

  if (client.connected()) {
     client.stop();
  }
}

void loop()
{
  
   reading = digitalRead(inPin);
   
   if (reading != state){
     if (reading==HIGH){
       switchON();
       delay(1000);
     }else{
       switchOFF();
       delay(1000);
     }
     state = reading;
   }
  
  // Read elapsed time
  currentTime = millis(); 
  // Check if it's time to read
  if(currentTime >= (lastTime + 5))
  {
    // read the two pins
    encA = digitalRead(pinA);
    encB = digitalRead(pinB);
    // check if A has gone from high to low
    if ((!encA) && (lastA))
    {
      // check if B is high 
      if (encB)
      {
          volumeUp();
      }
      else
      {
          volumeDown();
      }
    }
    // store reading of A and millis for next loop
    lastA = encA;
    lastTime = currentTime;

  }

}
