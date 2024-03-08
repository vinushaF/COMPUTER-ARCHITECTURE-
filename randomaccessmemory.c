#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {0}, i, index, value, choice;
    
    do {
        printf("\nRandom Access Memory (RAM) Operations\n1. Write to RAM\n2. Read from RAM\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index (0 to %d): ", SIZE - 1);
                scanf("%d", &index);
                if (index >= 0 && index < SIZE) {
                    printf("Enter value to write: ");
                    scanf("%d", &value);
                    arr[index] = value;
                    printf("Value written to RAM.\n");
                } else printf("Invalid index. Please enter a valid index.\n");
                break;
            case 2:
                printf("Enter index (0 to %d): ", SIZE - 1);
                scanf("%d", &index);
                if (index >= 0 && index < SIZE)
                    printf("Value at index %d: %d\n", index, arr[index]);
                else printf("Invalid index. Please enter a valid index.\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 3);
    
    return 0;
}
