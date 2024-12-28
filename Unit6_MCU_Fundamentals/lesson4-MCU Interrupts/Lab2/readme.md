# Unit 06 - Lesson 04 - Lab 02  
## **enable Ext Interrupt for Stm32F103XX**  

### **Requirements**  
Toggle A led on GPIOA pin13 by pressing a button on GPIOA pin0 in stm32f103c6

### **Approach**  
- Configure GPIOA pin0 as an Input and pin13 as output.
- Enable EXTI0 Line to be Connected with GPIOA0
- Configure EXTI0 to detect **Rising Edge**
- Configure **the Interrupt mask** for EXTI0 to deliver an interrupt to the **NVIC**
- Configure the **NVIC** to enable Interrupts on EXTI0
- Implement the EXTI0 ISR to toggle the required pin.
### **Documentation**  
https://drive.google.com/drive/folders/1tnZdaGzX_-ywEvnjla_2HofLGJG8X7XS
