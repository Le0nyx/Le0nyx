/*
Warning: This programm gets uploaded and verified automatically over an .c File
It uses Arduino-cli and an Arduino Mega for this to even Work. Also the diffrent components such as
an LCD Screen and an DHT11 are to be bought individually or replaced if needed as long as it works similarly
Pin 9 is set with an LED for Waterbreaks.
Note that the Potenziometer for the LCD Screen contrast should be around 10k Ohms
The diffrent Libraries shall be installed through the arduino IDE library manager
*/

#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

int lcdnewer;
int treevar;
int bootingseq;
unsigned long hours;
unsigned long minutes;
unsigned long seconds;
unsigned long currentTime;



void setup() {
  pinMode(9, OUTPUT);
  lcd.begin(16, 2);
  // Set up the serial communication for debugging
  Serial.begin(9600);
  dht.begin();

  unsigned long unixTimestamp = 0;
  Serial.println("Enter Unix timestamp: ");
  while (Serial.available() == 0) {
   // Wait for user input
  }

  String inputString = Serial.readString(); // Read the entire input as a string
  unixTimestamp = inputString.toInt(); // Convert the input string to unsigned long
  Serial.print("Unix timestamp entered: ");
  Serial.println(unixTimestamp);
  Serial.println();

  //this gets me the current time shit
  currentTime = unixTimestamp + (millis() / 1000);
  seconds = currentTime % 60;
  minutes = (currentTime / 60) % 60;
  hours = ((currentTime / 3600) + 2) % 24;
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.print(seconds);
  Serial.println();

  lcdnewer = 0;
  treevar = 1;
  bootingseq = 0;
}

void loop() {

/*
  digitalWrite(9, HIGH); //testing the led
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);
*/

  //add watersignal here for every 30 mins
  if((minutes == 30 || minutes == 0) && seconds == 0){
    digitalWrite(9, HIGH);
  }

  if((minutes == 30 || minutes == 0) && seconds == 1){
    digitalWrite(9, LOW);
  }

  if((minutes == 30 || minutes == 0) && seconds == 2){
    digitalWrite(9, HIGH);
  }

  if((minutes == 30 || minutes == 0) && seconds == 3){
    digitalWrite(9, LOW);
  }

  // Calculate the current Unix timestamp
  currentTime = currentTime + 1; // Increment the time by 1 second
  seconds = currentTime % 60; // Calculate the updated seconds
  minutes = (currentTime / 60) % 60; // Calculate the updated minutes
  hours = ((currentTime / 3600) + 2) % 24; // Calculate the updated hours

  // Reset the time to 00:00:00 if it reaches 24:00:00
  if (hours >= 24) {
    hours = 0;
    minutes = 0;
    seconds = 0;
    currentTime = 0;
  }

  // Display the time
/* Testing in the terminal monitor
  if (hours < 10) {
    Serial.print('0');
  }
  Serial.print(hours);
  Serial.print(':');

  if (minutes < 10) {
    Serial.print('0');
  }
  Serial.print(minutes);
  Serial.print(':');

  if (seconds < 10) {
    Serial.print('0');
  }
  Serial.println(seconds);
*/
  // Delay for 1 second before updating the time

  //prints the time
  if(lcdnewer == 10){
    lcd.clear();

    if(hours < 10){
      lcd.print("0");
    }
    lcd.print(hours);
    lcd.print(":");

    if(minutes < 10){
      lcd.print("0");
    }
    lcd.print(minutes);
    lcd.print(":");

    if(seconds > 10){ 
      lcd.print(seconds);

    }else{
      lcd.print("0");
      lcd.print(seconds);
    }


    //temperature and humidity
    lcd.setCursor(0, 1);
    float temperature = dht.readTemperature();
    //float humidity = dht.readHumidity();
    lcd.print(temperature);
    lcd.print("^C ");
    //lcd.print(humidity);
    //lcd.print("%");

    //displaying
    image1();
    lcdnewer = lcdnewer -10;
    //Serial.print("reached");
  }

  if(lcdnewer != 10){
    //Serial.print(lcdnewer);
    delay(1000);
    lcdnewer++;
  }

//make the booting animation
  if(bootingseq == 0){ //only gets done once
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lcdnewer*10);
    lcd.print("% - 100%");
    lcd.setCursor(0, 1);
    lcd.print("I");

    for(int i = 0;i<lcdnewer;i++){
      lcd.print("#");
    }

    lcd.setCursor(11, 1);
    lcd.print("I");

    if(lcdnewer==9){
      bootingseq = 1;
    }
  }

} //end of void loop




void image1(){ //animation stuff

  //creating sun and moon
  byte image16[8] = {B01110, B11111, B11111, B11101, B01110, B00000, B00000, B00000};
  byte image15[8] = {B00110, B00011, B00011, B00111, B11111, B01110, B00000, B00000};

  lcd.createChar(4, image16); //sun
  lcd.createChar(5, image15); //moon

  if(hours < 19 && hours > 8){ //put here to make the sun
    lcd.setCursor(15, 0);
    lcd.write(byte(4));

  } else{ //put here that makes the moon
    lcd.setCursor(15, 0);
    lcd.write(byte(5));
  }

  //create forest variations
  byte image32[8] = {B00000, B00100, B01110, B00100, B01110, B11111, B00100, B11111}; //spruce
  byte image31[8] = {B00000, B00000, B01110, B11111, B11111, B00100, B00100, B11111}; //oak
  byte image30[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B01001, B11111}; //grass1
  byte image29[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B01010, B11111}; //grass2

  lcd.createChar(0, image32); //spruce
  lcd.createChar(1, image31); //oak
  lcd.createChar(2, image30); //grass1
  lcd.createChar(3, image29); //grass2

  //treevar combinations 9-15 can be used
  if(treevar==1){
    lcd.setCursor(9, 1);
    lcd.write(byte(2));
    lcd.setCursor(10, 1);
    lcd.write(byte(3));
    lcd.setCursor(11, 1);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(0));
    lcd.setCursor(13, 1);
    lcd.write(byte(2));
    lcd.setCursor(14, 1);
    lcd.write(byte(3));
    lcd.setCursor(15, 1);
    lcd.write(byte(2));
  }

  if(treevar==2){
    lcd.setCursor(9, 1);
    lcd.write(byte(3));
    lcd.setCursor(10, 1);
    lcd.write(byte(0));
    lcd.setCursor(11, 1);
    lcd.write(byte(1));
    lcd.setCursor(12, 1);
    lcd.write(byte(1));
    lcd.setCursor(13, 1);
    lcd.write(byte(0));
    lcd.setCursor(14, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 1);
    lcd.write(byte(1));
  }

  if(treevar==3){
    lcd.setCursor(9, 1);
    lcd.write(byte(0));
    lcd.setCursor(10, 1);
    lcd.write(byte(1));
    lcd.setCursor(11, 1);
    lcd.write(byte(2));
    lcd.setCursor(12, 1);
    lcd.write(byte(0));
    lcd.setCursor(13, 1);
    lcd.write(byte(0));
    lcd.setCursor(14, 1);
    lcd.write(byte(3));
    lcd.setCursor(15, 1);
    lcd.write(byte(1));
  }

  if(treevar==4){
    lcd.setCursor(9, 1);
    lcd.write(byte(2));
    lcd.setCursor(10, 1);
    lcd.write(byte(1));
    lcd.setCursor(11, 1);
    lcd.write(byte(3));
    lcd.setCursor(12, 1);
    lcd.write(byte(2));
    lcd.setCursor(13, 1);
    lcd.write(byte(0));
    lcd.setCursor(14, 1);
    lcd.write(byte(2));
    lcd.setCursor(15, 1);
    lcd.write(byte(3));

    treevar = treevar-4;
  }
  treevar++;
}

