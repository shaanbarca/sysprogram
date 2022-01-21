
// Shaan Perlambang 71735892

#include <stdio.h>
#include<time.h>
#include <unistd.h>
#include <sys/time.h>
#include<signal.h>

void myhandler();

int main(int argc, char ** argv[]) 
{

struct timeval timecheck; 
long start, end;
int delay = strtol(argv[1],NULL,0);
/*-------------------------
signal
--------------------------*/
struct sigaction act;
act.sa_handler = myhandler;
sigaction(SIGINT, &act, NULL);
/* -----------------------------
timer
-------------------------------*/
gettimeofday(&timecheck, NULL);
start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
// will start at 0 and constantly subtract end to get time elapsed.
while(1){
usleep(delay * 1500000); //for some reason i cant capture floats/double
gettimeofday(&timecheck, NULL);
end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
printf("* %.2f \n", (float)(end - start) /1000); //prints time elapsed

}
return 0;
}
/*------------------------------
handler function
------------------------------*/

void myhandler(){
    printf("^C---CTL+c received\n"); //why does this not print?
    usleep(2000000);
    raise(SIGKILL);
}
