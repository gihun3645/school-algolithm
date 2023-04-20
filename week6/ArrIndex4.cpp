#include <stdio.h>

#define	N1	9
#define	N2	8
#define	N3	7
#define	N4	8
#define DIM	4
#pragma warning(disable: 4326 4996 6031)

int main(void)
{
    int B[N1][N2][N3][N4];
    int nArrDesc[2 * DIM + 1] = {DIM, 0, 0, 0, 0, N1, N2, N3, N4};
    int nDim = DIM;
    int *nNdx = nArrDesc + 1;
    int *nBound = nArrDesc + 1 + DIM;
    for (int i = 0; i < nBound[0]; i++)
        for (int j = 0; j < nBound[1]; j++)
            for (int k = 0; k < nBound[2]; k++)
                for (int l = 0; l < nBound[3]; l++)
                    B[i][j][k][l] = i * 1000 + j * 100 + k * 10 + l;
    int IsOK = true;
    while (IsOK) {
        int nValue;
        printf("index> ");
        for (int i = 0; i < DIM && IsOK; i++) {
            scanf("%d", nNdx + i);
            if (i == 0 && nNdx[i] < 0)
                IsOK = false;
        }
        if (IsOK) {
            int Aij(int A[], int nArrDesc[], int &nValue);
            if (Aij((int *)B, nArrDesc, nValue))
                printf("A[%d][%d][%d][%d] = %d(%d)\n",
                       nNdx[0], nNdx[1], nNdx[2], nNdx[3], B[nNdx[0]][nNdx[1]][nNdx[2]][nNdx[3]], nValue);
            else
                printf("색인 오류, ....\n");
            putchar('\n');
        }
    }
    printf("Bye, ....\n\n");
}

int Aij(int A[], int nArrDesc[], int &nValue)
{	// 적절한 색인이면 nValue에 색인에 대한 배열의 값을 저장하고 T/F를 반환한다.
    // 알다시피 차원에 따라 식이 달라지기 때문에, 대신 for loop를 사용하여 식을 계산하라.
    // 아래와 같이 색인의 순서를 거꾸로 계산을 한다.
    // nNdx[3] * nSize +		;; nSize = 1;
    // nNdx[2] * nSize +		;; nSize = nBound[3]
    // nNdx[1] * nSize +		;; nSize = nBound[2] * nBound[3]
    // nNdx[0] * nSize			;; nSize = nBound[1] * nBound[2] * nBound[3]
    int nSize = 1, nSum = 0;
    int nDim = nArrDesc[0];
    int *nNdx = nArrDesc + 1;
    int *nBound = nArrDesc + 1 + nDim;
    for (int i = nSum -1; i >= 0; i--) {
        if (nNdx[i] < 0 || nNdx[i] >= nBound[i])
            return false;
        nSum += nNdx[i] * nSize;
        nSize *= nBound[i];
    }
    nValue = A[nSum];
    return true;
}