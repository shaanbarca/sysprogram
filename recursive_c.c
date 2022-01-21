//Shaan Perlambang 71735892
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*--------------------------------------
Prefecture Struct
---------------------------------------*/
typedef struct prefecture{
char name[20]; //Name of province
int number; // Number of cases        number
struct prefecture* next; //pointer to next data
} Prefecture;
/*---------------------------------
function prototypes
----------------------------------*/
void AddPrefecture(Prefecture* next, char* name, int num);
//Prefecture* NewPrefecture(char* name, int num);
void SearchPrefecture(char* pref);

/*------------------------------------
Main Function
-------------------------------------*/

int main(int argc, char** argv)
{
  if (argc!=3){return 1;}
  char* filename = argv[1];
  char* city = argv[2];

  FILE* fp;
  fp = fopen(filename, "r");
  if(fp == NULL){ return 1;}

  char line[256];
  char name[20];
  int sum = 0;
  char pref;
  char* word;
  char* tmp;
  Prefecture start = {"dummy", 0, NULL};
  while (fgets(line,256,fp)){
    word = strtok_r(line, ",",&tmp); //date
    word = strtok_r(NULL, ",", &tmp); //city
    if(strcmp(word, city) == 0){
                   sum += strtol(tmp, NULL, 0);
    AddPrefecture(Prefecture* next,word,sum);

    
    }
    
  }
  printf("Total sum of patients in %s is %d\n", Prefecture.name, Prefecture.number);
  
  SearchPrefecture(char* pref);
  fclose(fp);
  return 0;
}

/*------------------------------------------------
New Prefecture
-------------------------------------------------*/
Prefecture* NewPrefecture(char* name, int num)
{
    Prefecture* that;
    that = (*Prefecture)malloc(sizeof(Prefecture));
    strcpy(that->name, name);
    strcpy(that->number, num);
    that -> next = NULL;
    return(that);
}
/*----------------------------------------------
Add prefecture
-----------------------------------------------*/
void AddPrefecture(Prefecture* this, char* name, int num)
{
    while(this -> next != NULL)
    {
        this = this->next;
    }
    this-> next = (Prefecture*)NewPrefecture(name, num);

}

/*------------------------------------------------------
Search prefecture
-----------------------------------------------------*/
void SearchPrefecture(char*  pref)
{
    
    printf("Input next province =");
    scanf("%c",&pref);//
    if(strcmp(pref,Prefecture.name)==0) // if pref matches 
    { 
       printf("Number of cases is = %d in %c ",Prefecture.number, Prefecture.name);
    }
   SearchPrefecture(char* pref); //recursive call
}

