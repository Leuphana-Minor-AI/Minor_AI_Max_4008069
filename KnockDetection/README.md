# Arduino Knock Counter

A simple project using an Arduino Uno and a KY-031 (HW-483) knock sensor to count physical impacts and display them via the Serial Monitor.

## Hardware Required
* Arduino Uno
* KY-031 / HW-483 Knock Sensor
* Jumper Wires

## Wiring Diagram
| Sensor Pin | Arduino Pin |
|------------|-------------|
| GND (-)    | GND         |
| VCC (Middle)| 5V          |
| Signal (S) | Digital 3   |

## How it Works
The code uses a digital input to listen for a 'LOW' signal from the mechanical spring inside the sensor. It includes a 200ms debounce delay to ensure physical vibrations don't trigger multiple counts for a single knock.

## How to Use
1. Clone this repository.
2. Open `src/knock_counter.ino` in the Arduino IDE.
3. Upload the code to your Arduino Uno.
4. Open the Serial Monitor at 9600 baud to see the live count.
