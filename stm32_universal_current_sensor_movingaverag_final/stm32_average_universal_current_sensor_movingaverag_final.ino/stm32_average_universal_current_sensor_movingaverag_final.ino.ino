#define VIN PA2 
const float VCC = 3.331;
const int model = 0;
const int NUM_SAMPLES = 1; 
const int NUM_SAMPLES = 116; 
const int QUIESCENT_SAMPLE_COUNT = 30;  // Number of samples for quiescent voltage calculation
float cutOffLimit = 1.00;
float sensitivity[] = {40.0, 60.0, 20.0, 40.0, 13.3, 16.7, 10.0, 20.0};
float quiescent_Output_voltage = 0.0;  // Initialize to 0 for automatic calculation
float noise_threshold = 0.00;
float FACTOR = sensitivity[model] / 1000;
int samples[NUM_SAMPLES];
int sampleIndex = 0;
bool isQuiescentMeasured = false;  // Flag to check if quiescent voltage is measured

void setup() {
    Serial.begin(9600);
    analogReadResolution(12); 
    
    // Measure quiescent voltage
    float quiescentSum = 0.0;
    for (int i = 0; i < QUIESCENT_SAMPLE_COUNT; i++) {
        int reading = analogRead(VIN);
        quiescentSum += reading;
        delay(100);  // Small delay between readings
    }
    
    // Calculate the average quiescent voltage
    float averageQuiescentADC = quiescentSum / QUIESCENT_SAMPLE_COUNT;
    quiescent_Output_voltage = (VCC / 4096) * averageQuiescentADC;

    // Display the calculated quiescent voltage
    Serial.print("Calculated Quiescent Voltage: ");
    Serial.println(quiescent_Output_voltage, 3);
    isQuiescentMeasured = true;
}

void loop() {
    if (!isQuiescentMeasured) {
        // If the quiescent voltage is not measured, skip processing
        return;
    }

    // Add new reading to samples array (circular buffer)
    samples[sampleIndex] = analogRead(VIN);
    sampleIndex = (sampleIndex + 1) % NUM_SAMPLES;
    
    // Calculate the average of the samples for smoother data
    int sum = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        sum += samples[i];
    }
    float averageADC = (float)sum / NUM_SAMPLES;

    // Convert the 12-bit ADC reading to voltage
    float measured_voltage = (VCC / 4096) * averageADC;
    float voltage = measured_voltage - quiescent_Output_voltage;

    // Apply noise threshold to ignore small fluctuations
    if (abs(voltage) < noise_threshold) {
        voltage = 0;
    }

    // Calculate the current using the sensitivity factor
    float current = voltage / FACTOR;

    // Print the voltage and current readings
    Serial.print("Voltage: ");
    Serial.print(voltage, 3);
    Serial.print(" V, Current: ");
    Serial.print(current, 2);
    Serial.println(" A");

    delay(500);  // Delay for readability
}
