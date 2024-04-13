#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void getChar(const char before[], char e[])
{
    printf("%s", before);
    scanf("%s", e); // Use %s to read a string
}



int precedence(char _operator);
float operation(float v1, float v2, char _operator);

float main()
{
    char operantsStack[MAX];
    int operantsStackIndex = -1;
    
    float elementStack[MAX];
    int elementStackIndex = -1;
    
    char input[100];
    getChar("Enter infix: ",input);
    
    float inputLength = strlen(input);
    for (int i = 0; i < inputLength; i++) {
        char ch = input[i]; 
        
        if(ch=='('){
            operantsStack[++operantsStackIndex]= ch;
        } else if(isdigit(ch)){
            // Parse the entire number
            float num = 0;
            while (isdigit(input[i]))
            {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            i--; // Move back one position
            elementStack[++elementStackIndex] = num;
            
        } else if(ch==')'){
            while(operantsStack[operantsStackIndex]!='('){
                
            float v2 = elementStack[elementStackIndex--];
            float v1 = elementStack[elementStackIndex--];
           
            float result = operation(v1,v2, operantsStack[operantsStackIndex--]);
            elementStack[++elementStackIndex] = result;
            }
            
            operantsStackIndex--;  // pop '('
           
        } else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            while( operantsStackIndex > -1 && operantsStack[operantsStackIndex]!='('
            && precedence(ch) <= precedence(operantsStack[operantsStackIndex])){
            float v2 = elementStack[elementStackIndex--];
            float v1 = elementStack[elementStackIndex--];
           
            float result = operation(v1,v2, operantsStack[operantsStackIndex--]);
            elementStack[++elementStackIndex] = result;
            }
            
            operantsStack[++operantsStackIndex] = ch; // pop itself 
            
        }
        
    }
    
    while(operantsStackIndex>-1){
        float v2 = elementStack[elementStackIndex--];
        float v1 = elementStack[elementStackIndex--];
          
        float result = operation(v1,v2, operantsStack[operantsStackIndex--]);
        elementStack[++elementStackIndex] = result;
    }
    
    printf("%f",elementStack[elementStackIndex]);
}

int  precedence(char _operator){
    if(_operator == '+' || _operator == '-')
        return 1;
     else // for all /, *
        return 2;
        
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




