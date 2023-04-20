#include <stdio.h>

#define	SIZE	10
#pragma warning(disable: 4326 4996 6031)

int main()
{
    int B[] = { 00,										// 0
                10,	11,									// 1, 2
                20,	21,	22,								// 3, 4, 5
                30,	31,	32,	33,							// 6, 7, 8, 9
                40,	41,	42,	43,	44,						// 10, 11, ...
                50,	51,	52,	53,	54,	55,
                60,	61,	62,	63,	64,	65,	66,
                70,	71,	72,	73,	74,	75,	76,	77,
                80,	81,	82,	83,	84,	85,	86,	87,	88,
                90,	91,	82,	93,	94,	95,	96,	97,	98,	99 };
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
        if (Aij(B, i, j, SIZE,  value) == false)
            printf("색인 오류, ....\n");
        else
            printf("A[%d][%d] = %d\n", i, j, value);
        putchar('\n');
    }
    printf("Bye, ....\n\n");
}

int Aij(int arr[], int i, int j, int n, int &nValue)
{	// 적절한 색인이면 nValue에 값을 저장하고 T/F를 return한다.
    if (i < 0 || i >= n ||
    j < 0 || j >= n)
        return false;
    int k = i * (i + 1) / 2 + j;
    nValue = i >= j ? arr[k] : 0;
    return true;
}