// hiho1062 Common ancestor
#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory.h>
using namespace std;

struct node{
	char name[30];
	int parent;
	int sibling;
	int child;

	node(){
		name[0] = 0;
		parent = -1;    // -1 means null
		sibling = -1;
		child = -1;
	}
};

node tree[200];

int find(const char* name){    // Find the index of the node with a given name
	int i = 0;
	while (tree[i].name[0] && strcmp(tree[i].name, name)) i++;
	// Not found
	if (!tree[i].name[0]) strcpy(tree[i].name, name);
	return i;
}

void insert(int par, int ch){    // Make tree[par] the parent of tree[ch]
	if (tree[par].child == -1) {
		tree[par].child = ch;
		tree[ch].parent = par;
		return;
	}
	int tmp = tree[par].child;
	while (tree[tmp].sibling != -1) tmp = tree[tmp].sibling;
	tree[tmp].sibling = ch;
	tree[ch].parent = tree[tmp].parent;
}

int findAncestor(int des1, int des2){
	int flag[200];
	memset(flag, 0, sizeof(flag));
	int t = des1;
	flag[t] = 1;
	while (tree[t].parent != -1){
		t = tree[t].parent;
		flag[t] = 1;
	}
	t = des2;
	while (t != -1){
		if (flag[t]) return t;
		t = tree[t].parent;
	}
	return -1;
}

int main(){
	int N, M, i, j;
	char fth[30], chd[30];
	scanf("%d", &N);

	int num = 0;
	for (i = 1; i <= N; i++){
		scanf("%s", fth);
		scanf("%s", chd);
		int fidx = find(fth);
		int cidx = find(chd);
		insert(fidx, cidx);
	}

	scanf("%d", &M);
	for (i = 1; i <= M; i++){
		scanf("%s", fth);
		scanf("%s", chd);
		int des1 = find(fth);
		int des2 = find(chd);
		int anc = findAncestor(des1, des2);
		if (anc == -1) printf("%d\n", -1);
		else printf("%s\n", tree[anc].name);
	}

	return 0;
}