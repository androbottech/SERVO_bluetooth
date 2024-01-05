#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);// TX,RX

Servo s0;
int dato;

void setup() 
{
  s0.attach(5);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() 
{
  if(bluetooth.available())//comunicacion disponible?
  {
    dato = (bluetooth.readString().toInt());//guardar datos y convertir en valor numeros
    Serial.println(dato);//enviar los numeros por MONITOR SERIAL
    s0.write(dato);//encender servo con esos numeros
    delay(10);//esperar 10 ms
  }
}
