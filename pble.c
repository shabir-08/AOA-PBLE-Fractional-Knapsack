#include <stdio.h>

#define MAX 100

struct Package {
    int id;
    float value;
    float weight;
    float ratio;
    float fraction;
};

struct Package packages[MAX];
int n = 0;
float capacity = 0;

void enterPackageDetails() {
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        packages[i].id = i + 1;

        printf("\nPackage %d\n", i + 1);

        printf("Enter value/profit: ");
        scanf("%f", &packages[i].value);

        printf("Enter weight: ");
        scanf("%f", &packages[i].weight);

        if (packages[i].weight <= 0) {
            printf("Weight must be greater than 0.\n");
            i--;
            continue;
        }

        packages[i].ratio = 0;
        packages[i].fraction = 0;
    }

    printf("\nEnter vehicle capacity: ");
    scanf("%f", &capacity);

    printf("\nPackage details entered successfully!\n");
}

void displayPackages() {
    int i;

    if (n == 0) {
        printf("\nNo package details available.\n");
        return;
    }

    printf("\n%-10s %-12s %-12s %-15s\n",
           "Package", "Value", "Weight", "Ratio");

    for (i = 0; i < n; i++) {
        printf("%-10d %-12.2f %-12.2f %-15.2f\n",
               packages[i].id,
               packages[i].value,
               packages[i].weight,
               packages[i].ratio);
    }

    printf("\nVehicle Capacity: %.2f\n", capacity);
}

void calculateRatio() {
    int i;

    if (n == 0) {
        printf("\nNo packages available.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        packages[i].ratio =
            packages[i].value / packages[i].weight;
    }

    printf("\nValue/Weight ratios calculated successfully.\n");

    printf("\n%-10s %-12s %-12s %-15s\n",
           "Package", "Value", "Weight", "Ratio");

    for (i = 0; i < n; i++) {
        printf("%-10d %-12.2f %-12.2f %-15.2f\n",
               packages[i].id,
               packages[i].value,
               packages[i].weight,
               packages[i].ratio);
    }
}

void sortPackages() {
    int i, j;
    struct Package temp;

    if (n == 0) {
        printf("\nNo packages available.\n");
        return;
    }

    // Calculate ratios if not already calculated
    for (i = 0; i < n; i++) {
        packages[i].ratio =
            packages[i].value / packages[i].weight;
    }

    // Bubble Sort in decreasing order of ratio
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            if (packages[j].ratio < packages[j + 1].ratio) {
                temp = packages[j];
                packages[j] = packages[j + 1];
                packages[j + 1] = temp;
            }
        }
    }

    printf("\nPackages sorted by decreasing Value/Weight ratio.\n");

    printf("\n%-10s %-12s %-12s %-15s\n",
           "Package", "Value", "Weight", "Ratio");

    for (i = 0; i < n; i++) {
        printf("%-10d %-12.2f %-12.2f %-15.2f\n",
               packages[i].id,
               packages[i].value,
               packages[i].weight,
               packages[i].ratio);
    }
}

float findMaximumValue() {
    int i;
    float remainingCapacity = capacity;
    float totalValue = 0;

    if (n == 0) {
        printf("\nNo packages available.\n");
        return 0;
    }

    // Ensure packages are sorted
    sortPackages();

    // Reset fractions
    for (i = 0; i < n; i++) {
        packages[i].fraction = 0;
    }

    for (i = 0; i < n; i++) {

        if (remainingCapacity <= 0)
            break;

        if (packages[i].weight <= remainingCapacity) {

            // Take complete package
            packages[i].fraction = 1.0;

            remainingCapacity -= packages[i].weight;
            totalValue += packages[i].value;
        }
        else {

            // Take fractional part
            packages[i].fraction =
                remainingCapacity / packages[i].weight;

            totalValue +=
                packages[i].value * packages[i].fraction;

            remainingCapacity = 0;
        }
    }

    return totalValue;
}

void displaySelectedPackages() {
    int i;
    float remainingCapacity = capacity;
    float totalValue = 0;
    float usedWeight = 0;

    if (n == 0) {
        printf("\nNo packages available.\n");
        return;
    }

    // Sort packages before selection
    sortPackages();

    for (i = 0; i < n; i++) {
        packages[i].fraction = 0;
    }

    printf("\n%-10s %-15s %-15s %-15s\n",
           "Package", "Fraction", "Weight Used", "Value Obtained");

    for (i = 0; i < n; i++) {

        if (remainingCapacity <= 0)
            break;

        if (packages[i].weight <= remainingCapacity) {

            packages[i].fraction = 1.0;

            remainingCapacity -= packages[i].weight;

            usedWeight += packages[i].weight;
            totalValue += packages[i].value;

            printf("%-10d %-15.2f %-15.2f %-15.2f\n",
                   packages[i].id,
                   packages[i].fraction,
                   packages[i].weight,
                   packages[i].value);
        }
        else {

            packages[i].fraction =
                remainingCapacity / packages[i].weight;

            float weightUsed =
                remainingCapacity;

            float valueObtained =
                packages[i].value * packages[i].fraction;

            usedWeight += weightUsed;
            totalValue += valueObtained;

            printf("%-10d %-15.2f %-15.2f %-15.2f\n",
                   packages[i].id,
                   packages[i].fraction,
                   weightUsed,
                   valueObtained);

            remainingCapacity = 0;
        }
    }

    printf("\nTotal weight used : %.2f", usedWeight);
    printf("\nMaximum value     : %.2f\n", totalValue);
}

int main() {
    int choice;

    do {
        printf("\n========================================");
        printf("\n SMART DELIVERY PLANNING");
        printf("\n FRACTIONAL KNAPSACK");
        printf("\n========================================");

        printf("\n1. Enter Package Details");
        printf("\n2. Display Package Details");
        printf("\n3. Calculate Value/Weight Ratio");
        printf("\n4. Sort Packages by Ratio");
        printf("\n5. Find Maximum Value");
        printf("\n6. Display Selected Packages");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                enterPackageDetails();
                break;

            case 2:
                displayPackages();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5: {
                float maxValue = findMaximumValue();
                printf("\nMaximum value that can be carried: %.2f\n",
                       maxValue);
                break;
            }

            case 6:
                displaySelectedPackages();
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}