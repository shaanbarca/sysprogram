
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*----------------------------------------------
Structure definition
-----------------------------------------------*/
typedef struct member{
char name[20]; // Name
int number; // Name index
struct member* next; // Pointer to the next instance
} MEMBER;
/*----------------------------------------------
Prototype
-----------------------------------------------*/
MEMBER* NewMember(char* name, int num);
void PrintMember(MEMBER* start);
/*--------------------------
Main function
----------------------------*/
int main(int argc, char** argv)
{
static int serialNum = 0;
MEMBER* start = NewMember("mitsugi", serialNum++);
PrintMember(start);
free(start);
return(0);
}
/*----------------------------------------------
Make a new list
-----------------------------------------------*/
MEMBER* NewMember(char* name, int num)
{
MEMBER* this; //
this = (MEMBER*)malloc(sizeof(MEMBER)); //allocate the memory
strcpy(this->name, name); //Copy the name
this->number = num;
this->next = NULL; //The next is NULL
return(this);
}
/*----------------------------------------------
Print the list in order
-----------------------------------------------*/
void PrintMember(MEMBER* start)
{
MEMBER* p;
for(p=start; p!= NULL; p=p->next){
printf("%s\t%d\n", p->name, p->number); //Until the next
// becomes NULL
}
}