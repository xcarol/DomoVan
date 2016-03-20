
//Posem en marxa les comunicacions amb el Serial per a pode mostrar missatge per la consola
//Eines -> Monitor sèrie. Si el flag waitSerial està a true esperarà a que connectem la consola
//per continuar. Si està a false no s'espera.
void setupSerial()
{
  bool waitSerial = false;
  
  Serial.begin(9600);
  
  while (waitSerial && !Serial) {
    // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println(F("DomoVan en marxa!"));
}


int readAnalogSensor(int analogPin)
{
  return analogRead(analogPin);
}

void setup() {
  setupSerial();
}

void loop() {
  int value = readAnalogSensor(A0);
  Serial.println(value);
  delay(1000);
}
