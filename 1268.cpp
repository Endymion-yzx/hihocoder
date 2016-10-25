//
//  main.cpp
//  offer1
//
//  Created by 杨照雄 on 16/3/12.
//  Copyright © 2016年 杨照雄. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int mesh[3][3];
    int i, j;
    for (i = 0; i <= 2; i++){
        for (j = 0; j <= 2; j++){
            cin >> mesh[i][j];
        }
    }
    int ra[12][3][3];
    ra[0][0][0] = 4;
    ra[0][0][1] = 9;
    ra[0][0][2] = 2;
    ra[0][1][0] = 3;
    ra[0][1][1] = 5;
    ra[0][1][2] = 7;
    ra[0][2][0] = 8;
    ra[0][2][1] = 1;
    ra[0][2][2] = 6;
    
    //int i, j;
    for (i = 1; i <= 3; i++){
        ra[i][0][0] = ra[i - 1][0][2];
        ra[i][0][1] = ra[i - 1][1][2];
        ra[i][0][2] = ra[i - 1][2][2];
        ra[i][1][0] = ra[i - 1][0][1];
        ra[i][1][1] = ra[i - 1][1][1];
        ra[i][1][2] = ra[i - 1][2][1];
        ra[i][2][0] = ra[i - 1][0][0];
        ra[i][2][1] = ra[i - 1][1][0];
        ra[i][2][2] = ra[i - 1][2][0];
    }
    
    for (i = 4; i <= 7; i++){
        ra[i][0][0] = ra[i - 4][2][0];
        ra[i][0][1] = ra[i - 4][2][1];
        ra[i][0][2] = ra[i - 4][2][2];
        ra[i][1][0] = ra[i - 4][1][0];
        ra[i][1][1] = ra[i - 4][1][1];
        ra[i][1][2] = ra[i - 4][1][2];
        ra[i][2][0] = ra[i - 4][0][0];
        ra[i][2][1] = ra[i - 4][0][1];
        ra[i][2][2] = ra[i - 4][0][2];
    }
    
    for (i = 8; i <= 11; i++){
        ra[i][0][0] = ra[i - 8][0][2];
        ra[i][0][1] = ra[i - 8][0][1];
        ra[i][0][2] = ra[i - 8][2][2];
        ra[i][1][0] = ra[i - 8][1][0];
        ra[i][1][1] = ra[i - 8][1][1];
        ra[i][1][2] = ra[i - 8][1][2];
        ra[i][2][0] = ra[i - 8][0][0];
        ra[i][2][1] = ra[i - 8][0][1];
        ra[i][2][2] = ra[i - 8][0][2];
    }
    int k;
//    for (k = 0; k <= 11; k++){
//        for (i = 0; i <= 2; i++){
//            for (j = 0; j <= 2; j++) cout << ra[k][i][j] << ' ';
//            cout << endl;
//        }
//        cout << endl;
//    }
    int c = 0;
    int last;
    for (k = 0; k <= 7; k++){
        int flag = 0;
        for (i = 0; i <= 2; i++){
            for (j = 0; j <= 2; j++){
                if (mesh[i][j] && mesh[i][j] != ra[k][i][j]){
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        
        if (!flag){
            c++;
            last = k;
        }
    }
    
    if (c == 1){
        for (i = 0; i <= 2; i++){
            for (j = 0; j <= 2; j++) cout << ra[last][i][j] << ' ';
            cout << endl;
        }
    }
    else cout << "Too Many";
    
    return 0;
}