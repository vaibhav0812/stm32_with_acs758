#define VIN PA2 
const float VCC = 3.331;
const int model = 0;
const int NUM_SAMPLES = 1; 
float cutOffLimit = 1.00;
float sensitivity[] = {40.0, 60.0, 20.0, 40.0, 13.3, 16.7, 10.0, 20.0};
float quiescent_Output_voltage = 2.486;
float noise_threshold = 0.00;
float FACTOR = sensitivity[model] / 1000;
int samples[NUM_SAMPLES];
int sampleIndex = 0;

void setup() {
    Serial.begin(9600);
    analogReadResolution(12); 
}

void loop() {
    // Add new reading to samples array (circular buffer)
    samples[sampleIndex] = analogRead(VIN);
    sampleIndex = (sampleIndex + 1) % NUM_SAMPLES;
    
   
    int sum = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        sum += samples[i];
    }
    float averageADC = (float)sum / NUM_SAMPLES;

   
    float measured_voltage = (VCC / 4096) * averageADC;
    float voltage = measured_voltage - quiescent_Output_voltage;


    if (abs(voltage) < noise_threshold) {
        voltage = 0;
    }

   
    float current = voltage / FACTOR;

  
    Serial.print("Voltage: ");
    Serial.print(voltage, 3);
    Serial.print(" V, Current: ");
    Serial.print(current, 2);
    Serial.println(" A");
    
    delay(500); 
}

