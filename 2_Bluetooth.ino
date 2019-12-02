//** Conexiones  físicas para CONFIGURAR el BLUETOOTH HC-05 con un Arduino **//
// Poner el modulo en modo AT 2 osea, presionar el boton antes de poner a 5v y se verá el blink lento
// Pin 10 - TX del BT
// Pin 11 - RX del BT
// Para empezar a mandar Comandos AT seleccionar en "Tools/Port" el correcto y abrir "Tools/Serial Monitor"
//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//

#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial

char read_Data = 0;
   
//** Definimos los pines TX y RX del Arduino conectados al Bluetooth */
SoftwareSerial miBT(10,11); //Pin 10 - TX
                            //Pin 11 - RX
void setup()
{
    //** Next line is for BLINK */
  pinMode(LED_BUILTIN, OUTPUT);

    //** Next lines are for BLUETOOTH */
  Serial.begin(9600);   // Inicializamos el puerto serie  
  miBT.begin(38400);    // Inicializamos el puerto serie miBT (Para Modo AT 2 - config)
  Serial.println("Listo");
}
 
void loop()
{
    //** Next line is for BLINK */
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(250);                       // wait for a 250 ms = 1/4 second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(250);                       // wait for a 250 ms = 1/4 second


    //** Next lines are for BLUETOOTH */
  if(miBT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
    {
      read_Data = miBT.read();
      Serial.write(read_Data);   //** Lee miBT y envia a arduino */
    }
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     miBT.write(Serial.read());  //** Lee arduino y envia a miBT */
  }
}//end loop()
