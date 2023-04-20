#include <stdio.h>

#define	SIZE	10
#pragma warning(disable: 4326 4996 6031)

int main(void)
{
    int B[] = { 0,	 1,  2,  3,  4,  5,  6,  7,  8,  9,	// 0,  1,  ...
                11,	12, 13, 14, 15, 16, 17, 18,	19,	// 10, 11, ...
                22,	23, 24, 25, 26, 27,	28, 29,	// 19, 20, ...
                33,	34, 35, 36,	37, 38, 39,	// 27, 28, ...
                44,	45, 46, 47, 48,	49,	// 34, 35, ...
                55, 56, 57, 58, 59,
                66, 67, 68, 69,
                77, 78, 79,
                88, 89,
                99 };
    // 2차원 하위삼각행렬을 이렇게 1차원 B에 저장했습니다.
    // 값이 지정되지 않은 곳은 0으로 간주합니다.

    while (1) {
        int i, j, value;
        printf("index> ");
        scanf("%d", &i);
        if (i < 0)
            break;
        scanf("%d", &j);
        int Aij(int arr[], int i, int j, int n, int &nValue);
        if (Aij(B, i, j, SIZE, value) == false)
            printf("색인 오류, ....\n");
        else
            printf("A[%d][%d] = %d\n", i, j, value);
    }
    printf("Bye, ....\n\n");
}

int Aij(int arr[], int i, int j, int n, int &nValue)
{	/* 적절한 색인이면 nValue에 값을 저장하고 T/F를 return한다. */
    // 개수를 세면 된다?
    if (i < 0 || i >= n ||
    j < 0 || j >= n)
        return false;
    int k = (n + n - i + 1) * i / 2 + j -i;
    nValue = i <= j ? arr[k] : 0;
    return true;
}
