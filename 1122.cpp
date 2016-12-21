// Hihocoder 1122
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <memory.h>
using namespace std;

struct Edge {
	int adj;
	Edge* next;

	Edge(int a = 0, Edge* n = NULL): adj(a), next(n) {}
};

struct Vertex {
	int label;
	int from;
	Edge* head;

	Vertex(){
		label = 0;
		from = 0;
		head = new Edge();
	}
};

int N, M;
Vertex vers[1010];
bool visited[1010];

void insert(int u, int w){
	vers[u].head->next = new Edge(w, vers[u].head->next);
	vers[w].head->next = new Edge(u, vers[w].head->next);
}

bool find_path(int u){
	Edge* tmp = vers[u].head;
	while (tmp->next) {
		if (vers[tmp->next->adj].from == 0){
			vers[u].from = tmp->next->adj;
			vers[tmp->next->adj].from = u;
			return true;
		}
		else if (!visited[tmp->next->adj]){
			visited[tmp->next->adj] = true;
			if (find_path(vers[tmp->next->adj].from)){
				vers[u].from = tmp->next->adj;
				vers[tmp->next->adj].from = u;
				return true;
			}
		}
		tmp = tmp->next;
	}
	return false;
}

int Hungarian(){
	int i;
	for (i = 1; i <= N; i++){
		if (vers[i].from == 0) {
			memset(visited, 0, sizeof(visited));
			find_path(i);
		}
	}

	int cnt = 0;
	for (i = 1; i <= N; i++){
		if (vers[i].from) cnt++;
	}
	return cnt / 2;
}

int main(){
	cin >> N >> M;
	int i, u, w;
	for (i = 1; i <= M; i++){
		cin >> u >> w;
		insert(u, w);
	}

	cout << Hungarian() << endl;

	return 0;
}