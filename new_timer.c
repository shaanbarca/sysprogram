
#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include <unistd.h>

int main(int argc, char** argv)
{
struct timespec slptm;
struct timespec rmtp;

slptm.tv_sec = 1.5;//delay
struct tm *p;
struct tm buf;
char timestring[100];

struct timeval start;
//int *delay = argv[1];
//struct timezone tz;

//gettimeofday(&start, NULL); //changed tv to start
time_t ltime = time(0);//capture current time

if (NULL != (p=localtime_r(&ltime, &buf))){ //what does this do ?
    while(1){
        if (nanosleep(&slptm, &rmtp) != -1){
        gettimeofday(&start, NULL);
        printf("time elapsed = %ld\n",start.tv_sec);
        printf("%s.", timestring);//second
        printf("%02d\n", (int)start.tv_usec );
        
        }
    }
}
return 0;
}
