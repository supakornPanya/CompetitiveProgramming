#include <bits/stdc++.h>
using namespace std;

// void mark(char col, int val, vector<vector<int>>& table, vector<vector<bool>>& flag) {
//     if (col == 'B') {
//         for (int i = 1;i <= 5;i++) {
//             if (table[1][i] == val) {
//                 flag[1][i] = true;
//                 break;
//             }
//         }
//     }
//     if (col == 'I') {
//         for (int i = 1;i <= 5;i++) {
//             if (table[2][i] == val) {
//                 flag[2][i] = true;
//                 break;
//             }
//         }
//     }
//     if (col == 'N') {
//         for (int i = 1;i <= 5;i++) {
//             if (table[3][i] == val) {
//                 flag[3][i] = true;
//                 break;
//             }
//         }
//     }
//     if (col == 'G') {
//         for (int i = 1;i <= 5;i++) {
//             if (table[4][i] == val) {
//                 flag[4][i] = true;
//                 break;
//             }
//         }
//     }
//     if (col == 'O') {
//         for (int i = 1;i <= 5;i++) {
//             if (table[5][i] == val) {
//                 flag[5][i] = true;
//                 break;
//             }
//         }
//     }
// }

// bool bingo(vector<vector<int>>& table, vector<vector<bool>>& flag, int cnt) {
//     bool ck = false;

//     //check row
//     for (int i = 0;i <= 5;i++) {
//         if (flag[i][1] && flag[i][2] && flag[i][3] && flag[i][4] && flag[i][5]) {
//             if(!ck) cout << cnt << endl;
//             cout << flag[i][1] << ", " << flag[i][2] << ", " << flag[i][3] << ", " << flag[i][4] << ", " << flag[i][5] << endl;
//             ck = true;
//         }
//     }
//     //check col
//     for (int i = 0;i <= 5;i++) {
//         if (flag[1][i] && flag[2][i] && flag[3][i] && flag[4][i] && flag[5][i]) {
//             if (!ck) cout << cnt << endl;
//             cout << flag[1][i] << ", " << flag[2][i] << ", " << flag[3][i] << ", " << flag[4][i] << ", " << flag[5][i] << endl;
//             ck = true;
//         }
//     }
//     //diagonal 1
//     if (flag[1][1] && flag[2][2] && flag[4][4] && flag[5][5]) {
//         if (!ck) cout << cnt << endl;
//         cout << flag[1][1] << ", " << flag[2][2] << ", " << flag[4][4] << ", " << flag[5][5] << endl;
//         ck = true;
//     }
//     //diagonal 2
//     if (flag[5][1] && flag[4][2] && flag[2][4] && flag[1][5]) {
//         if (!ck) cout << cnt << endl;
//         cout << flag[5][1] << ", " << flag[4][2] << ", " << flag[2][4] << ", " << flag[1][5] << endl;
//         ck = true;
//     }

//     return ck;
// }

int mian() {
    vector<vector<bool>> flag(6, vector<bool>(6, false));
    flag[3][3] = true;
    vector<vector<int>> table(6, vector<int>(6, -1));

    //get table
    for (int i = 0;i < 5;i++) { char x; cin >> x;  cout << x << " "; } //sudo input
    return 0;
    // for (int i = 1;i <= 5;i++) {
    //     for (int j = 1;j <= 5;j++) {
    //         string x; cin >> x;
    //         if(x == "*") continue;
    //         table[i][j] = stoi(x);
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // //get round
    // string q; int cnt = 0;
    // while (cin >> q) {
    //     cnt++;
    //     char col = q[0];
    //     string temp = ""; for (int i = 1;i < q.size();i++) { temp += q[i]; }
    //     int val = stoi(temp);

    //     mark(col, val, table, flag);
    //     bool ck = bingo(table, flag, cnt);
        
    //     if(ck) return 0;
    //     if(cnt == 10) break;
    // }

}