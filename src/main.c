#include <stdio.h>
#include <stdbool.h>
#include "person.h"
#include "processing.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Person p;
    Person young;
    bool first = true;


    while (fscanf(file, " %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %d; %d; %d; %d; %d; %[^;]; %[^\n]", 
           p.lastname, p.firstname, p.midname, p.gender, p.nationality, 
           &p.height, &p.weight, &p.birth.year, &p.birth.month, &p.birth.day, 
           p.phone, p.address) == 12) {
        
        if (first || FirstBiggerSecond(p.birth, young.birth)) {
            young = p;
            first = false;
        }
    }

    if (!first) {
        printf("Самый молодой человек: %s %s %s, Дата рождения: %02d.%02d.%d\n", 
               young.lastname, young.firstname, young.midname, 
               young.birth.day, young.birth.month, young.birth.year);
    } else {
        printf("Файл пуст или данные некорректны.\n");
    }

    fclose(file);
    return 0;
}
