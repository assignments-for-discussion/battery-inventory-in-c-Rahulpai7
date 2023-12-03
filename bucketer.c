#include <stdio.h>

typedef struct {
    int healthy;
    int exchange;
    int failed;
} CountsBySoH;

CountsBySoH countBatteriesByHealth(int currentCapacities[], int numBatteries) {
    CountsBySoH counts = {0, 0, 0}; // initialze  each of the type of condition of battery to 0
    int ratedCapacity = 120; 

    for (int i=0;i<numBatteries;i++) {
        float soh =((float)currentCapacities[i]/ratedCapacity)*100;  

        if (soh > 80) 
        { //if its soh is >80 then healthy
            counts.healthy++;
        } 
        else if (soh >= 62 && soh <= 80) 
        { //if in between 62 to 80 requires replacement
            counts.exchange++;
        } 
        else 
        { //if below 62 then failure of engine will happen
            counts.failed++;
        }
    }

    return counts;
}

void testBucketingByHealth() {
    printf("Counting batteries by SoH...\n\n");

    
    //EXTRA TEST CASES
/*
    // Check counts_empty values
    int currentCapacities[] = {};
    int numBatteries_empty = 0;
    CountsBySoH counts_empty = countBatteriesByHealth(currentCapacities_empty, numBatteries_empty);

    // Check counts_max values
    int currentCapacities[] = {1e9}; // the maximum value for battery capacity ie 1e9
    int numBatteries = sizeof(currentCapacities) / sizeof(currentCapacities[0]);
    CountsBySoH counts = countBatteriesByHealth(currentCapacities, numBatteries);

    // Check counts_min values
    int currentCapacities[] = {0}; //  minimum value for battery capacity can be 0 not negative
    int numBatteries = sizeof(currentCapacities) / sizeof(currentCapacities[0]);
    CountsBySoH counts= countBatteriesByHealth(currentCapacities, numBatteries);

      // Check counts_equal values
    int currentCapacities_equal[] = {80, 80, 80, 80, 80}; // All capacities are equal
    int numBatteries_equal = sizeof(currentCapacities) / sizeof(currentCapacities[0]);
    CountsBySoH counts_equal = countBatteriesByHealth(currentCapacities, numBatteries);
  */
    
    int currentCapacities[] = {113, 116, 80, 95, 92, 70};
    int numBatteries = sizeof(currentCapacities) / sizeof(currentCapacities[0]);

    CountsBySoH counts = countBatteriesByHealth(currentCapacities, numBatteries);
    
   //used printf instead of assert
    printf("Healthy Count: %d\n", counts.healthy);
    printf("Exchange Count: %d\n", counts.exchange);
    printf("Failed Count: %d\n", counts.failed);

    printf("\nDone counting :)\n");
}

int main() {
    testBucketingByHealth();
    return 0;
}
