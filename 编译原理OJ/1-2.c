#include <stdio.h>
#include <ctype.h>

char UnsignedIntMove(char S, char t)
{
    char nextstatus;
    if(isdigit(t)&&S == 'S')
    {
        nextstatus = 'S';
    } else {
        nextstatus = 0;
    }
    return nextstatus;
}

int UnsignedIntDFA(char *input)
{
    char S = 'S';
    int i;
    for(i=0; input[i] != '\0'; i++)
    {
        S = UnsignedIntMove(S,input[i]);
    }
    if(S == 'S')
        return 1;
    else
        return 0;
}

int main()
{
    char input[50];
    while(scanf("%s", input) != EOF)
    {
        int flag = UnsignedIntDFA(input);
        if(flag)
            printf("accept\n");
        else
            printf("not accept\n");
    }
    return 0;
}
