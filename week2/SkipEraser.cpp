#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

#define N 1000

int SkipEraser1(int n)
{
    int nNecklace[N], nNdx = 1; // 목걸이를 배열로 정의한다(1에서 n까지)
    for (int i = 1; i <= n; i++) // 목걸이 n개의 구슬을 1에서 n까지 초기화 한다
    {
        nNecklace[i] = i;
    }

    for (int i = 1; i < n; i++)
    {
        int NextBeadNdx(int nNecklace[], int nNdx, int nMod);
        nNecklace[nNdx = NextBeadNdx(nNecklace, nNdx, n)] = 0;
        nNdx = NextBeadNdx(nNecklace, nNdx, n);
    }
    return nNecklace[nNdx];
}

int NextBeadNdx(int nNecklace[], int nNdx, int nMod)
{
    int NextNdx(int nNdx, int nMod);
    while (nNecklace[nNdx = NextNdx(nNdx, nMod)] == 0);
    return nNdx;
}

int NextNdx(int nNdx, int nMod)
{
    return nNdx % nMod + 1;
}

int SkipEraser2(int n)
{
    int nNecklace[N]; // 목걸이를 배열로 정의한다(0에서 n-1까지)
    for (int i = 0; i < n; i++) // 목걸이 n개의 구슬을 1에서 n까지 초기화 한다
    {
        nNecklace[i] = i + 1;
    }

    while (n > 1)
    {
        for (int nTo = 0, nFrom = n % 2 * 2, nHalf = n / 2; nTo < nHalf; nTo++, nFrom += 2)
        {
            nNecklace[nTo] = nNecklace[nFrom];
        }
        n /= 2;
    }
    return nNecklace[0];
}

int SkipEraser3(int n) // 순환 함수로 작성
{
    if (n == 1)
    {
        return 1;
    }
    // 짝수면 -1 홀수면 1
    return 2 * SkipEraser3(n / 2) + (n % 2) * 2 - 1;
}

int main(void)
{
    while (1)
    {
        printf("? ");
        int n;
        scanf("%d", &n);
        if (n <= 0 || n > N)
        {
            break;
        }
        // 이 함수는 작동에는 별 문제가 없음
        int SkipEraser1(int n);
        int SkipEraser2(int n);
        int SkipEraser3(int n);
        printf("Simulation: %d\n", SkipEraser1(n));
        printf("Simulation: %d\n", SkipEraser2(n));
        printf(" Recursion: %d\n\n", SkipEraser3(n));
    }
    printf("Bye, ...\n");
    return 0;
}