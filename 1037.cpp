// hiho1037 triangle
#include<iostream>
#include<cstdio>
using namespace std;

int max(int &x, int &y){ return (x > y) ? x : y; }

int main(){
	int N, i, j, tri[110][110], dp[110][110];
	scanf("%d", &N);
	
	for (i = 0; i <= N - 1; i++)
	for (j = 0; j <= i; j++)
		scanf("%d", &tri[i][j]);

	for (i = N - 1, j = 0; j <= i; j++) dp[i][j] = tri[i][j];

	for (i = N - 2; i >= 0; i--)
	for (j = 0; j <= i; j++)
		dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + tri[i][j];

	printf("%d", dp[0][0]);
	return 0;
}