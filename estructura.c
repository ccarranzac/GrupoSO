#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

struct dogType{
	char nombre[32];
	char tipo[32];
	int edad;
	char raza[16];
	int estatura;
	float peso;
	char genero;
	int hash_id;
};

int hash(char nombre[32]){
	unsigned int hash = 5381;
	int c;

	while(c = *nombre++){
		hash = ((hash << 5) + hash) + c;
	}
	hash = hash % 1000;
	return hash;
}

int randomNumber(int size){
	int randomNumber;
	randomNumber = rand() % size;
	return randomNumber;
}

void fillStruct(){
	struct dogType *dog;
	dog = (struct dogType*)malloc(sizeof(struct dogType));
	char buffer[32];
	FILE *fp;
	FILE *dogData;

	fp = fopen("nombreMascotas.txt", "r");
	if(fp == NULL){
		perror("Error fopen ");
		exit(-1);
	}
	int aleatorio = randomNumber(10700);
	fseek(fp, aleatorio, SEEK_CUR);
	char current = fgetc(fp);
	while(current != '\n' && aleatorio>10){
		fseek(fp, -2, SEEK_CUR);
		current = fgetc(fp);
	}
	fgets(buffer, sizeof(buffer), fp);

	dogData = fopen("dogData.dat", "a+");
	if (dogData == NULL){
		perror("Error fopen ");
		exit(-1);
	}

	strcpy(dog->nombre, buffer);
	strcpy(dog->tipo, "Perro");
	dog->edad = randomNumber(12);
	strcpy(dog->raza, " ");
	dog->estatura = randomNumber(120) + 20;
	dog->peso = drand48()*5;
	if(randomNumber(2) == 0){
		dog->genero = 'F';
	}else{
		dog->genero = 'M';
	}

	dog->hash_id = hash(buffer);

	int r = fwrite(dog, sizeof(struct dogType), 1, dogData);
	if (r < 0){
		perror("Error fwrite ");
		exit(-1);
	}
	fclose(fp);
	fclose(dogData);
	free(dog);
}

int main(){
	srand(time(NULL));
	srand48(time(NULL));
	for (int i = 0; i < 10000000; i++){
		printf("\nEstructura #: %i", i);
		fillStruct();
	}
	return 0;
}
