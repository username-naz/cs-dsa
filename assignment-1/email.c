#include <stdio.h>
#include <string.h>

int isValidMail(char* email, int length){
    int localLength = 0, domainLength = 0;
    while(*(email+localLength) != '@' && localLength <= length){
        localLength++;
    }
    
    domainLength = length - localLength - 1;

    if(!localLength||(localLength>52) || !domainLength || domainLength<1 || domainLength > 63) return 0;
    
    int dotOn = 0;
    for(int i = 0; i<localLength;i++){
        char currentChar = *(email + i);
        if(currentChar==' ') return 0;
        
        if(!((currentChar>47 && currentChar<58) || (currentChar>64 && currentChar<123)) && !(
            currentChar == '!'||
            currentChar == '#'||
            currentChar == '$'||
            currentChar == '*'||
            currentChar == '%'||
            currentChar == '&'||
            currentChar == '_'||
            currentChar == 39 ||
            currentChar == '+'||
            currentChar == '-'||
            currentChar == '{'||
            currentChar == '}'||
            currentChar == '^'||
            currentChar == '~'||
            currentChar == '|'||
            currentChar == '.'
            )) return 0;
         
        if(dotOn && currentChar=='.') return 0;
            
        dotOn = currentChar == '.';
        if(dotOn){
            if(i==0) return 0;
            if(i==(localLength-1)) return 0;
        }
            
    }

    dotOn = 0;
        for(int i = localLength+1; i<length; i++){
            char currentChar = *(email+i);
            printf(" %c ", currentChar);
            if(!((currentChar>47 && currentChar<58) || (currentChar>64 && currentChar<123)) && !(
            currentChar == '('||
            currentChar == ')'||
            currentChar == '['||
            currentChar == ']'||
            currentChar == '.'||
            currentChar == '-'
            )) return 5;

            if(dotOn && currentChar=='.') return 0;
            
            dotOn = currentChar == '.';
            if(dotOn){
                if(i==localLength) return 0;
                if(i==(length-1)) return 0;
            }
            
            if(currentChar == '-' && (i==localLength || i==(length-1)))return 0;
        }
    
    return 1;
}

int main()
{
    char email[200];
    scanf("%[^\n]%*c", email);
    int result = isValidMail(email, strlen(email));
    printf("%d", result);
    return 0;
}
