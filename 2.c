#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*Faça um programa que crie um processo filho. Este processo filho executará uma tarefa dependendo do seu ID de 
processo e do ID do seu pai. 
Se ambos IDs foram pares, o processo filho deverá multiplicar dois vetores de 
dimensão N (informada pelo usuário) e com valores aleatoriamente gerados. 
Se ambos IDs forem ímpares, o processo filho deverá subtrair os vetores.
Se o pai for ímpar e o filho par, deverá realizar a adição dos vetores. 
Se o pai for par e o filho ímpar, deverá realizar as três operações.
Se o ID do filho for par, o processo pai deve esperar pelo seu encerramento. 
Se o ID for ímpar, não precisa esperar pelo filho.*/

int get_vector_size(){

    int vector_size;

    printf("Insira o tamanho dos vetores a serem multiplicados: ");
    scanf("%d", &vector_size);
    printf("vector_size: %d\n\n", vector_size);


    return vector_size;
}

void generate_vector(int **vector, int vector_size){

    *vector = malloc(vector_size*sizeof(int));

    for(int i = 0; i<vector_size; i++){

        int randomNumber;

        randomNumber = rand() % 10+1;
        (*vector)[i] = randomNumber;
    
    }
    
}

void print_vector(int **vector, int vector_size, char *vector_name){

    printf("%s = (", vector_name);

    for (int i = 0; i < vector_size; i++){

        if(i<vector_size-1){

            printf("%d, ", (*vector)[i]);
        }else{
            
            printf("%d", (*vector)[i]);
        }
    }

    printf(")\n");
}

void add_vector(int **vector1, int **vector2, int **vector_res, int vector_size){

    for(int i = 0; i < vector_size; i++){

        (*vector_res)[i] = (*vector1)[i] + (*vector2)[i];
    }
}

int sub_vector(int **vector1, int **vector2, int **vector_res, int vector_size){

    for(int i = 0; i < vector_size; i++){

        (*vector_res)[i] = (*vector1)[i] - (*vector2)[i];
    }
}

int mult_vector(int **vector1, int **vector2, int **vector_res, int vector_size){
    
    for(int i = 0; i < vector_size; i++){

        (*vector_res)[i] = (*vector1)[i] * (*vector2)[i];
    }
}


int main(){

    pid_t new_pid, parent, child;
    int status, vector_size, x;
    int *vector_a, *vector_b;
    

    vector_size = get_vector_size();

    int *vector_c = malloc(vector_size*sizeof(int));

    generate_vector(&vector_a, vector_size);
    generate_vector(&vector_b, vector_size);

    printf("\n\n\nADD:\n");
    add_vector(&vector_a, &vector_b, &vector_c, vector_size);
    print_vector(&vector_a, vector_size, "Vector_A");
    print_vector(&vector_b, vector_size, "Vector_B");      
    print_vector(&vector_c, vector_size, "Vector_C");
    
    printf("\n\n\nSUB:\n");
    sub_vector(&vector_a, &vector_b, &vector_c, vector_size);
    print_vector(&vector_a, vector_size, "Vector_A");
    print_vector(&vector_b, vector_size, "Vector_B");      
    print_vector(&vector_c, vector_size, "Vector_C");
    
    printf("\n\n\nMULT:\n");
    mult_vector(&vector_a, &vector_b, &vector_c, vector_size);
    print_vector(&vector_a, vector_size, "Vector_A");
    print_vector(&vector_b, vector_size, "Vector_B");      
    print_vector(&vector_c, vector_size, "Vector_C");
    
    free(vector_a);
    free(vector_b);
    free(vector_c);
   

    return 0;
}