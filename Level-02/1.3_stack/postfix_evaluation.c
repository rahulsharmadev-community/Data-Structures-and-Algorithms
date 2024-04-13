
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

float operation(float v1, float v2, char _operator);
void getChar(const char before[], char e[]);

int main()
{
    float stack[MAX];
    int stackIndex = -1;
    
    char input[100];
    getChar("Enter postfix (separated by ','): ",input);
    
    float inputLength = strlen(input);
    for (int i = 0; i < inputLength; i++) {
        char ch = input[i]; 
        if(isdigit(ch)){
            float num=0;
            while(isdigit(input[i])){
                num=num *10 + (input[i] - '0');
                i++;
            }
            i--; // Move back one step (for increment and this will neutral)
            stack[++stackIndex] = num;
            
        }else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            float v1 = stack[stackIndex--];
            float v2 = stack[stackIndex--];
            
            float sol = operation(v1,v2, ch);
            stack[++stackIndex]= sol;
        }
    }
    
    printf("%f", stack[stackIndex]);
    

    return 0;
}







void getChar(const char before[], char e[])
{
    printf("%s", before);
    scanf("%s", e); // Use %s to read a string
}

float operation(float v1, float v2, char _operator){
    if(_operator == '+')
        return v1 + v2;
     else if(_operator == '-')
        return v1 - v2;
     else if(_operator == '*')
        return v1 * v2;
     else return v1 / v2;
        
}
