#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100

int virtual_memory[MEMORY_SIZE];

void write_to_memory(int address, int value) {
    if (address >= 0 && address < MEMORY_SIZE) {
        virtual_memory[address] = value;
        printf("Value %d written to address %d\n", value, address);
    } else printf("Error: Address out of bounds!\n");
}

int read_from_memory(int address) {
    if (address >= 0 && address < MEMORY_SIZE) {
        printf("Value at address %d: %d\n", address, virtual_memory[address]);
        return virtual_memory[address];
    } else {
        printf("Error: Address out of bounds!\n");
        return -1;
    }
}

int main() {
    int choice, address, value;
    printf("Welcome to Virtual Memory System\n");

    do {
        printf("\n1. Read from memory\n2. Write to memory\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter address to read from: ");
                scanf("%d", &address);
                read_from_memory(address);
                break;
            case 2:
                printf("Enter address to write to: ");
                scanf("%d", &address);
                printf("Enter value to write: ");
                scanf("%d", &value);
                write_to_memory(address, value);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
