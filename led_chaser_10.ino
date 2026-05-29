/*
 * Project: 10 LED Light Chaser / Dancing Lights
 * Description: Multiple light patterns with 10 LEDs - Knight Rider, Wave, Random, and more!
 * Hardware: Arduino Uno, 10x LEDs, 10x 220Ω Resistors
 * Pin Mapping: LEDs connected to Digital Pins 2-11
 * Author: [Your Name]
 * License: MIT
 * 
 * Features:
 * - 8 different light patterns
 * - Adjustable speed with potentiometer
 * - Button to change effects
 * - Serial control support
 */

// Pin Definitions
const int LED_START_PIN = 2;   // First LED pin
const int LED_COUNT = 10;      // Number of LEDs
const int EFFECTS_COUNT = 8;   // Number of different effects

// Global Variables
int currentEffect = 0;
int speed = 100;               // Default speed (milliseconds)
bool autoChange = false;       // Auto change effects every 30 seconds
unsigned long lastEffectChange = 0;

// Potentiometer pin (optional)
const int POT_PIN = A0;
const int BUTTON_PIN = 12;     // Button to change effect

void setup() {
  // Initialize all LED pins as outputs
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_START_PIN + i, OUTPUT);
    digitalWrite(LED_START_PIN + i, LOW);
  }
  
  // Initialize button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Start serial communication
  Serial.begin(9600);
  Serial.println("=== 10 LED Light Chaser ===");
  Serial.println("Commands:");
  Serial.println("  e[0-7]  - Change effect");
  Serial.println("  s[50-500] - Set speed (ms)");
  Serial.println("  auto    - Toggle auto effect change");
  Serial.println("  list    - List all effects");
  Serial.println("============================");
  
  // Initial blink to show startup
  startupSequence();
}

void loop() {
  // Read potentiometer for speed control (optional)
  int potValue = analogRead(POT_PIN);
  speed = map(potValue, 0, 1023, 30, 300);
  
  // Check button press
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50); // Debounce
    if (digitalRead(BUTTON_PIN) == LOW) {
      currentEffect = (currentEffect + 1) % EFFECTS_COUNT;
      Serial.print("Effect changed to: ");
      Serial.println(currentEffect);
      delay(300); // Wait for button release
    }
  }
  
  // Auto change effect every 30 seconds
  if (autoChange && (millis() - lastEffectChange > 30000)) {
    currentEffect = (currentEffect + 1) % EFFECTS_COUNT;
    lastEffectChange = millis();
    Serial.print("Auto changed to effect: ");
    Serial.println(currentEffect);
  }
  
  // Handle serial commands
  handleSerialCommands();
  
  // Run current effect
  switch(currentEffect) {
    case 0:
      effectKnightRider();
      break;
    case 1:
      effectWave();
      break;
    case 2:
      effectRandom();
      break;
    case 3:
      effectBounce();
      break;
    case 4:
      effectFillAndClear();
      break;
    case 5:
      effectAlternating();
      break;
    case 6:
      effectFirefly();
      break;
    case 7:
      effectDanceParty();
      break;
  }
}

// ============ EFFECTS ============

// Effect 0: Knight Rider (Cylon) - Back and forth
void effectKnightRider() {
  for (int i = 0; i < LED_COUNT; i++) {
    clearLEDs();
    setLED(i, HIGH);
    delay(speed);
  }
  for (int i = LED_COUNT - 2; i > 0; i--) {
    clearLEDs();
    setLED(i, HIGH);
    delay(speed);
  }
}

// Effect 1: Wave - Progressive wave effect
void effectWave() {
  for (int i = 0; i < LED_COUNT; i++) {
    clearLEDs();
    for (int j = 0; j <= i; j++) {
      setLED(j, HIGH);
    }
    delay(speed);
  }
  for (int i = LED_COUNT - 2; i >= 0; i--) {
    clearLEDs();
    for (int j = 0; j <= i; j++) {
      setLED(j, HIGH);
    }
    delay(speed);
  }
}

// Effect 2: Random - Random LEDs light up
void effectRandom() {
  clearLEDs();
  for (int i = 0; i < LED_COUNT; i++) {
    int randomLED = random(LED_COUNT);
    setLED(randomLED, HIGH);
    delay(speed / 2);
    setLED(randomLED, LOW);
  }
}

// Effect 3: Bounce - Ball bouncing effect
void effectBounce() {
  static int position = 0;
  static int direction = 1;
  
  clearLEDs();
  setLED(position, HIGH);
  position += direction;
  
  if (position >= LED_COUNT - 1) {
    position = LED_COUNT - 1;
    direction = -1;
  } else if (position <= 0) {
    position = 0;
    direction = 1;
  }
  
  delay(speed);
}

// Effect 4: Fill and Clear - All LEDs fill then clear
void effectFillAndClear() {
  // Fill all LEDs
  for (int i = 0; i < LED_COUNT; i++) {
    setLED(i, HIGH);
    delay(speed);
  }
  
  // Clear all LEDs
  for (int i = LED_COUNT - 1; i >= 0; i--) {
    setLED(i, LOW);
    delay(speed);
  }
}

// Effect 5: Alternating - Odd/Even LEDs
void effectAlternating() {
  // Turn on even LEDs
  for (int i = 0; i < LED_COUNT; i += 2) {
    setLED(i, HIGH);
  }
  delay(speed);
  
  // Turn on odd LEDs
  clearLEDs();
  for (int i = 1; i < LED_COUNT; i += 2) {
    setLED(i, HIGH);
  }
  delay(speed);
}

// Effect 6: Firefly - Gentle random blinking like fireflies
void effectFirefly() {
  int activeLEDs = random(1, 4); // 1-3 LEDs active at once
  
  clearLEDs();
  for (int i = 0; i < activeLEDs; i++) {
    int led = random(LED_COUNT);
    setLED(led, HIGH);
    delay(random(20, 100));
  }
  delay(speed / 2);
}

// Effect 7: Dance Party - Complex pattern
void effectDanceParty() {
  // Pattern 1: All blink
  allLEDs(HIGH);
  delay(speed / 2);
  allLEDs(LOW);
  delay(speed / 4);
  
  // Pattern 2: Spiral pattern
  for (int i = 0; i < LED_COUNT; i++) {
    setLED(i, HIGH);
    setLED(LED_COUNT - 1 - i, HIGH);
    delay(speed / 3);
  }
  clearLEDs();
  delay(speed / 2);
  
  // Pattern 3: Binary counting
  for (int i = 0; i < 8; i++) {
    for (int bit = 0; bit < LED_COUNT; bit++) {
      if (i & (1 << bit)) {
        setLED(bit, HIGH);
      }
    }
    delay(speed);
    clearLEDs();
  }
}

// ============ HELPER FUNCTIONS ============

void setLED(int index, int state) {
  // Set individual LED state
  digitalWrite(LED_START_PIN + index, state);
}

void clearLEDs() {
  // Turn off all LEDs
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_START_PIN + i, LOW);
  }
}

void allLEDs(int state) {
  // Turn all LEDs on or off
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_START_PIN + i, state);
  }
}

void startupSequence() {
  // Blink all LEDs 3 times
  for (int i = 0; i < 3; i++) {
    allLEDs(HIGH);
    delay(200);
    allLEDs(LOW);
    delay(100);
  }
  
  // Sequential turn on
  for (int i = 0; i < LED_COUNT; i++) {
    setLED(i, HIGH);
    delay(50);
  }
  delay(200);
  
  // Sequential turn off
  for (int i = 0; i < LED_COUNT; i++) {
    setLED(i, LOW);
    delay(50);
  }
}

void handleSerialCommands() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    
    if (command.startsWith("e")) {
      int effect = command.substring(1).toInt();
      if (effect >= 0 && effect < EFFECTS_COUNT) {
        currentEffect = effect;
        Serial.print("Effect changed to: ");
        Serial.println(currentEffect);
        clearLEDs();
      } else {
        Serial.println("Invalid effect! Use 0-7");
      }
    }
    else if (command.startsWith("s")) {
      int newSpeed = command.substring(1).toInt();
      if (newSpeed >= 30 && newSpeed <= 500) {
        speed = newSpeed;
        Serial.print("Speed set to: ");
        Serial.println(speed);
      } else {
        Serial.println("Speed must be 30-500 ms");
      }
    }
    else if (command == "auto") {
      autoChange = !autoChange;
      Serial.print("Auto change effects: ");
      Serial.println(autoChange ? "ON" : "OFF");
      if (autoChange) lastEffectChange = millis();
    }
    else if (command == "list") {
      Serial.println("Available Effects:");
      Serial.println("0: Knight Rider (Cylon)");
      Serial.println("1: Wave");
      Serial.println("2: Random");
      Serial.println("3: Bounce");
      Serial.println("4: Fill and Clear");
      Serial.println("5: Alternating");
      Serial.println("6: Firefly");
      Serial.println("7: Dance Party");
    }
    else if (command == "help") {
      Serial.println("Commands: e[0-7], s[30-500], auto, list, help");
    }
  }
}
