// Hiho 110
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;

long long table[32][110][110];

int main(){
	int N, M, i, j, k;
	cin >> N >> M;

	for (i = 0; i <= N - 1; i++){
		for (j = 0; j <= N - 1; j++){
			cin >> table[0][i][j];
		}
	}

	for (k = 1; k <= 31; k++){
		int stop = 1;
		for (i = 0; i <= N - 1; i++){
			for (j = 0; j <= N - 1; j++){
				int mid;
				long long res = -1;
				for (mid = 0; mid <= N - 1; mid++){
					if (table[k - 1][i][mid] == 0 || table[k - 1][mid][j] == 0)
						continue;
					if (res == -1)
						res = table[k - 1][i][mid] + table[k - 1][mid][j];
					else {
						if ((table[k - 1][i][mid] + table[k - 1][mid][j]) < res)
							res = table[k - 1][i][mid] + table[k - 1][mid][j];
					}
				}
				table[k][i][j] = res;
				if (res <= M) stop = 0;
			}
		}
		if (stop) break;
	}

	int gran = k - 2;
	int cur = 1 << (k - 1);

	long long curMat[110][110];
	long long tmpMat[110][110];
	for (i = 0; i <= N - 1; i++){
		for (j = 0; j <= N - 1; j++){
			curMat[i][j] = table[k - 1][i][j];
		}
	}

	for (; gran >= 0; gran--){
		int viable = 0;
		for (i = 0; i <= N - 1; i++){
			for (j = 0; j <= N - 1; j++){
				int mid;
				long long res = -1;
				for (mid = 0; mid <= N - 1; mid++){
					if (curMat[i][mid] == 0 || table[gran][mid][j] == 0)
						continue;
					if (res == -1)
						res = curMat[i][mid] + table[gran][mid][j];
					else {
						if ((curMat[i][mid] + table[gran][mid][j]) < res)
							res = curMat[i][mid] + table[gran][mid][j];
					}
				}
				tmpMat[i][j] = res;
				if (res <= M) viable = 1;
			}
		}

		if (viable){
			cur = cur + (1 << gran);
			for (i = 0; i <= N - 1; i++){
				for (j = 0; j <= N - 1; j++){
					curMat[i][j] = tmpMat[i][j];
				}
			}
		}
	}
	cout << cur << endl;

	return 0;
}