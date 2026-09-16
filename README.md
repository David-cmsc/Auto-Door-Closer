# Auto Door Closer

An ESP32-based system that automatically pulls a door shut using IR proximity sensing and a motor-driven cable mechanism; no manual push required.

## How it works

An IR proximity sensor watches the doorway. When it detects the door has been opened, the ESP32 reads the sensor state and triggers a motor to pull the door closed via a cable routed through a mounted hub, mechanically closing it without anyone touching the door.

## Hardware

**Current prototype**
- ESP32 (ESP-WROOM-32 dev board)
- IR proximity sensor
- TT gear motor + L298N motor driver (initial bench test rig)

**In progress — upgraded build**
- JGY-370 10 RPM worm gear motor (self-locking, higher torque — holds position without continuous power)
- TalentCell 12V rechargeable battery pack
- DC5521 power pigtail cable
- SpiderWire 30lb braided line (pull cable)
- goBILDA 6mm D-bore clamping hub

## Pin mapping

| Signal | ESP32 Pin |
|---|---|
| IR sensor | D15 |
| Servo / motor control | D13 |

## Status

 **Work in progress**

Current firmware reads and logs the IR sensor's raw digital value over serial, used to validate sensing behavior before wiring in motor control. The servo/motor-drive logic is scaffolded in the sketch but not yet active. The mechanical build has moved on from the initial TT gear motor test rig to the self-locking worm gear motor intended for the final pull mechanism.

## Setup

1. Arduino IDE 2.x with the ESP32 board package installed; select board **"ESP32 Dev Module"**
2. Install the `ESP32Servo` library (Library Manager)
3. Wire the IR sensor to D15 as described above
4. Flash `Door_proj.ino` and open the Serial Monitor at **115200 baud** to confirm sensor readings

## Roadmap

- [ ] Wire and activate the worm gear motor control logic
- [ ] Mount the pull mechanism (braided line + clamping hub) to a real door
- [ ] Add debounce/state logic so the door closes once per open event, not repeatedly
- [ ] Tune the IR sensor's detection range/threshold for reliable triggering

