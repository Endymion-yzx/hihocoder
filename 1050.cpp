// hiho 1050
// Find the length of the longest path in a tree
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

class graph{
private:
	struct edgeNode{
		int end;
		edgeNode* next;
		
		edgeNode(int e, edgeNode* n = NULL): end(e), next(n) {}
		edgeNode(): next(NULL) {}
	};
	
	struct verNode{
		int vertex;      // 有用吗 
		edgeNode* head;
		int step;
		
		verNode(int v, edgeNode* h = NULL): vertex(v), head(h), step(0) {}
		verNode(): head(NULL), step(0) {}
	};
	
	verNode* table;
	int vSize;
	
public:
	graph(int v){
		table = new verNode[v];
		vSize = v;
	}
	
	~graph(){
		int i;
		for (i = 0; i <= vSize - 1; i++){
			edgeNode* tmp = table[i].head;
			while (tmp != NULL){
				table[i].head = table[i].head->next;
				delete tmp;
				tmp = table[i].head;
			}
		}
		delete[] table;
	}
	
	void insert(int u, int w){
		table[u].head = new edgeNode(w, table[u].head);
		table[w].head = new edgeNode(u, table[w].head);
		//cout << "Insert " << u << ", " << w << " successfully." << endl;
	}
	
	// Return the farthest node away from u
	int bfs(int u){
		char *flag = new char[vSize + 10];
		memset(flag, 0, sizeof(char) * (vSize + 10));
		
		int *queue = new int[vSize + 10];
		int front, end;
		front = end = 0;
		queue[end++] = u;
		flag[u] = 1;
		table[u].step = 0;
		int cur;
		//int last;
		
		while (end > front){
			cur = queue[front++];
			//cout << "dequeue: " << cur << endl;
			edgeNode* tmp = table[cur].head;
			while (tmp){
				if (!flag[tmp->end]){
					queue[end++] = tmp->end;
					table[tmp->end].step = table[cur].step + 1;
					flag[tmp->end] = 1;
				}
				tmp = tmp->next;
			}
		}
		
		delete[] flag;
		delete[] queue;
		return cur;         // The last node to dequeue
	}
	
	inline int step(int u){
		return table[u].step;
	}
};

int main(){
	int N, i, A, B;
	scanf("%d", &N);
	graph gp(N);
	
	for (i = 1; i <= N - 1; i++){
		scanf("%d%d", &A, &B);
		gp.insert(A - 1, B - 1);
	}
	
	int cur = gp.bfs(0);
	int last = gp.bfs(cur);
	cout << gp.step(last) << endl;
	
	return 0;
}