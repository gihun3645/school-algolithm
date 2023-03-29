#include <stdio.h>

int main(void)
{
    while (1) {
        printf("정수 ? ");
        int nNmbr;
        scanf("%d", &nNmbr);
        if (nNmbr <= 0)
            break;
        int Lyons(int nNmbr);
//        int Simple(int nNmbr);
//        int Spence(int nNmbr);
//        int Toja(int nNmbr);
        printf(" Lyons: %d\n", Lyons(nNmbr));
//        printf("Simple: %d\n", Simple(nNmbr));
//        printf("Spence: %d\n", Spence(nNmbr));
//        printf("  Toja: %d\n\n", Toja(nNmbr));

    }
    printf("Bye, ...\n");
}

int Lyons(int nNmbr)
{
    int nGroup[3] = {0};
    int idx = 0;
    int rem;

    while (nNmbr > 0) {
        rem = nNmbr % 100;
        nGroup[idx] += rem % 7;
        nNmbr /= 100;
        idx = (idx + 1) % 3;
    }

    int sum1 = nGroup[0] + nGroup[1];
    int sum2 = nGroup[1] + nGroup[2];

    int rem1 = sum1 % 7;
    int rem2 = sum2 % 7;

    int result = rem2 - rem1;
    if (result < 0) {
        result += 7;
    }

    return (result == 0);
}

int Simple(int nNmbr)
{
    static int nRems[] = { 1, 3, 2, 6, 4, 5 };
//    //
//    // ???
//    //

//    return true;		// 또는 return false;
}

int Spence(int nNmbr)
{
    //
    // ???
    //
    return true;		// 또는 return false;
}

int Toja(int nNmbr)
{
    //
    // ???
    //
    return true;		// 또는 return false;
}

