// Shaan Perlambang 71735892

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include  <sys/types.h>
/*---------------------
parsing
-----------------------*/
void  parse(char *line, char **argv)
{
     while (*line != '\0') {       
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             
     }
     *argv = '\0';                 
}
/*------------------
shell function
--------------------*/    
void shell(char **argv){


     pid_t pid;
     int state_loc;
     
     if ((pid = fork()) < 0) {  
         
         printf("\n"); 
          printf("fork failed \n");
          return -1;
     }
     else if (pid == 0) {        
          if (execvp(*argv, argv) < 0) {    
               printf("error occured\n");
               exit(1);
          }
     }
     else {                                  
          while (wait(&state_loc) != pid);
          printf("child process terminated with %d\n", state_loc);      
               
     }
}
/*------------------------------------
Main function
--------------------------------------*/
int main(){
char  *argv[64];
char  line[1024]; 
// ----------------------time-----------------------------------
time_t rawtime;
struct tm *info;
char buffer[80];

time( &rawtime );

info = localtime( &rawtime );

strftime(buffer,80,"%a-%b-%d-%H-%M-%S-%Y", info);
// --------------------------------------------------------------                           

while(1){
    printf("** %s\n", buffer );   
    gets(line);  
    parse(line, argv);   
    if (strcmp(argv[0],"exit" ) == 0){
        exit(0);
        }
    shell(argv);
    }
}

    