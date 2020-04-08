#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define Maxlongitud 40

struct dogType{
    char nombre[32];
    char tipo[32];
    int edad;
    char raza[16];
    int estatura;
    float peso;
    char sexo;
};

int printStruct(void *ap){
    struct dogType *data; 
    data = ap;
    printf("\n nombre: %s", data->nombre);
    printf("\n tipo: %s", data->tipo);
    printf("\n edad: %i", data->edad);
    printf("\n raza: %s", data->raza);
    printf("\n estatura (cm): %i", data->estatura);
    printf("\n peso (Kg): %f", data->peso);
    printf("\n sexo [H/M]: %c", data->sexo);
}
int loadStruct(void *ap){
    struct dogType *data; 
    data = ap;
    printf("\n nombre: ");
    scanf(" %s", data->nombre); 
    printf("\n tipo: ");
    scanf(" %s", data->tipo);
    printf("\n edad: ");
    scanf(" %i", &data->edad);
    printf("\n raza: ");
    scanf(" %s", data->raza);
    printf("\n estatura (cm): ");
    scanf(" %i", &data->estatura);
    printf("\n peso (Kg): ");
    scanf(" %f", &data->peso);
    printf("\n sexo [H/M]: ");
    scanf(" %c", &data->sexo);
    return 0;
}
int guardar(void *ap){
    struct dogType *data;
    data = ap;
    
    FILE *apFile;
    int r;
    
    apFile = fopen("dataDogs.dat","a+");
    if(apFile == NULL){
        perror("error fopen:");
        exit(-1);
    }
    
    r = fwrite(ap, sizeof(struct dogType), 1, apFile);
    if(r <= 0){
        perror("error fwrite");
        exit(-1);
    }
    
    r = fclose(apFile);
    if(r < 0){
        perror("error fclose: ");
        exit(-1);
    }


}

//Abrir archivo nombreMascotas.txt y guardarlo en un arreglo
int cargarNombresMascotas(char arreglo[][Maxlongitud]){
	FILE *apFile;
	int r;
    int longitudArreglo=1717;
    apFile = fopen("nombreMascotas.txt","r");
    if(apFile == NULL){
        perror("error fopen:");
        exit(-1);
    }

    for(int i=0; i < longitudArreglo; i++){
    	fscanf(apFile,"%s\n",&arreglo[i]);

    }
    //Comprobar que se haya llenado el arreglo
    /*for(int i=0; i < longitudArreglo; i++){
    	printf("%s\n",arreglo[i]);
    }*/

    r = fclose(apFile);
    if(r < 0){
        perror("error fclose: ");
        exit(-1);
    }

}
//Abrir archivo nombreRazas.txt y guardarlo en un arreglo
int cargarNombresRazas(char arreglo[][Maxlongitud]){
	FILE *apFile;
	int r;
    int longitudArreglo=89;
    apFile = fopen("nombreRazas.txt","r");
    if(apFile == NULL){
        perror("error fopen:");
        exit(-1);
    }

    for(int i=0; i < longitudArreglo; i++){
    	fscanf(apFile,"%s\n",&arreglo[i]);

    }
    //Comprobar que se haya llenado el arreglo
    /*for(int i=0; i < longitudArreglo; i++){
    	printf("%s\n",arreglo[i]);
    }*/

    r = fclose(apFile);
    if(r < 0){
        perror("error fclose: ");
        exit(-1);
    }
}
//Genera numeros aleatorios entre 0 - 1716(cantidad de nombres para Perros segun el txt)
int numeroAleatorioNombreMascota(){
	srand(time(NULL));
	int num_random= rand() % (1716+1);
	return num_random;
}

//Genera numeros aleatorios entre 0 - 88(cantidad de Razas según el txt)
int numeroAleatorioRazas(){
	srand(time(NULL));
	int num_random= rand() % (88+1);
	return num_random;

}

//Genera numeros aleatorios entre 0 - 20
int numeroAleatorioEdad(){
	srand(time(NULL));
	int num_random= rand() % (20+1);
	return num_random;
}

//Genera numeros aleatorios entre 15 - 110
int numeroAleatorioEstatura(){
	srand(time(NULL));
	int num_random= 15 + rand() % (111 - 15);
	return num_random;
}

//Genera numeros aleatorios entre 15 - 45
int numeroAleatorioPeso(){
	srand(time(NULL));
	int num_random= 15 + rand() % (46 -15);
	return num_random;
}


int LLenarEstructura(void *ap, char nombre[][Maxlongitud], char raza[][Maxlongitud],int n){
	struct dogType *data;
    data = ap;
    FILE *apFile;
    
    int a, b, c, d, e;
    a=numeroAleatorioNombreMascota();
    b=numeroAleatorioRazas();
    c=numeroAleatorioEdad();
    d=numeroAleatorioEstatura();
    e=numeroAleatorioPeso();
    

    strcpy(data->nombre,nombre[a]); 
    strcpy(data->tipo, "Perro"); 
    strcpy(data->raza,raza[b]); 
    data->edad=c;
   	data->estatura=d;
    data->peso=e;

    if(n%2==0){ //si n es par
    	data->sexo='M';
    }else{ //si n es impar
    	data->sexo='F';
    }
    //arreglar esto
   

    return 0;
}



int main(){
	char nombresMascotas[1717][Maxlongitud];
	char nombresRazas[89][Maxlongitud];
	char opcion;
    int n=1;
  

    struct dogType *data;
    data = malloc(sizeof(struct dogType));
    if(data == NULL){
        perror("error malloc: ");
        exit(-1);
    }
    //generacion de arreglos
    cargarNombresMascotas(nombresMascotas);
    cargarNombresRazas(nombresRazas);

    //generacion de la estructura
    for(int i=0; i < 10000000; i++){
    	n++;
    	printf("Generando la la estructura %i ...\n", i+1);
    	LLenarEstructura((void*)data,nombresMascotas,nombresRazas,n);
    	guardar((void*)data);
    }
    //estructuras generadas


    
   
    //parte Visual
    printf("\n Sistema de gesti%cn de Veterinaria",162);
     do
    {
        printf( "\n   1. Ingresar registro.");
        printf( "\n   2. Ver registro.");
        printf( "\n   3. Borrar registro.");
        printf( "\n   4. Buscar registro.");
        printf( "\n   5. Salir");

        do
        {
            printf( "\n   Introduzca opci%cn (1-5): ", 162 );
            fflush(stdin);
            scanf( "%c", &opcion );

        } while ( opcion < '1' || opcion > '6' );

        switch ( opcion )
        {
            case '1': printf( "\n   Ingresar registro.");
                      loadStruct((void *)data);
                      guardar((void*)data);
                      /*continuar codigo



                      */
                      system("pause");
                      break;

            case '2': printf( "\n   Ver registro. ");
                      printStruct((void*)data);
                      /*continuar codigo



                      */
                      system("pause");
                      break;

            case '3': printf( "\n   Borrar registro. ");
                      printf( "\n   esta es la opcion 3 \n");
                      /*continuar codigo



                      */
                      system("pause");
                      break;
            
            case '4': printf( "\n   Buscar registro. ");
                      printf( "\n   esta es la opcion 4 \n");
                      /*continuar codigo



                      */
                      system("pause");
                      break;
         }

    } while ( opcion != '5' );

    free(data);
    return 0;
    
}
    
    

