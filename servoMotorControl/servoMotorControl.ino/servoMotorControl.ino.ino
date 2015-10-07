// Faz um teste utilizando todos os quatro displaywriteFourDigitswriteFourDigits
// Controla um servomotor através [porta 13]
void servoMotor() {
  int motor = 13;
  float middle = 1.5;
  float right = 2;
  float left = .9;
  pinMode(motor, OUTPUT);
  float pwmModeTime = middle;

  for ( int i = 0; i < 100000; i++ )
  {
    for ( int j = 0; j < 50; j++ )
    {

      digitalWrite(motor, HIGH);
      delay(pwmModeTime);
      digitalWrite(motor, LOW);
      delay(20 - pwmModeTime);
    }
    if ( pwmModeTime == right )
    {
      pwmModeTime = middle;
    }
    else
    {
      if ( pwmModeTime == middle )
      {
        pwmModeTime = left;
      }
      else
      {
        if ( pwmModeTime == left )
        {
          pwmModeTime = right;
        }
      }
    }
  }
}

// Controla um servomotor através [porta 13]
void servoMotor2() {
  int motor = 13;
  float pwmModeTime = 1;

  pinMode(motor, OUTPUT);

  for ( int k = 0; k < 100000000000000; k++ )
  {
    for ( int j = 0; j < 10000000; j++ )
    {
      pwmModeTime = pwmModeTime + .05;

      digitalWrite( motor, HIGH );
      delay( pwmModeTime );
      digitalWrite( motor, LOW );
      delay( 20 - pwmModeTime );

      if ( pwmModeTime == 2 )
      {
        pwmModeTime = 0.99995;
      }
    }
  }
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
