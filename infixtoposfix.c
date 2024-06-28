#include <stdio.h>
#include<ctype.h>
#define size 10

char stack [size];
int top = -1;
void push(char ele){
    if(top <size-1){
        top++;   
        stack[top] = ele;
    }
    else{
        printf("stack overflow");
    }
}
char pop(){
    if(top>=0){
        char ele = stack[top];
        top = top-1;
        return ele;
    }
    return '\0';
}
int oper(char ele){
    if(ele == '+' || ele == '-' ||ele == '*' ||ele == '/' ||ele == '^'){
        return 1;
    }
    return 0;

}
int rank(char ele){
switch(ele){
         case '+':return 1;
         break;
         case '-':return 1;
         break;
         case '*':return 2;
         break;
         case '/':return 2;
         break;
         case '^':return 3;
         break;
         default: return 0;
}}
void conv(char inf[],char pos[]){
    int i = 0;
    int j = 0;
    while(inf[i] !='\0'){
        char ele = inf[i];
        if(isalnum(ele)){
            pos[j] = ele;
            j=j+1;
        }
        else if(ele == '('){
            push(ele);
        }
        else if(ele == ')'){
            char popele = pop();
            while(popele !='('){
                pos[j] = popele;
                j = j+1;
                popele = pop();
            }
        }
        else if(oper(ele)){
            while(top>0 &&rank(stack[top]) >= rank(ele)){
                pos[j] = pop();
                j=j+1;
            }
            push(ele);
        }
        i = i+1;
    }
    
    while(top>=0){
        pos[j] = pop();
        j = j+1;
    }
    pos[j] = '\0';
}

int main(){
    char inf[size];
    char pos[size];
    printf("enter the number: \n");
    scanf("%s",inf);
    conv(inf,pos);
    printf("postfix expression:%s",pos);
    return 0;
}
