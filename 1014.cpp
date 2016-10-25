// hiho1014 trie
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

struct trieNode{
	int count;
	trieNode* next[26];

	trieNode(int n = 0){ count = n; memset(next, 0, sizeof(trieNode*) * 26); }
};

void insert(trieNode* root, char* s){
	if (*s == '\0'){
		root->count++;
		return;
	}

	if (root->next[*s - 'a'] == NULL){
		root->count++;
		root->next[*s - 'a'] = new trieNode;
		insert(root->next[*s - 'a'], s + 1);
	}
	else {
		root->count++;
		insert(root->next[*s - 'a'], s + 1);
	}
}

int find(trieNode* root, char* s){
	if (*s == '\0') return root->count;

	if (root->next[*s - 'a']) return find(root->next[*s - 'a'], s + 1);
	else return 0;
}

int main(){
	trieNode* root = new trieNode;
	int n, m, res;
	char entry[20], inq[20];

	scanf("%d", &n);
	while (n--){
		scanf("%s", entry);
		insert(root, entry);
	}

	scanf("%d", &m);
	while (m--) {
		scanf("%s", inq);
		res = find(root, inq);
		printf("%d\n", res);
	}

	return 0;
}