#include <bits/stdc++.h>
using namespace std;

bool find(int x, int y, vector<vector<char>>& table, vector<vector<char>>& table2, int n) {
    bool ck = false;
    //loop row
    for (int i = 1;i <= n;i++) {
        if (i != y && table[x][i] == 'Q') {
            table2[x][i] = '-';
            ck = true;
        }
    }
    //loop column
    for (int i = 1;i <= n;i++) {
        if (i != x && table[i][y] == 'Q') {
            table2[i][y] = '-';
            ck =  true;
        }
    }
    //4 dir
    int x1 = x + 1, x2 = x - 1, y1 = y + 1, y2 = y - 1;
    while (true) {
        if (x1 > n && x2 < 1 && y1 > n && y2 < 1) break;
        if (x1 <= n && y1 <= n && table[x1][y1] == 'Q') {
            table2[x1][y1] = '-';
            ck = true;
        }
        if (x1 <= n && y2 >= 1 && table[x1][y2] == 'Q') {
            table2[x1][y2] = '-';
            ck = true;
        }
        if (x2 >= 1 && y1 <= n && table[x2][y1] == 'Q') {
            table2[x2][y1] = '-';
            ck = true;
        }
        if (x2 >= 1 && y2 >= 1 && table[x2][y2] == 'Q') {
            table2[x2][y2] = '-';
            ck = true;
        }
        x1++; x2--; y1++; y2--;
    }
    return ck;
}

int main() {
    int n; cin >> n; cin.ignore();
    vector<vector<char>> table(n + 10, vector<char>(n + 10)); //input
    vector<vector<char>> table2(n + 10, vector<char>(n + 10)); //mark each position
    for (int i = 1;i <= n;i++) {
        string s; getline(cin, s);
        for (int j = 1;j <= n;j++) {
            char x = s[j - 1];
            if (x == 'Q') {
                table[i][j] = 'Q';
                bool ck = find(i, j, table, table2, n);
                table2[i][j] = (ck) ? '-' : 'Q';
            } else {
                table[i][j] = '-';
                table2[i][j] = '-';
            }
        }
    }

    //output
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << table2[i][j];
        }
        cout << endl;
    }

    return 0;
}