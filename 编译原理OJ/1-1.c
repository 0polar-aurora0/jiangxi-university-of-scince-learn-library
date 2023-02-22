#include <stdio.h>;

char Move(char S, char t1)
{
    char nextstatus;
    if(t1 == 'a')
    {
        if(S == 'S') nextstatus = 'U';
        if(S == 'U') nextstatus = 'Q';
        if(S == 'V') nextstatus = 'U';
        if(S == 'Q') nextstatus = 'Q';
    }
    else if(t1 == 'b')
    {
        if(S == 'S') nextstatus = 'V';
        if(S == 'U') nextstatus = 'V';
        if(S == 'V') nextstatus = 'Q';
        if(S == 'Q') nextstatus = 'Q';
    }
    return nextstatus;
}
int DFA(char *t)
{
    char S='S';
    for( int i = 0; t[i] != '\0'; i++)
        S = Move(S,t[i]);
    if(S == 'Q')
        return 1;
    else
        return 0;
}
int main()
{
    char input[50];
    while(scanf("%s", input) != EOF)
    {
        if(DFA(input))
            printf("accept\n");
        else
            printf("not accept\n");
    }
    return 0;
}
