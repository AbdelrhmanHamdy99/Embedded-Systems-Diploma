# Unit 07 - Lesson 01 - Lab 03  

## **Push Button Controlled LEDs on ATmega32**  

### **Objective**  
This project demonstrates controlling an array of 8 LEDs connected to GPIO Port A on the ATmega32 microcontroller using a push button connected to GPIO Port C Pin 0. The behavior is based on triggering the button press to toggle LEDs in a specific sequence.

---  

### **Implementation Overview**  

#### **Behavior Description**  
1. **Button Action**:  
   - When the push button (connected to PC0) is pressed, the currently lit LED will turn off, and the next LED in the sequence will light up.  
   - This behavior loops cyclically through LEDs from LED0 to LED7.  

2. **Key Logic**:  
   - The system detects a **triggering transition** from 1 to 0 (button press).  
   - Holding the button does not cause repeated toggling. Only a single press and release action triggers the next LED change.  

3. **Edge Case Handling**:  
   - At LED7, the next press will turn on LED0 and turn off LED7 to continue the loop.

---  

### **Microcontroller & Tools Used**
- **Microcontroller**: ATmega32  
- **Simulation Software**: Proteus  
- **Development Environment**: Atmel Studio  

---  

### **Connections**  
| Component   | Pin     |
|-------------|---------|
| LED0        | PA0     |
| LED1        | PA1     |
| LED2        | PA2     |
| LED3        | PA3     |
| LED4        | PA4     |
| LED5        | PA5     |
| LED6        | PA6     |
| LED7        | PA7     |
| Push Button | PC0     |

---  

### **Code Overview**  

#### **Initialization**  
1. **GPIO Configuration**:  
   - GPIOA pins (PA0 to PA7) are configured as **output** for LEDs.  
   - GPIOC Pin 0 is configured as **input** for the push button, with an internal pull-up resistor enabled.

2. **Button Debouncing**:  
   - A software debounce mechanism is implemented to ensure accurate button press detection.  

#### **Main Logic**  
1. Continuously monitor the state of the push button on PC0.  
2. Detect a transition from **HIGH** (1) to **LOW** (0), indicating a button press.  
3. Update the LED sequence:  
   - Turn off the currently lit LED.  
   - Turn on the next LED in the sequence.  
   - If the currently lit LED is LED7, loop back to LED0.  

---  

### **Simulation Video**  
[Simulation Video Link](https://drive.google.com/drive/folders/1i2_Rj10AH08k_jouNgPZgkO_cWDFkIgB)  
This video demonstrates the LED toggling behavior controlled by a push button, including edge case handling and sequential logic.  

---  

### **Challenges**  
1. **Debouncing**:  
   - Ensuring the button press is registered only once despite mechanical noise.  
2. **Edge Cases**:  
   - Correctly looping the sequence from LED7 back to LED0.  
3. **Triggering Logic**:  
   - Detecting only the transition of the button press and ignoring the hold state.  

---  

### **Key Learning Points**  
1. Configuring GPIO pins for input (with pull-up) and output modes.  
2. Implementing edge triggering for button presses.  
3. Managing LED sequences using cyclic logic.  
4. Handling button debouncing for accurate input detection.  
5. Using Proteus for simulation of embedded systems.  

