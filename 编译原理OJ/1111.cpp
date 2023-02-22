#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool isD(char c)
{
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}
bool isA(char c)
{
    if(c == '_'){
        return 1;
    }
    if(c >= 'a' && c <= 'z'){
        return 1;
    }
    if(c >= 'A' && c <= 'Z'){
        return 1;
    }
    return 0;
}

int DFA(char input[]){
	int len = strlen(input);
	if(!isA(input[0])){
        return 0;
	}
    bool endstatus = 0;
	for(int i=1;i<len;i++){
		if(isA(input[i]) || isD(input[i])){
            endstatus = true;
		}else{
            return 0;
		}
	}
	return 1;
}
int main()
{
	char input[50];
	while(gets(input) != NULL){
        bool flag = DFA(input);
        if(flag){
            cout<<"accept"<<endl;
        }else{
            cout<<"not accept"<<endl;
        }
	}
	return 0;
}
