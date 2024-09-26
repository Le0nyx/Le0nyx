// C++ code
//
char msg[8]; //ascii code array 256
char wort; //converted symbol
int ascii = 0;
int transfer_bit[8];

int inputPin = 2;
int outputPin = 8;


void setup(){
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop(){
  send_message();
  recieve_message();
}


void recieve_message(){
  if(digitalRead(inputPin) == HIGH){ //write the symbol with ascii code into the array
    delay(6);
    for(int i = 0; i < 8; i++){
      if(digitalRead(inputPin) == HIGH){
        msg[i] = '1';
      }
      if(digitalRead(inputPin) == LOW){
        msg[i] = '0';
      }
      delay(4);
    }
    char receivedChar = binaryToChar(msg); // convert the binary array to a char
    Serial.print(receivedChar);
    digitalWrite(outputPin, HIGH);
    delay(1);
    digitalWrite(outputPin, LOW);
  }
}


void send_message(){
  if(Serial.available() > 0){
    wort = Serial.read();
	  ascii = int(wort);
    for(int i = 7; i >= 0; i--) {
      transfer_bit[i] = ascii % 2;
      ascii = ascii / 2;
  	}
    digitalWrite(outputPin, HIGH); //start signal
    delay(1);
    digitalWrite(outputPin, LOW);
    for(int i = 0;i<8;i++){ //send the 8 bits for later to be ascii
      delay(4);
      if(transfer_bit[i] == 1){
        digitalWrite(outputPin, HIGH);
      }
      if(transfer_bit[i] == 0){
        digitalWrite(outputPin, LOW);
      }
    }
    delay(2);
    digitalWrite(outputPin, LOW);
    while(digitalRead(inputPin)!= HIGH){ //wait for the receiver to be ready
      delay(1);
    }
    delay(5);
  }
}


char binaryToChar(char binary[]){
  int decimalValue = 0;
  for(int i = 0; i < 8; i++){
    decimalValue += (binary[i] - '0') << (7 - i);  // convert char '0'/'1' to integer 0/1  (<< is a bitshift to the left)
  }
  return char(decimalValue);
}