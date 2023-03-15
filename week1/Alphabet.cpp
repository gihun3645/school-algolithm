//
// Created by 송기훈 on 2023/03/13.
//

#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)


#define N 26

int main(void) {
    // 다음을 출력하라
    for (int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            putchar('A'+(i+j)%N);
        }
        // 줄바꿈
        putchar(10);
    }
}
