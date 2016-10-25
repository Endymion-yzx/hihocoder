// hiho 1105 heap
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

template <typename E>
class Heap{
private:
	E* heap;
	int max;
	int n;     // Current number of elements

	void swap(int idx1, int idx2){
		E tmp = heap[idx1];
		heap[idx1] = heap[idx2];
		heap[idx2] = tmp;
	}

	void siftdown(int pos){
		while (!isLeaf(pos)){
			int ch = pos * 2 + 1;
			if (ch + 1 < n && heap[ch + 1] > heap[ch]) ch++;
			if (heap[ch] < heap[pos]) return;
			swap(pos, ch);
			pos = ch;
		}
	}

public:
	Heap(E* h, int m, int num) : heap(h), max(m), n(num) { buildHeap(); }
	~Heap(){}

	void buildHeap(){
		for (int i = n / 2 - 1; i >= 0; i--) siftdown(i);
	}

	inline int parent(int pos){ return (pos - 1) / 2; }

	inline int leftchild(int pos){ return pos * 2 + 1; }

	inline int rightchild(int pos){ return pos * 2 + 2; }

	bool isLeaf(int pos){ return pos * 2 + 1 >= n && pos < n; }

	void insert(const E& e){
		heap[n++] = e;
		int cur = n - 1;
		while (cur > 0 && heap[cur] > heap[parent(cur)]){
			swap(cur, parent(cur));
			cur = parent(cur);
		}
	}

	E remove(){
		swap(0, --n);
		if (n > 0) siftdown(0);
		return heap[n];
	}
};

int main(){
	int N, i, h[100010], t;
	char op;
	Heap<int> hp(h, 100010, 0);
	cin >> N;
	for (i = 1; i <= N; i++){
		cin >> op;
		if (op == 'A'){
			cin >> t;
			hp.insert(t);
		}
		else cout << hp.remove() << endl;
	}

	return 0;
}