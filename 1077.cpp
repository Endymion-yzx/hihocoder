// hiho1077 segment tree
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

struct segNode{
	int s;
	int e;
	int min;
};

segNode tree[3000100];
int data[1000100];

void build(segNode* tree, int cur, int* data, int s, int e){
	tree[cur].s = s;
	tree[cur].e = e;
	if (s == e){
		tree[cur].min = data[s];
		return;
	}
	build(tree, cur * 2 + 1, data, s, (e - s + 1) / 2 + s - 1);
	build(tree, cur * 2 + 2, data, (e - s + 1) / 2 + s, e);
	tree[cur].min = (tree[cur * 2 + 1].min < tree[cur * 2 + 2].min) ? \
		tree[cur * 2 + 1].min: tree[cur * 2 + 2].min;
}

int find(segNode* tree, int cur, int s, int e){
	if (tree[cur].s == s && tree[cur].e == e) return tree[cur].min;

	if (tree[cur * 2 + 1].e >= e) return find(tree, cur * 2 + 1, s, e);
	if (tree[cur * 2 + 2].s <= s) return find(tree, cur * 2 + 2, s, e);
	int min1 = find(tree, cur * 2 + 1, s, tree[cur * 2 + 1].e);
	int min2 = find(tree, cur * 2 + 2, tree[cur * 2 + 2].s, e);
	return (min1 < min2) ? min1 : min2;
}

void modify(segNode* tree, int cur, int pos, int val){
	if (tree[cur].s == tree[cur].e) {
		tree[cur].min = val;
		return;
	}
	if (pos <= tree[cur * 2 + 1].e) modify(tree, cur * 2 + 1, pos, val);
	else modify(tree, cur * 2 + 2, pos, val);
	tree[cur].min = (tree[cur * 2 + 1].min < tree[cur * 2 + 2].min) ? \
		tree[cur * 2 + 1].min: tree[cur * 2 + 2].min;
}

int main(){
	enum Op{ inq = 0, mod } op;
	int N, Q, i, optype, l, r, res;
	scanf("%d", &N);
	for (i = 0; i <= N - 1; i++) scanf("%d", &data[i]);
	build(tree, 0, data, 0, N - 1);

	scanf("%d", &Q);
	while (Q--){
		scanf("%d%d%d", &optype, &l, &r);
		op = static_cast<Op>(optype);
		switch (op){
		case inq:
			res = find(tree, 0, l - 1, r - 1);
			printf("%d\n", res);
			break;
		case mod:
			modify(tree, 0, l - 1, r);
			break;
		}
	}
	return 0;
}