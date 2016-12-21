// Hihocoder 1158
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;

bool primes[500100];

void init(){
	memset(primes, 1, sizeof(primes));
	primes[1] = false;
	int cur = 2;
	while (cur * cur <= 500000){
		int end = 500000 / cur;
		int i;
		for (i = 2; i <= end; i++)
			primes[i * cur] = false;
		while (!primes[++cur]);
	}
}

struct Edge {
	int adj;
	Edge* next;

	Edge(int a = 0, Edge* n = NULL): adj(a), next(n) {}
};

struct Vertex {
	int num;
	// int deg;
	Edge* head;
	int matchWith;

	Vertex(){
		num = 0;
		// deg = 0;
		head = new Edge();
		matchWith = 0;
	}

	~Vertex(){
		Edge* tmp = head;
		while (head){
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
};

class Graph {
private:
	int N;
	Vertex* vers;
	bool* visited;

	bool find_path(int u){
		Edge* tmp = vers[u].head;
		while (tmp->next){
			if (vers[tmp->next->adj].matchWith == 0){
				vers[tmp->next->adj].matchWith = u;
				vers[u].matchWith = tmp->next->adj;
				return true;
			}
			else if (!visited[tmp->next->adj]){
				visited[tmp->next->adj] = true;
				if (find_path(vers[tmp->next->adj].matchWith)){
					vers[tmp->next->adj].matchWith = u;
					vers[u].matchWith = tmp->next->adj;
					return true;
				}
			}
			tmp = tmp->next;
		}
		return false;
	}

public:
	Graph(int n): N(n) {
		vers = new Vertex[n + 1];
		visited = new bool[n + 1];
	}

	~Graph(){
		delete[] vers;
		delete[] visited;
	}

	void setNum(int idx, int num){
		vers[idx].num = num;
	}

	void insert(int u, int w){
		vers[u].head->next = new Edge(w, vers[u].head->next);
		vers[w].head->next = new Edge(u, vers[w].head->next);
		// vers[u].deg++;
		// vers[w].deg++;
	}

	void build(){
		int i, j;
		for (i = 1; i <= N - 1; i++){
			for (j = i + 1; j <= N; j++){
				if (((vers[i].num % vers[j].num == 0 && primes[vers[i].num / vers[j].num]) 
					|| (vers[j].num % vers[i].num == 0 && primes[vers[j].num / vers[i].num])))
					insert(i, j);
			}
		}
	}

	int Hungarian(){
		int i;
		for (i = 1; i <= N; i++){
			// cout << "i = " << i << endl;
			if (!vers[i].matchWith){
				memset(visited, 0, sizeof(bool) * (N + 1));
				find_path(i);
			}
		}

		int cnt = 0;
		for (i = 1; i <= N; i++){
			if (vers[i].matchWith) cnt++;
		}
		return N - cnt / 2;
	}

};

int main(){
    init();
	int T, N, k;
	cin >> T;
	// cout << "T = " << T << endl;

	for (k = 1; k <= T; k++) {
		cin >> N;
		Graph g(N);
		int i, x;
		for (i = 1; i <= N; i++){
			cin >> x;
			g.setNum(i, x);
		}
		g.build();
		
		cout << "Case #" << k << ": " << g.Hungarian() << endl;
	}

	return 0;
}