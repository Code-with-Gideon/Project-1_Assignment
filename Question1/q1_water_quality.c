#include <stdio.h>
#include <math.h>

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

    // Using fabs() from math.h because Temperature is a float. 
    // Using standard abs() from stdlib.h would truncate decimals.
    float temp_deviation = fabs(temperature - 25.0);
    float turbidity_penalty = turbidity / 2.0;

    int index = 100 - (int)(temp_deviation + turbidity_penalty);

    printf("===== Water Quality Monitoring Report =====\n");
    printf("Temperature Reading: %.2f C\n", temperature);
    printf("Turbidity Reading: %.2f NTU\n", turbidity);
    printf("Calculated Index: %d\n", index);
    
    classify_water(index);

    return 0;
}
