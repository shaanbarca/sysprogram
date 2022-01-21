//Proccess id 
// every single proccess has an id
/*------------------------------------------------------------------------------ 
child proccess needs to be terminated before parent or else memory wont get freed

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int id == fork()
    if (id == 0){
        sleep(1);
    }
    printf("Current ID: %d, Parent ID: %d\n",
    getpid(),getppid());

    int res = wait(NULL);// wait for child to die. returns -1 if no child left 
    if (res == -1){
        printf("No children to wait for \n");

    }
    else {
        printf("%d finished execution\n", res) // we end up getting the proccess id we were waiting for 
    }
    return 0;
}