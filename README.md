# 10 LED Light Chaser / Dancing Lights

[![Arduino](https://img.shields.io/badge/Arduino-00979D?logo=arduino&logoColor=fff)](https://www.arduino.cc/)
[![Platform](https://img.shields.io/badge/platform-Arduino%20Uno-blue)]()
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)

<div align="center">
  
### *✨ Make your LEDs dance! A spectacular light show with 10 LEDs ✨*

</div>

A comprehensive Arduino project featuring **8 different light patterns** with 10 LEDs. Perfect for decorations, learning programming concepts, or just having fun!

## 🎬 Demo

<div align="center">
  
  *[Insert GIF or video of the light show here]*
  
</div>

## 📋 Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Light Effects](#light-effects)
- [Control Methods](#control-methods)
- [Code Structure](#code-structure)
- [Troubleshooting](#troubleshooting)
- [Advanced Projects](#advanced-projects)
- [Contributing](#contributing)
- [License](#license)

## ✨ Features

- **8 Unique Light Effects**
  - Knight Rider (Cylon) - Back and forth scanning
  - Wave - Progressive wave pattern
  - Random - Random LED blinking
  - Bounce - Ball bouncing effect
  - Fill and Clear - Sequential fill/clear
  - Alternating - Odd/even pattern
  - Firefly - Gentle random blinking
  - Dance Party - Complex multi-pattern

- **Multiple Control Options**
  - Automatic effect cycling
  - Serial monitor commands
  - Push button control
  - Potentiometer speed control

- **Adjustable Settings**
  - Speed control (30-500ms)
  - Auto effect change (every 30 seconds)
  - Real-time effect switching

## 🧱 Hardware Requirements

### Essential Components

| Component | Quantity | Specifications |
|-----------|----------|----------------|
| Arduino Uno R3 | 1 | Any compatible board |
| LEDs (any color) | 10 | 3mm or 5mm |
| Resistors | 10 | 220Ω - 330Ω |
| Breadboard | 1 | 400 or 830 points |
| Jumper Wires (M-M) | 20+ | Various colors |
| USB Cable | 1 | For programming |

### Optional Components

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Potentiometer | 1 | 10kΩ - speed control |
| Push Button | 1 | Change effects |
| External Power | 1 | 5V 1A for standalone |

## 🔌 Circuit Diagram

### Pin Connections

| LED Number | Arduino Pin | LED Color (Suggested) |
|------------|-------------|----------------------|
| LED 1 | Digital Pin 2 | Red |
| LED 2 | Digital Pin 3 | Orange |
| LED 3 | Digital Pin 4 | Yellow |
| LED 4 | Digital Pin 5 | Green |
| LED 5 | Digital Pin 6 | Blue |
| LED 6 | Digital Pin 7 | Indigo |
| LED 7 | Digital Pin 8 | Violet |
| LED 8 | Digital Pin 9 | White |
| LED 9 | Digital Pin 10 | Pink |
| LED 10 | Digital Pin 11 | Cyan |

### Optional Controls

| Component | Arduino Pin |
|-----------|-------------|
| Potentiometer (middle) | A0 |
| Potentiometer (outer) | 5V & GND |
| Push Button | Pin 12 |

### Wiring Diagram
