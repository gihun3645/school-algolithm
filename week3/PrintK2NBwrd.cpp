#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

void main()
{
	while (1) {
		int k, n;
		printf("k ? ");
		scanf("%d", &k);
		if (k < 0)
			break;
		printf("n ? ");
		scanf("%d", &n);
		if (k > n)
			break;
		int PrintK2NBwrd1(int k, int n);
		int PrintK2NBwrd2(int k, int n);
		int PrintK2NBwrd3(int k, int n);
		int PrintK2NBwrd4(int k, int n);
		int PrintK2NBwrd5(int k, int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd1(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd2(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd3(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd4(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd5(k, n));
	}
}

// k부터 n까지 거꾸로 출력하고 그들의 합을 반환한다
int PrintK2NBwrd1(int k, int n)		// n-1개, 1개
{
	/***
	[분할] ?
	[일반규칙] p(k,n) ::= ?
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	return 0;
}

int PrintK2NBwrd2(int k, int n)		// 1개, n-1개
{
	/***
	[분할] ?
	[일반규칙] p(k,n) ::= ?
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	return 0;
}

int PrintK2NBwrd3(int k, int n)		// n/2개, 1개, n/2개
{
	/***
	[분할] ?
	[일반규칙] p(k,n) ::= ?
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	return 0;
}

int PrintK2NBwrd4(int k, int n)		// n/3개, 1개, n/3개, 1개, n/3개
{
	/***
	[분할] ?
	[일반규칙] p(k,n) ::= ?
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	return 0;
}

int PrintK2NBwrd5(int k, int n)		// n/4개, 1개, n/4개, 1개, n/4개, 1개, n/4개
{
	/***
	[분할] ?
	[일반규칙] p(k,n) ::= ?
	[진행방향] ?
	[중단조건] ?
	[단순해] ?
	***/
	return 0;
}
