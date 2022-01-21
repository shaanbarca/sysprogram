#include<stdio.h>
#include<signal.h>
void myhandler(int); //prototype
int main(){
struct sigaction act;
act.sa_handler = myhandler;

return 0;
}
void myhandler(){
    usleep(1500000);
}
