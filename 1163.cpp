// hihocoder 1163
#include <iostream>
using namespace std;

int main(){
    int N, a, i;
    cin >> N;
    int x = 0;
    for (i = 1; i <= N; i++) {
        cin >> a;
        x ^= a;
    }
    if (x) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    
    return 0;
}