//Shaan Perlambang 71735892

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define max(x,y) x>y ? x : y
int main(int c, char** v)
{
    struct timeval tv;
    fd_set fdset;
    char tmpline[10];
    int maxfd ;
    int nfds;
    int nc;
    maxfd = max(STDIN_FILENO, STDOUT_FILENO) + 1;
    
    while(1){
    tv.tv_sec = 5;// moved it down to the while loop
    tv.tv_usec = 0;
        FD_ZERO(&fdset) ;
        FD_SET(STDIN_FILENO, &fdset);
        nfds = select(maxfd, &fdset, NULL, NULL, &tv);
        printf("nfds = %d\n", nfds);
        if (FD_ISSET(STDIN_FILENO, &fdset)) {
        printf("data in keyboard\n");
        if ((nc=read(STDIN_FILENO, tmpline, sizeof(tmpline)))!=-1){
            printf("%d\n", nc);
            write(STDOUT_FILENO, tmpline, nc);
            }
        }
    }
    return 0;
}