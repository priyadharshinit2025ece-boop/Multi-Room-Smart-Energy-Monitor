/* Multi-Room Energy Monitor - Wokwi Compatible Version
   - Simulates current measurements using potentiometers
   - Works with Blynk Cloud (Port 80 - non SSL)
   - Works with ThingSpeak
*/

#define BLYNK_TEMPLATE_ID "TMPL3rZVm8nBP"
#define BLYNK_TEMPLATE_NAME "Multi room smart energy monitor"
#define BLYNK_AUTH_TOKEN "EHwbJBTULYnJt-oz7I5qyaI9WjbJaFea"

#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include <BlynkSimpleEsp32.h>     

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

String THINGSPEAK_APIKEY = "7MPP8XEABLBLYIS7";

const float V_RMS = 230.0;

float SAFE_LIMIT_W = 5000.0;

const int PIN_I1 = 34;
const int PIN_I2 = 35;
const int PIN_I3 = 32;

const int PIN_RELAY = 2;
const int PIN_ALARM = 15;

const int ADC_MAX = 4095;
const float SIM_MAX_CURRENT = 10.0;

BlynkTimer timer;

unsigned long lastTS = 0;
const long TS_INTERVAL = 15000;

double energyWh = 0;
unsigned long lastMillis = 0;

bool relayState = true;

float readSimCurrent(int pin) {
  int raw = analogRead(pin);
  float current = ((float)raw / ADC_MAX) * SIM_MAX_CURRENT;
  return current;
}
void sendToThingSpeak(float p1, float p2, float p3, float total, double energy)
{
  if (WiFi.status() != WL_CONNECTED) return;
  if (THINGSPEAK_APIKEY == "") return;

  HTTPClient http;

  String url = "http://api.thingspeak.com/update?api_key=" + THINGSPEAK_APIKEY +
               "&field1=" + String(p1, 2) +
               "&field2=" + String(p2, 2) +
               "&field3=" + String(p3, 2) +
               "&field4=" + String(total, 2) +
               "&field5=" + String(energy, 3);

  http.begin(url);
  http.GET();
  http.end();
}

void processSensors()
{
  float I1 = readSimCurrent(PIN_I1);
  float I2 = readSimCurrent(PIN_I2);
  float I3 = readSimCurrent(PIN_I3);

  float P1 = V_RMS * I1;
  float P2 = V_RMS * I2;
  float P3 = V_RMS * I3;

  float total = P1 + P2 + P3;

  Blynk.virtualWrite(V1, P1);
  Blynk.virtualWrite(V2, P2);
  Blynk.virtualWrite(V3, P3);
  Blynk.virtualWrite(V4, total);

  unsigned long now = millis();
  if (lastMillis > 0) {
    double hours = (now - lastMillis) / 3600000.0;
    energyWh += total * hours;
  }
  lastMillis = now;

  Blynk.virtualWrite(V5, energyWh);

  if (total > SAFE_LIMIT_W) {
    relayState = false;
    digitalWrite(PIN_RELAY, LOW);
    digitalWrite(PIN_ALARM, HIGH);
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V7, 1);
  } else {
    digitalWrite(PIN_ALARM, LOW);
    Blynk.virtualWrite(V7, 0);
  }

  if (millis() - lastTS >= TS_INTERVAL) {
    lastTS = millis();
    sendToThingSpeak(P1, P2, P3, total, energyWh);
  }
}

BLYNK_WRITE(V0)   
{
  int v = param.asInt();
  relayState = v;
  digitalWrite(PIN_RELAY, v ? HIGH : LOW);
}

BLYNK_WRITE(V6)   // Reset Energy
{
  int v = param.asInt();
  if (v == 1) {
    energyWh = 0;
    Blynk.virtualWrite(V5, 0);
  }
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);

  pinMode(PIN_RELAY, OUTPUT);
  pinMode(PIN_ALARM, OUTPUT);

  digitalWrite(PIN_RELAY, HIGH);
  digitalWrite(PIN_ALARM, LOW);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  // IMPORTANT → Works in WOKWI
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);

  timer.setInterval(1000, processSensors);
}
void loop() {
  Blynk.run();
  timer.run();
}