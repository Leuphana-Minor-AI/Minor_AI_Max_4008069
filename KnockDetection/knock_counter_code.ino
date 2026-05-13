// --- DEFINITIONS ---
// We assign names to the physical pins so the code is easier to read.
int knockPin = 3;     // This identifies Digital Pin 3 as the 'Signal' input from your sensor.
int ledPin = 13;      // This identifies the built-in LED on your Arduino board.
int val;              // This is a temporary container to store the 'High' or 'Low' reading.

// --- THE COUNTER ---
// This is a tally sheet stored in the Arduino's memory. 
// We place it here at the top so the Arduino remembers the number even after the 'loop' finishes.
int knockCount = 0;   

void setup() {
  // This section runs once to prepare the Arduino's 'brain'.
  
  pinMode(ledPin, OUTPUT);  // Tell Pin 13 to act as an exit for electricity (to light the LED).
  pinMode(knockPin, INPUT); // Tell Pin 3 to act as an entrance for electricity (to listen to the sensor).
  
  // This starts the 'phone call' between the Arduino and your computer.
  // 9600 is the communication speed.
  Serial.begin(9600); 
  Serial.println("System Initialized. Waiting for knock...");
}

void loop() {
  // This section repeats forever, as long as the Arduino has power.

  // THE READING LOGIC:
  // The Arduino 'looks' at Pin 3. If the spring inside the sensor vibrates and 
  // touches the contact, it completes a circuit that the Arduino reads as 'LOW'.
  val = digitalRead(knockPin); 

  // THE DECISION LOGIC:
  // We ask: "Is the reading currently LOW?"
  if (val == LOW) {            
    
    // THE COUNTER LOGIC:
    // If a knock is detected, we update our tally. 
    // This takes the current total, adds 1, and saves it back into 'knockCount'.
    knockCount = knockCount + 1; 
    
    // THE FEEDBACK LOGIC:
    // We turn on the built-in LED so you have a visual cue on the board itself.
    digitalWrite(ledPin, HIGH);
    
    // THE COMMUNICATION LOGIC:
    // We send the data to your computer screen in two steps.
    // 'print' sends the number, and 'println' sends the text and starts a new line.
    Serial.print(knockCount);
    Serial.println(" knocks detected"); 
    
    // THE DEBOUNCE LOGIC:
    // Mechanical springs 'bounce' when hit. Without this 200ms (0.2s) pause, 
    // the Arduino is so fast it might count 10 knocks for a single finger tap.
    delay(200); 
  } 
  else {
    // If the sensor is not vibrating (it's 'HIGH'), we make sure the LED stays off.
    digitalWrite(ledPin, LOW);
  }
}
