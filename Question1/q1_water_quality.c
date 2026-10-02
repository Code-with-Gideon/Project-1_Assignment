#include <stdio.h>
#include <stdlib.h>

// Function to classify water quality
void classify_water(int index) {
    if (index >= 80) {
        printf("Water Quality Status: Good\n");
    } else if (index >= 60 && index < 80) {
        printf("Water Quality Status: Warning\n");
    } else {
        printf("Water Quality Status: Critical\n");
    }
}

int main() {
    float temperature = 28.5; // Example temperature in Celsius
    float turbidity = 12.0;   // Example turbidity in NTU

    // Calculate index components
    float temp_dev = temperature - 25.0;
    if (temp_dev < 0) {
        temp_dev = -temp_dev; // manual absolute value
    }

    float turbidity_penalty = turbidity / 2.0;

    // Calculate Water Quality Index
    int index = 100 - (int)(temp_dev + turbidity_penalty);

    // Print report
    printf("===== Water Quality Monitoring Report =====\n");
    printf("Temperature Reading: %.2f C\n", temperature);
    printf("Turbidity Reading: %.2f NTU\n", turbidity);
    printf("Calculated Index: %d\n", index);
    
    classify_water(index);

    return 0;
}