# Unit 07 - Lesson 01 - Lab 04  

## **7-Segment Counter on ATmega32**  

### **Objective**  
This project demonstrates the use of a 7-segment display connected to GPIO Port D on the ATmega32 microcontroller. The 7-segment is programmed to function as a counter that increments from 0 to 9 continuously in a loop.  

---  

### **Implementation Overview**  

#### **Behavior Description**  
1. The 7-segment display is connected to Port D (PD0 to PD6).  
2. The counter starts at 0 and increments by 1 every second until it reaches 9.  
3. After displaying 9, the counter resets to 0 and the cycle repeats.

---

### **Microcontroller & Tools Used**  
- **Microcontroller**: ATmega32  
- **Simulation Software**: Proteus  
- **Development Environment**: Atmel Studio  

---

### **Connections**  
| 7-Segment Pin | GPIO Pin on Port D |  
|---------------|--------------------|  
| a             | PD0               |  
| b             | PD1               |  
| c             | PD2               |  
| d             | PD3               |  
| e             | PD4               |  
| f             | PD5               |  
| g             | PD6               |  

- The used 7-segment is **common cathode**.  

---  

### **Code Overview**  

#### **Initialization**  
1. Configure GPIO Port D (PD0 to PD6) as output for the 7-segment display.  
2. Initialize the counter to 0.  

#### **Main Logic**  
1. Use a lookup table or array to map numbers (0–9) to the corresponding 7-segment patterns.  
2. Output the patterns to Port D based on the current count value.  
3. Increment the counter every 1 second using a delay function.  
4. Reset the counter to 0 after reaching 9.  

---

### **Challenges**  
1. **7-Segment Encoding**:  
   - Correctly mapping numbers to their binary representation for the 7-segment display. 

---

### **Simulation Video**  
[Simulation Video Link](https://drive.google.com/drive/folders/1aJY1Us4syCwOU1o1B_gbwSFdRqXJWmGT)  
The video demonstrates the counter incrementing from 0 to 9 on the 7-segment display, repeating in a loop.

---

### **Key Learning Points**  
1. Configuring GPIO pins for controlling external peripherals like 7-segment displays.  
2. Understanding 7-segment encoding for number representation.  
3. Implementing a basic counter logic using a microcontroller.  
4. Simulating embedded systems projects using Proteus.  

