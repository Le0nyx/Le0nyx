/*
Warning: This programm gets uploaded and verified automatically over an .c File
It uses Arduino-cli and an Arduino Mega for this to even Work. Also the diffrent components such as
an LCD Screen and an DHT11 are to be bought individually or replaced if needed as long as it works similarly
Pin 9 is set with an LED for Waterbreaks.
Note that the Potenziometer for the LCD Screen contrast should be around 10k Ohms
The diffrent Libraries shall be installed through the arduino IDE library manager
*/

#include <LiquidCrystal.h>
#include <TimeLib.h>
#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7


const int left_button = 18;
const int right_button = 19;

volatile int current_display_mode = 0;
long long timer_time = 0;
unsigned long interrupt_last_pressed = 0;


int lcdnewer;
int bootingseq;

int days;
int years;
int months;

unsigned long hours;
unsigned long minutes;
unsigned long seconds;

unsigned long currentTime = 1722201035;

unsigned long startUnixStamp = 0;


void image1() { 
  //animation stuff

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
  lcd.setCursor(9, 1);
  lcd.write(byte(random(0, 4)));
  lcd.setCursor(10, 1);
  lcd.write(byte(random(0, 4)));
  lcd.setCursor(11, 1);
  lcd.write(byte(random(0, 4)));
  lcd.setCursor(12, 1);
  lcd.write(byte(random(0, 4)));
  lcd.setCursor(13, 1);
  lcd.write(byte(random(0, 4)));
  lcd.setCursor(14, 1);
  lcd.write(byte(random(0, 4)));
  lcd.setCursor(15, 1);
  lcd.write(byte(random(0, 4)));
}


void change_display_mode(){
  if((currentTime - interrupt_last_pressed) > 3){ //debounce the signal
    current_display_mode = (current_display_mode + 1) % 3;
    interrupt_last_pressed = currentTime;
  }
}

void add_five(){
  if((currentTime - interrupt_last_pressed) > 3){ //debounce the signal
    timer_time = timer_time + 300;
    interrupt_last_pressed = currentTime;
  }
}


void setup() {
  pinMode(9, OUTPUT); // LED light for water and if timer is over
  
  attachInterrupt(digitalPinToInterrupt(left_button), add_five, FALLING);
  attachInterrupt(digitalPinToInterrupt(right_button), change_display_mode, FALLING);
  
  lcd.begin(16, 2);

  // Set up the serial communication for debugging
  Serial.begin(9600);
  dht.begin();
 
  lcdnewer = 0;
  bootingseq = 0;

  // timezone and summertime /winter
  currentTime = currentTime + 3600;
  currentTime = currentTime + 3600;

  startUnixStamp = currentTime;
}

void loop() {
  // Calculate the current Unix timestamp
  //randomSeed(currentTime);
  

  seconds = second(currentTime);
  minutes = minute(currentTime);
  hours = hour(currentTime);

  days = day(currentTime);
  months = month(currentTime);
  years = year(currentTime);

  //add watersignal here for every 30 mins
  if((minutes == 0) && seconds == 0){ digitalWrite(9, HIGH); }
  if((minutes == 0) && seconds == 1){ digitalWrite(9, LOW); }
  if((minutes == 0) && seconds == 2){ digitalWrite(9, HIGH); }
  if((minutes == 0) && seconds == 3){ digitalWrite(9, LOW); }


  if(current_display_mode == 0){
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

      if(seconds >= 10){ 
        lcd.print(seconds);

      }else{
        lcd.print("0");
        lcd.print(seconds);
      }

      //temperature and humidity
      lcd.setCursor(0, 1);
      float temperature = dht.readTemperature();
      
      lcd.print(temperature);
      lcd.print("^C ");
      //displaying
      image1();
      lcdnewer = 0;
    }
  }

  if(current_display_mode == 1){
    //prints humidity what day/month/year and uptime of arduino
    float humidity = dht.readHumidity();

    if(lcdnewer == 10){
      lcd.clear();

      if(days < 10){ lcd.print("0"); }
      lcd.print(days);
      lcd.print(":");
      if(months < 10){ lcd.print("0"); }
      lcd.print(months);
      lcd.print(":");
      lcd.print(years);

      lcd.setCursor(0, 1);

      
      if(hour(currentTime - startUnixStamp) < 10){ lcd.print("0"); }
      lcd.print(hour(currentTime - startUnixStamp));
      lcd.print(":");
      if(minute(currentTime - startUnixStamp) < 10){ lcd.print("0"); }
      lcd.print(minute(currentTime - startUnixStamp));
      lcd.print(":");
      if(second(currentTime - startUnixStamp) < 10){ lcd.print("0"); }
      lcd.print(second(currentTime - startUnixStamp));

      lcd.print("  ");

      lcd.print(humidity);
      lcd.print("%");


      if(hours < 19 && hours > 8){ //put here to make the sun
        lcd.setCursor(15, 0);
        lcd.write(byte(4));
        
      } else{ //put here that makes the moon
        lcd.setCursor(15, 0);
        lcd.write(byte(5));
      }


      lcdnewer = 0;
    }
  }


  if(current_display_mode == 2){
    if(minute(timer_time) < 1 && second(timer_time) < 10 && second(timer_time) > 0 ){
      if (second(timer_time) % 2 == 0) { digitalWrite(9, LOW); }
      else{ digitalWrite(9, HIGH); }
    }
    if(minute(timer_time) == 0 && second(timer_time) == 0){ digitalWrite(9, LOW); }

    if(lcdnewer == 10){
      lcd.clear();

      lcd.print("Timer: ");
      lcd.setCursor(0, 1);


      if(hour(timer_time) < 10){ lcd.print("0"); }
      lcd.print(hour(timer_time));
      lcd.print(":");
      if(minute(timer_time) < 10){ lcd.print("0"); }
      lcd.print(minute(timer_time));
      lcd.print(":");
      if(second(timer_time) < 10){ lcd.print("0"); }
      lcd.print(second(timer_time));

      image1();

      lcdnewer = 0;
    }
  }




  if(lcdnewer != 10){
    delay(1000);
    currentTime = currentTime + 1; // Increment the time by 1 second
    lcdnewer++;

    if(timer_time <= 0){
      timer_time = 0;
    }else{
      timer_time--;
    }

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





