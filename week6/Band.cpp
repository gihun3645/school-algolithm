


#include <stdio.h>

#define	SIZE	10
#pragma warning(disable: 4326 4996 6031)

int main(void)
{
    int B[] = { 00, 01,										// 0, 1,
                10, 11, 12,									// 2, 3, 4,
                21, 22,	23,								// 5, 6, 7,
                32,	33,	34,							// 8, ....
                43,	44,	45,
                54,	55,	56,
                65,	66,	67,
                76,	77,	78,
                87,	88,	89,
                98,	99 };
    // 2차원 대각행렬을 이렇게 1차원 B에 저장했습니다.
    // 값이 지정되지 않은 곳은 0으로 간주합니다.

    while (1) {
        int i, j, value;
        printf("index> ");
        scanf("%d", &i);
        if (i < 0)
            break;
        scanf("%d", &j);
        int Aij(int arr[], int i, int j, int nSize, int *pValue);
        if (Aij(B, i, j, SIZE, &value) == false)
            printf("색인 오류, ....\n");
        else
            printf("A[%d][%d] = %d\n", i, j, value);
        putchar('\n');
    }
    printf("Bye, ....\n\n");
}

int Aij(int arr[], int i, int j, int n, int *pValue)
{	// 2차원 배열 A가 1차원 배열 B로 저장할 때 A[i][j]에 해당하는 B[?]를 pValue에 저장하고 T/F를 반환한다.
    if (i < 0 || i >= n ||
    j < 0 || j >= n)
        return false;
    int nDelta = j - i;
    int k = 3 * i + nDelta;
    *pValue = nDelta >= -1 && nDelta <= 1 ? arr[k] : 0;
    return true;
}