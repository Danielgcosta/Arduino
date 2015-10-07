int time = 250;
byte A = 11111010; 
byte B = 11111110; 
byte C = 01101100; 
byte D = 01111110; 
byte E = 11101100;
byte F = 11101000;
byte G = 11101110;
byte H = 11011010;
byte I = 00010010;
byte J = 00111110;
byte K = 11011010;
byte L = 01001100;
byte M = 01111010;
byte N = 01111010;
byte O = 01111110;
byte P = 11111000;
byte Q = 01111110;
byte R = 11111010;
byte S = 11100110;
byte T = 11001100;
byte U = 01011110;
byte V = 01011110;
byte X = 11011010;
byte Y = 11010110;
byte Z = 10111100;
byte number0 = 01111110;
byte number1 = 00010010;
byte number2 = 10111100;
byte number3 = 10110110;
byte number4 = 11010010;
byte number5 = 11100110;
byte number6 = 11101110;
byte number7 = 00110010;
byte number8 = 11111110;
byte number9 = 11110110;
byte vazio = 00000000;
byte exclam = 10001100;

bool getBit( byte segment, int position ){
    return ( segment >> position ) & 0x1;
}
// Writes a letter from an array of integer points
void writeDigitSegment( byte segment, int screen = 1 ) {
  for ( int i = 0; i < 8; i++ )
  {
    if ( getBit( segment,i ) == 0)
    {
      digitalWrite( 14 + 8 * screen + i, HIGH);
    }
    else
    {
      digitalWrite( 14 + 8 * screen + i, LOW);
    }
  }
}

byte intToSegment( byte segment, int number ) {
  switch ( number ){
    case 0:
      segment = number0;
      break;
    case 1:
      segment = number1;
      break;
    case 2:
      segment = number2;
      break;
    case 3:
      segment = number3;
      break;
    case 4:
      segment = number4;
      break;
    case 5:
      segment = number5;
      break;
    case 6:
      segment = number6;
      break;
    case 7:
      segment = number7;
      break;
    case 8:
      segment = number8;
      break;
    case 9:
      segment = number9;
      break;
    default:
      segment = vazio;
      break;
  }
  
  
}
void writeDigit( int number, int screen = 1 ){
  //Serial.println( number );
  
  byte segment;  
  intToSegment( segment, number );
  for( int i = 0; i < 8; i++ ){
    //Serial.print( i );
    //Serial.print( "," );
    //Serial.println( segment[i] );    
    }
  
  writeDigitSegment( segment, screen ); 
  //Serial.println( screen ); 
  //Serial.println();
}
void printNumber( float number = 1.250 ){

//  writeDigitSegment( intToSegment( 1 ),
//  Serial.println( number );
//  int firstDigitInteger = int( number );
//  Serial.println( firstDigitInteger );
//
//  int secondDigitInteger = int( ( number - firstDigitInteger ) * 10 );
//  //Serial.println( secondDigitInteger );
//
//  int firstDigitArray[7];
//  detectSingleDigit( firstDigitArray, firstDigitInteger, true );
//  for ( int i = 0; i <= 7; i ++ )
//  {
//    Serial.println( firstDigitArray[i] );
//  }
//  int secondDigitArray[7];
//  detectSingleDigit( secondDigitArray, secondDigitInteger, false );
//  for ( int i = 0; i <= 7; i ++ )
//  {
//    Serial.println( secondDigitArray[i] );
//  }
//  delay(2500);
}
void setup() { //Setup our pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);

  //Dígito 1
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);

  //Dígito 2
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);

  //Dígito 3
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);

  //Dígito 4
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);

  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Daniel's Arduino is on the run!\n");  // prints hello with ending line break
}
void loop() {
  
}
byte setDot( byte segment ) {
  segment ^= 00000001;
  return segment;
}
void fourDisplaysNumberTest() {
  writeDigitSegment( number1, 1 );
  writeDigitSegment( number2, 2 );
  writeDigitSegment( number3, 3 );
  writeDigitSegment( number4, 4 );
  delay(time);

  writeDigitSegment( number2, 1 );
  writeDigitSegment( number3, 2 );
  writeDigitSegment( number4, 3 );
  writeDigitSegment( number5, 4 );
  delay(time);

  writeDigitSegment( number3, 1 );
  writeDigitSegment( number4, 2 );
  writeDigitSegment( number5, 3 );
  writeDigitSegment( number6, 4 );
  delay(time);

  writeDigitSegment( number4, 1 );
  writeDigitSegment( number5, 2 );
  writeDigitSegment( number6, 3 );
  writeDigitSegment( number7, 4 );
  delay(time);

  writeDigitSegment( number5, 1 );
  writeDigitSegment( number6, 2 );
  writeDigitSegment( number7, 3 );
  writeDigitSegment( number8, 4 );
  delay(time);

  writeDigitSegment( number6, 1 );
  writeDigitSegment( number7, 2 );
  writeDigitSegment( number8, 3 );
  writeDigitSegment( number9, 4 );
  delay(time);

  writeDigitSegment( number7, 1 );
  writeDigitSegment( number8, 2 );
  writeDigitSegment( number9, 3 );
  writeDigitSegment( number0, 4 );
  delay(time);

  writeDigitSegment( number8, 1 );
  writeDigitSegment( number9, 2 );
  writeDigitSegment( number0, 3 );
  writeDigitSegment( number1, 4 );
  delay(time);

  writeDigitSegment( number9, 1 );
  writeDigitSegment( number0, 2 );
  writeDigitSegment( number1, 3 );
  writeDigitSegment( number2, 4 );
  delay(time);

  writeDigitSegment( number0, 1 );
  writeDigitSegment( number1, 2 );
  writeDigitSegment( number2, 3 );
  writeDigitSegment( number3, 4 );
  delay(time);
}
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
void writeFourDigits( byte firstDigit, byte secondDigit, byte thirdDigit, byte fourthtDigit ) {
  writeDigitSegment( firstDigit, 1 );
  writeDigitSegment( secondDigit, 2 );
  writeDigitSegment( thirdDigit, 3 );
  writeDigitSegment( fourthtDigit, 4 );
}
void writeFourDigitsWithDelay( byte firstDigit, byte secondDigit, byte thirdDigit, byte fourthtDigit, int time = 200 ) {
  writeDigitSegment( firstDigit, 1 );
  writeDigitSegment( secondDigit, 2 );
  writeDigitSegment( thirdDigit, 3 );
  writeDigitSegment( fourthtDigit, 4 );
  delay(time);
}
void lorenaEuTeAmo() {
  writeFourDigitsWithDelay(vazio, vazio, vazio, vazio);
  writeFourDigitsWithDelay(vazio, vazio, vazio, L);
  writeFourDigitsWithDelay(vazio, vazio, L, setDot(O));
  writeFourDigitsWithDelay(vazio, L, O, R);
  writeFourDigitsWithDelay(L, O, R, E);
  writeFourDigitsWithDelay(O, R, E, N);
  writeFourDigitsWithDelay(R, E, N, A);
  writeFourDigitsWithDelay(E, N, A, vazio);
  writeFourDigitsWithDelay(N, A, vazio, E);
  writeFourDigitsWithDelay(A, vazio, E, U);
  writeFourDigitsWithDelay(vazio, E, U, vazio);
  writeFourDigitsWithDelay(E, U, vazio, T);
  writeFourDigitsWithDelay(U, vazio, T, E);
  writeFourDigitsWithDelay(vazio, T, E, vazio);
  writeFourDigitsWithDelay(T, E, vazio, A);
  writeFourDigitsWithDelay(E, vazio, A, M);
  writeFourDigitsWithDelay(vazio, A, M, setDot(O));
  writeFourDigitsWithDelay(A, M, O, vazio);
  writeFourDigitsWithDelay(M, O, vazio, vazio);
  writeFourDigitsWithDelay(O, vazio, vazio, vazio);
  writeFourDigitsWithDelay(vazio, vazio, vazio, vazio);
}
