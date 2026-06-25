#include <stdio.h>
// need to make my own (unistd.h)
#include <stdlib.h>
#include <string.h>

#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

// typedef struct{
//     char color[5];


// }Result;

typedef char Result;
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
