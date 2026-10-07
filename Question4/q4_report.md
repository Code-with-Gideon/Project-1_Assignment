# Question 4: Smart Parking System

## 1. Tinkercad Circuit Design
> **[TODO: Add your screenshot of the Tinkercad circuit here]**
*(Make sure it shows the Arduino Uno connected to the Ultrasonic Sensor, Green LED, Red LED, and Buzzer).*

## 2. Block Diagram
> **[TODO: Add your block diagram image here]**
**Data Flow:**
Ultrasonic Sensor (Triggers Sound -> Reads Echo) -> Arduino Uno (Calculates distance -> Applies threshold logic) -> Output (Triggers Red LED & Buzzer if occupied, OR Green LED if empty).

## 3. Short Explanation
- **Role of Components:** The Ultrasonic sensor measures how far away a car is by bouncing sound waves off it. The Arduino Uno is the brain that runs the code to do the math and make decisions. The LEDs and Buzzer are actuators that give the user visual and audio feedback.
- **Processing Data:** The Arduino triggers a pulse on the 	rigPin, counts how long it takes to return on the echoPin, and divides by the speed of sound to get the distance in centimeters.
- **Controlling Outputs:** It compares the calculated distance to a hardcoded threshold (50cm). If the distance is smaller, it writes a HIGH voltage to the Red LED and Buzzer pins, and LOW to the Green LED. If larger, it flips them.

## 4. Test Cases
**Test Case 1: Vehicle outside the threshold (e.g., 100 cm)**
- **Expected:** Green LED ON, Red LED OFF, Buzzer OFF
- **Actual:** Green LED ON, Red LED OFF, Buzzer OFF (Passed)

**Test Case 2: Vehicle within the threshold (e.g., 30 cm)**
- **Expected:** Green LED OFF, Red LED ON, Buzzer ON
- **Actual:** Green LED OFF, Red LED ON, Buzzer ON (Passed)