#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*Faça um programa que crie um processo filho. Este processo filho executará uma tarefa dependendo do seu ID de 
processo e do ID do seu pai. 
Se ambos IDs foram pares, o processo filho deverá multiplicar dois vetores de dimensão N (informada pelo usuário) e com valores aleatoriamente gerados. 
Se ambos IDs forem ímpares, o processo filho deverá subtrair os vetores.
Se o pai for ímpar e o filho par, deverá realizar a adição dos vetores. 
Se o pai for par e o filho ímpar, deverá realizar as três operações.
Se o ID do filho for par, o processo pai deve esperar pelo seu encerramento. 
Se o ID for ímpar, não precisa esperar pelo filho.
*/

int get_vector_size(){

    int vector_size;

    printf("Insira o tamanho dos vetores a serem multiplicados: ");
    scanf("%d", &vector_size);
    printf("vector_size: %d\n\n", vector_size);


    return vector_size;
}

void generate_vector(int **vector, int vector_size){

    *vector = malloc(vector_size*sizeof(int));
    int random_number;

    srand(time(NULL));

    for(int i = 0; i<vector_size; i++){

        random_number = rand() % 20+1;
        (*vector)[i] = random_number;
        sleep(1);
    
    }
    
}

void print_vector(int *vector, int vector_size, char *vector_name){

    printf("%s = (", vector_name);

    for (int i = 0; i < vector_size; i++){

        if(i<vector_size-1){

            printf("%d, ", vector[i]);
        }else{
            
            printf("%d", vector[i]);
        }
    }

    printf(")\n");
}

void print_all_vectors(int *vector1, int *vector2, int *vector3, int vector_size){

    print_vector(vector1, vector_size, "VectorA");
    print_vector(vector2, vector_size, "VectorB");
    print_vector(vector3, vector_size, "VectorC");
}

void add_vector(int *vector1, int *vector2, int *vector_res, int vector_size){

    for(int i = 0; i < vector_size; i++){

        vector_res[i] = vector1[i] + vector2[i];
    }
}

void sub_vector(int *vector1, int *vector2, int *vector_res, int vector_size){

    for(int i = 0; i < vector_size; i++){

        vector_res[i] = vector1[i] - vector2[i];
    }
}

void mult_vector(int *vector1, int *vector2, int *vector_res, int vector_size){
    
    for(int i = 0; i < vector_size; i++){

        vector_res[i] = vector1[i] * vector2[i];
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

/*PARTE COM PROCESSOS*/

    new_pid = fork();
    parent = getppid();
    child = getpid();

    if(new_pid != 0){

        if(child % 2 == 0){

            waitpid(new_pid, &status, 0);
            sleep(5);
            printf("FILHO DE ID %d ENCERROU OPERAÇÔES. PAI DE ID %d ENCERRANDO.\n", new_pid, child);
        }else{

            printf("PAI DE ID %d ENCERRANDO. FILHO DE ID %d TALVEZ AINDA OPERANDO.\n", child, new_pid);
        }

    }else{

        if(child % 2 == 0 && parent % 2 == 0){

            printf("\nMULTIPLICAÇÂO:\n");
            mult_vector(vector_a, vector_b, vector_c, vector_size);
            print_all_vectors(vector_a, vector_b, vector_c, vector_size);
        }

        if(child % 2 != 0 && parent % 2 != 0){

            printf("\nSUBTRAÇÂO:\n");
            sub_vector(vector_a, vector_b, vector_c, vector_size);
            print_all_vectors(vector_a, vector_b, vector_c, vector_size);
        }

        if(child % 2 == 0 && parent % 2 != 0){

            printf("\nADIÇÂO:\n");
            add_vector(vector_a, vector_b, vector_c, vector_size);
            print_all_vectors(vector_a, vector_b, vector_c, vector_size);
        }
        
        if(child % 2 != 0 && parent % 2 == 0){

            printf("ADIÇÂO:\n");
            add_vector(vector_a, vector_b, vector_c, vector_size);
            print_all_vectors(vector_a, vector_b, vector_c, vector_size);

            printf("SUBTRAÇÂO:\n");
            sub_vector(vector_a, vector_b, vector_c, vector_size);
            print_all_vectors(vector_a, vector_b, vector_c, vector_size);

            printf("MULTIPLICAÇÂO:\n");
            mult_vector(vector_a, vector_b, vector_c, vector_size);
            print_all_vectors(vector_a, vector_b, vector_c, vector_size);
        }

        printf("\nFILHO DE ID %d ENCERRANDO. PAI DE ID %d TALVEZ AINDA OPERANDO.\n", child, parent);
    }

    
    free(vector_a);
    free(vector_b);
    free(vector_c);

    return 0;
}