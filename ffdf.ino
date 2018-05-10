
int pirPin = 13; // PIR pin
int ledPin = 12;   // LED pin
int deger = 0;   


int buzzer = 11;
int smokeA0 = A1;
String data;
int role1 = 10;
int role2 = 8;
int role3 = 7;
int role4 = 6;
int role5=  5;
int role6 = 4;
int role7 = 3;
int role8 = 2;

int sensorThres = 400;
void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
 
pinMode(ledPin,OUTPUT);

 pinMode(role1,OUTPUT);
 pinMode(role2,OUTPUT);
 pinMode(role3,OUTPUT);
 pinMode(role4,OUTPUT);
 pinMode(role5,OUTPUT);
 pinMode(role6,OUTPUT);
 pinMode(role7,OUTPUT);
 pinMode(role8,OUTPUT);
 digitalWrite(role1,HIGH);
 digitalWrite(role2,HIGH);
 digitalWrite(role3,HIGH);
 digitalWrite(role4,HIGH);
 digitalWrite(role5,HIGH);
 digitalWrite(role6,HIGH);
 digitalWrite(role7,HIGH);
 digitalWrite(role8,HIGH);
 Serial.begin(9600);
}

void loop() {

  
 
int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres) 
  {
  
    tone(buzzer, 1000, 200);
  }
  else
  {
   
    noTone(buzzer);
  }
    

deger = digitalRead(pirPin);  // Dijital pin okunuyor
  Serial.println(deger);          // Okunan değer seri porttan okunuyor.
  if (deger == HIGH) {            
    digitalWrite(ledPin, HIGH); // Eğer okunan değer 1 ise LED yakılıyor.
  }
  else{
    digitalWrite(ledPin,LOW);   // Eğer okunan değer 0 ise LED söndürülüyor.
  }

    



  
    while(Serial.available())
    {
    delay(10);
    data += char(Serial.read());
    }
    if(data.length() >0) {
    Serial.println(data);

    if(data == "oneopen")  {digitalWrite(role1,LOW);}
    if(data == "oneclose") {digitalWrite(role1,HIGH);}
    
    if(data == "twoopen")  {digitalWrite(role2,LOW);}
    if(data == "twoclose") {digitalWrite(role2,HIGH);}
    
    if(data == "threeopen")  {digitalWrite(role3,LOW);}
    if(data == "threeclose") {digitalWrite(role3,HIGH);}
    
    if(data == "fouropen")  {digitalWrite(role4,LOW);}
    if(data == "fourclose") {digitalWrite(role4,HIGH);}
    
    if(data == "fiveopen")  {digitalWrite(role5,LOW);}
    if(data == "fiveclose") {digitalWrite(role5,HIGH);}
    
    if(data == "sixopen")  {digitalWrite(role6,LOW);}
    if(data == "sixclose") {digitalWrite(role6,HIGH);}
    
    if(data == "sevenopen")  {digitalWrite(role7,LOW);}
    if(data == "sevenclose") {digitalWrite(role7,HIGH);}
    
    if(data == "eightopen")  {digitalWrite(role8,LOW);}
    if(data == "eightclose") {digitalWrite(role8,HIGH);}

    if(data=="fullopen"){digitalWrite(role1,LOW);digitalWrite(role2,LOW);digitalWrite(role3,LOW);digitalWrite(role4,LOW);}
    if(data=="fullclose"){digitalWrite(role1,HIGH);digitalWrite(role2,HIGH);digitalWrite(role3,HIGH);digitalWrite(role4,HIGH);}

if(data=="fullopen1"){digitalWrite(role1,HIGH);digitalWrite(role2,HIGH);digitalWrite(role3,HIGH);digitalWrite(role4,HIGH);digitalWrite(role6,LOW);digitalWrite(role7,LOW);}
    if(data=="fullclose1"){digitalWrite(role1,LOW);digitalWrite(role2,LOW);digitalWrite(role3,LOW);digitalWrite(role4,LOW);digitalWrite(role6,HIGH);digitalWrite(role7,HIGH);}
   }
   data = "";
}
