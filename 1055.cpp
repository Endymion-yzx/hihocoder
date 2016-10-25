// hiho1055
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

int adj[110][110];      // 邻接表
int dp[110][110], V[110];
bool flag[110];

int max(int x, int y){ return (x > y) ? x : y; }

void dfs(int cur, int m, int N){
	flag[cur] = true;
	dp[cur][0] = 0;
	for (int i = 1; i <= m; i++) dp[cur][i] = V[cur];

	for (int tc = 0; tc <= N - 1; tc++){
		if (adj[cur][tc] && !flag[tc]){
			dfs(tc, m - 1, N);
			for (int i = m; i >= 2; i--)
			for (int mc = 1; mc <= i - 1; mc++)
				dp[cur][i] = max(dp[cur][i], dp[cur][i - mc] + dp[tc][mc]);
		}
	}
}

int main(){
	int N, M, i, j;
	scanf("%d%d", &N, &M);
	for (i = 0; i <= N - 1; i++) scanf("%d", &V[i]);

	int a, b;
	for (i = 1; i <= N - 1; i++){
		scanf("%d%d", &a, &b);
		adj[a - 1][b - 1] = 1;
		adj[b - 1][a - 1] = 1;
	}
	//memset(flag, 0, sizeof(flag));

	dfs(0, M, N);
	printf("%d\n", dp[0][M]);

	return 0;
}