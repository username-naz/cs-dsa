#include <stdio.h>
#include <math.h>

struct BigInt {
    char digits[14000];
    int length;
};

struct BigInt addBigInts(struct BigInt num1,struct BigInt num2){
    int carryFlag = 0;
    struct BigInt sum;
    struct BigInt a = num1.length>num2.length?num1:num2;
    struct BigInt b = num1.length>num2.length?num2:num1;
    int length  = a.length;

    for(int i = 0; i < length; i++){
        int result = a.digits[i] + b.digits[i] + carryFlag;
        sum.digits[i] = result - (result/10) * 10;
        carryFlag =  result<10?0:1;
    }
    if(carryFlag==1) {
        sum.digits[length] = 1;
        length++;
    }
    sum.length = length;
    return sum;
}

struct BigInt getFibNum(int  n){
    struct BigInt result;
    result.digits[0] = 1;
    result.length = 1;

    struct BigInt prev;
    prev.digits[0] = 1;
    prev.length = 1;

    if(n<3)
        return result;
    
    for(int i = 3; i<=n; i++){
        struct BigInt tempPrev;
        tempPrev = prev;
        prev = result;
        result = addBigInts(tempPrev, result);
    }

    return result;
}

int main(){
    struct BigInt a;
    printf("Enter n for F(n): ");
    int n;
    scanf("%d", &n);
    struct BigInt result = getFibNum(n);

    printf("\nresult:\n");
    for(int i=result.length-1; i>=0; i--)
        printf("%d", result.digits[i]);

}