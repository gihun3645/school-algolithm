//
// Created by User on 2023-03-15.
//
#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++)
        a[i] = 10 + i;
    int i, j, k;
    while (1) {
        printf("for p = &a[k]\n  k ? ");
        scanf("%d", &k);
        if (k == 0)
            break;
        putchar('\n');
        int *p;
        p = &a[k];            // p = a + k;
        printf("for a[i]\n");
        while (1) {
            printf("       i ? ");
            scanf("%d", &i);
            if (i < 0 || i >= 10)
                break;
            printf("    a[%d] = %d\n", i, a[i]);
            printf("*(a + %d) = %d\n", i, *(a + i));
            printf("       j = i - k = %d\n", j = i - k);
            //
            printf("*(p + j) = %d\t\t; *(p%+d)\n", *(p + j), j);
            printf("    p[j] = %d\t\t; p[%d]\n", p[j], j);
            putchar('\n');
        }
        putchar('\n');
    }
    printf("Bye, ...\n\n");
}