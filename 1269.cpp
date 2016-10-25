//
//  main.cpp
//  offer2
//
//  Created by 杨照雄 on 16/3/12.
//  Copyright © 2016年 杨照雄. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int N;
long long Q;
int P[100010];

int test(int k){
    int i;
    long long sum = 0;
    int c = 1;
    priority_queue<int> q;
    for (i = 0; i <= N - 1; i++){
        if (i >= k) {
            sum += c * q.top();
            q.pop();
            c++;
        }
        q.push(P[i]);
    }
    for (; c <= N; c++){
        sum += c * q.top();
        q.pop();
    }
    if (sum <= Q) return 1;
    else return 0;
}

int main() {
    int i;
    cin >> N >> Q;
    for (i = 0; i <= N - 1; i++) cin >> P[i];
    
    if (!test(N)){
        cout << -1;
        return 0;
    }
    if (test(1)){
        cout << 1;
        return 0;
    }
    int lb = 1, ub = N;
    while (lb < ub - 1){
        int mid = (lb + ub) >> 1;
        if (test(mid)) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}