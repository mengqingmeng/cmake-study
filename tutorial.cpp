#include <iostream>
#include "head.h"

int main(){
    int a = 12,b=20;
    printf("a=%d,b=%d\n",a,b);
    printf("a + b = %d \n",add(a,b));
    printf("a - b = %d \n",subtract(a,b));
    printf("a * b = %d \n",multiply(a,b));
    printf("a / b = %f \n",divide(a,b));
    return 1;
}