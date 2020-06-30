#include<stdio.h>
int main()  
{   
    int a[5] = {1,2,3,4,5};
    a[-1] = 9;
    
    printf("%d", a[4]);
    return 0;
}
