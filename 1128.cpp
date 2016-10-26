// Hihocoder 1128
#include <iostream>
using namespace std;

int search(int value, int* arr, int len){
	// int j;
	// for (j = 0; j <= len - 1; j++) cout << arr[j] << ' ';
	// cout << endl;
	if (len == 0) return -1;
	else if (len == 1){
		if (arr[0] == value) return 1;
		else return -1;
	}

	int k = arr[0];
	int end = arr[len - 1];
	arr[len - 1] = k;
	arr[0] = end;

	int cnt = 0, i;
	for (i = 0; i <= len - 2; i++){
		if (arr[i] < k){
			int t = arr[cnt];
			arr[cnt] = arr[i];
			arr[i] = t;
			cnt++;
		}
	}
	// cout << cnt << endl;
	int t = arr[cnt];
	arr[cnt] = k;
	arr[len - 1] = t;

	if (k == value) return cnt + 1;
	else if (value > k){
		int res = search(value, arr + cnt + 1, len - cnt - 1);
		if (res == -1) return -1;
		else return res + cnt + 1;
	}
	else {
		int res = search(value, arr, cnt);
		if (res == -1) return -1;
		else return res;
	}
}

int a[1000010];

int main(){
	int N, K, i;
	cin >> N >> K;

	for (i = 0; i <= N - 1; i++)
		cin >> a[i];

	cout << search(K, a, N) << endl;
	// int find = 0;
	// for (i = 0; i <= N - 1; i++){
	// 	if (a[i] == K) {
	// 		find = 1;
	// 		break;
	// 	}
	// }
	// if (!find) cout << -1 << endl;
	// else {
	// 	int cnt = 0;
	// 	for (i = 0; i <= N - 1; i++){
	// 		if (a[i] < K) cnt++;
	// 	}
	// 	cout << cnt + 1 << endl;
	// }

	return 0;
}