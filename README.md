STM32 Blue Pill board Current Measurement with  Hall Effect Sensor
This project is designed to measure current using an STM32 Blue Pill board and a ACS758LCB-050B-PFF-T Hall Effect sensor. The setup incorporates a low-pass filter to minimize noise, ensuring stable readings. The system also features an automatic quiescent voltage calibration at startup to improve accuracy. The 12-bit ADC of the STM32 Blue Pill is used for precise data acquisition, making this project suitable for applications in embedded systems and IoT environments.

Table of Contents
Introduction
Hardware Components
Features
Circuit Diagram
Software Setup
Calibration Process
Usage
Code Explanation

Introduction
This project aims to provide a reliable and accurate method for current measurement using a Hall Effect sensor, interfaced with an STM32 Blue Pill microcontroller. The project uses a 12-bit ADC to ensure precise measurements and features an auto-calibration process for the quiescent voltage at startup. The low-pass filter connected to the sensor output reduces noise, making the readings more stable and accurate.

Hardware Components
STM32 Blue Pill - Microcontroller board with 12-bit ADC capabilities.
Hall Effect Current Sensor - Measures current flowing through a circuiti am using ACS758LCB-050B-PFF-T which can measure current ±50amps with sensitivity of 40mv/A
Low-Pass Filter - Consisting of a 3.3k ohm resistor and 0.1uf capacitor to filter high-frequency noise.
Power Supply - Provides a 5V source for the STM32 5v terminal and connecting sensor with stm32 3.3 v terminal.
Features
Accurate Current Measurement: Utilizes the STM32's 12-bit ADC for precision.
Noise Filtering: A low-pass filter is used to eliminate unwanted noise from the signal.
Auto-Calibration: Automatically determines the quiescent voltage (no-current baseline) during startup.

Circuit Diagram
The circuit consists of a Hall Effect sensor where it's vcc pin connected to the STM32 Blue Pill's 3.3 volt terminal and ground with gnd pin , with a low-pass filter consisting of a resistor where one terminal of it is connected with sensor output pin and other is connected to PA2 analog input pin and a 0.1uf capacitor connected between gnd and PA2 pin. 

Software Setup
Arduino IDE - Set up the Arduino IDE to program the STM32 Blue Pill.
Install the STM32 board package via Boards Manager.
Select generic STM32F1 series as the board and select bluePillf103c8.
Library - Use the default libraries for analog reading (no additional libraries are required).

Calibration Process
At startup, the code automatically takes multiple samples of the quiescent voltage when no current is flowing through the sensor. It averages these values to determine the baseline quiescent voltage, which is then used to calculate the actual current.

Usage
Connect the Hardware as per the circuit diagram.
Upload the Code to the STM32 Blue Pill using the Arduino IDE.
Open the Serial Monitor to see real-time current measurements. The system will auto-calibrate at startup to determine the baseline voltage.
The current and voltage values will be displayed, showing accurate readings after the calibration.
Code Explanation
The code reads voltage values from the Hall Effect sensor using the STM32's 12-bit ADC. It calculates the baseline quiescent voltage by averaging multiple samples at startup. The current is then computed using the difference between the measured voltage and the quiescent voltage, divided by the sensor's sensitivity. A low-pass filter helps reduce fluctuations in the readings.

Key code sections:

Auto-Calibration: Takes multiple quiescent voltage samples at startup.
Low-Pass Filtering: Uses a capacitor-resistor combination to stabilize the signal.
Voltage to Current Conversion: Employs the Hall Effect sensor's sensitivity to calculate the current.
