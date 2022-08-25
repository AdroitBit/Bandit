#include<stdio.h>
float stack[100];
int top = -1;

void push(float x){
    stack[++top] = x;
}

float pop(){
    return stack[top--];
}

int main(){
    int n;
    scanf("%d", &n);

    char exp[100];
    char *e;
    float n1,n2,num;
    float n3;
    scanf("%s",exp);
    e = exp;
    while(*e != '\0'){
        if(isdigit(*e)){
            num = *e - 48;
            push(num);
        }
        else{
            n1 = pop();
            n2 = pop();
            switch(*e){
                case '+':
                    n3 = n1 + n2;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n1 * n2;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
            }
            push(n3);
        }
        e++;
    }
    printf("%.2f\n",pop());
    return 0;
}