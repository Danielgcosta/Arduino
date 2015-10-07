#include <pitches.h>

int buzzerPin = 20;

void setup() {     
pinMode(buzzerPin, OUTPUT);   
}

void loop() {
  //tone(pin, note, duration)
    tone(buzzerPin,LA3,Q); 
    delay(1+Q);
    tone(buzzerPin,LA3,Q);
    delay(1+Q);
    tone(buzzerPin,LA3,Q);
    delay(1+Q);
    tone(buzzerPin,F3,E+S);
    delay(1+E+S);
    tone(buzzerPin,C4,S);
    delay(1+S);
    
    tone(buzzerPin,LA3,Q);
    delay(1+Q);
    tone(buzzerPin,F3,E+S);
    delay(1+E+S);
    tone(buzzerPin,C4,S);
    delay(1+S);
    tone(buzzerPin,LA3,H);
    delay(1+H);
    
    tone(buzzerPin,E4,Q); 
    delay(1+Q); 
    tone(buzzerPin,E4,Q);
    delay(1+Q);
    tone(buzzerPin,E4,Q);
    delay(1+Q);
    tone(buzzerPin,F4,E+S);
    delay(1+E+S);
    tone(buzzerPin,C4,S);
    delay(1+S);
    
    tone(buzzerPin,Ab3,Q);
    delay(1+Q);
    tone(buzzerPin,F3,E+S);
    delay(1+E+S);
    tone(buzzerPin,C4,S);
    delay(1+S);
    tone(buzzerPin,LA3,H);
    delay(1+H);
    
    tone(buzzerPin,LA4,Q);
    delay(1+Q);
    tone(buzzerPin,LA3,E+S);
    delay(1+E+S);
    tone(buzzerPin,LA3,S);
    delay(1+S);
    tone(buzzerPin,LA4,Q);
    delay(1+Q);
    tone(buzzerPin,Ab4,E+S);
    delay(1+E+S);
    tone(buzzerPin,G4,S);
    delay(1+S);
    
    tone(buzzerPin,Gb4,S);
    delay(1+S);
    tone(buzzerPin,E4,S);
    delay(1+S);
    tone(buzzerPin,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(buzzerPin,Bb3,E);
    delay(1+E);
    tone(buzzerPin,Eb4,Q);
    delay(1+Q);
    tone(buzzerPin,D4,E+S);
    delay(1+E+S);
    tone(buzzerPin,Db4,S);
    delay(1+S);
    
    tone(buzzerPin,C4,S);
    delay(1+S);
    tone(buzzerPin,B3,S);
    delay(1+S);
    tone(buzzerPin,C4,E);
    delay(1+E);
    delay(1+E);
    tone(buzzerPin,F3,E);
    delay(1+E);
    tone(buzzerPin,Ab3,Q);
    delay(1+Q);
    tone(buzzerPin,F3,E+S);
    delay(1+E+S);
    tone(buzzerPin,LA3,S);
    delay(1+S);
    
    tone(buzzerPin,C4,Q);
    delay(1+Q);
     tone(buzzerPin,LA3,E+S);
    delay(1+E+S);
    tone(buzzerPin,C4,S);
    delay(1+S);
    tone(buzzerPin,E4,H);
    delay(1+H);
    
     tone(buzzerPin,LA4,Q);
    delay(1+Q);
    tone(buzzerPin,LA3,E+S);
    delay(1+E+S);
    tone(buzzerPin,LA3,S);
    delay(1+S);
    tone(buzzerPin,LA4,Q);
    delay(1+Q);
    tone(buzzerPin,Ab4,E+S);
    delay(1+E+S);
    tone(buzzerPin,G4,S);
    delay(1+S);
    
    tone(buzzerPin,Gb4,S);
    delay(1+S);
    tone(buzzerPin,E4,S);
    delay(1+S);
    tone(buzzerPin,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(buzzerPin,Bb3,E);
    delay(1+E);
    tone(buzzerPin,Eb4,Q);
    delay(1+Q);
    tone(buzzerPin,D4,E+S);
    delay(1+E+S);
    tone(buzzerPin,Db4,S);
    delay(1+S);
    
    tone(buzzerPin,C4,S);
    delay(1+S);
    tone(buzzerPin,B3,S);
    delay(1+S);
    tone(buzzerPin,C4,E);
    delay(1+E);
    delay(1+E);
    tone(buzzerPin,F3,E);
    delay(1+E);
    tone(buzzerPin,Ab3,Q);
    delay(1+Q);
    tone(buzzerPin,F3,E+S);
    delay(1+E+S);
    tone(buzzerPin,C4,S);
    delay(1+S);
    
    tone(buzzerPin,LA3,Q);
    delay(1+Q);
     tone(buzzerPin,F3,E+S);
    delay(1+E+S);
    tone(buzzerPin,C4,S);
    delay(1+S);
    tone(buzzerPin,LA3,H);
    delay(1+H);
    
    delay(2*H);
}
