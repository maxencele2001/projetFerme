#define pinPot A0
#define LED D1

unsigned long ms;
unsigned long secondes;
unsigned long minutes;
int dayMax;
int midDay;
int test;
int valPot = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

}

void loop() {
  ms = millis();
  secondes = ms/1000;
  minutes = secondes/60;
  Serial.println(secondes);
  Serial.println(minutes);


  valPot = analogRead(pinPot);
  int valTrans = map(valPot, 0, 1024, 1, 10);
  dayMax = 600 / valTrans;
  Serial.println(dayMax);
  midDay = dayMax/2;
  test = secondes%midDay;
  Serial.println("Valeur modulo : ");
  Serial.println(test);
  

  if(test == 0){
    digitalWrite(LED, LOW);
    delay(1000);
    digitalWrite(LED, HIGH);
  }

  

  
  delay(1000);
}


//BASSE COUR

void animPoule(){
  
}

void coqChante(){
  
}

void vacheMeugle(){
  
}


//FERME

void ferme(){
  
}

void fumee(){
  
}

//BARBECUE

void barbecue(){
  
}
