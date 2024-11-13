# stm32_with_acs758
 
Current Sensor with STM32 Blue Pill and Low-Pass Filter
This project utilizes an STM32 Blue Pill microcontroller to accurately measure current using a Hall Effect sensor. A low-pass filter has been integrated to stabilize sensor readings, reducing noise and ensuring precise measurements even at higher currents.

Key Features
Microcontroller: STM32 Blue Pill, leveraging 12-bit ADC for enhanced resolution.
Sensor: Hall Effect current sensor for non-intrusive and real-time current measurement.
Low-Pass Filter: Hardware filter implemented to minimize noise and stabilize data.
Quiescent Voltage Auto-Calibration: The system automatically measures and adjusts the baseline (quiescent) voltage at startup for improved accuracy.
User-Friendly Output: Voltage and current data displayed via Serial Monitor for easy monitoring.
Technical Details
Microcontroller ADC: 12-bit resolution for better accuracy.
Power Supply: 3.3V for STM32 with stabilized readings.
Sampling: Averaging method applied for smooth and consistent current readings.
Sensitivity Configurable: Easily adjust sensitivity based on your Hall Effect sensor type.
This setup is ideal for applications requiring accurate current sensing in embedded systems and IoT projects.

