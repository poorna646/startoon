#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 1000

void find(double data[], int n) {
    
    printf("%-10s %-10s %-10s\n", "Index", "Type", "Value");
    
    for (int i = 1; i < n - 1; ++i) {
        if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
            printf("%-10d %-10s %-10.2f\n", i, "Peak", data[i]);
        } else if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
            printf("%-10d %-10s %-10.2f\n", i, "Trough", data[i]);
        }
    }
}

int main() {
    FILE *file = fopen("Data_1.txt", "r");
    if (!file) {
        printf("Unable to open the file");
    }

    double data[MAX_DATA_SIZE];
    int size = 0;

    // Read data into array
    while (size < MAX_DATA_SIZE && fscanf(file, "%lf", &data[size]) == 1) {
        size++;
    }
    fclose(file);

    find(data, size);

    return 0;
}
