#include <stdio.h>

void updateSector(int grid[2][2]) {
    int row, col, choice;
    printf("Enter Row (0-1): ");
    scanf("%d", &row);
    printf("Enter Column (0-1): ");
    scanf("%d", &col);

    printf("\n1. Power ON\n2. Power OFF\n3. Set Overload\n4. Clear Overload\n5. Set Maintenance\n6. Clear Maintenance\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) grid[row][col] |= 1;      // Power ON
    else if (choice == 2) grid[row][col] &= ~1; // Power OFF
    else if (choice == 3) grid[row][col] |= 2;  // Overload ON
    else if (choice == 4) grid[row][col] &= ~2; // Overload OFF
    else if (choice == 5) grid[row][col] |= 4;  // Maintenance ON
    else if (choice == 6) grid[row][col] &= ~4; // Maintenance OFF
    else printf("Invalid choice!\n");
}

void querySector(int grid[2][2]) {
    int row, col;
    printf("Enter Row (0-1): ");
    scanf("%d", &row);
    printf("Enter Column (0-1): ");
    scanf("%d", &col);

    printf("\nSector (%d,%d) Status:\n", row, col);
    printf("Power: %s\n", (grid[row][col] & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (grid[row][col] & 2) ? "YES" : "NO");
    printf("Maintenance: %s\n", (grid[row][col] & 4) ? "YES" : "NO");
}

void diagnostic(int grid[2][2]) {
    int overload = 0, maintenance = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[i][j] & 2) overload++;
            if (grid[i][j] & 4) maintenance++;
        }
    }
    printf("\nSystem Diagnostic Report:\n");
    printf("Overloaded Sectors: %d\n", overload);
    printf("Maintenance Required: %d\n", maintenance);
}

int main() {
    int grid[2][2] = {0};
    int choice;

    do {
        printf("\n--- IESCO Power Grid System ---\n");
        printf("1. Update Sector\n2. Query Sector\n3. Run Diagnostic\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) updateSector(grid);
        else if (choice == 2) querySector(grid);
        else if (choice == 3) diagnostic(grid);
        else if (choice == 4) printf("Exiting System...\n");
        else printf("Invalid Choice!\n");
    } while (choice != 4);

    return 0;
}

