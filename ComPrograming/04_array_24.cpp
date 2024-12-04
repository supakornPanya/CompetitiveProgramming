#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++) { cin >> v[i]; }
    vector<int> ck = v; sort(ck.begin(), ck.end());

    for(int x : v) { cout << x << " "; } cout << endl;

    int round = 0;
    int idx = n - 1; //sorted from end to i - 1
    while (idx >= 0) {
        //bottom to index idx is sorted
        if (ck[idx] == v[idx]) {
            idx--;
        }
        //biggest(range now) in top -> swap(range(top, i)) & idx--
        else if (ck[idx] == v[0]) {
            for (int i = 0;i <= idx / 2;i++) {
                swap(v[i], v[idx - i]);
            }
            idx--;
            //out put
            //cout << " case biggest in top" << " : ";
            for (int x : v) { cout << x << " "; } cout << endl;
        }
        //biggest not in top -> find the biggest -> swap(range(top, biggest))
        else {
            //find the biggest
            int biggest;
            for (int i = 0;i <= idx;i++) {
                if (v[i] == ck[idx]) { biggest = i; break; }
            }
            //swap(range(top, index biggest))
            for(int i = 0;i <= biggest / 2;i++) {
                swap(v[i], v[biggest - i]);
            }
            //out put
            for (int x : v) { cout << x << " "; } cout << endl;
        }

    }

    return 0;
}