// hiho1015 KMP Algorithm
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void getNext(char* pat, int* next){
	char tmp[10010];
	int len = strlen(pat + 1);
	strcpy(tmp, pat);

	next[0] = -1;
	next[1] = 0;
	
	for (int i = 2; i <= len; i++){
		tmp[i] = '\0';
		int q = 0, p = 1;
		while (true){
			while (p < i && pat[p + 1] == tmp[q + 1]){
				p++;
				q++;
			}
			if (p == i) break;
			else {
				q = next[q];
				if (q == -1){
					q++;
					p++;
				}
			}
		}
		next[i] = q;
		tmp[i] = pat[i];
	}
	/*for (int i = 1; i <= len; i++) cout << next[i] << ' ';
	cout << endl;*/
}

int find(char* pat, char* ori, int* next){
	int res = 0;
	int p = 0, q = 0, olen = strlen(ori + 1), plen = strlen(pat + 1);
	while (true){
		while (p < olen && ori[p + 1] == pat[q + 1]){
			p++;
			q++;
			if (q == plen) res++;
		}
		if (p == olen) break;
		else {
			q = next[q];
			if (q == -1){
				q++;
				p++;
			}
		}
	}
	return res;
}

int main(){
	int N, i, next[10010];
	char *pat = new char[10010], *ori = new char[1000100]; // 下标从1开始！
	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%s", pat + 1);
		scanf("%s", ori + 1);
		pat[0] = 'a';

		getNext(pat, next);
		int res = find(pat, ori, next);
		printf("%d\n", res);
	}

	return 0;
}