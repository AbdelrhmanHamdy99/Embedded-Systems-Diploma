# Unit 07 - Lesson 01 - Lab 01  
## **GPIO in STM32**  

### **Objective**  
This lab focuses on controlling LEDs connected to GPIO Port B (pins 1 and 13) using switches connected to GPIO Port A (pins 1 and 13) in a simulated environment using Proteus. The project was developed from scratch using register-level programming based on the STM32 Technical Reference Manual (TRM). The goal is to understand and implement GPIO configurations in STM32 microcontrollers.  

---

### **Requirements**  
1. **Simulation Environment:**  
   - Proteus Design Suite for simulation.  
   - STM32 microcontroller model.  
   - Virtual LEDs and switches in Proteus.  

2. **Programming:**  
   - Register-level programming using addresses from the STM32 TRM.  
   - No reliance on HAL or MCAL drivers.  

3. **Development Tools:**  
   - STM32CubeIDE (or any other preferred IDE for writing and debugging the code).

---

### **Steps and Configuration**  

#### **GPIO Configuration**  
1. **LEDs:**  
   - Configure GPIOB Pin 1 and Pin 13 as **Push-Pull Output** pins by directly setting the relevant registers.   

2. **Switches:**  
   - Configure GPIOA Pin 1 as a **Floating Input** with a pull-up circuit.  
   - Configure GPIOA Pin 13 as a **Floating Input** with a pull-down circuit.  

#### **Switch Behavior**  
- **Switch on GPIOA Pin 1:**  
  - **Single Press Toggle:**  
    - A single press of the switch toggles the LED on GPIOB Pin 1.  
    - Continuous pressing is treated as a single press, toggling the LED only once.  

- **Switch on GPIOA Pin 13:**  
  - **Continuous Toggle:**  
    - A continuous press of the switch keeps toggling the LED on GPIOB Pin 13.  
    - Releasing the switch stops the toggling action.  

#### **Implementation Logic**  
- Directly manipulate GPIO registers to set pin modes and states.  
- Implement logic for single press vs continuous press detection.  

#### **Challenges**  
- **Avoiding Starvation During Continuous Pressing:**  
  A potential issue arises when one switch is continuously pressed, causing the system to ignore inputs from the other switch. This could lead to starvation.    

---

### **Simulation**  
[Simulation Files](https://drive.google.com/drive/u/0/folders/156QKSOnOMuA_GqQIq6cSmH2fWMFmPMGB)  

The circuit was designed and simulated in Proteus. Ensure all connections (GPIO pins, LEDs, switches) are accurately reflected in the simulation environment.

---

### **Code Overview**  
- **Initialization:**  
  - Configure GPIO ports and pins as per the requirements.  

- **Main Logic:**  
  - Continuously monitor the status of switches on GPIOA.  
  - Apply appropriate toggling logic for LEDs on GPIOB based on the switch behavior.  

---

### **Key Learning Points**  
1. Configuring GPIO pins for different modes (output push-pull, input floating).  
2. Understanding single press vs continuous press behavior and its effect on GPIO output.  
3. Using Proteus for practical simulation of GPIO control.  

