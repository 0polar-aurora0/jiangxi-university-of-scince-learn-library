
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;//��ʱ���������������
    while (scanf("%s", c)) {
        if (isdigit(c)) {
           printf("accept\n");
        } else  printf("not accept\n");
    }
    return 0;
}
