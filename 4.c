#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>

void get_program(char **path){

    *path = malloc(256*sizeof(char));

    printf("Insira o caminho para o programa (Caminho completo para um arquivo compilado (Ex: .exe), não para arquivo .c!): ");
    scanf("%[^\n]s", *path);
}

int main(){

    pid_t new_pid, parent, child;
    char *path;
    int status = 0;

    get_program(&path);
    new_pid = fork();

    if(new_pid == 0){

        printf("Filho Chegou Aqui.\n");
        execl(path, path, NULL);
    }

    if(new_pid != 0){
        
        waitpid(new_pid, &status, 0);
        printf("Filho encerrou. Pai Encerrando.\n"); 
    }


    return 0;
}