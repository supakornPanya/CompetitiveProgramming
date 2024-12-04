#include <bits/stdc++.h>
using namespace std;

int main() {
    string id1, id2; 
    float gpax1, gpax2; 
    char cp1, cp2, c11, c12, c21, c22;
    cin >> id1 >> gpax1 >> cp1 >> c11 >> c21;
    cin >> id2 >> gpax2 >> cp2 >> c12 >> c22;

    map<char, int> m = { {'A',5},{'B',4},{'C',3},{'D',2},{'F',1} };

    //1) can change? comp == A, cal1 >= C, cal2 >= C
    bool n1 = false, n2 = false;
    if (m[cp1] == 5 && m[c11] >= 3 && m[c21] >= 3) { n1 = true; }
    if (m[cp2] == 5 && m[c12] >= 3 && m[c22] >= 3) { n2 = true; }
    //cout << m[cp1] << " " << m[c11] << " " << m[c21] << endl;
    //cout << "n1 : " << n1 << ", n2 : " << n2 << endl;
    if (!n1 && !n2) {
        cout << "None"; return 0;
    } else if (n1 && !n2) {
        cout << id1; return 0;
    } else if (!n1 && n2) {
        cout << id2; return 0;
    }

    //2.1) compare gpax 
    if (gpax1 > gpax2) { 
        cout << id1; return 0; 
    } else if (gpax1 < gpax2) { 
        cout << id2; return 0; 
    }

    //2.2) compare cal1
    if (m[c11] > m[c12]) {
        cout << id1; return 0;
    } else if (m[c11] < m[c12]) {
        cout << id2; return 0;
    }

    //2.3) compare cal2
    if (m[c21] > m[c22]) {
        cout << id1; return 0;
    } else if (m[c21] < m[c22]) {
        cout << id2; return 0;
    }
    else {
        cout << "Both"; return 0;
    }



    return 0;
}