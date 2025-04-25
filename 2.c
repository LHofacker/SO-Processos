#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*Faça um programa que crie um processo filho. Este processo filho executará uma tarefa dependendo do seu ID de 
processo e do ID do seu pai. Se ambos IDs foram pares, o processo filho deverá multiplicar dois vetores de dimensão N
(informada pelo usuário) e com valores aleatoriamente gerados. 
Se ambos IDs forem ímpares, o processo filho deverá subtrair os vetores.
Se o pai for ímpar e o filho par, deverá realizar a adição dos vetores. 
Se o pai for par e o filho ímpar, deverá realizar as três operações.
Se o ID do filho for par, o processo pai deve esperar pelo seu encerramento. 
Se o ID for ímpar, não precisa esperar pelo filho.*/

void generate_vector(int **vector, int vector_size){

    *vector = malloc(vector_size*sizeof(int));

    for(int i = 0; i < vector_size; i++){

        (*vector)[i] = i;
    }
    
}


int main(){

    pid_t new_pid, parent, child;
    int status, vector_size, x;
    int *vector_a;
    int *vector_b;

    printf("Insira o tamanho dos vetores a serem multiplicados: ");
    scanf("%d", &vector_size);
    printf("vector_size: %d\n", vector_size);

    generate_vector(&vector_a, vector_size);

    for (int i = 0; i < vector_size; i++){

        printf("%d\n", vector_a[i]);
    }
    
    free(vector_a);
   

    return 0;
}