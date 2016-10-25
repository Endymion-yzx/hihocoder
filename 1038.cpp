// hiho1038 backpack
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

inline int max(int x, int y){ return (x > y) ? x : y; }

int main(){
	int i, j, N, M, value[510], need[510], dp[100100];
	scanf("%d%d", &N, &M);

	for (i = 0; i <= N - 1; i++) scanf("%d%d", &need[i], &value[i]);

	memset(dp, 0, sizeof(dp));
	for (i = 0; i <= N - 1; i++){
		for (j = M; j >= need[i]; j--)
			dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
	}

	printf("%d", dp[M]);
	return 0;
}