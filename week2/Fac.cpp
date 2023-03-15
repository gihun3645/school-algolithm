//
// Created by User on 2023-03-15.
//


#include <stdio.h>


int Fact(int n)
{
    if (n == 0)
        return 1;
    int nFact = Fact(n-1);
    return n * nFact;
}

int main(void)
{
    while (1) {
        int n;
        printf("n ? : ");
        scanf("%d", &n);
        if (n < 0)
            break;
        int Fact(int n);
        printf("%d! = %d\n\n", n, Fact(n));
    }
}