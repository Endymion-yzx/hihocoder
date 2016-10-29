// Hihocoder 1033
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;

const long long OFFSET = 100;
const long long MOD = 1000000007;
long long h(long long x) { return x + OFFSET; }
long long dp[20][10][200];
long long dpsum[20][10][200];

void init(){
    long long i, j, k, l;
    for (j = 0; j <= 9; j++)
        dp[1][j][h(j)] = 1;
    for (i = 2; i <= 19; i++){
        for (j = 0; j <= 9; j++){
            for (k = -90; k <= 90; k++){
                long long sum = 0;
                for (l = 0; l <= 9; l++)
                    sum += dp[i - 1][l][h(j - k)];
                dp[i][j][h(k)] = sum % MOD;
            }
        }
    }
    
    for (j = 0; j <= 9; j++)
        dpsum[1][j][h(j)] = j;
    long long t = 1;
    for (i = 2; i <= 19; i++){
        t *= 10;
        for (j = 0; j <= 9; j++){
            for (k = -90; k <= 90; k++){
                if (dp[i][j][h(k)]){
                    long long it = t % MOD;
                    it = it * j % MOD;
                    it = it * dp[i][j][h(k)] % MOD;
                    for (l = 0; l <= 9; l++)
                        it = (it + dpsum[i - 1][l][h(j - k)]) % MOD;
                    dpsum[i][j][h(k)] = it;
                }
            }
        }
    }
}

void calc(long long input, long long K, long long& cnt, long long& sum, bool outmost){
    if (input < 0){
        cnt = 0;
        sum = 0;
        return;
    }
    else if (input == 0){
        if (K == 0) cnt = 1;
        else cnt = 0;
        sum = 0;
        return;
    }
    long long copy = input, t;
    long long n = 0;
    t = 1;
    while (copy > 0){
        copy /= 10;
        n++;
        t *= 10;
    }
    t /= 10;
    cnt = 0;
    sum = 0;
    if (n == 1){
        if (K <= input && K >= 0){
            cnt = 1;
            sum = K;
        }
        return;
    }
    long long i, j, k = K;
    for (i = n - 1; i >= 1; i--){
        if (!outmost) k = -k;
        for (j = 1; j <= 9; j++){
            cnt = (cnt + dp[i][j][h(k)]) % MOD;
            sum = (sum + dpsum[i][j][h(k)]) % MOD;
        }
    }
    if (K == 0) cnt = (cnt + 1) % MOD;
    
    long long first_digit = input / t;
    for (j = 1; j <= first_digit - 1; j++){
        cnt = (cnt + dp[n][j][h(K)]) % MOD;
        sum = (sum + dpsum[n][j][h(K)]) % MOD;
    }
    
    long long sub_cnt, sub_sum;
    long long sub = input - (first_digit * t);
    
    long long tt = t;
    long long sign = 1;
    while (sub < tt){
        tt /= 10;
        sign = -sign;
    }
    if (sign == 1) calc(sub, K - first_digit, sub_cnt, sub_sum, false);
    else calc(sub, first_digit - K, sub_cnt, sub_sum, false);
    
    cnt = (cnt + sub_cnt) % MOD;
    sum = (sum + ((t * first_digit) % MOD) * sub_cnt % MOD + sub_sum) % MOD;
}

int main(){
    init();
//    int i, j, k;
//    for (i = 1; i <= 10; i++){
//        for (j = 0; j <= 9; j++){
//            cout << "dpsum(" << i << ", " << j << ", 1) = " << dpsum[i][j][h(1)] << endl;
//        }
//    }
    
    long long L, R;
    long long K;
    
    cin >> L >> R >> K;
    long long lcnt, lsum, rcnt, rsum;
    calc(L - 1, K, lcnt, lsum, true);
    calc(R, K, rcnt, rsum, true);
    cout << ((rsum + MOD) - lsum) % MOD << endl;
    
    return 0;
}