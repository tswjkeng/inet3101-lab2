
#include <stdio.h>
#include <stdlib.h>

struct part {
    int partNumber;
    char partName[50];
    float partSize;
    char partSizeMetric[10];
    float partCost;
};

// Helper function to remove a newline character from a string.
void removeNewline(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

// Prints all records.
void printAllRecords(const struct part *database, int numRecords) {
    if (numRecords == 0) {
        printf("\nNo records to print.\n");
        return;
    }
    printf("\n--- All Records ---\n");
    for (int i = 0; i < numRecords; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Part Number: %d\n", database[i].partNumber);
        printf("Part Name: %s\n", database[i].partName);
        printf("Part Size: %.2f\n", database[i].partSize);
        printf("Metric: %s\n", database[i].partSizeMetric);
        printf("Part Cost: %.2f\n", database[i].partCost);
    }
}

// Add a record.
void addRecord(struct part **database, int *numRecords) {
    int newCount = *numRecords + 1;
    struct part *temp = realloc(*database, newCount * sizeof(struct part));
    if (temp == NULL) {
        printf("Memory allocation failed. Could not add new record.\n");
        return;
    }
    *database = temp;
    *numRecords = newCount;

    // Enter data for the new record.
    struct part *newPart = &((*database)[newCount - 1]);

    printf("Enter Part Number: ");
    scanf("%d", &newPart->partNumber);
    getchar();

    printf("Enter Part Name: ");
    fgets(newPart->partName, sizeof(newPart->partName), stdin);
    removeNewline(newPart->partName);

    printf("Enter Part Size (float): ");
    scanf("%f", &newPart->partSize);
    getchar();

    printf("Enter Part Size Metric: ");
    fgets(newPart->partSizeMetric, sizeof(newPart->partSizeMetric), stdin);
    removeNewline(newPart->partSizeMetric);

    printf("Enter Part Cost (float): ");
    scanf("%f", &newPart->partCost);
    getchar();

    printf("\nRecord added successfully.\n");
}

// Delete the last record.
void deleteLastRecord(struct part **database, int *numRecords) {
    if (*numRecords == 0) {
        printf("No records to delete.\n");
        return;
    }
    
    int newCount = *numRecords - 1;
    struct part *temp = NULL;

    // If records remain, reallocate memory otherwise, free it.
    if (newCount > 0) {
        temp = realloc(*database, newCount * sizeof(struct part));
        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            return;
        }
    }
    
    *database = temp;
    *numRecords = newCount;
    printf("\nLast record deleted. Total records now: %d\n", newCount);
}

int main(void) {
    struct part *database = NULL; // Pointer to our dynamic array of parts.
    int numRecords = 0;           // Number of records in our database.
    int choice = 0;               // User's menu choice.
    int running = 1;              // Controls the main loop.

    while (running) {
        printf("\nMENU\n");
        printf("=====\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database (bytes)\n");
        printf("4. Add record\n");
        printf("5. Delete last record\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printAllRecords(database, numRecords);
                break;
            case 2:
                printf("\nNumber of records: %d\n", numRecords);
                break;
            case 3:
                printf("\nDatabase size in bytes: %lu\n",
                       (unsigned long)(numRecords * sizeof(struct part)));
                break;
            case 4:
                addRecord(&database, &numRecords);
                break;
            case 5:
                deleteLastRecord(&database, &numRecords);
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    free(database);
    database = NULL;

    return 0;
}
