const byte Led = 10; 
byte nPWM;
String comando="";
//int npwm = 0;
char A;
char caracter;
void setup()
{
  pinMode(Led, OUTPUT);  
  Serial.begin(115200);     
  analogWrite(Led, 0);
  digitalWrite(Led, HIGH);
  delay(1000);
digitalWrite(Led, LOW);
  delay(1000);+
  
}
void loop()
{
if(!comando.equals("start")){
 
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
         
      nPWM = Serial.read();
      analogWrite(Led,((int)nPWM));
    delay(10);
  
}
}
