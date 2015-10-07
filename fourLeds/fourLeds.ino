//Declaração inicial de variáveis
int time = 250;
byte A = 0b11111010;
byte B = 0b11111110;
byte C = 0b01101100;
byte D = 0b01111110;
byte E = 0b11101100;
byte F = 0b11101000;
byte G = 0b11101110;
byte H = 0b11011010;
byte I = 0b00010010;
byte J = 0b00111110;
byte K = 0b11011010;
byte L = 0b01001100;
byte M = 0b01111010;
byte N = 0b01111010;
byte O = 0b01111110;
byte P = 0b11111000;
byte Q = 0b01111110;
byte R = 0b11111010;
byte S = 0b11100110;
byte T = 0b11001100;
byte U = 0b01011110;
byte V = 0b01011110;
byte X = 0b11011010;
byte Y = 0b11010110;
byte Z = 0b10111100;
byte number0 = 0b01111110;
byte number1 = 0b00010010;
byte number2 = 0b10111100;
byte number3 = 0b10110110;
byte number4 = 0b11010010;
byte number5 = 0b11100110;
byte number6 = 0b11101110;
byte number7 = 0b00110010;
byte number8 = 0b11111110;
byte number9 = 0b11110110;
byte vazio = 0b00000000;
byte exclam = 0b10001100;

// Visualização serial
//
// Escreve na serial um byte
void printByte( byte segment ) {
  for ( int i = 0; i < 8; i++ ) {
    Serial.print( getBit( segment, i ) );
  }
  Serial.println();
}


// Operações Binárias 
//
// Inverte a ordem dos bits de um byte
byte invertBits( byte segment ) {
  segment = (segment & 0xF0) >> 4 | (segment & 0x0F) << 4;
  segment = (segment & 0xCC) >> 2 | (segment & 0x33) << 2;
  segment = (segment & 0xAA) >> 1 | (segment & 0x55) << 1;
  return segment;
}

// Pega o bit em uma posição de um byte
bool getBit( byte segment, int position ) {
  return ( segment >> position ) & 0x1;
}

// Seta um bit em uma posição de um byte
byte setBit( byte segment, int position, bool bitValue ) {
  return segment ^= ( -bitValue ^ segment ) & ( 1 << position );
}

// Adiciona ponto de decimal à sequência de segmentos
byte setDot( byte segment ) {
  return setBit( segment, 7, 1 );
}


// Identificação dos dígitos
//
// Pega dígito a dígito de um float
void getDigitsWithDivisor( float number, int& firstDigit, int& secondDigit, int& thirdDigit, int& fourthDigit, float divisor ) {

  firstDigit = floor( number / divisor );
  float auxStep = number - divisor * firstDigit;

  secondDigit = floor( ( 10 * auxStep ) / divisor );
  auxStep -= divisor * secondDigit / 10;

  thirdDigit = floor( ( 100 * auxStep ) / divisor );
  auxStep -= divisor * thirdDigit / 100;

  fourthDigit = floor( ( 1000 * auxStep ) / divisor );
  auxStep -= divisor * fourthDigit / 1000;
}


// Conversões
//
// Converte inteiro para segmentos de LEDs
byte intToByte( int number ) {
  byte segment;
  switch ( number ) {
    case 0:
      segment = invertBits( number0 );
      break;
    case 1:
      segment = invertBits( number1 );
      break;
    case 2:
      segment = invertBits( number2 );
      break;
    case 3:
      segment = invertBits( number3 );
      break;
    case 4:
      segment = invertBits( number4 );
      break;
    case 5:
      segment = invertBits( number5 );
      break;
    case 6:
      segment = invertBits( number6 );
      break;
    case 7:
      segment = invertBits( number7 );
      break;
    case 8:
      segment = invertBits( number8 );
      break;
    case 9:
      segment = invertBits( number9 );
      break;
    default:
      segment = vazio;
      break;
  }
  return segment;
}

// Converte caracter char em valor byte da letra respectiva par o LED de 7 segmentos
byte charToByte( char input ){
  byte segment;
  switch( input ){
    case 'A':
      segment = A;
      break;
    case 'B':
      segment = B;  
      break;
    case 'C':
      segment = C;  
      break;
    case 'D':
      segment = D;  
      break;
    case 'E':
      segment = E;  
      break;
    case 'F':
      segment = F;  
      break;
    case 'G':
      segment = G;  
      break;
    case 'H':
      segment = H;  
      break;
    case 'I':
      segment = I;  
      break;
    case 'J':
      segment = J;  
      break;
    case 'K':
      segment = K;  
      break;
    case 'L':
      segment = L;  
      break;
    case 'M':
      segment = M;  
      break;
    case 'N':
      segment = N;  
      break;
    case 'O':
      segment = O;  
      break;
    case 'P':
      segment = P;  
      break;
    case 'Q':
      segment = Q;  
      break;
    case 'R':
      segment = R;  
      break;
    case 'S':
      segment = S;  
      break;
    case 'T':
      segment = T;  
      break;
    case 'U':
      segment = U;  
      break;
    case 'V':
      segment = V;  
      break;
    case 'X':
      segment = X;  
      break;
    case 'Y':
      segment = Y;  
      break;
    case 'Z':
      segment = Z;
      break; 
    case '1':
      segment = number1;
      break; 
    case '2':
      segment = number2;
      break; 
    case '3':
      segment = number3;
      break;                   
    case '4':
      segment = number4;
      break;             
    case '5':
      segment = number5;
      break;             
    case '6':
      segment = number6;
      break;             
    case '7':
      segment = number7;
      break;             
    case '8':
      segment = number8;
      break;             
    case '9':
      segment = number9;
      break;             
    case '0':
      segment = number0;
      break;             
    default:
      segment = vazio;   
      break;
  }
  return segment;
}


// Escrita na tela e visualização
//
// Escreve o segmento em uma tela
void writeDigitSegment( byte segment, int screen = 1 ) {
  for ( int i = 0; i < 8; i++ )
  {    
    if ( getBit( segment, i ) == 0 )
    {
      digitalWrite( 14 + 8 * screen + i, HIGH);
    }
    else
    {
      digitalWrite( 14 + 8 * screen + i, LOW);
    }
  }
}

// Escreve o dígito inteiro em uma tela
void writeDigit( int number, int screen = 1 ) {

  byte segment = intToByte( number );
  writeDigitSegment( segment, screen );
}

// Escreve quatro inteiros nos displays
void writeFourDigits( int firstDigit, int secondDigit, int thirdDigit, int fourthtDigit, int delayTime = 0 ) {
  writeDigit( firstDigit, 1 );
  writeDigit( secondDigit, 2 );
  writeDigit( thirdDigit, 3 );
  writeDigit( fourthtDigit, 4 );
  delay( delayTime );
}

// Escreve quatro bytes nos displays
void writeFourDigits( byte firstDigit, byte secondDigit, byte thirdDigit, byte fourthtDigit, int delayTime = 0 ) {
  writeDigitSegment( invertBits( firstDigit ), 1 );
  writeDigitSegment( invertBits( secondDigit ), 2 );
  writeDigitSegment( invertBits( thirdDigit ), 3 );
  writeDigitSegment( invertBits( fourthtDigit ), 4 );
  delay( delayTime );  
}

// Imprime um char em quatro displays de LED
// Ainda não possibilita número com ponto
void printText( char input[4] ){
  writeFourDigits( charToByte( input[ 0 ] ), charToByte( input[ 1 ] ), charToByte( input[ 2 ] ), charToByte( input[ 3 ] ) );
}

// Imprime um número real em quatro displays de LED
void printNumber( float number = 1.000 ) {

  float divisor;
  int pointPosition;
  byte auxByte;

  int firstDigit;
  int secondDigit;
  int thirdDigit;
  int fourthDigit;

  if ( number > 9999 ) {
    number = 9999;
    divisor = 1000;
    pointPosition = 4;
    getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );
  }
  else {
    if ( number > 999 ) {
      divisor = 1000;
      pointPosition = 4;
      getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );
    }
    else {
      if ( number > 99 ) {
        divisor = 100;
        pointPosition = 3;
        getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );
      }
      else {
        if ( number > 9 ) {
          divisor = 10;
          pointPosition = 2;
          getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );
        }
        else {
          if ( number > .9 ) {
            divisor = 1;
            pointPosition = 1;
            getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );
          }
          else {
            if ( number > .09 ) {
              divisor = .1;
              pointPosition = 1;
              getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );

              fourthDigit = thirdDigit;
              thirdDigit = secondDigit;
              secondDigit = firstDigit;
              firstDigit = 0;
            }
            else {
              if ( number > .009 ) {
                divisor = .01;
                pointPosition = 1;
                getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );

                fourthDigit = secondDigit;
                thirdDigit = firstDigit;
                secondDigit = 0;
                firstDigit = 0;
              }
              else {
                if ( number > .0009) {
                  divisor = .001;
                  pointPosition = 1;
                  getDigitsWithDivisor( number, firstDigit, secondDigit, thirdDigit, fourthDigit, divisor );

                  fourthDigit = firstDigit;
                  thirdDigit = 0;
                  secondDigit = 0;
                  firstDigit = 0;
                }
              }
            }
          }
        }
      }
    }
  }

  switch ( pointPosition ) {
    case 1:
      auxByte = setDot( intToByte( firstDigit ) );
      writeFourDigits( firstDigit, secondDigit, thirdDigit, fourthDigit );
      writeDigitSegment( auxByte, 1 );
      break;
    case 2:
      auxByte = setDot( intToByte( secondDigit ) );
      writeFourDigits( firstDigit, secondDigit, thirdDigit, fourthDigit );
      writeDigitSegment( auxByte, 2 );
      break;
    case 3:
      auxByte = setDot( intToByte( thirdDigit ) );
      writeFourDigits( firstDigit, secondDigit, thirdDigit, fourthDigit );
      writeDigitSegment( auxByte, 3 );
      break;
    case 4:
      auxByte = setDot( intToByte( fourthDigit ) );
      writeFourDigits( firstDigit, secondDigit, thirdDigit, fourthDigit );
      writeDigitSegment( auxByte, 4 );
      break;
  }
}


// Testes //
//
// Imprime números e textos relacionados à LOST para testar 4 displays LED
void lostNumbers() {
  printNumber( 4 );
  delay( 1000 );
  printNumber( 8 );
  delay( 1000 );
  printNumber( 15 );
  delay( 1000 );
  printNumber( 16 );
  delay( 1000 );
  printNumber( 23 );
  delay( 1000 );
  printNumber( 42 );
  delay( 1000 );
  writeFourDigits( L, O, S, T, 1000 );

  for ( int i = 0; i < 20; i++ ) {
    writeFourDigits( L, O, S, T, 1000 - 50*i );
    writeFourDigits( vazio, vazio, vazio, vazio, 50 );
    if( i == 19 ){
      for( int j = 0; j < 20; j++ ){
        writeFourDigits( L, O, S, T, 50 );
        writeFourDigits( vazio, vazio, vazio, vazio, 50 );
      }
    }
  }
}

// Testa números crescentes varrendo todo o alcance dos displays
void numberTest() {
  float number = .001;
  for ( int i = 0; i <= 1000000; i++ ) {
    number += .001;

    printNumber( number );
    delay(50);
    if ( i == 9999 ) {
      i = 0;
      number = .001;
    }
  }
}

// Teste simples e rápido para os 4 displays LED
void simpleNumberTest(){
  
  float number = .001;
  float increment = .001;
  Serial.println( number );
  printNumber( number );
  
  for( int i = 1; i <= 9; i++ ){
    number += increment;
    delay( 100 );
    printNumber( number );    
    if( i == 9 && number < 9999 ){
      i = 0;
      increment = increment * 10;
      number = increment;
    }
//    if( number > 9999 ){
//      number = .001;
//      increment = .001;
//      Serial.println( number );
//      printNumber( number );
//      delay( 500 );
//    }
  }
}

// Faz um teste utilizando todos os quatro displays
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

// Faz um teste com caracteres
void testNames(){
  int time = 1000;
  printText( "LORE" );
  delay(time);  
  printText( "DANI" );
  delay(time);  
  printText( "JOAO" );
  delay(time);
  printText( "REGI" );
  delay(time);
  printText( "RAPH" );
  delay(time);
  printText( "VICT" );
  delay(time);
  printText( "PAUL" );
  delay(time);
  printText( "LAUR" );
  delay(time);
}

// Preparação das pinagens
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

// Loop de trabalho
void loop() {
  testNames();
}


