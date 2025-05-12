#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*Faça um programa que crie um processo filho. Este processo filho deverá realizar a multiplicação de dois vetores de dimensão N
(informada pelo usuário) e com valores aleatoriamente gerados. Garanta que o processo pai somente vai encerrar após o término dos
cálculos pelo processo filho. Dica: utilize a função sleep() no processo filho para retardar a execução de cálculos e também
mensagens de print no processo pai para indicar o que está acontecendo.*/


void get_vector_size(int **vector_size){

    *vector_size = malloc(sizeof(int));

    printf("Insira o tamanho dos vetores a serem utilizados: ");
    scanf("%d", *vector_size);
    printf("vector_size: %d\n\n", **vector_size);
}

void generate_vector(int **vector, int *vector_size){

    *vector = malloc(*vector_size*sizeof(int));
    int random_number;

    for(int i = 0; i < *vector_size; i++){

        random_number = rand() % 20+1;
        for(int i = 0; i < *vector_size; i++){
            
        }
        (*vector)[i] = random_number;
    
    }
    
}

void mult_vector(int *vector1, int *vector2, int *vector_res, int *vector_size){
    
    for(int i = 0; i < *vector_size; i++){

        vector_res[i] = vector1[i] * vector2[i];
    }
}

void print_vector(int *vector, int *vector_size, char *vector_name){

    printf("%s = (", vector_name);

    for (int i = 0; i < *vector_size; i++){

        if(i < *vector_size-1){

            printf("%d, ", vector[i]);
        }else{
            
            printf("%d", vector[i]);
        }
    }

    printf(")\n");
}

void print_all_vectors(int *vector1, int *vector2, int *vector3, int *vector_size){

    print_vector(vector1, vector_size, "VectorA");
    print_vector(vector2, vector_size, "VectorB");
    print_vector(vector3, vector_size, "VectorC");
}

int main(){

    pid_t newPid, parent, child;
    int status, x;
    int randomNumber;
    int *vector_size, *vector_a, *vector_b, *vector_c;

    newPid = fork();
    parent = getppid();
    child = getpid();



    if(newPid != 0){

        printf("Aguardando processo filho. PID do Filho: %d\n", newPid);
        x = waitpid(newPid, &status, 0);
        printf("Processo filho de PID %d encerrou.\n", newPid);
    }else{

        get_vector_size(&vector_size);
        generate_vector(&vector_a, vector_size);
        generate_vector(&vector_b, vector_size);
        mult_vector(vector_a, vector_b, vector_c, vector_size);
        print_all_vectors(vector_a, vector_b, vector_c, vector_size);
    }
    
    return 0;
}