#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h" 
#include <SPI.h>
#include "SdFat.h"
#include <string.h>
#include <stdio.h>

 
#define chipSelect 10 // pinul la care este conectat cardul (xx = 4 pe shieldul Ethernet, xx = 10 pentru ecrane)
 
File myFile;

SdFat sd;

MCUFRIEND_kbv tft(A3, A2, A1, A0, A4); 


void takeCoordinates(char linie[])
{
  int lx1,lx2,ly1,ly2;
  int cx,cy,cr;
  lx1=0;
  lx2=0;
  ly1=0;
  ly2=0;
  cx=0;
  cy=0;
  cr=0;
  int i = 0;
  if (linie[i] == 'l'){
    const char s[2] = " ";
    char* token;
    int counter=0;
  // get the first token /
    token = strtok(linie, s);

   // walk through other tokens */
   while( token != NULL ) {
      if(counter == 1){
        lx1 = atoi(token);
        Serial.println(lx1);
      }
      if(counter == 2){
        ly1 = atoi(token);
        Serial.println(ly1);
      }
      if(counter == 3){
        lx2 = atoi(token);
        Serial.println(lx2);
      }
      if(counter == 4){
        ly2 = atoi(token);
        Serial.println(ly2);
      }
      token = strtok(NULL, s);
      counter++;
      }
    tft.drawLine(lx1, ly1, lx2, ly2, 0x0000);
    i=0;
  }
  if (linie[i] == 'c'){
    const char s[2] = " ";
    char* token;
    int counter=0;
  // get the first token /
    token = strtok(linie, s);

   // walk through other tokens */
   while( token != NULL ) {
      if(counter == 1){
        cx = atoi(token);
      }
      if(counter == 2){
        cy = atoi(token);
      }
      if(counter == 3){
        cr = atoi(token);
      }
      token = strtok(NULL, s);
      counter++;
      }
    tft.drawCircle(cx, cy, cr, 0x0000);
  }
}


void setup() {
  Serial.begin(9600);
  while (!Serial);  
  delay(1000);
 
  // Pornim cardul; daca nu merge, se pot folosi viteze mai mici de 50Mhz
  if (!sd.begin(chipSelect, SD_SCK_MHZ(50))) {
    sd.initErrorHalt(); // afiseaza pe portul serial posibilele motive ale erorii
  }
  else 
  {
    Serial.println("Card ready");  
  }

  Serial.println("initialization done.");

  uint16_t ID = tft.readID();
  tft.begin(ID); 
  tft.width(); //int16_t width(void);
  tft.height(); //int16_t height(void); 
  tft.fillScreen(0xFFFF);
  // tft.fillCircle(50, 50, 10, 0x0000);
  // tft.drawLine(150, 150, 200, 200, 0x0000);

  myFile = sd.open("testline3.txt", FILE_WRITE);

  if (myFile) {
      Serial.println("Writing to file...");
      myFile.println("l 10 10 50 50 ");
      myFile.println("c 100 100 25 ");
      Serial.println("Done writing");
      myFile.close();}

  //myFile = sd.open("testline3.txt");

  SdFile myFile("testline3.txt", O_READ);
  if (myFile) { 
      while (myFile.available()) {
        char line[25];
        int n;
  
  while ((n = myFile.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
      // remove '\n'
      line[n-1] = 0;
      // replace next line with LCD call to display line
      takeCoordinates(line);
    }
  }

        // char line[32];
        // int index = 0;
        // char letter = myFile.read();
        // Serial.println(letter);
        // while (letter!= '\n'){
        //   line[index] = letter;
        //   index++;
        //   letter = myFile.read();
        // }
        // for(int i=0; i<strlen(line); i++)
        // {Serial.print(line[i]);}
        // line[index] = '\0';
        // takeCoordinates(line);
        // Serial.print(letter); //display character
        // myFile.close(); //close file
    }

  Serial.println("done!");

}
}

void loop() {
}


