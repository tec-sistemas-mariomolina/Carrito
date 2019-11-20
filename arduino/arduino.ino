
 //Encendido y apagado del Led 13 mediante puerto serie.

const byte Led = 10;   // Declaramos la variable pin del Led.

byte nPWM;
String comando="";
//int npwm = 0;
char A;
char caracter;
void setup()
{
  pinMode(Led, OUTPUT);  // Inicializa el pin del LED como salida:
  Serial.begin(115200);     // Puerto serie 115200 baudios.
  analogWrite(Led, 0);
  digitalWrite(Led, HIGH);
  delay(1000);
digitalWrite(Led, LOW);
  delay(1000);
  
}

void loop()
{
  /*
    Voy leyendo carácter a carácter lo que se recibe por el canal serie
    (mientras llegue algún dato allí), y los voy concatenando uno tras otro
    en una cadena. En la práctica, si usamos el "Serial monitor" el bucle while
    acabará cuando pulsamos Enter. El delay es conveniente para no saturar el
    canal serie y que la concatenación se haga de forma ordenada.
  */
  //digitalWrite(Led, HIGH);
  //Serial.print("High");
  //delay(1000);
  //digitalWrite(Led, LOW);
  //delay(1000);
 //Serial.write('A');
 //Serial.flush();
 //);
if(!comando.equals("start")){
 // Serial.println(comando);
  //Serial.println("if");
  while(Serial.available() >0){
    
    caracter= Serial.read();
    if(caracter >= 0 && caracter <= 255 ){
    comando.concat(caracter);
    Serial.println("incilizar");
    Serial.println(comando);
    }
    delay(10);
  } 
}
  if (Serial.available() > 0 && comando.equals("start"))
    {
          //Serial.println("pwm");
      nPWM = Serial.read();
      analogWrite(Led,((int)nPWM));
    //Serial.println(((int)nPWM));
    //Serial.write(nPWM);
    delay(10);
  }//else{
  // Serial.println("Else");
  //  analogWrite(Led, 0);
 // }

  /*
    Una vez ya tengo la cadena "acabada", compruebo su valor y hago que
    la placa Arduino reacciones según sea este. Aquí podríamos hacer lo
    que quisiéramos: si el comando es "tal", enciende un Led, si es cual,
    mueve un motor... y así.
  */

  // Si le llega el mensaje Luz_ON.
  /*if (comando.equals("Luz_ON") == true)
  {
    digitalWrite(Led, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }

  // Si le llega el mensaje Luz_ON.
  if (comando.equals("Luz_OFF") == true)
  {
    digitalWrite(Led, LOW); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }*/

  // Limpiamos la cadena para volver a recibir el siguiente comando.
  //comando = "";
}
