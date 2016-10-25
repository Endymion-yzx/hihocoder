//
//  main.cpp
//  offer3
//
//  Created by 杨照雄 on 16/3/12.
//  Copyright © 2016年 杨照雄. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[110][300010];

int max(int x, int y){
    return (x > y)? x: y;
}

int main() {
    int Q, N, M, K, T;
    int A[110], B[110];
    cin >> Q;
    while (Q--){
        cin >> N >> M >> K >> T;
        int i, j;
        for (i = 0; i <= M - 1; i++) cin >> A[i];
        for (i = 0; i <= M - 1; i++) cin >> B[i];
        
        int viable = 1;
        int cost = 0;
        while (N--){
            int allz = 1;
            for (i = 0; i <= M - 1; i++){
                if (B[i]){
                    allz = 0;
                    break;
                }
            }
            if (allz) {
                //cout << "No Answer" << endl;
                viable = 0;
                break;
            }
            
            int size = 0x7FFFFFFF;
            for (i = 0; i <= M - 1; i++){
                if (B[i]){
                    if ((K + B[i] - 1) / B[i] * A[i] < size)
                        size = (K + B[i] - 1) / B[i] * A[i];
                }
            }
            
            for (j = 0; j <= size; j++) dp[0][j] = j / A[0] * B[0];
            for (i = 1; i <= M - 1; i++){
                for (j = 0; j <= size; j++){
                    if (j < A[i]) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = max(dp[i][j - A[i]] + B[i], dp[i - 1][j]);
                }
            }
            for (j = 0; j <= size; j++)
                if (dp[M - 1][j] >= K){
                    cost += j;
                    break;
                }
            
            for (i = 0; i <= M - 1; i++) B[i] /= T;
        }
        if (viable) cout << cost << endl;
        else cout << "No Answer" << endl;
    }
    
    return 0;
}