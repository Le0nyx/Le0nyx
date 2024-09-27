#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

float currentRed = 0;
float currentGreen = 0;
float currentBlue = 0;

int targetRed = 0;
int targetGreen = 0;
int targetBlue = 0;

const int updatesPerSecond = 60;  // Adjust this value for the desired updates per second
const int delayTime = 1000 / updatesPerSecond;  // Delay between updates

void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.println("Arduino ready");
}

void loop() {
  if (Serial.available() >= 3) {
    targetRed = Serial.read();
    targetGreen = Serial.read();
    targetBlue = Serial.read();
  }

  smoothTransition();
  delay(delayTime);  // Adjust delay for desired updates per second
}

void smoothTransition() {
  float easing = 0.045;  // Adjust this value for different easing effects (0 < easing <= 1)
  float threshold = 1.1;  // Only update if the change is larger than this threshold

  float deltaRed = targetRed - currentRed;
  float deltaGreen = targetGreen - currentGreen;
  float deltaBlue = targetBlue - currentBlue;

  if(targetRed < 3 && targetGreen < 3 && targetBlue < 3){ //smooth turning off transition
    for(int i = 0;i<10;i++){
      delay(100);
      currentRed = currentRed * 0.5;
      currentGreen = currentGreen * 0.5;
      currentBlue = currentBlue * 0.5;

      analogWrite(RED_PIN, (int)currentRed);
      analogWrite(GREEN_PIN, (int)currentGreen);
      analogWrite(BLUE_PIN, (int)currentBlue);
    }

    currentRed = 0; 
    currentGreen = 0; 
    currentBlue = 0; 
    }

  if (abs(deltaRed) > threshold) {
    currentRed += deltaRed * easing;
  }

  if (abs(deltaGreen) > threshold) {
    currentGreen += deltaGreen * easing;
  }

  if (abs(deltaBlue) > threshold) {
    currentBlue += deltaBlue * easing;
  }

  analogWrite(RED_PIN, (int)currentRed);
  analogWrite(GREEN_PIN, (int)currentGreen);
  analogWrite(BLUE_PIN, (int)currentBlue);
}
