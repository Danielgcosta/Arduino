byte names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};  
int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};

void setup() {
  int buzzer=20;
  pinMode(buzzer,OUTPUT);
}

int time = 500;
void loop() {
  tone(20,200,time);
  delay(time+100);
}
