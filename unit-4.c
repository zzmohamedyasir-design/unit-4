#include <stdio.h>
#include <string.h>

struct Vehicle {
    int id;
    char name[50];
    char brand[50];
    int type;
    int seats;
    int available;
};

struct Vehicle v[100];
int count = 0;

void addVehicle() {
    printf("Enter Vehicle ID: ");
    scanf("%d", &v[count].id);

    printf("Enter Vehicle Name: ");
    scanf(" %49[^\n]", v[count].name);

    printf("Enter Brand: ");
    scanf(" %49[^\n]", v[count].brand);

    printf("Select Vehicle Type:\n1. Car\n2. Bike\n");
    printf("Enter choice: ");
    scanf("%d", &v[count].type);

    if (v[count].type == 1) {
        printf("Enter Number of Seats: ");
        scanf("%d", &v[count].seats);
    } else {
        v[count].seats = 0;
    }

    v[count].available = 1;
    count++;

    printf("Vehicle Added Successfully!\n");
}

void displayVehicles() {
    int i;
    if (count == 0) {
        printf("No Vehicles Found!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nBrand: %s\n",
               v[i].id, v[i].name, v[i].brand);
        printf("Type: %s\n",
               v[i].type == 1 ? "Car" : "Bike");
        if (v[i].type == 1)
            printf("Seats: %d\n", v[i].seats);

        printf("Status: %s\n",
               v[i].available ? "Available" : "Rented");
    }
}

void searchVehicle() {
    int id, i;
    printf("Enter Vehicle ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (v[i].id == id) {
            printf("Vehicle Name: %s\n", v[i].name);
            printf("Brand: %s\n", v[i].brand);
            printf("Type: %s\n",
                   v[i].type == 1 ? "Car" : "Bike");
            printf("Status: %s\n",
                   v[i].available ? "Available" : "Rented");
            return;
        }
    }
    printf("Vehicle Not Found!\n");
}

void rentVehicle() {
    int id, i;
    printf("Enter Vehicle ID to Rent: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (v[i].id == id) {
            if (v[i].available) {
                v[i].available = 0;
                printf("Vehicle Rented Successfully!\n");
            } else {
                printf("Vehicle Already Rented!\n");
            }
            return;
        }
    }
    printf("Vehicle Not Found!\n");
}

void returnVehicle() {
    int id, i;
    printf("Enter Vehicle ID to Return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (v[i].id == id) {
            if (!v[i].available) {
                v[i].available = 1;
                printf("Vehicle Returned Successfully!\n");
            } else {
                printf("Vehicle Is Already Available!\n");
            }
            return;
        }
    }
    printf("Vehicle Not Found!\n");
}

void displayAvailable() {
    int i, found = 0;

    for (i = 0; i < count; i++) {
        if (v[i].available) {
            printf("\nID: %d\nName: %s\nBrand: %s\n",
                   v[i].id, v[i].name, v[i].brand);
            found = 1;
        }
    }

    if (!found)
        printf("No Available Vehicles!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== VEHICLE RENTAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Vehicle\n");
        printf("2. Display All Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Rent Vehicle\n");
        printf("5. Return Vehicle\n");
        printf("6. Display Available Vehicles\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: displayVehicles(); break;
            case 3: searchVehicle(); break;
            case 4: rentVehicle(); break;
            case 5: returnVehicle(); break;
            case 6: displayAvailable(); break;
            case 7: printf("Thank You!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}