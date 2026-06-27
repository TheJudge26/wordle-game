#include <stdio.h>
#include "fetch.h"// my own lib to readfile()
#include <stdlib.h>
#include <string.h>

#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

// typedef struct{
//     char color[5];


// }Result;

typedef char Result;

typedef struct 
{
    char **arr;
    int n;
}words;

typedef Result Results[5];

void Example_print_results(Results);
void cw(char*, char*, Results);
Result cc(char, int, char*);
int isin(char target_letter, char *word);
int main(int, char**);


void Example_print_results(Results res){
    int i;

    for ( i = 0; i < 5; i++)
    {
        switch (res[i])
        {
        case ResultGreen:
            printf("%s\n", "Green");
            break;
        case ResultYellow:

            printf("%s\n", "Yellow");
            break;

        case ResultRed:
            printf("%s\n", "Red");
            break;
        default:

            printf("UNknow %d\n", res[i]);
            break;
        }
    }
    
    return;
}
Result cc(char guess, int idx, char *word){
    char correct;
    correct=word[idx];

    if (guess==correct)
    {
        return ResultGreen;
    }
    else if (isin(guess, word))
    {
        return ResultYellow;
    }
    else{
        return ResultRed;
    }
    
}


int isin(char target_letter, char *word) {
    for (int i = 0; i < 5; i++) {
        if (word[i] == target_letter) {
            return 1; 
        }
    }
    return 0; 
}

words **readfile(char *filename, int max){

    char buf[8];
    int i ;
    int i, size;
    FILE *fd;
    char *ret[5];
    words words;


    fd = fopen(filename, "r");
    if (!fd)
    {
        perror("fopen");
        words={
           .arr = (char **)0,
           .n = 0
        };
        return words;
    }

    size=max*5;
    ret = (char **)malloc(size);
    id (!ret){
        fclose(fd);
        perror("malloc");

        return (char **)0;
    }

    i=0;

    memset(buf, 0, 8);
    while (fgets(buf,7,fd))
    {
        size = strlen(buf);
        if (size<1)
        {
            memset(buf, 0, 8);
            continue;
        }
        
        size --;
        buf[size]=0;

        if (size != 5)
        {
            memset(buf, 0 ,8);
            continue;
        }
        
        ret[i][0]=buf[0];
        ret[i][1]=buf[1];
        ret[i][2]=buf[2];
        ret[i][3]=buf[3];
        ret[i][4]=buf[4];

        memset (buf,0,8);
        n++;

        if (max<=n)
        {
            break;
        }
        
    }

    fclose(fd);
     


    
}

void cw(char *guess, char *word, Results out_res) {
   
    for (int i = 0; i < 5; i++) {
        
        out_res[i] = cc(guess[i], i, word);
    }
}
int main(int argc, char *argv[]) {
    char *correct, *guess;
    Results res;

    if (argc<3)
    {
        fprintf(stderr,"use %s corect guess",argv[0]);
        return -1;
    }

    correct = argv[1];
    guess = argv[2];

    cw(guess, correct, res);
    // res=cw(correct,guess);

    Example_print_results(res);

    
    return 0;
}
