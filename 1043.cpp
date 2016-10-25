// hiho1043 Complete backpack
#include<iostream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
using namespace std;

int max(int x, int y){ return (x > y) ? x : y; }

int main(){
	int i, j, N, M, need[550], val[550], dp[100100];
	scanf("%d%d", &N, &M);
	for (i = 0; i <= N - 1; i++) scanf("%d%d", &need[i], &val[i]);

	memset(dp, 0, sizeof(dp));
	for (i = 0; i <= N - 1; i++){
		//cout << i << endl;
		for (j = 0; j <= M; j++){
			if (j >= need[i]) {
				dp[j] = max(dp[j - need[i]] + val[i], dp[j]);
				//cout << "dp[" << j << "] = " << dp[j] << endl;
			}
		}
	}

	printf("%d\n", dp[M]);
	//system("pause");
	return 0;
}