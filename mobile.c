#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PHONES 100
#define FILE_NAME "1.txt"
typedef struct {
    char brand[20];
    char model[20];
    int ram;
    int internal_storage;
    int external_storage;
    int sims;
    int battery_capacity;
    char processor[20];
    int main_camera_resolution;
    int year_of_introduction;
    char colors[20];
} Phone;

Phone phones[MAX_PHONES];

void addPhone(int count) {
    printf("Enter brand: ");
    scanf("%s", phones[count].brand);
    printf("Enter model: ");
    scanf("%s", phones[count].model);
    printf("Enter RAM: ");
    scanf("%d", &phones[count].ram);
    printf("Enter internal storage: ");
    scanf("%d", &phones[count].internal_storage);
    printf("Enter external storage: ");
    scanf("%d", &phones[count].external_storage);
    printf("Enter number of SIMs: ");
    scanf("%d", &phones[count].sims);
    printf("Enter battery capacity: ");
    scanf("%d", &phones[count].battery_capacity);
    printf("Enter processor: ");
    scanf("%s", phones[count].processor);
    printf("Enter main camera resolution: ");
    scanf("%d", &phones[count].main_camera_resolution);
    printf("Enter year of introduction: ");
    scanf("%d", &phones[count].year_of_introduction);
    printf("Enter colors: ");
    scanf("%s", phones[count].colors);
}

void searchPhones() {
    int count = 0;
    printf("Enter search criteria (Brand, Model, RAM, Internal Storage, External Storage, Number of SIMs, Battery Capacity, Processor, Main Camera Resolution, Year of Introduction, Colors): ");
    char search_criteria[20];
    scanf("%s", search_criteria);

    for (int i = 0; i < count; i++) {
        if (strcmp(search_criteria, phones[i].brand) == 0 ||
            strcmp(search_criteria, phones[i].model) == 0 ||
            phones[i].ram == atoi(search_criteria) ||
            phones[i].internal_storage == atoi(search_criteria) ||
            phones[i].external_storage == atoi(search_criteria) ||
            phones[i].sims == atoi(search_criteria) ||
            phones[i].battery_capacity == atoi(search_criteria) ||
            strcmp(search_criteria, phones[i].processor) == 0 ||
            phones[i].main_camera_resolution == atoi(search_criteria) ||
            phones[i].year_of_introduction == atoi(search_criteria) ||
            strcmp(search_criteria, phones[i].colors) == 0) {
            printf("Phone found: %s\n", phones[i].model);
            count++;
        }
    }
}

void comparePhones(int count) {
    for (int i = 0; i < count; i++) {
        Phone *phone1 = &phones[i];
        Phone *phone2 = &phones[i];

        if (strcmp(phone1->brand, phone2->brand) != 0 ||
            strcmp(phone1->model, phone2->model) != 0 ||
            phone1->ram != phone2->ram ||
            phone1->internal_storage != phone2->internal_storage ||
            phone1->external_storage != phone2->external_storage ||
            phone1->sims != phone2->sims ||
            phone1->battery_capacity != phone2->battery_capacity ||
            strcmp(phone1->processor, phone2->processor) != 0 ||
            phone1->main_camera_resolution != phone2->main_camera_resolution ||
            phone1->year_of_introduction != phone2->year_of_introduction ||
            strcmp(phone1->colors, phone2->colors) != 0) {
            printf("Feature differences:\n");
            printf("- RAM: %d vs %d\n", phone1->ram, phone2->ram);
            printf("- Internal Storage: %d vs %d\n", phone1->internal_storage, phone2->internal_storage);
            printf("- External Storage: %d vs %d\n", phone1->external_storage, phone2->external_storage);
            printf("- Number of SIMs: %d vs %d\n", phone1->sims, phone2->sims);
            printf("- Battery Capacity: %d vs %d\n", phone1->battery_capacity, phone2->battery_capacity);
            printf("- Processor: %s vs %s\n", phone1->processor, phone2->processor);
            printf("- Main Camera Resolution: %d vs %d\n", phone1->main_camera_resolution, phone2->main_camera_resolution);
            printf("- Year of Introduction: %d vs %d\n", phone1->year_of_introduction, phone2->year_of_introduction);
            printf("- Colors: %s vs %s\n", phone1->colors, phone2->colors);
        }
    }
}

void printPhones(int count) {
    for (int i = 0; i < count; i++) {
        printf("Phone Model: %s\n", phones[i].model);
        printf("Brand: %s\n", phones[i].brand);
        printf("RAM: %d\n", phones[i].ram);
        printf("Internal Storage: %d\n", phones[i].internal_storage);
        printf("External Storage: %d\n", phones[i].external_storage);
        printf("Number of SIMs: %d\n", phones[i].sims);
        printf("Battery Capacity: %d\n", phones[i].battery_capacity);
        printf("Processor: %s\n", phones[i].processor);
        printf("Main Camera Resolution: %d\n", phones[i].main_camera_resolution);
        printf("Year of Introduction: %d\n", phones[i].year_of_introduction);
        printf("Colors: %s\n", phones[i].colors);
        printf("\n");
    }
}

void printFeatures() {
    int count = 0;
    printf("Enter feature name (RAM, Internal Storage, External Storage, Number of SIMs, Battery Capacity, Processor, Main Camera Resolution, Year of Introduction, Colors): ");
    char feature_name[20];
    scanf("%s", feature_name);

    for (int i = 0; i < count; i++) {
        if (strcmp(feature_name, "RAM") == 0) {
            printf("Feature: %d\n", phones[i].ram);
        } else if (strcmp(feature_name, "Internal Storage") == 0) {
            printf("Feature: %d\n", phones[i].internal_storage);
        } else if (strcmp(feature_name, "External Storage") == 0) {
            printf("Feature: %d\n", phones[i].external_storage);
        } else if (strcmp(feature_name, "Number of SIMs") == 0) {
            printf("Feature: %d\n", phones[i].sims);
        } else if (strcmp(feature_name, "Battery Capacity") == 0) {
            printf("Feature: %d\n", phones[i].battery_capacity);
        } else if (strcmp(feature_name, "Processor") == 0) {
            printf("Feature: %s\n", phones[i].processor);
        } else if (strcmp(feature_name, "Main Camera Resolution") == 0) {
            printf("Feature: %d\n", phones[i].main_camera_resolution);
        } else if (strcmp(feature_name, "Year of Introduction") == 0) {
            printf("Feature: %d\n", phones[i].year_of_introduction);
        } else if (strcmp(feature_name, "Colors") == 0) {
            printf("Feature: %s\n", phones[i].colors);
        }
    }
}

int main() {
    int count;
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        fp = fopen(FILE_NAME, "wb");
        int count = 0;
        addPhone(count);
        fclose(fp);
        return 0;
    }

    while (fread(&phones[count], sizeof(Phone), 1, fp)) {
        count++;
    }

    int choice;
    while (1) {
        printf("1. Add phone model\n");
        printf("2. Search for phone models\n");
        printf("3. Compare phone models\n");
        printf("4. Print all phone models\n");
        printf("5. Print features of phone models\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPhone(count);
                break;
            case 2:
                searchPhones();
                break;
            case 3:
                comparePhones(count);
                break;
            case 4:
                printPhones(count);
                break;
            case 5:
                printFeatures();
                break;
            case 6:
                fclose(fp);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
