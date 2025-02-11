# Unit 07 - Lesson 03 - STM32F103 GPIO Driver

## **Objective**
This lesson focuses on developing a **GPIO driver from scratch** for the STM32F103C6Tx microcontroller using **register-level programming**. The driver is then tested with an application that controls LEDs based on button presses.

---

## **Project Overview**

### **1️⃣ GPIO Driver Development**
- Implemented a **custom GPIO driver** for STM32F103C6Tx.
- Used **register-level programming** based on the STM32F103 **Technical Reference Manual (TRM)**.
- Provides functions for configuring GPIO pins, setting/resetting values, and reading inputs.
- Includes a **locking mechanism** to prevent unintended changes to GPIO configurations.

### **2️⃣ Application: LED Toggle using Buttons**
- Integrated the GPIO driver with an **LED control application**.
- The application controls two LEDs using two buttons with the following behavior:
  1. **Button 1 (Single Press Toggle)**: Pressing **once** toggles LED1 **ON/OFF**.
  2. **Button 2 (Continuous Toggle)**: Holding the button continuously toggles LED2 **ON/OFF** at a set rate.

---

## **Development Environment**
- **Microcontroller**: STM32F103C6Tx
- **IDE**: STM32CubeIDE
- **Debugger**: ST-Link V2
- **Simulation Software**: Proteus

---

## **Project Structure**
```
📂 Unit7-Lesson3-STM32F103C6Tx
│── 📂 STM32F103C6Tx_Drivers
│   │── 📂 GPIO
│   │   │── stm32f103c6_GPIO_Driver.c  # GPIO Driver Implementation
│   │   │── stm32f103c6_GPIO_Driver.h  # GPIO Driver Header
│   │── 📂 Inc
│   │   │── stm32f103x6.h              # STM32F103 Register Definitions
│── 📂 Src
│   │── main.c                         # Application Code (Button-LED Control)
│   │── syscalls.c, sysmem.c           # System Files
│── README.md                          # Project Documentation
```

---

## **GPIO Driver Features**
### **✅ Supported Functions**
- `MCAL_GPIO_Init(GPIO_T* GPIOx, GPIO_PinConfig_t* pinConfig)`: Initializes GPIO pins with user-defined configurations.
- `MCAL_GPIO_DeInit(GPIO_T* GPIOx)`: Resets GPIO registers to default state.
- `MCAL_GPIO_ReadPin(GPIO_T* GPIOx, uint8_t PinNumber)`: Reads the value of a specific GPIO pin.
- `MCAL_GPIO_ReadPort(GPIO_T* GPIOx)`: Reads all pin values in a port.
- `MCAL_GPIO_WritePin(GPIO_T* GPIOx, uint8_t PinNumber, uint8_t Value)`: Sets or clears a specific GPIO pin.
- `MCAL_GPIO_WritePort(GPIO_T* GPIOx, uint16_t Value)`: Writes a value to an entire GPIO port.
- `MCAL_GPIO_TogglePin(GPIO_T* GPIOx, uint8_t PinNumber)`: Toggles the state of a GPIO pin.
- `MCAL_GPIO_LockPin(GPIO_T* GPIOx, uint8_t PinNumber)`: Locks a GPIO pin configuration to prevent accidental changes.

### **🔧 GPIO Configuration Options**
- **Modes**:
  - Output (Push-Pull / Open-Drain)
  - Input (Floating / Pull-Up / Pull-Down)
  - Alternate Function (AF Push-Pull / AF Open-Drain)
- **Pull-up/Pull-down**: Internal resistors supported.
- **Output Speed**: 10MHz, 2MHz, 50MHz.
- **Locking Mechanism**: Prevents unintended pin changes after initialization.

---

## **Peripheral Configuration**
### **📌 Clock Enable for GPIO Ports**
| Peripheral | Macro |
|------------|----------------------|
| GPIOA | `GPIOA_Clock_Enable` |
| GPIOB | `GPIOB_Clock_Enable` |
| GPIOC | `GPIOC_Clock_Enable` |
| AFIO | `AFIO_Clock_Enable` |

### **📌 Button-LED Mapping**
| Button (GPIOA) | LED (GPIOB) | Behavior |
|---------------|------------|-----------|
| PA1 (Button 1) | PB1 (LED1) | Single press toggles LED ON/OFF |
| PA13 (Button 2) | PB13 (LED2) | Continuous press toggles LED rapidly |

### **📝 Code Overview**
1. **System Initialization**: Configures system clocks.
2. **GPIO Initialization**: Uses the custom GPIO driver to configure pins.
3. **Main Loop Logic**:
   - Reads button states.
   - Implements toggle logic based on single press/continuous press behavior.
   - Calls GPIO driver functions to update LED states.

---

## **Challenges & Solutions**
| Challenge | Solution |
|-----------|----------|
| Ensuring correct GPIO register access | Used **direct register manipulation** with proper bit masking |
| Handling switch debouncing | Implemented a **software delay** to filter unintended toggles |
| Implementing single vs continuous press logic | Used **flag-based logic** to differentiate press types |

---

## **Simulation & Testing**
- The project was tested in **Proteus** to verify LED behavior based on button inputs.
- Debugging was done using **STM32CubeIDE + ST-Link V2**.
- **[Simulation Files](https://drive.google.com/drive/folders/1Jhc3CNUA_o46zo6YPBk_hM8SLl0yXobu)** 📂

---

## **Key Takeaways**
1. **Understanding GPIO register configurations** in STM32.
2. **Developing a custom driver** for GPIO that covers most functionality.
3. **Implementing button-driven LED control** with different behaviors.
4. **Handling real-time GPIO inputs** with efficient polling techniques.

---

🚀 Developed as part of **Unit 7 - Lesson 3** in the Embedded Systems Course!
