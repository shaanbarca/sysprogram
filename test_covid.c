 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>



typedef struct {
    char pref[20];
    int num;
} Case;

int read_case(char *filename, char*prefecture);
Case split(char *line, char* delimiter);

int main(int argc, char** argv){
    char *filename;
    char *pref;
    int case_num;

    if(argc == 3){
        filename=argv[1];
        pref = argv[2];

        case_num = read_case(filename,pref);
        printf("Total sum of COVID patients in %s is %d\n", pref, case_num);
    }


return 0;

}

int read_case(char *filename, char *pref){
    int LINE_SIZE = 256;

    FILE *fp;// file pointer
    char tmpline[LINE_SIZE];

    Case tmpcase;
    int num = 0;

    fp = fopen(filename, "r");
    if(fp!=NULL){
        while(fgets(tmpline, LINE_SIZE, fp)){
            tmpcase = split(tmpline, ", ");// split data into tmparr

            if(!strcmp(tmpcase.pref,pref)){
                num += tmpcase.num;
            }
        }
    }
    fclose(fp);
    return num;
}

//

Case split(char *line, char *delimiter){

    int wc = 0; // count word in array
    char *tmp;//store split
    char *word; // each data

    Case out_case;

    word = strtok_r(line, delimiter, &tmp);// first word
    while(word!=NULL){
        if(wc == 1){
            strcpy(out_case.pref, word);
        }
        else if (wc == 2){
            out_case.num = atoi(word);

        }
        word = strtok_r(NULL, delimiter,&tmp);

        wc++;
    }
    return out_case;

}