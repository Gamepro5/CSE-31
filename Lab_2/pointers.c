#include <stdio.h> 
 
int main() { 
    int x, y, *px, *py;
    px = &x;
    py = &y;
    int arr[10];
    //for (int i=0;i<10;i++) {
    //    printf("%i\n%i\n",*(arr+i), arr[i]);
    //}
    printf("%p\n", &arr);
    //printf("%i\n%i\n%p\n%p\n%i\n%i\n", x, y, px, py, *px, *py);
    return 0;
} 