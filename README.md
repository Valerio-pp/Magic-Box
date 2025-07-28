# Magic Box 🪄📦

**By Valerio – July 2025**

This Arduino project controls a magical box (or book) using a servo motor, a hidden button, and an internal light.  
When the hidden button is pressed, the box slowly opens and the LED lights up — creating a theatrical and mysterious effect, perfect for storytelling and magic performances.

---

## 🎯 Features

- Smooth servo movement (from 15° to 90° and back)
- **Hidden button** to secretly trigger the effect
- LED turns on during and after the opening
- Small delay before opening (adds dramatic tension)
- Uses a **transistor** to control the LED (or future upgrades)

---

## 🔧 Components

| Component             | Description                        |
|-----------------------|------------------------------------|
| Arduino board         | Uno, Nano, or compatible           |
| Servo motor           | SG90 or similar                    |
| Hidden push button    | Mounted inside or behind the box   |
| 9 LED                 | Standard 5mm                       |
| Resistor              | 220–330Ω (for the LED)             |
| **NPN Transistor**    | e.g. 2N2222 or BC337 (for LED)     |
| Wires + breadboard    | Or soldered setup                  |

---

## 🪛 Wiring

- **Servo** → Pin `9`
- **Button** → Pin `8`
- **LED anode (+)** → To **collector** of transistor
- **Transistor emitter (–)** → GND
- **Transistor base** → Digital pin (e.g. `7`) via 1kΩ resistor

> This setup allows the Arduino to turn on the LED using the transistor as a switch.  
> The LED can also be controlled directly if you use less led and you don't need the transistor.

---

## 🚦 Behavior

1. **On startup:**
   - Servo moves to 15° (closed)
   - LED is off

2. **First press of the hidden button:**
   - Waits 2 seconds
   - Servo opens slowly to 90°
   - LED turns on and stays on

3. **Second press of the button:**
   - Servo closes slowly to 15°
   - LED turns off

> The system keeps the current state until the button is pressed again.

---

## 📂 Files

- `Main.ino` → Arduino sketch
- `LICENSE` → Open-source license (MIT)
- `README.md` → This file

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, and share it, as long as you credit the original author.
