#include <NimBLEDevice.h>
#include <NimBLEHIDDevice.h>
#include <NimBLECharacteristic.h>

// Button and Joystick pin mapping
const int buttonPins[] = {4, 5, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33, 14, 15, 16, 17}; // 16 buttons (up to 16 pins)
const int joystickXPin = 34; // Joystick X-axis (Left)
const int joystickYPin = 35; // Joystick Y-axis (Left)
const int joystick2XPin = 36; // Joystick X-axis (Right)
const int joystick2YPin = 39; // Joystick Y-axis (Right) 

NimBLEHIDDevice* hid;
NimBLECharacteristic* inputReport;
uint8_t report[5] = {0x00, 0x00, 0x00, 0x00, 0x00}; // Button states, Joystick 1 (X, Y), Joystick 2 (X, Y)
bool previousButtonState[16] = {false}; // Track previous button states for press/release detection

void setup() {
  Serial.begin(115200);
  NimBLEDevice::init("ESP32 GamepadV.2");

  NimBLEServer* server = NimBLEDevice::createServer();
  hid = new NimBLEHIDDevice(server);
  inputReport = hid->inputReport(1); // Report ID 1

  hid->manufacturer()->setValue("ESP32 Manufacturer");
  hid->pnp(0x02, 0x1234, 0x5678, 0x0110); // Vendor ID, Product ID, Version
  hid->hidInfo(0x00, 0x01);

  // Define HID report map for 16 buttons and 2 joysticks
  const uint8_t reportMap[] = {
    0x05, 0x01,  // Usage Page (Generic Desktop)
    0x09, 0x05,  // Usage (Game Pad)
    0xA1, 0x01,  // Collection (Application)
    0x15, 0x00,  // Logical Minimum (0)
    0x25, 0x01,  // Logical Maximum (1)
    0x35, 0x00,  // Physical Minimum (0)
    0x45, 0x01,  // Physical Maximum (1)
    0x75, 0x01,  // Report Size (1)
    0x95, 0x10,  // Report Count (16 buttons)
    0x05, 0x09,  // Usage Page (Button)
    0x19, 0x01,  // Usage Minimum (1)
    0x29, 0x10,  // Usage Maximum (16)
    0x81, 0x02,  // Input (Data, Var, Abs)
    
    // Joystick 1 (X, Y)
    0x05, 0x01,  // Usage Page (Generic Desktop)
    0x09, 0x30,  // Usage (X)
    0x09, 0x31,  // Usage (Y)
    0x15, 0x81,  // Logical Minimum (-127)
    0x25, 0x7F,  // Logical Maximum (127)
    0x75, 0x08,  // Report Size (8)
    0x95, 0x02,  // Report Count (2)
    0x81, 0x02,  // Input (Data, Var, Abs)
    
    // Joystick 2 (X, Y)
    0x09, 0x30,  // Usage (X)
    0x09, 0x31,  // Usage (Y)
    0x81, 0x02,  // Input (Data, Var, Abs)
    
    0xC0         // End Collection
  };

  hid->reportMap((uint8_t*)reportMap, sizeof(reportMap));
  hid->startServices();

  NimBLEAdvertising* advertising = server->getAdvertising();
  advertising->setAppearance(0x03C0); // Gamepad
  advertising->start();

  // Set up button pins
  for (int i = 0; i < 16; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);  // Initialize button pins with pull-up resistors
  }
  
  // Set up joystick pins
  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);
  pinMode(joystick2XPin, INPUT);
  pinMode(joystick2YPin, INPUT);

  Serial.println("Gamepad ready and advertising...");
}

void loop() {
  // Read button states
  for (int i = 0; i < 16; i++) {
    bool currentButtonState = (digitalRead(buttonPins[i]) == LOW); // Active low buttons
    if (currentButtonState != previousButtonState[i]) {
      if (currentButtonState) {
        Serial.print("Button ");
        Serial.print(i + 1);
        Serial.println(" pressed");
        report[0] |= (1 << i); // Set bit for button press
      } else {
        Serial.print("Button ");
        Serial.print(i + 1);
        Serial.println(" released");
        report[0] &= ~(1 << i); // Clear bit for button release
      }
      previousButtonState[i] = currentButtonState; // Update previous state
    }
  }

  // Read joystick 1 values (Left joystick)
  int joystick1X = analogRead(joystickXPin);
  int joystick1Y = analogRead(joystickYPin);

  // Read joystick 2 values (Right joystick)
  int joystick2X = analogRead(joystick2XPin);
  int joystick2Y = analogRead(joystick2YPin);

  // Map joystick values (0-4095) to (-127 to 127)
  report[1] = map(joystick1X, 0, 4095, -127, 127);
  report[2] = map(joystick1Y, 0, 4095, -127, 127);

  report[3] = map(joystick2X, 0, 4095, -127, 127);
  report[4] = map(joystick2Y, 0, 4095, -127, 127);

  // Send the updated report
  inputReport->setValue(report, sizeof(report));
  inputReport->notify();

  // Debugging output
  Serial.print("Buttons: ");
  Serial.print(report[0], BIN);
  Serial.print(" Joystick 1 (X, Y): ");
  Serial.print(report[1]);
  Serial.print(", ");
  Serial.print(report[2]);
  Serial.print(" Joystick 2 (X, Y): ");
  Serial.print(report[3]);
  Serial.print(", ");
  Serial.println(report[4]);

  delay(20); // Adjust for desired polling rate
}
