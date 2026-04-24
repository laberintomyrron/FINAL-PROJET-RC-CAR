#  RC Car using ESP32

A custom-built RC car powered by the ESP32 microcontroller — featuring wireless control, modular electronics, and fully documented hardware and firmware.

---

##  Preview

![RC Car](media/isometric%20view.jpg)
---

##  Features

-  Wireless control via ESP32 (Wi-Fi / Bluetooth)
-  Motor driver integration
-  Battery management
-  Easy-to-reproduce design

---

##  Parts List

---

See the [`parts/`](./parts/) folder for components images

| Component | Description | Qty |
|---|---|---|
| ESP32 Dev Board | Main microcontroller | 1 |
| L298N | Motor driver module | 1 |
| DC Motors | 12v N20 | 4 |
| 18650 Battery | Power supply | 3 |
| Chassis | RC car frame | 1 |
| Jumper wires | Connections | — |

---

##  Wiring / Schematics

See the [`schematics/`](./schematics/) folder for full wiring diagrams.

---

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software)
- ESP32 board package installed
  
---

##  Step by step process
# Build Instructions
 
This guide walks you through assembling the RC Car using ESP32 from scratch.
 
---
 
## Step 1: Attach the DC Motors to the Chassis
 
- Take all **4 DC motors** and position them at the four corners of the chassis frame.
- Use **screws and mounting brackets** to secure each motor firmly to the chassis.
- Make sure all motors are aligned properly so the wheels will be level and straight.
---
 
## Step 2: Attach the L298N Motor Driver to the Chassis
 
- Mount the **L298N motor driver** onto the chassis using screws.
- Place it in a central location for easier wiring to both the motors and the ESP32.
- Wire the **4 DC motors** to the output terminals of the L298N:
  - **OUT1 & OUT2** → Right front and rear motors
  - **OUT3 & OUT4** → Left front and rear motors
---
 
## Step 3: Attach the ESP32 to the Chassis
 
- Mount the **ESP32 development board** onto the chassis.
- Connect the ESP32 GPIO pins to the input terminals of the L298N using jumper wires.
- Refer to the wiring table below for the exact connections.
---
 
## 🔌 ESP32 to L298N Wiring Table
 
| L298N Pin | ESP32 Pin | Description              |
|-----------|-----------|--------------------------|
| ENA       | D14       | Enable Motor A (PWM)     |
| IN1       | D4        | Motor A Direction Pin 1  |
| IN2       | D2        | Motor A Direction Pin 2  |
| IN3       | D15       | Motor B Direction Pin 1  |
| IN4       | D13       | Motor B Direction Pin 2  |
| ENB       | D27       | Enable Motor B (PWM)     |
| GND       | GND       | Common Ground            |
| +5v       | Vin       | 5V Power Supply to ESP32 |

---

## Final Check
 
Before powering on, verify the following:
 
- All 4 motors are secured tightly to the chassis with no wobble.
- Motor wires are connected to the correct L298N output terminals.
- All jumper wires between ESP32 and L298N match the wiring table above.
- ESP32 and L298N share a common ground.
- Battery is connected to the L298N power input not the ESP32 directly.
  
---

##  Build Photos

See the [`media/`](./media/) folder for components images

---

## Author

**Your Name**  
GitHub: [laberintomyrron](https://github.com/laberintomyrron)
