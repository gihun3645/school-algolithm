//
// Created by 송기훈 on 2023/03/13.
//
#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

// chatGPT로 짠 코드
//void MultiTblDan(int nDan);
//void MultiTblRow(int nDan, int nRow);
//void MultiTbl();
//
//int main(void) {
//    MultiTbl();
//}
//
//// n단 x (2~9)
//void MultiTblDan(int nDan) {
//    for(int i=2; i<=9; i++) {
//        printf("%d x %d = %2d\n", nDan, i, nDan*i);
//    }
//}
//
//
//void MultiTblRow(int nDan, int nRow) {
//    for(int i=2; i<=9; i+= nRow) {
//        for(int j=0; j<nRow && i+j<=9; j++) {
//            printf("%d x %d = %2d\t", nDan, i+j, nDan*(i+j));
//        }
//        printf("\n");
//    }
//}
//
//void MultiTbl() {
//    for(int i=2; i<=9; i++) {
//        MultiTblRow(i, 1);
//        printf("\n");
//    }
//}

// 교수님 코드
//
void MultiTbl();
void MultiTblRow(int nDan, int nRow);
void MultiTbl();
void MultiTblDan(int nDan);

// 구구단의 한 행(nDan의 nRow행)을 출력한다.
void MultiTblRow(int nDan, int nRow) {
    printf("%d x %d = %2d\n", nDan, nRow, nDan * nRow);
}

// 구구단의 한 단(nDan)을 출력한다
void MultiTblDan(int nDan) {
    void MultiTblRow(int nDan, int nRow);
    for(int nRow=2; nRow<=9; nRow++) {
        MultiTblRow(nDan, nRow);
    }
}

// 2단부터 9단까지 구구단을 출력한다.
void MultiTbl() {
    void MultiTblDan(int nDan);
    for(int nDan = 2; nDan <= 9; nDan++) {
        MultiTblDan(nDan);
        putchar(10);
    }
}

int main(void) {
    MultiTbl();
}