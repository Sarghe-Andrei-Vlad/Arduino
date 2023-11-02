#define p_tip 4
#define p_r1 5
#define p_r2 6
#define p_sleeve 7
 
 
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
 
 
int note[] = {
    NOTE_G5,4,  NOTE_G5,4,
    NOTE_D6,4,  NOTE_D6,4,
    NOTE_E6,4,  NOTE_E6,4, 
    NOTE_D6,8,
    NOTE_C6,4, NOTE_C6,4,
    NOTE_B5,4, NOTE_B5,4,

    NOTE_A5,4, NOTE_A5,4,
    NOTE_G6,8,
    NOTE_D6,4, NOTE_D6,4,
    NOTE_C6,4, NOTE_C6,4,
    NOTE_B5,4, NOTE_B5,4,
    NOTE_A5,8,

    NOTE_D6,4, NOTE_D6,4,
    NOTE_C6,4, NOTE_C6,4,
    NOTE_B5,4, NOTE_B5,4,
    NOTE_A5,8,
    NOTE_G5,4, NOTE_G5,4,
    NOTE_D6,4, NOTE_D6,4,

    NOTE_E6,4, NOTE_E6,6,
    NOTE_D6,8, NOTE_C6,4,
    NOTE_C6,4,
    NOTE_B5,4, NOTE_B5,4,
    NOTE_A5,4, NOTE_A5,4,
    NOTE_G5,8
};
 
void setup() {
  for(int i=4; i<=7; i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
 
    for (int nota_curenta = 0; nota_curenta < 30; nota_curenta++) 
    {
      tone(p_tip, note[nota_curenta*2],100*note[nota_curenta*2+1]); // 3 = pinul cu buzzer-ul, nota, delay
      delay(100*note[nota_curenta*2+1]);
      noTone(p_tip);
    }  
}
 
void loop() {
 
 
}