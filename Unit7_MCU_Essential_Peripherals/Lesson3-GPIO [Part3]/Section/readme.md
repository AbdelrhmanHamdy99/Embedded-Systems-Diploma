# Unit 07 - Lesson 03 - Section: Interfacing Keypad, LCD & 7-Segment with STM32

## **📌 Project Overview**
This project demonstrates the interfacing of a **4x4 Keypad**, **16x2 LCD**, and a **7-Segment Display** with the **STM32F103C6Tx** microcontroller using a **layered architecture**. The **GPIO Driver** (developed in a previous lesson) is utilized to handle low-level register access, while the **HAL Layer** provides high-level abstraction for the **Keypad, LCD, and 7-Segment drivers**. The application reads key presses from the Keypad and displays the corresponding character on the LCD and 7-Segment display.

---

## **🛠️ System Architecture**
The project follows a structured **MCAL & HAL layered architecture**:

1. **Application Layer**
   - Communicates with the **HAL Layer**.
   - Processes user input from the Keypad.
   - Sends characters to be displayed on the LCD and 7-Segment display.

2. **HAL (Hardware Abstraction Layer)**
   - **Keypad Driver**: Reads button presses using the GPIO Driver.
   - **LCD Driver**: Controls the LCD using GPIO operations.
   - **7-Segment Driver**: Supports **both Common Anode & Common Cathode** configurations.

3. **MCAL (Microcontroller Abstraction Layer)**
   - **GPIO Driver**: Handles low-level register manipulations for GPIO operations.

---

## **Project Structure**
```
📂 Codes
│── 📂 STM32F103C6Tx_Drivers 
│   │── 📂 inc
│   │   │── stm32f103x6.h  # MCU Driver Header
│   │   │── stm32f103c6_GPIO_Driver.h  # GPIO Driver Header
│   │── 📂 GPIO
│   │   │── stm32f103c6_GPIO_Driver.c  # GPIO Driver Implementation
│── 📂 HAL_Drivers
│   │── 📂 inc
│   │   │── LCD.h  # LCD Header
│   │   │── KeyPad.h  # Keypad Header
│   │   │── 7Seg.h  # Seven Segment Header
│   │── 📂 KeyPad
│   │   │── KeyPad.c  # Keypad Implementation
│   │── 📂 LCD
│   │   │── LCD.c  # LCD Implementation
│   │── 📂 7Seg
│   │   │── 7Seg.c  # Seven Segment Implementation
│── 📂 Src
│   │── main.c  # Main Application Logic
│   │── syscalls.c, sysmem.c           # System Files
```

---

## **⚙️ Functionality**
1. **System Initialization**
   - Enables GPIO clocks.
   - Initializes the **Keypad**, **LCD**, and **7-Segment Display** via the HAL Layer.

2. **User Input Handling**
   - Reads keypresses from the **Keypad**.
   - The **ON/C button** is treated as a press on `' '` (space), since the Keypad lacks a space bar.
   - Pressing `' '` clears the **LCD** and resets the **7-Segment Display**.
   - Any other key is displayed on the **LCD** and **7-Segment Display**.
   - **If a non-numeric character is entered, the 7-Segment display is cleared.**

3. **Layered Communication**
   - The **Application Layer** calls `KeyPad_GetKeyPressed()`.
   - The **Keypad HAL Driver** communicates with **MCAL GPIO Driver** to read input.
   - The **LCD HAL Driver** uses **MCAL GPIO Driver** to send commands and data to the LCD.
   - The **7-Segment HAL Driver** updates the displayed number via GPIO operations.

---

## **🔧 Drivers Overview**
### **GPIO Driver (MCAL Layer)**
The **GPIO driver** provides fundamental APIs for pin manipulation:
- `MCAL_GPIO_Init()` → Initializes a GPIO pin with a specific mode.
- `MCAL_GPIO_WritePin()` → Writes a **HIGH** or **LOW** state to a pin.
- `MCAL_GPIO_ReadPin()` → Reads the state of a given pin.
- `MCAL_GPIO_TogglePin()` → Toggles the state of a specific pin.
- `MCAL_GPIO_LockPin()` → Locks the configuration of a pin to prevent unintended modifications.

### **LCD Driver (HAL Layer)**
The **LCD driver** abstracts the complexity of **sending commands & data** by using GPIO operations:
- `LCD_Init()` → Initializes the LCD in **4-bit or 8-bit mode**.
- `LCD_Write_Data()` → Displays a string on the LCD.
- `LCD_SendCharacter()` → Displays a single character.
- `LCD_Write_Command()` → Sends a command to the LCD.
- `LCD_Busy()` → Checks if the LCD is busy before sending data.

### **Keypad Driver (HAL Layer)**
The **Keypad driver** scans rows & columns using GPIO:
- `keyPad_Init()` → Configures the **rows as output** and **columns as input**.
- `KeyPad_GetKeyPressed()` → Scans the Keypad matrix and returns the pressed key.
- Implements **debouncing** and **long press prevention** for reliable key detection.

### **7-Segment Driver (HAL Layer)**
The **7-Segment driver** provides:
- **Support for both Common Anode & Common Cathode** (`SevenSeg_Init(uint8_t type)`).
- **Automatic clearing if a non-numeric character is displayed**.
- **APIs for initializing and displaying numbers:**
  - `SevenSeg_Init()` → Configures the display type and initializes pins.
  - `SevenSeg_DisplayNumber()` → Displays a digit (0-9) or clears if invalid.
  - `SevenSeg_Clear()` → Clears the 7-Segment display.

---

## **📺 Simulation Video**
Watch the project simulation in action:  
[Simulation Video Link](https://drive.google.com/drive/folders/102GUbOr1Ug8HQSL8okD3Vu_Qg5a8cGet?usp=sharing)

---

## **✅ Key Takeaways**
✔ **Efficient Layered Design** → MCAL (GPIO), HAL (LCD, Keypad, & 7-Segment), and Application Layers.
✔ **Modular Reusability** → The GPIO driver can be reused for multiple peripherals.
✔ **Separation of Concerns** → The application doesn’t directly manipulate hardware, it uses HAL functions.
✔ **Real-World Implementation** → A structured way to interface peripherals in STM32-based projects.

---

## **🚀 Future Enhancements**
🔹 Implement **interrupt-based Keypad scanning** for better responsiveness.
🔹 Expand functionality to support **custom characters on the LCD**.
🔹 Add **non-volatile storage** (EEPROM) to store last entered characters.
🔹 Support **multi-digit display** on the 7-Segment using multiplexing.

---

🚀 Developed as part of **Unit 7 - Lesson 03 - Section** in the Embedded Systems Course!
