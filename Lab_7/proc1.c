#include<stdio.h>

int sum(int a0, int a1) {
    return a0 + a1;
}

int main() {
    int m = 10;
    int n = 5;
    

   int v0 = sum(m, n);

    printf("%d\n", v0);
    return 0;
}
