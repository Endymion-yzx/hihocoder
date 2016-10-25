// hiho1049 postorder
#include<iostream>
#include<cstdio>
#include<memory.h>
#include<cstring>
using namespace std;

struct BinNode{
	char ch;
	BinNode* left;
	BinNode* right;

	BinNode(char c, BinNode* l = NULL, BinNode* r = NULL) : ch(c), left(l), right(r) {}
	BinNode() : left(NULL), right(NULL){}
};

BinNode* build(char* preorder, char* inorder, int size){
	if (size <= 0) return NULL;
	int pos, i;
	for (i = 0; i <= size - 1; i++){
		if (inorder[i] == preorder[0]) break;
	}
	pos = i;
	BinNode* root = new BinNode(preorder[0]);
	root->left = build(preorder + 1, inorder, pos);
	root->right = build(preorder + pos + 1, inorder + pos + 1, size - pos - 1);
	return root;
}

void postorder(BinNode* root){
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	//printf("%c", root->ch);
	cout << root->ch;
}

int main(){
	char pre[30], in[30];
	scanf("%s", pre);
	scanf("%s", in);
	BinNode* rt = build(pre, in, strlen(pre));
	postorder(rt);

	return 0;
}