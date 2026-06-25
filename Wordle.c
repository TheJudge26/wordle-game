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

Result cc(char, int, char*);
int main();

Result cc(char guess, int idx, char *word){
    char correct;
    correct=word[idx];

    switch (word[idx])
    {
    case correct:
        return ResultGreen;
        break;
    
    default:
        if (isin(correct, word))
            return ResultYellow;
        break;
    }
    return ResultRed;
}

int main() {
    printf("\nabc\n");
    return 0;
}
