using namespace std;
#include <vector>
#define pinPot A0
#define LED D1


unsigned long ms;
unsigned long secondes;
unsigned long minutes;
int valPot = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  vector<float> tabHeures;
  ms = millis();
  secondes = ms/1000;
  minutes = secondes/60;

  valPot = analogRead(pinPot);
  int valTrans = map(valPot, 0, 1024, 1, 10);
  // int dayMaxInt = 1200 / valTrans;
  // float dayMax = 1200 / valTrans;
  int dayMaxInt = 600 / 10;
  float dayMax = 600 / 10;
  
  float uneHeure = dayMax / 24;
  float heure = secondes%dayMaxInt;
  
  

  for(int i = 1; i<=24; i++){
    float heureToTab = uneHeure * i;
    tabHeures.push_back(heureToTab);
  }

  for(int i = 0; i<tabHeures.size(); i++){
    if(heure == tabHeures[i]){
      eglise();
    }
  }

  int six = heureDonnee(uneHeure,6);
  int sept = heureDonnee(uneHeure,7);
  int huit = heureDonnee(uneHeure,8);
  int midi = heureDonnee(uneHeure,12);
  int dixHuit = heureDonnee(uneHeure,18);
  int dixNeuf = heureDonnee(uneHeure,19);
  int vingt = heureDonnee(uneHeure,20);
  int vingtDemi = heureDonnee(uneHeure,20.5);
  int vingtUn = heureDonnee(uneHeure,21);
  int vingtTrois = heureDonnee(uneHeure,23);
  int minuit = heureDonnee(uneHeure,24);

  if(heure == six){
    fermeOn();
  }

  if(heure == sept){
    fumeeOff();
    coqChante();
    pouleOn();
  }

  if(heure == huit){
    fermeOff();
  }

  if(heure == midi){
    coqChante();
  }

  if(heure == dixHuit){
    fumeeOn();
  }

  if(heure == dixNeuf){
    coqChante();
    fermeOn();
  }

  if(heure == vingt){
    pouleOff();
  }

  if(heure == vingtDemi){
    barbecueOn();
  }

  if(heure == vingtUn){
    fermeOff();
  }

  if(heure == vingtTrois){
    barbecueOff();
  }

  if(heure == minuit){
    coqChante();
    vacheMeugle();
  }
  delay(1000);
}





//EGLISE

void eglise(){
  Serial.println("DING DONG");
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
  Serial.println("Vache Meugle");
}


//FERME

void fermeOn(){
  Serial.println("fermeOn");
}

void fermeOff(){
  Serial.println("fermeOff");
}

void fumeeOn(){
  Serial.println("fumeeOn");
}

void fumeeOff(){
  Serial.println("fumeeOff");
}


//BARBECUE

void barbecueOn(){
  Serial.println("barbecueOn");
}

void barbecueOff(){
  Serial.println("barbecueOff");
}

// Utils

int heureDonnee(float uneHeure, float heure){
  int heureDonnee = uneHeure * heure;
  return heureDonnee;
}
