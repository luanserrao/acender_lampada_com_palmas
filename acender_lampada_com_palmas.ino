int soundSensor = 8;            // pino 8 sensor de som
int relay = 9;                 //pino 9 modolo relé
int claps = 0;                  // contagem de palmas
long detectionSpanInitial = 0;
long detectionSpan = 0;
boolean lightState = false;
 
void setup() {
pinMode(soundSensor, INPUT);   //pino 8 entrada
pinMode(relay, OUTPUT);        //pino 9 saida
}
 
void loop() {
 
int sensorState = digitalRead(soundSensor);    //ler o sinal do sensor de som
 
if (sensorState == 0)
{
if (claps == 0)
{
detectionSpanInitial = detectionSpan = millis();
claps++;
}
else if (claps > 0 && millis()-detectionSpan >= 50)
{
detectionSpan = millis();
claps++;
}
}
 
if (millis()-detectionSpanInitial >= 400)
{
if (claps = 2)
{
if (!lightState)
{
lightState = true;
digitalWrite(relay, HIGH);    // ligar relé
}
else if (lightState)
{
lightState = false;
digitalWrite(relay, LOW);        // desligar relé
}
}
claps = 0;
}
}

