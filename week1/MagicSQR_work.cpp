#include <stdio.h>
#include <math.h>

#pragma warning(disable : 4326 4996 6031 6262)

#define	N	100

int main(void)
{
    void MakeMagicSquare(int nMagicSqr[][N], int nN);
    void ShowMagicSquare(int nMagicSqr[][N], int nN);
    void CheckMagicSquare(int nMagicSqr[][N], int nN);

    int nN;
    int nMagicSqr[N][N];
    while (1) {
        printf("? ");
        scanf("%d", &nN);
        // 짝수
        if (nN <= 2 || nN > N)
            break;
        MakeMagicSquare(nMagicSqr, nN);
        ShowMagicSquare(nMagicSqr, nN);
        CheckMagicSquare(nMagicSqr, nN);
        putchar('\n');
    }
    printf("Bye, ....\n");
}

void MakeMagicSquare(int nMagicSqr[][N], int nN)
{
    // 출력 포맷을 초기화
    // 홀수인 경우
    // 짝수이면서 4의 배수가 아닌 경우
    // 4의 배수인 경우
    void OddMagicSquare(int nMagicSqr[][N], int nN, int nOrgRow, int nOrgCol, int nBgn);
    void DblyEvenMagicSquare(int nMagicSqr[][N], int nN);

    if (nN % 2 == 1)
        OddMagicSquare(nMagicSqr, nN, 0, nN / 2, 1);
    else if (nN % 4 != 0)
        OddMagicSquare(nMagicSqr, nN, 0, nN / 2 - 1, 2);
    else
        DblyEvenMagicSquare(nMagicSqr, nN);
}

static char sFmt0[] = "%1d ";
static char sFmt1[] = "행 %1d";
static char sFmt2[] = "열 %1d";
static char sFmt3[] = "대 %1c";

void ShowMagicSquare(int nMagicSqr[][N], int nN)
{
    printf("\n[마방진]\n");
    for (int nRow = 0; nRow < nN; nRow++) {
        for (int nCol = 0; nCol < nN; nCol++)
            printf(sFmt0, nMagicSqr[nRow][nCol]);
        putchar('\n');
    }
}

void CheckMagicSquare(int nMagicSqr[N][N], int nN)
{
    void CheckMagicSquareRow(int nMagicSqr[N][N], int nN);
    void CheckMagicSquareCol(int nMagicSqr[N][N], int nN);
    void CheckMagicSquareDgl(int nMagicSqr[N][N], int nN, int nDir);

    CheckMagicSquareRow(nMagicSqr, nN);
    CheckMagicSquareCol(nMagicSqr, nN);
    printf("\n[대각선 검사]\n");
    CheckMagicSquareDgl(nMagicSqr, nN, '\\');
    CheckMagicSquareDgl(nMagicSqr, nN, '/');
}

void InitFormat(int nN)
{
    sFmt0[1] = (int)log10(nN * nN) + 0x31;
    sFmt1[4] = sFmt2[4] = sFmt3[4] = (int)log10(nN - 1) + 0x31;
}

void CheckMagicSquareRow(int nMagicSqr[N][N], int nN)
{
    printf("\n[행 검사]\n");
    for (int nRow = 0; nRow < nN; nRow++) {
        printf(sFmt1, nRow);
        int nSum = 0;
        for (int nCol = 0; nCol < nN; nCol++) {
            printf("%c ", nCol ? '+' : ':');
            printf(sFmt0, nMagicSqr[nRow][nCol]);
            nSum += nMagicSqr[nRow][nCol];
        }
        printf("= %d\n", nSum);
    }
}

void CheckMagicSquareCol(int nMagicSqr[N][N], int nN)
{
    printf("\n[열 검사]\n");
    for (int nCol = 0; nCol < nN; nCol++) {
        printf(sFmt2, nCol);
        int nSum = 0;
        for (int nRow = 0; nRow < nN; nRow++) {
            printf("%c ", nRow ? '+' : ':');
            printf(sFmt0, nMagicSqr[nRow][nCol]);
            nSum += nMagicSqr[nRow][nCol];
        }
        printf("= %d\n", nSum);
    }
}

void CheckMagicSquareDgl(int nMagicSqr[N][N], int nN, int nDir)
{
    int nSum = 0, nDgnl = nDir == '/';
    int nCol = nDgnl * (nN - 1), nDelta = 1 - nDgnl * 2;
    printf(sFmt3, nDir);
    for (int nRow = 0; nRow < nN; nRow++, nCol += nDelta) {
        printf("%c ", nRow ? '+' : ':');
        printf(sFmt0, nMagicSqr[nRow][nCol]);
        nSum += nMagicSqr[nRow][nCol];
    }
    printf("= %d\n", nSum);
}

void OddMagicSquare(int nMagicSqr[][N], int nN, int nOrgRow, int nOrgCol, int nBgn)
{
    // 실습: (nRow, nCol)이 (0, 0)에서 1부터 시작,
    // 과제: (nOrgRow, nOrgCol)에서 nBgn부터 시작되도록 수정해야 한다
    // 예제: 크기가 10인 경우, 4등분하면 크기가 5인 홀수 마방진이 생긴다.
    //  17  24   1   8  15  67  74  51  58  65
    //  23   5   7  14  16  73  55  57  64  66
    //   4   6  13  20  22  54  56  63  70  72
    //  10  12  19  21   3  60  62  69  71  53
    //  11  18  25   2   9  61  68  75  52  59
    //  92  99  76  83  90  42  49  26  33  40
    //  98  80  82  89  91  48  30  32  39  41
    //  79  81  88  95  97  29  31  38  45  47
    //  85  87  94  96  78  35  37  44  46  28
    //  86  93 100  77  84  36  43  50  27  34						OddMagicSquare(nMagicSqr, 10)
    // 홀수 마방진 A는 (0, 0)에서 시작하는 붉은색 블록에서  1부터 시작	OddMagicSquare(nMagicSqr, 5, 0, 0, 1)
    // 홀수 마방진 B는 (5, 5)에서 시작하는 갈대색 블록에서 26부터 시작	OddMagicSquare(nMagicSqr, 5, 5, 5, 26)
    // 홀수 마방진 C는 (0, 5)에서 시작하는 보라색 블록에서 51부터 시작	OddMagicSquare(nMagicSqr, 5, 0, 5, 51)
    // 홀수 마방진 D는 (5, 0)에서 시작하는 하늘색 블록에서 76부터 시작	OddMagicSquare(nMagicSqr, 5, 5, 0, 76)
    //
    // 이렇게 다양한 홀수 마방진이 nOrgRow, nOrgCol, nBgn으로 매개변수로 호출될 수 있다
    // 이러한 경우를 지원하도록 확장해야 한다.
}

void DblyEvenMagicSquare(int nMagicSqr[][N], int nN)
{
    // 이번 과제의 주요 부분입니다.
    // (i+j+1) 또는 (i-j)가 4의 배수 여부에 따라 ...
}