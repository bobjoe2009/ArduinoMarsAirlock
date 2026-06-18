# Mars Airlock Security System

A sci-fi inspired Arduino project that simulates a secure Mars colony airlock. The system operates in three different security modes and uses a servo motor, LCD display, and LED indicators to communicate the current status of the airlock.

## Features

- Safe Mode
  - Green LED
  - Airlock remains open
  - LCD displays "SAFE"

- Invasion Alert Mode
  - Yellow LED
  - Airlock prepares for lockdown
  - LCD displays "INVASION ALERT"

- Total Lockdown Mode
  - Red LED
  - Airlock closes completely
  - LCD displays "TOTAL LOCKDOWN"

## Components Used

- Arduino Uno
- Servo Motor
- LCD 1602 Display
- Green LED
- Yellow LED
- Red LED
- Breadboard
- Jumper Wires

## How It Works

The system cycles through three security states:

1. Safe
   - Normal operation.
   - Green status indicator is active.

2. Invasion Alert
   - Potential threat detected.
   - Yellow warning indicator activates.

3. Total Lockdown
   - Emergency mode.
   - Red indicator activates and the airlock closes.

The LCD display continuously updates to show the current status of the airlock.

## Images

### Full System
![System Overview](images/overview.jpg)

### Safe Mode
![Safe Mode](images/safe.jpg)

### Invasion Alert
![Alert Mode](images/alert.jpg)

### Total Lockdown
![Lockdown Mode](images/lockdown.jpg)

## Code

The Arduino source code can be found in the `code` folder.

## Inspiration

This project was inspired by airlock systems commonly seen in science fiction and space exploration concepts.

## Future Improvements

- Keypad authentication
- RFID access control
- Sound effects and alarms
- Automatic threat detection
- Data logging system

## Author

Bobjoe2009
