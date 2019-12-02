int led = 13;   // usamos pin13 de salida al LED
int DATO = 0;   // variable de lectura serial

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){   // si el Bluetooh MASTER manda dato lo guardamos en DATO
    DATO = Serial.read();
    Serial.println("LLego un dato");
  }                             // esta parte de codice es para solo 1 caracter

  if (DATO == '0'){
    digitalWrite(led, LOW);
    Serial.println(" 0 ");
  }

  if (DATO == '1'){
    digitalWrite(led, HIGH);
    Serial.println(" 1 ");
  }
}
