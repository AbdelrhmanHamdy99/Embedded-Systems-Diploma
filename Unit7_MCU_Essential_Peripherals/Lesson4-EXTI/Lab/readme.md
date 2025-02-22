# Unit 07 - Lesson 04 - STM32F103C6 External Interrupt (EXTI) Driver

## **📌 Project Overview**
This project focuses on implementing an **External Interrupt (EXTI) Driver** for the **STM32F103C6** microcontroller. The driver is tested using a **simple application**, where a button press triggers an interrupt, and the status is displayed on an **LCD**.

---

## **🛠️ System Architecture**
The project follows a structured **MCAL & HAL layered architecture**:

1. **Application Layer**
   - Initializes the **Button** and **LCD**.
   - Waits for an **external interrupt (button press)**.
   - Displays the interrupt status on the **LCD**.

2. **HAL (Hardware Abstraction Layer)**
   - **Button Driver**: Uses the EXTI driver to handle external interrupts.
   - **LCD Driver**: Displays messages when the interrupt is triggered.

3. **MCAL (Microcontroller Abstraction Layer)**
   - **EXTI Driver**: Configures external interrupts for GPIO pins.
   - **GPIO Driver**: Handles GPIO configurations.

---

## **Project Structure**
```
📂 Codes
│── 📂 STM32F103C6Tx_Drivers 
│   │── 📂 inc
│   │   │── stm32f103x6.h  # MCU Driver Header
│   │   │── stm32f103c6_GPIO_Driver.h  # GPIO Driver Header
│   │   │── stm32f103c6_EXTI_Driver.h  # EXTI Driver Header
│   │── 📂 GPIO
│   │   │── stm32f103c6_GPIO_Driver.c  # GPIO Driver Implementation
│   │── 📂 EXTI
│   │   │── stm32f103c6_EXTI_Driver.c  # EXTI Driver Implementation
│── 📂 HAL_Drivers
│   │── 📂 inc
│   │   │── LCD.h  # LCD Header
│   │   │── Button.h  # Push Button Header
│   │── 📂 LCD
│   │   │── LCD.c  # LCD Implementation
│   │── 📂 PushButton
│   │   │── Button.c  # Push Button Implementation
│── 📂 Src
│   │── main.c  # Main Application Logic
```

---

## **⚙️ Functionality**
1. **System Initialization**
   - Enables **GPIO clocks**.
   - Configures the **button** as an external interrupt.
   - Initializes the **LCD** for displaying status messages.

2. **Interrupt Handling**
   - When the **button is pressed**, an **IRQ (interrupt request)** is generated.
   - The **EXTI driver** handles the interrupt and calls the **callback function**.
   - The **LCD displays**: `IRQ EXTI9 is happened`
   - A global flag (`IRQ_happened`) is set to indicate an interrupt event.

3. **Debugging and Testing**
   - The driver was **debugged in Keil** using breakpoints to check the EXTI behavior.
   - The application was **simulated in Proteus** to visualize button-triggered interrupts.

---

## **🔌 Hardware Connections**
### **Button Connection**
| Component | STM32 Pin |
|-----------|----------|
| Button    | PB9      |

### **LCD Connection**
| LCD Pin | STM32 Pin |
|---------|----------|
| RS      | PA10     |
| RW      | PA9      |
| E       | PA8      |
| D4      | PB15     |
| D5      | PB14     |
| D6      | PB13     |
| D7      | PB12     |

---

## **🔧 Drivers Overview**
### **EXTI Driver (MCAL Layer)**
The **EXTI driver** provides APIs to configure and handle external interrupts:
- `MCAL_EXTIx_Configure(EXTI_Config_t* config)` → Configures an EXTI line for a given GPIO pin.
- `MCAL_EXTIx_GetPinMapping(GPIO_T* GPIOx, uint8_t pinNumber)` → Returns the EXTI mapping for a pin.
- `MCAL_EXTI_DeInit()` → Resets EXTI configurations.

### **Button Driver (HAL Layer)**
The **Button driver** integrates the EXTI driver to handle button presses:
- `Button_Init()` → Configures the button as an EXTI source.
- `Button_CallBack()` → Executes when the button is pressed.

### **LCD Driver (HAL Layer)**
The **LCD driver** is used to display interrupt status:
- `LCD_Write_Data(char* str)` → Displays a string on the LCD.
- `LCD_SendCharacter(char c)` → Displays a single character.
- `LCD_Write_Command(char cmd)` → Sends a command to the LCD.

---

## **Documentation & Simulation Video**
[Documetation Link](https://drive.google.com/file/d/1ACRFgp2lwJ7TKWx4Aekrmxvl-c6UgYnZ/view?usp=sharing)
[Simulation Video Link](https://drive.google.com/file/d/1fzqlMrjvALzU7CyBOnXss254R4yEV2l7/view?usp=sharing)

---

## **✅ Key Takeaways**
✔ **Understanding External Interrupts (EXTI) in STM32**.
✔ **Using EXTI for real-time event handling**.
✔ **Integrating EXTI with GPIO and HAL drivers**.
✔ **Debugging STM32 applications in Keil**.
✔ **Simulating embedded systems using Proteus**.

---

🚀 Developed as part of **Unit 7 - Lesson 04** in the Embedded Systems Course!

