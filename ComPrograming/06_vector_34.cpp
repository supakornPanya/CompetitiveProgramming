#include <bits/stdc++.h>
using namespace std;

int main() {
    int rounds; cin >> rounds;
    queue<pair<int, int>> q; //queue = (number of queue, time start of this queue)
    int n; //number of queue now
    pair<int, int> next; //(number of queue, time start of this queue)
    double sumAvr = 0, sumN = 0;
    while (rounds--) {
        string opr; cin >> opr;
        if (opr == "reset") {
            cin >> n;
        }
        if (opr == "new") {
            int t; cin >> t;
            cout << ">> ticket " << n << endl;
            q.push({ n, t }); n++;
        }
        if (opr == "next") {
            next = q.front(); q.pop();
            cout << ">> call " << next.first << endl;
        }
        if (opr == "order") {
            int t; cin >> t;
            sumAvr += t - next.second; sumN++;
            cout << ">> qtime " << next.first << " " << t - next.second << endl;
        }
        if (opr == "avg_qtime") {
            cout << ">> avg_qtime " << round((sumAvr / sumN) * 100.0) / 100.0 << endl;
        }
    }
}