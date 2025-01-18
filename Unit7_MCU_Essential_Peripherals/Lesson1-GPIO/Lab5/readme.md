# Unit 07 - Lesson 01 - Lab 05  

## **Controlling Two 7-Segment Displays with 6 Pins**  

### **Objective**  
This project demonstrates how to control two 7-segment displays using only 6 GPIO pins on the ATmega32 microcontroller. The project uses a **74HC4511 BCD to 7-Segment Decoder** and **2N2222 transistors** to enable selective control over the two displays, implementing a counter from 00 to 99.  

---  

### **Implementation Overview**  

#### **Behavior Description**  
1. The **74HC4511** decoder accepts a 4-bit binary-coded decimal (BCD) input and converts it into signals to drive a 7-segment display.  
2. Two 7-segment displays share the decoder's outputs, but only one display is active at a time, controlled via **2N2222 transistors**.  
3. The microcontroller alternates between the two displays using GPIO pins to control the transistors, displaying the tens digit on one and the units digit on the other.  

#### **Key Features**  
- Efficient use of GPIO pins through shared connections and multiplexing.  
- Smooth counting from 00 to 99 with minimal hardware.  

---

### **Microcontroller & Tools Used**  
- **Microcontroller**: ATmega32  
- **Decoder**: 74HC4511 BCD to 7-Segment Decoder  
- **Transistors**: 2N2222 (two units)  
- **Simulation Software**: Proteus  
- **Development Environment**: Atmel Studio  

---

### **Connections**  

#### **Decoder Input (74HC4511)**  
| BCD Pin | GPIO Pin on Port D |  
|---------|--------------------|  
| A       | PD0               |  
| B       | PD1               |  
| C       | PD2               |  
| D       | PD3               |  

#### **Transistor Control**  
| Transistor | 7-Segment | GPIO Pin on Port D |  
|------------|-----------|--------------------|  
| 2N2222 #1  | Display 1 | PD4               |  
| 2N2222 #2  | Display 2 | PD5               |  

#### **Decoder Output**  
The outputs of the decoder (a, b, c, d, e, f, g) are connected to both 7-segment displays.  

#### **Common Cathode**  
The common cathode of each 7-segment display is connected to the collector of its respective transistor.  

---

### **Code Overview**  

#### **Initialization**  
1. Configure GPIO pins (PD0–PD3) as output for the BCD input.  
2. Configure GPIO pins (PD4 and PD5) as output for controlling the transistors.  

#### **Main Logic**  
1. Use **multiplexing** to control the two displays:  
   - Enable the transistor for Display 1 and output the tens digit.  
   - Disable Display 1 and enable Display 2 to output the units digit.  
   - Repeat this process rapidly to give the illusion that both displays are active simultaneously.  

2. Implement a counter to increment from 00 to 99:  
   - Split the counter value into two digits (tens and units).  
   - Send each digit to the decoder sequentially.  

---

### **Challenges**  
1. **Multiplexing Timing**:  
   - The delay between updates must be short enough to prevent flicker but long enough to ensure clear display transitions.  
2. **Transistor Control**:  
   - Properly bias the 2N2222 transistors to enable or disable the displays without overlapping.  
3. **Decoder Output Sharing**:  
   - Ensure both 7-segment displays receive correct signals without interference.  

---

### **Simulation Video**  
[Simulation Video Link](https://drive.google.com/drive/folders/1DENCbeyapUWblJwr8ehHAt1zORwkzJBR)  
The video showcases the two 7-segment displays counting from 00 to 99, controlled using only 6 GPIO pins.  

---

### **Key Learning Points**  
1. Efficient GPIO pin usage by sharing connections between multiple devices.  
2. Implementing **multiplexing** for controlling multiple displays.  
3. Using a **BCD to 7-segment decoder** for simplifying display control.  
4. Leveraging **transistors** as electronic switches for selective control.  
5. Understanding timing considerations in multiplexed systems.  

---

### **Workflow Example**  
1. **Input to Decoder**:  
   - Send a decimal digit (0–9) to the 74HC4511 using PD0–PD3.  
2. **Control Display 1**:  
   - Enable transistor 1 (PD4 HIGH) to display the tens digit.  
   - Disable transistor 1 (PD4 LOW).  
3. **Control Display 2**:  
   - Enable transistor 2 (PD5 HIGH) to display the units digit.  
   - Disable transistor 2 (PD5 LOW).  
4. Repeat this process with rapid switching to ensure seamless display operation.  

---

### **Tips for Success**  
- Use a **delay between 5–10 ms** during multiplexing to balance flicker-free operation and smooth transitions.  
- Ensure proper connections for decoder outputs to both 7-segment displays.  
- Test transistor biasing to avoid leakage currents or improper switching.  

---

### **Conclusion**  
This lab illustrates how to efficiently control two 7-segment displays with minimal GPIO pins by combining a BCD decoder, transistors, and multiplexing techniques. It demonstrates resource optimization and highlights key principles of embedded systems design.  
