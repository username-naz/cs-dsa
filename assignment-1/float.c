#include <stdio.h>
#include <string.h>

int isFloat(char* num, int length){
    int digitsBeforeDot = 0;
    int digitsAfterDot = 0;
    
    for(int i = 0, dotPassed =0; i<length; i++){
        char currentDigit = *(num+i);
        if(currentDigit == '-' && i==0) continue;
        
        if(currentDigit == '.'&& !dotPassed) {dotPassed = 1; continue;};
        
        
        if(!dotPassed) digitsBeforeDot++;
        else digitsAfterDot++;
        
        if((currentDigit < 48 || currentDigit> 57)) return 0;
    }
    
    if(digitsBeforeDot == 0 || digitsAfterDot == 0) return 0;
    
    return 1;
}

int main()
{
    char num[15];
    scanf("%s", num);
    int result;
    result = isFloat(num, strlen(num));
    
    result?printf("vlaid"):printf("invalid");
    return 0;
}