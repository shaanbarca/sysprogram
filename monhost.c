//Shaan Perlambang
// 71735892
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
/*--------------------------------------------------------------
Structure for host
----------------------------------------------------------------*/
struct host { 
    char ip[256];
    int interval;
    int filedes[2];
    pthread_t tid;
} hosts[256];
int host_num = 0;
/*----------------------------------------------------------
Prototypes of functions
------------------------------------------------------------*/
void read_hosts(char *filename);
void pings();
void sender(char *ip, int interval, int fd);
void *response(void *arg);
void multithread();
/*--------------------------------------------------------
read file function
---------------------------------------------------------*/
void read_hosts(char *filename) {
    FILE *file_ptr = fopen(filename, "r");
    char buffer[256];
    while(fgets(buffer, 256, file_ptr)) {
        sscanf(buffer, "%s %d", hosts[host_num].ip, &hosts[host_num].interval);
        if (hosts[host_num].interval <= 0) {
            printf("Interval Error\n");
            exit(1);
        }
        host_num++;
    }
    fclose(file_ptr);
    pings();
    multithread();
}
/*------------------------------------------------------
ping function
------------------------------------------------------*/
void pings() {
    pid_t pid; 
    for (int i = 0; i < host_num; i++) {
    
        if (pipe(hosts[i].filedes) == -1) {
            printf("pipe error \n");
            exit(1);
        }
        if ((pid=fork()) == -1) {
            printf("fork error \n");
            exit(1);
        }
        if (pid == 0) {
            sender(hosts[i].ip, hosts[i].interval, hosts[i].filedes[1]);
            return ;
        }
    }
}
/*-----------------------------------------------------
Send ping function
------------------------------------------------------*/
void sender(char *ip, int interval, int fd) {
    char interval_l[256];
    sprintf(interval_l, "%d", interval);
    dup2(fd, 1); 
    execlp("ping", "ping", ip, "-i", interval_l, NULL);
    exit(0);
}
/*-----------------------------------------------------
reponse function
------------------------------------------------------*/
void *response(void *arg) {
    struct host *hosp = arg;
    FILE *file_ptr = fdopen(hosp->filedes[0], "r");
    char time_buff[256];
    time_t timer;
    struct tm *tm_info;
    char buffer[256];
    
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        timer = time(NULL);
        tm_info = localtime(&timer);
        strftime(time_buff, 26, "%a-%b-%d-%Y %H:%M:%S", tm_info);

        if (buffer == strstr(buffer, "PING")) {
            continue;
        } else if (buffer == strstr(buffer, "64 bytes")) {
            printf("%s : %s : %s", time_buff, hosp->ip, buffer);
        } else {
            printf("\033[0;31m%s : %s : %s\033[31m", time_buff, hosp->ip, buffer); //color change 
        }
    }


    return NULL;
}
/*-----------------------------------------------------------
multithread function
--------------------------------------------------------------*/
void multithread() {
    for (int i = 0; i < host_num; i++) {
        pthread_create(&hosts[i].tid, NULL, response, &hosts[i]);
    } 
    for (int i = 0; i < host_num; i++) { 
        pthread_join(hosts[i].tid, NULL);
    }
}
/*------------------------------------
main function
-------------------------------------*/
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Must have exactly 2 args. \n");
        return 1;
    }
    read_hosts(argv[1]);
    return 0;
}