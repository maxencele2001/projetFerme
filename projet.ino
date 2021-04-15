#define pinPot A0
#define LED D1

unsigned long ms;
unsigned long secondes;
unsigned long minutes;
int dayMax;
int midDay;
int midiMinuit;
int valPot = 0;
bool isMinuit = true;

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


  valPot = analogRead(pinPot);
  int valTrans = map(valPot, 0, 1024, 1, 10);
  //dayMax = 1200 / valTrans;
  dayMax = 600 / 10;
  
  int uneHeure = (dayMax / 24);
  int heure = secondes%dayMax;

  float six = heureDonnee(dayMax,6);
  float sept = heureDonnee(dayMax,7);
  float huit = heureDonnee(dayMax,8);
  float midi = heureDonnee(dayMax,12);
  float dixHuit = heureDonnee(dayMax,18);
  float dixNeuf = heureDonnee(dayMax,19);
  float vingt = heureDonnee(dayMax,20);
  float vingtDemi = heureDonnee(dayMax,20.5);
  float vingtUn = heureDonnee(dayMax,21);
  float vingtTrois = heureDonnee(dayMax,23);
  float minuit = 0;

  if(heure == six){
    // C 6 heures
  }

  if(heure == sept){
    // C midi
  }

  if(heure == huit){
    // C midi
  }

  if(heure == midi){
    // C midi
  }

  if(heure == dixHuit){
    // C midi
  }

  if(heure == dixNeuf){
    // C midi
  }

  if(heure == vingt){
    // C midi
  }

  if(heure == vingtDemi){
    // C midi
  }

  if(heure == vingtUn){
    // C midi
  }
  
  if(heure == vingtTrois){
    // C midi
  }

  if(heure == minuit){
    // C midi
  }
  
  delay(1000);
}







void eglise(){
  Serial.println("DING DONG");
  delay(1000);
}

//BASSE COUR

void pouleOn(){
  Serial.println("pouleOn");
}

void pouleOff(){
  Serial.println("pouleOff");
}

void coqChante(){
  Serial.println("Coq chante");
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

float heureDonnee(float uneHeure, float heure){
  float heureDonnee = uneHeure * heure;
  return heureDonnee;
}
