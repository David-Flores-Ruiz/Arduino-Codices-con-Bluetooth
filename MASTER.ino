//** Conexiones  físicas del ARDUINO y BLUETOOTH HC-05 que son MASTER **//
// Pines de 5v y GND para alimentar la proto
// Pin 10 - Pin TX del BT Master
// Pin 11 - Pin Rx del BT 
//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//

//** Un HC-05 debe estar como MASTER, osea, AT+ROLE=1, AT+CMODE=0, AT+BIND= "MAC del BT Slave"
//** Y el otro HC-05 debe ser SLAVE,  osea, AT+ROLE=0, AT+CMODE=1, AT+BIND= "00:00:0000:00:00"

//** Conexiones  físicas del ARDUINO y BLUETOOTH HC-05 que son SLAVE **
// Pin 0 (RX del Arduino) - TX del BT Slave
// Pin 1 (TX del Arduino) - RX del BT
// Pin 13 - Resistor de 330 y con LED polarizado a la Tierra
//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//


#include <SoftwareSerial.h>     // Incluimos la librería SoftwareSerial

// Se define el Pin 10 - TX, Pin 11 - RX
SoftwareSerial mySerial(10,11);


void setup() {
  // Inicializa la comunicacion serial
  Serial.begin(9600);   // Inicializamos el puerto serie  
  mySerial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  mySerial.write('1');
  Serial.println("LED: on");
  delay(2000);

  mySerial.write('0');
  Serial.println("LED: off");
  delay(2000);
}
