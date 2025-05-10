#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void get_max_number_of_processes(int *max_process_number){

    printf("Insira a quantidade de processos a serem criados: ");
    scanf("%d", max_process_number);
    printf("Número de processos: %d\n\n", *max_process_number);
}

void get_x_from_pid(int *collatz, pid_t pid){

    *collatz = (pid / 10) % 100;

    if(*collatz == 0){

        printf("VALOR DE PID É ZERO. SOMANDO 1 AO VALOR.\n");
        *collatz = *collatz + 1;
    }
}

void collatz_conjecture(int *collatz){

    printf("(");

    while(*collatz != 1){
        
        if(*collatz % 2 == 0){
        
            *collatz = *collatz / 2;
            printf("%d", *collatz);
        }else{

            *collatz = (3 * *collatz) + 1;
            printf("%d", *collatz);
        }

        if(*collatz != 1){
            printf(", ");
        }
    }

    printf(")\n");
}

int main(){

    pid_t new_pid, parent, child, master = getpid();
    int status;
    int *collatz = malloc(sizeof(int));
    int *max_process_number = malloc(sizeof(int));

    get_max_number_of_processes(max_process_number);
    
    for(int process_number = 0; process_number < *max_process_number - 1; process_number++){

        if(master == getpid()){

            new_pid = fork();
        }
    }   

    get_x_from_pid(collatz, getpid());
    printf("Processo %d: collatz = (%d) -> ", getpid(), *collatz);
    collatz_conjecture(collatz);
    fflush(stdout);

    waitpid(new_pid, &status, 0);

    free(collatz);
    free(max_process_number);

    return 0;
}