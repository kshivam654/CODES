#include<bits/stdc++.h>
using namespace std;
// int main(){

//     int x = 5;
//     int *p;
//     p = &x;
//     printf("%d", *p);

//     // int precision = 3;
//     // float  value = 123.3;
//     // printf("%*f", precision, value);
//     int my_array[5] = {1, 2, 3, 4, 5};
//     for(int i = 0; i < sizeof(my_array)/sizeof(int); ++i){
//         cout << my_array[i] << " ";
//     }
//     return 0;
// }

int main(){
    char a[] = {'a', 'b', 'c', 'd'};
    char *p = &a[0];
    *p++;
    printf("%c, %c\n", *++p, --*p);
    cout << a;
    return 0;
}