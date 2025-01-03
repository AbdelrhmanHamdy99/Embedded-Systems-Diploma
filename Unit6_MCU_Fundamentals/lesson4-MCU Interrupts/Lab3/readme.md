# Unit 06 - Lesson 04 - Lab 03  
## **Interrupt Controller On Atmega32**  

### **Requirements**  
Control 3 LEDs on PortD(5,6,7) using the 3 External Interrupts(INT0,1,2) using different triggering event for each interrupt.

### **Approach**  
- Configure INT0 to fire at **any Logical Change**.
- Configure INT1 to fire at **rising edge**.
- Configure INT2 to fire at **failing edge**.
- Each interrupt just make the **LED ON for 1 sec** .
- INT0 Controls Led0 on PortD pin5.
- INT1 Controls Led1 on PortD pin6.
- INT2 Controls Led2 on PortD pin7.
- the main function always turns off all LEDs.

### **Documentation and output video**  
https://drive.google.com/drive/u/0/folders/1ipG9_z-CuT1P4vDf9cuqAS2HwCOJ3p4Z
