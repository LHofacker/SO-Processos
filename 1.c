#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*Faça um programa que crie um processo filho. Este processo filho deverá realizar a multiplicação de dois vetores de dimensão N
(informada pelo usuário) e com valores aleatoriamente gerados. Garanta que o processo pai somente vai encerrar após o término dos
cálculos pelo processo filho. Dica: utilize a função sleep() no processo filho para retardar a execução de cálculos e também
mensagens de print no processo pai para indicar o que está acontecendo.*/

int main(){

    pid_t newPid, parent, child;
    int status, vectorSize, x, randomNumber;

    printf("Insira o tamanho dos vetores a serem multiplicados: ");
    scanf("%d", &vectorSize);
    printf("vectorSize: %d\n", vectorSize);

    int *vectorA = malloc(vectorSize*sizeof(int));
    int *vectorB = malloc(vectorSize*sizeof(int));
    int *vectorC = malloc(vectorSize*sizeof(int));

    srand(time(NULL));

    for(int i = 0; i<vectorSize; i++){

        randomNumber = rand() % 10+1;
        vectorA[i] = randomNumber;
        randomNumber = rand() % 10+1;
        vectorB[i] = randomNumber;
    }

    for(int i = 0; i < vectorSize; i++){

        printf("VectorA[%d] = %d\n", i, vectorA[i]);
        printf("VectorB[%d] = %d\n", i, vectorB[i]);
        printf("\n");
    }


/*PARTE COM PROCESSOS*/

    newPid = fork();
    parent = getppid();
    child = getpid();

    if(newPid != 0){

        printf("Aguardando processo filho. PID do Filho: %d\n", newPid);
        x = waitpid(newPid, &status, 0);
        printf("Processo filho de PID %d encerrou.\n", newPid);

    }else{
        for(int i = 0; i < vectorSize; i++){

            vectorC[i] = vectorA[i] * vectorB[i];
        }

        for(int i = 0; i < vectorSize; i++){

            printf("VectorC[%d] = %d * %d = %d\n", i, vectorA[i], vectorB[i], vectorC[i]);

        }


    }



    return 0;
}