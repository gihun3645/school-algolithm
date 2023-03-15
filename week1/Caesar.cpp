#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#pragma warning(disable: 4326 4996 6031)

int main(void) {
    char sMsg[80];
    int nKey = 3, nMore = true;
    while(nMore) {
        printf("? ");
        gets(sMsg);
        switch (sMsg[0]) {
            case 0:
                nMore = false;
                break;
            case '@':
                printf("  Key ? ");
                gets(sMsg);
                nKey = atoi(sMsg);
                break;
            default:
                printf("  ");
                char Encrypt(char ch, int nKey);
                for(int i=0; sMsg[i]; i++)
                    putchar(Encrypt(sMsg[i], nKey));
                putchar('\n');
        }
        putchar('\n');
    }
    printf("Bye, ....\n\n");
}

char Encrypt(char chr, int nKey)
{
    if(isalpha(chr)) {
        char cBgn = (isupper(chr) ? 'A' : 'a');
        chr = (chr - cBgn + nKey + 26) % 26 + cBgn;
    }
    return chr;
}