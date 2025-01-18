# Unit 07 - Lesson 01 - Lab 02  

## **LED Control on ATmega32**  

### **Objective**  
This project aims to demonstrate practical control of GPIO pins by implementing a sequential lighting and dimming pattern on 8 LEDs connected to Port A of the ATmega32 microcontroller. The lab focuses on understanding GPIO configurations.

---  

### **Implementation Overview**  
1. **Lighting Sequence**:  
   - LEDs light up sequentially from LED0 (PA0) to LED7 (PA7).  
   - A delay is introduced between each LED activation.  

2. **Dimming Sequence**:  
   - LEDs turn off sequentially in reverse order, from LED7 to LED0.  
   - A delay is also introduced between each LED deactivation.  

3. **Key Logic**:  
   - GPIOA is configured as output to control the LEDs.  
   - Delays are implemented using a simple delay function to manage timing.  

---  

### **Microcontroller & Tools Used**
- **Microcontroller**: ATmega32  
- **Simulation Software**: Proteus  
- **Development Environment**: Atmel Studio  

---  

### **Connections**
| LED   | Pin |
|-------|-----|
| LED0  | PA0 |
| LED1  | PA1 |
| LED2  | PA2 |
| LED3  | PA3 |
| LED4  | PA4 |
| LED5  | PA5 |
| LED6  | PA6 |
| LED7  | PA7 |

---  

### **Challenges**  
- Synchronizing delays to maintain smooth transitions.  
- Ensuring correct GPIO configuration to avoid unwanted behavior.  

---  

### **Simulation Video**  
[Simulation Video Link](https://drive.google.com/drive/folders/1Ob_EBbkb6oocDZSdcv1RdgQInMiJyQYs)  
This video demonstrates the sequential lighting and dimming of LEDs on the ATmega32, as implemented in this lab.  

---  

### **Key Learning Points**  
1. Configuring GPIO pins for output and understanding their behavior.  
2. Implementing timing control using delay functions.  
3. Writing efficient code for sequential operations.  
4. Simulating embedded systems using Proteus.  