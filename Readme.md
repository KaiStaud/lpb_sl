# How to Run
Current Software is developed in three stages:
C++ Development in CMake Suite
Cross Compilation with Buildroot CrossCompiler
Intergration into Custom Embedded Linux Image with Conan into Buildroot

To run the finished Software run "./lpbsl tcp"

# Logging

# Machine modes

# Data storage

# IK

# MQTT Interface

# Pinout
Used Pinout on Rasberry PI 4.
SPI6 needs to be enabled with provided device tree overlay.
| #  | Pin       | # Header Pin | GPIO   |       Peripheral         |
|----|-----------|--------------|--------|--------------------------|
| 1  | I2C1.SDA  | 3            | GPIO2  |Graphic LCD               |
| 2  | I2C2.SCL  | 5            | GPIO3  |Graphic LCD               |
| 3  | A0        |              |        |Graphic LCD               |
| 4  | ~RD       |              |        |Graphic LCD               |
| 5  | ~WR       |              |        |Graphic LCD               |
| 6  | I2C2.SDA  | 27           | GPIO00 |Amp,LED,ADC               |
| 7  | I2C2.SCL  | 28           | GPIO07 |Amp,LED,ADC               |
| 8  | SPI0.MISO | 21           | GPIO09 |CAN1                      |
| 9  | SPI0.MOSI | 19           | GPIO10 |CAN1                      |
| 10 | SPI0.SCK  | 23           | GPIO11 |CAN1                      |
| 11 | SPI0.CS   | 24           | GPIO8  |CAN1                      |
| 12 | SPI0.INT  | 26           | GPIO7  |CAN1                      |
| 13 | SPI6.MISO | 35           |        |CAN2                      |
| 14 | SPI6.MOSI | 38           |        |CAN2                      |
| 15 | SPI6.SCK  | 40           |        |CAN2                      |
| 16 | SPI6.CS2  | 12           |        |CAN2                      |
| 17 | SPI6.INT2 |              |        |CAN2                      |
| 18 | UART.TX   | 12           |        |Kernel Early Boot Console |
| 19 | UART.RX   |              |        |Kernel Early Boot Console |
| 20 | ENC1.A    |              |        |Encoder 1                 |
| 21 | ENC1.~A   |              |        |Encoder 1                 |
| 22 | ENC1.PB   |              |        |Encoder 1                 |
| 23 | ENC2.A    |              |        |Encoder 2                 |
| 24 | ENC2.~A   |              |        |Encoder 2                 |  
| 25 | ENC2.~PB  |              |        |Encoder 2                 |

# Statusleds
| # | name        | blink rate     | description                                    |   |
|---|-------------|----------------|------------------------------------------------|---|
| 1 | run         | 1 Hz,2 Hz,3 Hz | sw is running, configuring, downloading config |   |
| 2 | can-err     | 1 Hz, 2 Hz     | general error,not initialized                  |   |
| 3 | tx overflow |                | message couldn't be sent, no space in queue    |   |
| 4 | rx error    | 2 Hz           | lost message, error frame                      |   |
| 5 | i/o error   |                |                                                |   |