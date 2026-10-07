#include <stdio.h>
#include <stdlib.h>

/* Forward declarations */
int compute_index(int temperature, int turbidity);
const char *classify_water(int index);

/*
 * compute_index - calculate the water-quality index.
 *
 * Formula:
 *   TemperatureDeviation = abs(temperature - 25)
 *   TurbidityPenalty     = turbidity / 2
 *   Index = 100 - (TemperatureDeviation + TurbidityPenalty)
 */
int compute_index(int temperature, int turbidity)
{
    int temp_deviation = abs(temperature - 25);
    int turbidity_penalty = turbidity / 2;

    return 100 - (temp_deviation + turbidity_penalty);
}

/*
 * classify_water - return a qualitative status string for the given index.
 *
 *   Index >= 80  -> "Good"
 *   60 <= Index < 80  -> "Warning"
 *   Index < 60  -> "Critical"
 */
const char *classify_water(int index)
{
    if (index >= 80)
        return "Good";
    else if (index >= 60)
        return "Warning";
    else
        return "Critical";
}

int main(void)
{
    /* Sensor readings (degrees C, NTU) */
    int temperature = 20;
    int turbidity   = 6;

    int index = compute_index(temperature, turbidity);
    const char *status = classify_water(index);

    printf("=== Water Quality Monitoring Report ===\n");
    printf("Temperature reading : %d C\n", temperature);
    printf("Turbidity reading   : %d NTU\n", turbidity);
    printf("Water Quality Index : %d\n", index);
    printf("Water Quality Status: %s\n", status);
    printf("========================================\n");

    return 0;
}
