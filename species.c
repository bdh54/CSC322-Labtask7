// Program to keep track of species found in the jungle
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create a String
#define MAXSTRING 128
typedef char string[MAXSTRING];

//Define initial ArraySize

#define INITIALSIZE 1

//define the enum to be used for struct
typedef enum {
    mammal,
    insect,
    bird,
    fish
} animalType;

//defines the struct of each animal
typedef struct {
    string name;
    double size;
    animalType type;
} jungleAnimal;

//Malloc function
void * Malloc(size_t size) {

    void * Memory;

    if ((Memory = malloc(size)) == NULL) {
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    } else {
        return(Memory);
    }
}

//main function

int main(void) {

//declare local variables
    int size;
    int speciesCount;
    jungleAnimal *animalArray;
    string animalType;
    int index;

    size = INITIALSIZE;
    speciesCount = 0;

//Allocate initial memory
    animalArray = (jungleAnimal *)Malloc(size * sizeof(jungleAnimal));

    printf("> NewSpecies\n");
//Loop to get user input and realloc memory
    while(1) {
        if(size == speciesCount) {
            size *= 2;
            //realloc memory
            animalArray = (jungleAnimal *)realloc(animalArray,size * sizeof(jungleAnimal));
        }
    
//Get user input
        jungleAnimal animal;
        printf("Enter animal information (\"exit\" to exit)\n");
       
        printf("What is the name : ");
        scanf("%s", animal.name);

//Check if the user needs to exit
        if (strcmp(animal.name, "exit") == 0) {
            break;
        }

        printf("What is the size : ");
        scanf("%lf", &animal.size);

        printf("What is the type : ");
        scanf("%s", animalType);

//Make sure the type is one of the enums, then add it to the jungleAnimal struct
        if (strcmp(animalType, "mammal") == 0) {
            animal.type = mammal;
        } else if (strcmp(animalType, "insect") == 0) {
            animal.type = insect;
        } else if (strcmp(animalType, "bird") == 0) {
            animal.type = bird;
        } else if (strcmp(animalType, "fish") == 0) {
            animal.type = fish;
        }

//Add the new animal to the array
        animalArray[speciesCount] = animal;
        ++speciesCount;

    }

//Print out the array
printf("\nThe following new species were found: \n");

    for (index = 0; index < speciesCount; ++index) {
        printf("%-21s has size %6.2lf and is a ", animalArray[index].name, animalArray[index].size);

//if else to get the type
        if(animalArray[index].type == mammal) {
            printf("mammal\n");
        } else if(animalArray[index].type == insect) {
            printf("insect\n");
        } else if(animalArray[index].type == bird) {
            printf("bird\n");
        } else if(animalArray[index].type == fish) {
            printf("fish\n");
        }
}

//Free the memory
    free(animalArray);
    return(EXIT_SUCCESS);

}





