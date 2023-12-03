#include <stdio.h>

typedef struct {
    int healthy;
    int exchange;
    int failed;
} CountsBySoH;

CountsBySoH countBatteriesByHealth(int currentCapacities[], int numBatteries) {
    CountsBySoH counts = {0, 0, 0};
    int ratedCapacity = 120; 

    for (int i = 0; i < numBatteries; i++) {
        float soh = ((float)currentCapacities[i] / ratedCapacity) * 100;  

        if (soh > 80) {
            counts.healthy++;
        } else if (soh >= 62 && soh <= 80) {
            counts.exchange++;
        } else {
            counts.failed++;
        }
    }

    return counts;
}

void newcases() {
    int currentCapacities_empty[] = {};
    int numBatteries_empty = 0;
    CountsBySoH counts_empty = countBatteriesByHealth(currentCapacities_empty, numBatteries_empty);

    printf("Healthy Count: %d\n", counts_empty.healthy);
    printf("Exchange Count: %d\n", counts_empty.exchange);
    printf("Failed Count: %d\n", counts_empty.failed);

    int currentCapacities_max[] = {1000000000};
    int numBatteries_max = sizeof(currentCapacities_max) / sizeof(currentCapacities_max[0]);
    CountsBySoH counts_max = countBatteriesByHealth(currentCapacities_max, numBatteries_max);
 
    printf("Healthy Count: %d\n", counts_max.healthy);
    printf("Exchange Count: %d\n", counts_max.exchange);
    printf("Failed Count: %d\n", counts_max.failed);

    int currentCapacities_min[] = {0};
    int numBatteries_min = sizeof(currentCapacities_min) / sizeof(currentCapacities_min[0]);
    CountsBySoH counts_min = countBatteriesByHealth(currentCapacities_min, numBatteries_min);
  
    printf("Healthy Count: %d\n", counts_min.healthy);
    printf("Exchange Count: %d\n", counts_min.exchange);
    printf("Failed Count: %d\n", counts_min.failed);

    int currentCapacities_equal[] = {80, 80, 80, 80, 80};
    int numBatteries_equal = sizeof(currentCapacities_equal) / sizeof(currentCapacities_equal[0]);
    CountsBySoH counts_equal = countBatteriesByHealth(currentCapacities_equal, numBatteries_equal);
    
    printf("Healthy Count: %d\n", counts_equal.healthy);
    printf("Exchange Count: %d\n", counts_equal.exchange);
    printf("Failed Count: %d\n", counts_equal.failed);
}

void testBucketingByHealth() {
    printf("Counting batteries by SoH...\n\n");
    int currentCapacities[] = {113, 116, 80, 95, 92, 70};
    int numBatteries = sizeof(currentCapacities) / sizeof(currentCapacities[0]);

    CountsBySoH counts = countBatteriesByHealth(currentCapacities, numBatteries);
    
    printf("Healthy Count: %d\n", counts.healthy);
    printf("Exchange Count: %d\n", counts.exchange);
    printf("Failed Count: %d\n", counts.failed);

    printf("\nDone counting :)\n");
}

int main() {
    testBucketingByHealth();
    newcases();
    return 0;
}

