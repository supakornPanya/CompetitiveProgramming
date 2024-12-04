#include <bits/stdc++.h>
using namespace std;

struct A {
    int n; string b, p;
};

int main() {
    int n1; cin >> n1;
    map<string, pair<int, string>> m1; //keep best bit of this product : (key:name product -> pair<price of bit , name who bit>) 
    map<string, bool> m2; //list name who bit (in case name duplicate)
    vector<A> v2; //keep all bit : (n : price of Bit, b : code who bit, p : code of product) 
    map<pair<string,string>, bool> found;
    for (int i = 0;i < n1;i++) {
        char opr; string b, p; int n;
        cin >> opr >> b >> p;
        if (opr == 'B') {
            cin >> n;
            if (found[{b, p}]) {
                for(int j = 0;j < v2.size();j++) {
                    if (v2[j].b == b && v2[j].p == p) {
                        v2.erase(v2.begin() + j);
                        break;
                    }
                }
            }
            v2.push_back({ n,b,p });
            found[{b,p}] = true;
            m2[b] = true; //add to list name
        }
        if (opr == 'W') {
            //find code who bit & code of product
            for (int j = 0;j < v2.size();j++) {
                if (v2[j].b == b && v2[j].p == p) {
                    v2.erase(v2.begin() + j);
                    break;
                }
            }
        }
    }

    //for all Bit
    for (int i = 0;i < v2.size();i++) {
        //find all of bit in v2 that bit from price v2 is greater than price m1
        if (v2[i].n > m1[v2[i].p].first) { //price of v2 > price of m1(name:product) 
            m1[v2[i].p] = { v2[i].n, v2[i].b }; //code product = {price , name who bit}
        }
    }

    //ouput
    for (auto it1 = m2.begin();it1 != m2.end();it1++) {
        //find (sum of all bit & product) of name:v[i]
        int sum = 0; vector<string> ans;
        for (auto it = m1.begin();it != m1.end();it++) { //loop all bit
            if (it->second.second == it1->first) { //name of best bit this product = this name 
                sum += it->second.first; //price of bit this product
                ans.push_back(it->first); //name product
            }
        }

        cout << it1->first << ": $" << sum;
        if (sum != 0) {
            cout << " -> ";
            for (int j = 0;j < ans.size();j++) {
                cout << ans[j] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}


