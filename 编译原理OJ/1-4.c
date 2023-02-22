#include <stdio.h>
#include <ctype.h>

char IdentifierMove(char S, char t, int i)
{
    char nextstatus;
    if(i == 0) {
        if(((t >='a' && t<='z' ||  t >='A' && t<='Z')||t=='_')&&S == 'S')
        {
            nextstatus = 'S';
        } else {
            nextstatus = 0;
        }
        return nextstatus;
    } else {
        if(((t >='a' && t<='z' ||  t >='A' && t<='Z')||isdigit(t)||t=='_')&&S == 'S')
        {
            nextstatus = 'S';
        } else {
            nextstatus = 0;
        }
        return nextstatus;
    }
}

int IdentifierDFA(char *input)
{
    char S = 'S';
    int i;
    for(i=0; input[i] != '\0'; i++)
    {
        S = IdentifierMove(S,input[i],i);
    }
    if(S == 'S')
        return 1;
    else
        return 0;
}

int main()
{
    char input[50];
    while(scanf("%[^\n]", input) != EOF)
    {
        int flag = IdentifierDFA(input);
        if(flag)
            printf("accept\n");
        else
            printf("not accept\n");
    }
    return 0;
}

