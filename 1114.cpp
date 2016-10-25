// mine
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

int map[100100], state[100100];

void determine(int i){
	int not_deter = (state[i - 1] == 0) + (state[i] == 0) + \
	    (state[i + 1] == 0);
	if (!not_deter) return;
	
	int mine = (state[i - 1] == 1) + (state[i] == 1) + \
	    (state[i + 1] == 1);
	int vacant = (state[i - 1] == -1) + (state[i] == -1) + \
	    (state[i + 1] == -1);
	    
	if (mine == map[i]){
		for (int j = i - 1; j <= i + 1; j++){
			if (state[j] == 0) state[j] = -1;
		}
	}
	if (vacant == 3 - map[i]){
		for (int j = i - 1; j <= i + 1; j++){
			if (state[j] == 0) state[j] = 1;
		}
	}
}

int main(){
	int T, N, i, j;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		for (i = 1; i <= N; i++) scanf("%d", &map[i]);
		memset(state, 0, sizeof(state));
		
		state[0] = state[N + 1] = -1;
		for (i = 3; i <= N; i += 3){
			if (map[i - 2] == map[i - 1]) state[i] = state[i - 3];
			else state[i] = -state[i - 3];
		}
		if ((N + 1) % 3){
			for (i = N - 2; i >= 1; i -= 3){
				if (map[i + 1] == map[i + 2]) state[i] = state[i + 3];
				else state[i] = -state[i + 3];
			}
		}
		
		for (i = 1; i <= N; i++) determine(i);
		for (i = N; i >= 1; i--) determine(i);
		
		int mine = 0, vacant = 0;
		for (i = 1; i <= N; i++) {
			if (state[i] == 1) mine++;
			else if (state[i] == -1) vacant++;
		}
		
		printf("%d ", mine);
		for (i = 1; i <= N; i++) if (state[i] == 1) printf("%d ", i);
		printf("\n");
		printf("%d ", vacant);
		for (i = 1; i <= N; i++) if (state[i] == -1) printf("%d ", i);
		printf("\n");
	}
	
	return 0;	
}