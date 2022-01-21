#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    int id1 = fork();
    int id2 = fork();
    if(id1 == 0){
        if (id2 == 0) {
             printf("Process y\n");
        } else {
            printf("We are process x\n");
}
    else {
        if (id2==0){
            printf("Process z\n");
        } else {
        printf("Proccess x\n");
        }
    }
    while(wait(NULL) != -1 || errno != ECHILD)// waits for all child processes to finish executing
    return 0;
}
