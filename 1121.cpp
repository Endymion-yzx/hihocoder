// hiho 1121
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

class graph{
private:
	struct edgeNode{
		int end;
		edgeNode* next;
	    
		edgeNode() : next(NULL) {}
		edgeNode(int e, edgeNode* n = NULL) : end(e), next(n) {}
	};

	struct verNode{
		edgeNode* head;

		verNode() : head(NULL) {}
	};

	verNode* table;
	//bool* flag;
	char* color;
	int v;

public:
	graph(int vSize){
		v = vSize + 1;
		table = new verNode[v];
		//flag = new bool[v];
		color = new char[v];
	}

	~graph(){
		int i;
		for (i = 0; i <= v - 1; i++){
			edgeNode* tmp = table[i].head;
			while (tmp){
				table[i].head = tmp->next;
				delete tmp;
				tmp = table[i].head;
			}
		}
		delete[] table;
		//delete[] flag;
		delete[] color;
	}

	void insert(int u, int w){
		table[u].head = new edgeNode(w, table[u].head);
		table[w].head = new edgeNode(u, table[w].head);
	}

	bool judge(){
		int qu[10100], fr = 0, ed = 0, i;
		memset(color, 0, v * sizeof(char));
		color[1] = 'r';
		qu[ed++] = 1;

		while (fr != ed){
			// 以下的循环检查一个连通分量
			while (fr != ed){
				int cur = qu[fr++];

				edgeNode* tmp = table[cur].head;
				while (tmp){
					if (color[cur] == color[tmp->end]) return false;
					if (color[tmp->end] == 0) {
						color[tmp->end] = (color[cur] == 'r') ? 'b' : 'r';
						qu[ed++] = tmp->end;
					}
					tmp = tmp->next;
				}
			}

			for (i = 1; i <= v - 1; i++) 
			if (color[i] == 0) { color[i] = 'r'; qu[ed++] = i; break; }
		}
		return true;
	}
};

int main(){
	int T, N, M, i, u, w;
	scanf("%d", &T);

	while (T--){
		scanf("%d%d", &N, &M);
		graph gp(N);
		for (i = 1; i <= M; i++){
			scanf("%d%d", &u, &w);
			gp.insert(u, w);
		}
		if (gp.judge()) printf("Correct\n");
		else printf("Wrong\n");
	}

	return 0;
}