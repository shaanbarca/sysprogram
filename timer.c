
#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include <unistd.h>

int main()
{
struct timespec slptm;
struct timespec rmtp;

slptm.tv_sec = 1.5;//delay
struct tm *p;
struct tm buf;
char timestring[100];
struct timeval tv;
struct timezone tz;

gettimeofday(&tv, &tz);
time_t ltime = time(NULL);//capture current time

if (NULL != (p=localtime_r(&ltime, &buf))){ //what does this do ?
    while(1){
        if (nanosleep(&slptm, &rmtp) != -1){
        gettimeofday(&tv, &tz);
        strftime(timestring, sizeof(timestring), "%S", p);
        printf("%s.", timestring);//second
        printf("%02d\n", (int)tv.tv_usec);
        
        }
    }
}
return 0;
}

    
