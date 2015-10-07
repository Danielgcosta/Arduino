// declaração de variáveis

int digito1[] = {50, 51, 52, 53, 22, 23, 24, 25};
int digito2[] = {46, 47, 48, 49, 26, 27, 28, 29};
int digito3[] = {42, 43, 44, 45, 30, 31, 32, 33};
int digito4[] = {38, 39, 40, 41, 34, 35, 36, 37};

// Buzzer
#define buzzer 18

// Testando RF
#define data 19
#define dataLed 20
#define receiver 20
#define potenciometer A0

// padrões e limites
#define defaultTime 250
#define rfInfLimit 200
#define rfSupLimit 800

// Notas Musicais
#define  C0 16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define LA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define LA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define LA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define LA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define LA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03

#define BPM 100
#define NoteTimeQ 60000/BPM
#define NoteTimeW 4*NoteTimeQ
#define NoteTimeH 2*NoteTimeQ
#define NoteTimeE NoteTimeQ/2
#define NoteTimeS NoteTimeQ/4


#define A 0b11111010
#define B 0b11111110
#define C 0b01101100
#define D 0b01111110
#define E 0b11101100
#define F 0b11101000
#define G 0b11101110
#define H 0b11011010
#define I 0b00010010
#define J 0b00111110
#define K 0b11011010
#define L 0b01001100
#define M 0b01111010
#define N 0b01111010
#define O 0b01111110
#define P 0b11111000
#define Q 0b01111110
#define R 0b11111010
#define S 0b11100110
#define T 0b11001100
#define U 0b01011110
#define V 0b01011110
#define X 0b11011010
#define Y 0b11010110
#define Z 0b10111100
#define number0 0b01111110
#define number1 0b00010010
#define number2 0b10111100
#define number3 0b10110110
#define number4 0b11010010
#define number5 0b11100110
#define number6 0b11101110
#define number7 0b00110010
#define number8 0b11111110
#define number9 0b11110110
#define vazio 0b00000000
#define exclam 0b10001100

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
byte charToByte( char input ) {
  byte segment;
  switch ( input ) {
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

  switch ( screen ) {
    case 1:
      for ( int i = 0; i < 8; i++ )
      {
        if ( getBit( segment, i ) == 0 )
        {
          digitalWrite( digito1[i], HIGH);
        }
        else {
          digitalWrite( digito1[i], LOW);
        }
      }
      break;
    case 2:
      for ( int i = 0; i < 8; i++ )
      {
        if ( getBit( segment, i ) == 0 )
        {
          digitalWrite( digito2[i], HIGH);
        }
        else {
          digitalWrite( digito2[i], LOW);
        }
      }
      break;
    case 3:
      for ( int i = 0; i < 8; i++ )
      {
        if ( getBit( segment, i ) == 0 )
        {
          digitalWrite( digito3[i], HIGH);
        }
        else {
          digitalWrite( digito3[i], LOW);
        }
      }
      break;
    case 4:
      for ( int i = 0; i < 8; i++ )
      {
        if ( getBit( segment, i ) == 0 )
        {
          digitalWrite( digito4[i], HIGH);
        }
        else {
          digitalWrite( digito4[i], LOW);
        }
      }
      break;
  }
}

// Escreve o dígito inteiro em uma tela
void writeDigit( int number, int screen = 1 ) {

  byte segment = intToByte( number );
  writeDigitSegment( segment, screen );
}

// Escreve quatro inteiros nos displays
void writeFourDigits( int firstDigit, int secondDigit, int thirdDigit, int fourthtDigit, int delaydefaultTime = 0 ) {
  writeDigit( firstDigit, 1 );
  writeDigit( secondDigit, 2 );
  writeDigit( thirdDigit, 3 );
  writeDigit( fourthtDigit, 4 );
  delay( delaydefaultTime );
}

// Escreve quatro bytes nos displays
void writeFourDigits( byte firstDigit, byte secondDigit, byte thirdDigit, byte fourthtDigit, int delaydefaultTime = 0 ) {
  writeDigitSegment( invertBits( firstDigit ), 1 );
  writeDigitSegment( invertBits( secondDigit ), 2 );
  writeDigitSegment( invertBits( thirdDigit ), 3 );
  writeDigitSegment( invertBits( fourthtDigit ), 4 );
  delay( delaydefaultTime );
}

// Imprime um char em quatro displays de LED
// Ainda não possibilita número com ponto
void printText( char input[4], int delaydefaultTime = 0 ) {
  writeFourDigits( charToByte( input[ 0 ] ), charToByte( input[ 1 ] ), charToByte( input[ 2 ] ), charToByte( input[ 3 ] ) );
  delay( delaydefaultTime );
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

// Imprime um texto contínuo em quatro displays de LED
void printScrollText( char input[], int delaySpeed = defaultTime ){
int textLength = sizeof( input )*sizeof( char );

int emptyCounter = 0;
int i = 3;

 while( emptyCounter < 4 ){     

    writeFourDigits( charToByte( input[i-3] ), charToByte( input[i-2] ), charToByte( input[i-1] ), charToByte( input[i] ), delaySpeed ); 
    i++;
    
    if( input[ i ] == ' ' ){
      emptyCounter++;
    }
    else {
      emptyCounter = 0;
    }

    Serial.print( "i = " );
    Serial.print( i );
    Serial.print( " / input[" );
    Serial.print( i );
    Serial.print( "] = ");
    Serial.println( input[ i ] );    
  }
}


// Testes //
//
// Imprime números e textos relacionados à LOST para testar 4 displays LED
void lostNumbers() {
  printText( "  4 " );
  delay( 1000 );
  printText( "  8 " );
  delay( 1000 );
  printText( " 15 " );
  delay( 1000 );
  printText( " 16 " );
  delay( 1000 );
  printText( " 23 " );
  delay( 1000 );
  printText( " 42 " );
  delay( 1000 );
  printText( "LOST", 250 );

  for ( int i = 0; i < 20; i++ ) {
    printText( "LOST", 250 - 5 * i );
    printText( "    ", 50 );
    if ( i == 19 ) {
      for ( int j = 0; j < 20; j++ ) {
        printText( "LOST", 50 );
        printText( "    ", 50 );
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

void numberTest2() {
  for (int i = 0; i <= 9; i++ ) {
    writeFourDigits(i, i, i, i, 1000);
  }
}

// Teste simples e rápido para os 4 displays LED
void simpleNumberTest() {

  float number = .001;
  float increment = .001;
  Serial.println( number );
  printNumber( number );

  for ( int i = 1; i <= 9; i++ ) {
    number += increment;
    delay( 100 );
    printNumber( number );
    if ( i == 9 && number < 9999 ) {
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
  delay(defaultTime);

  writeDigitSegment( number2, 1 );
  writeDigitSegment( number3, 2 );
  writeDigitSegment( number4, 3 );
  writeDigitSegment( number5, 4 );
  delay(defaultTime);

  writeDigitSegment( number3, 1 );
  writeDigitSegment( number4, 2 );
  writeDigitSegment( number5, 3 );
  writeDigitSegment( number6, 4 );
  delay(defaultTime);

  writeDigitSegment( number4, 1 );
  writeDigitSegment( number5, 2 );
  writeDigitSegment( number6, 3 );
  writeDigitSegment( number7, 4 );
  delay(defaultTime);

  writeDigitSegment( number5, 1 );
  writeDigitSegment( number6, 2 );
  writeDigitSegment( number7, 3 );
  writeDigitSegment( number8, 4 );
  delay(defaultTime);

  writeDigitSegment( number6, 1 );
  writeDigitSegment( number7, 2 );
  writeDigitSegment( number8, 3 );
  writeDigitSegment( number9, 4 );
  delay(defaultTime);

  writeDigitSegment( number7, 1 );
  writeDigitSegment( number8, 2 );
  writeDigitSegment( number9, 3 );
  writeDigitSegment( number0, 4 );
  delay(defaultTime);

  writeDigitSegment( number8, 1 );
  writeDigitSegment( number9, 2 );
  writeDigitSegment( number0, 3 );
  writeDigitSegment( number1, 4 );
  delay(defaultTime);

  writeDigitSegment( number9, 1 );
  writeDigitSegment( number0, 2 );
  writeDigitSegment( number1, 3 );
  writeDigitSegment( number2, 4 );
  delay(defaultTime);

  writeDigitSegment( number0, 1 );
  writeDigitSegment( number1, 2 );
  writeDigitSegment( number2, 3 );
  writeDigitSegment( number3, 4 );
  delay(defaultTime);
}

// Faz um teste com caracteres
void testNames() {
  printText( "LORE" );
  delay(defaultTime);
  printText( "DANI" );
  delay(defaultTime);
  printText( "JOAO" );
  delay(defaultTime);
  printText( "REGI" );
  delay(defaultTime);
  printText( "RAPH" );
  delay(defaultTime);
  printText( "VICT" );
  delay(defaultTime);
  printText( "PAUL" );
  delay(defaultTime);
  printText( "LAUR" );
  delay(defaultTime);
}

void displayHiDaniel() {
  printText( "    " );
  delay(defaultTime);
  printText( "   H" );
  delay(defaultTime);
  printText( "  HI" );
  delay(defaultTime);
  printText( " HI " );
  delay(defaultTime);
  printText( "HI  D" );
  delay(defaultTime);
  printText( "I DA" );
  delay(defaultTime);
  printText( " DAN" );
  delay(defaultTime);
  printText( "DANI" );
  delay(defaultTime);
  printText( "ANIE" );
  delay(defaultTime);
  printText( "NIEL" );
  delay(defaultTime);
  printText( "IEL " );
  delay(defaultTime);
  printText( "EL L" );
  delay(defaultTime);
  printText( "L LO" );
  delay(defaultTime);
  printText( " LOR" );
  delay(defaultTime);
  printText( "LORE" );
  delay(defaultTime);
  printText( "OREN" );
  delay(defaultTime);
  printText( "RENA" );
  delay(defaultTime);
  printText( "ENA " );
  delay(defaultTime);
  printText( "NA A" );
  delay(defaultTime);
  printText( "E AN" );
  delay(defaultTime);
  printText( " AND" );
  delay(defaultTime);
  printText( "AND " );
  delay(defaultTime);
  printText( "ND L" );
  delay(defaultTime);
  printText( "D LA" );
  delay(defaultTime);
  printText( " LAU" );
  delay(defaultTime);
  printText( "LAUR" );
  delay(defaultTime);
  printText( "AURA" );
  delay(defaultTime);
  printText( "URA " );
  delay(defaultTime);
  printText( "RA  " );
  delay(defaultTime);
  printText( "A   " );
  delay(defaultTime);
  printText( "    " );
}

void displayNiceToMeetYou() {
  printText( "    " );
  delay(defaultTime);
  printText( "   N" );
  delay(defaultTime);
  printText( "  NI" );
  delay(defaultTime);
  printText( " NIC" );
  delay(defaultTime);
  printText( "NICE" );
  delay(defaultTime);
  printText( "ICE " );
  delay(defaultTime);
  printText( "CE T" );
  delay(defaultTime);
  printText( "E TO" );
  delay(defaultTime);
  printText( " TO " );
  delay(defaultTime);
  printText( "TO M" );
  delay(defaultTime);
  printText( "O ME" );
  delay(defaultTime);
  printText( " MEE" );
  delay(defaultTime);
  printText( "MEET" );
  delay(defaultTime);
  printText( "EET " );
  delay(defaultTime);
  printText( "ET Y" );
  delay(defaultTime);
  printText( "T YO" );
  delay(defaultTime);
  printText( " YOU" );
  delay(defaultTime);
  printText( "YOU " );
  delay(defaultTime);
  printText( "OU  " );
  delay(defaultTime);
  printText( "U   " );
  delay(defaultTime);
  printText( "    " );
  delay(defaultTime);
}


// Buzzer
//
// Barulho de coração
void playHeartbeat(){
  tone( buzzer, 800, 150 );
  delay( 300 );
  tone( buzzer, 800, 180 );
}

// Star Wars Imperial March
void playImperialMarch(){
//tone(pin, note, duration)
    tone(buzzer,LA3,NoteTimeQ); 
    delay(1+NoteTimeQ);
    tone(buzzer,LA3,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,LA3,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,F3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,LA3,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,F3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,LA3,NoteTimeH);
    delay(1+NoteTimeH);
    
    tone(buzzer,E4,NoteTimeQ); 
    delay(1+NoteTimeQ); 
    tone(buzzer,E4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,E4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,F4,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,Ab3,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,F3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,LA3,NoteTimeH);
    delay(1+NoteTimeH);
    
    tone(buzzer,LA4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,LA3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,LA3,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,LA4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,Ab4,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,G4,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,Gb4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,E4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,F4,NoteTimeE);
    delay(1+NoteTimeE);
    delay(1+NoteTimeE);//PAUSE
    tone(buzzer,Bb3,NoteTimeE);
    delay(1+NoteTimeE);
    tone(buzzer,Eb4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,D4,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,Db4,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,B3,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,C4,NoteTimeE);
    delay(1+NoteTimeE);
    delay(1+NoteTimeE);
    tone(buzzer,F3,NoteTimeE);
    delay(1+NoteTimeE);
    tone(buzzer,Ab3,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,F3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,LA3,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,C4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,LA3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,E4,NoteTimeH);
    delay(1+NoteTimeH);
    
    tone(buzzer,LA4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,LA3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,LA3,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,LA4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,Ab4,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,G4,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,Gb4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,E4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,F4,NoteTimeE);
    delay(1+NoteTimeE);
    delay(1+NoteTimeE);//PAUSE
    tone(buzzer,Bb3,NoteTimeE);
    delay(1+NoteTimeE);
    tone(buzzer,Eb4,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,D4,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,Db4,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,B3,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,C4,NoteTimeE);
    delay(1+NoteTimeE);
    delay(1+NoteTimeE);
    tone(buzzer,F3,NoteTimeE);
    delay(1+NoteTimeE);
    tone(buzzer,Ab3,NoteTimeQ);
    delay(1+NoteTimeQ);
    tone(buzzer,F3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    
    tone(buzzer,LA3,NoteTimeQ);
    delay(1+NoteTimeQ);
     tone(buzzer,F3,NoteTimeE+NoteTimeS);
    delay(1+NoteTimeE+NoteTimeS);
    tone(buzzer,C4,NoteTimeS);
    delay(1+NoteTimeS);
    tone(buzzer,LA3,NoteTimeH);
    delay(1+NoteTimeH);
    
    delay(2*NoteTimeH);
}

// Pokémon battle
void playPokemonBattle(){
  
}

// RF
//
// Primeira tentativa de trabalhar com RF
void rfTrial() {
    unsigned int receivedData = 0;
 
  for( int j = 0; j < 10000; j++ ) {
    digitalWrite( data, HIGH );
    Serial.print( "HIGH: " );
    receivedData = analogRead( receiver );
    Serial.print( receivedData );
    if( receivedData > rfSupLimit ){
      digitalWrite( data, HIGH );
    }
    else{
      if( receivedData < rfInfLimit ){
        digitalWrite( data, LOW );
      }
    }    
    delay( 500 );
    
    digitalWrite( data, LOW );
    Serial.print( " / LOW: " );    
    receivedData = analogRead( receiver );
    Serial.println( receivedData );
    if( receivedData > rfSupLimit ){
      digitalWrite( data, HIGH );
    }
    else{
      if( receivedData < rfInfLimit ){
        digitalWrite( data, LOW );
      }
    } 
    delay( 500 );
  }
}


// Potenciometer() 
void voltmeter() {
  
float sum = 0;
const int limit = 50;
  for( int i = 0; i < limit ; i++ ){
    tone( buzzer, 800, 10 );

    float voltage = analogRead( potenciometer )* ( 5.0 / 1023.0 );
    sum += voltage;
    
    Serial.print( voltage );
    Serial.println( "V" );
    
    delay( 10 );
  }
  printNumber( sum / limit );
}


// Tarefas principais
//
// Preparação das pinagens
void setup() {
  for ( int i = 0; i < 8; i++ ) {
    pinMode( digito1[i], OUTPUT );
    pinMode( digito2[i], OUTPUT );
    pinMode( digito3[i], OUTPUT );
    pinMode( digito4[i], OUTPUT );
  }

  pinMode( receiver, INPUT );
  pinMode( data, OUTPUT );
  pinMode( dataLed, OUTPUT );
  pinMode( buzzer, OUTPUT );

  Serial.begin(9600);
  Serial.println("Daniel's Arduino is on the run!\n");

   for( int i = 100; i < 3000; i++ ){
    tone( buzzer, i, 1 );
    delayMicroseconds( 1 );
    noTone( buzzer );
  }
}

// Loop de trabalho
void loop() {
  printScrollText( "    BOM DIA    " ); 
  printScrollText( "    SEMPRE ALERTA ESCOTEIRO    " ); 
  Serial.println( "Cycle"); 
  delay( 1000 );
  printScrollText( "    VAMOS OUVIR UMA MUSICA    " ); 
  playImperialMarch();
  printScrollText( "    VOCE GOSTA DE LOST    " ); 
  lostNumbers();
}
