#include <bits/stdc++.h>
using namespace std;

struct A {
    int sum;
    vector<int> v;
    bool operator < (const A& other) const {
        if (sum != other.sum) return sum > other.sum;
        if (v.size() != other.v.size()) return v.size() < other.v.size();
        for (int i = 0;i < v.size();i++) {
            if (v[i] != other.v[i]) return v[i] < other.v[i];
        }
    }
};

int main() {
    string opr; cin >> opr;
    vector<int> v; int x;
    while (cin >> x) v.push_back(x);

    vector<A> ans;
    if (opr == "first") {
        //process
        ans.push_back({ v[0], vector<int>{v[0]} });
        for (int i = 1;i < v.size();i++) { //for each number
            int n = ans.size();
            for (int j = 0;j < n;j++) { //for each group of answer
                if (ans[j].sum + v[i] <= 100) { //found some that can push
                    ans[j].v.push_back(v[i]); //push in vector group j
                    ans[j].sum += v[i]; //add v[i] in sum
                    break;
                }
                if (j == n - 1) { //no have some group that can push
                    ans.push_back({ v[i], vector<int>{v[i]} });
                }
            }
        }
        //sort vector of each group ans 
        for (int i = 0;i < ans.size();i++) {
            sort(ans[i].v.begin(), ans[i].v.end());
        }
        sort(ans.begin(), ans.end()); //sort sum and vector
        //output
        for (int i = 0;i < ans.size();i++) {
            for (int j = 0;j < ans[i].v.size();j++) {
                cout << ans[i].v[j] << " ";
            }
            cout << endl;
        }
    }


    if (opr == "best") {
        //process
        ans.push_back({ v[0], vector<int>{v[0]} });
        for (int i = 1;i < v.size();i++) { //for each number
            int n = ans.size();
            int bestFit = INT_MAX, bestIdx = -1;
            for (int j = 0;j < n;j++) { //for each group of answer
                if (ans[j].sum + v[i] <= 100 && 100 - (ans[j].sum + v[i]) < bestFit) {//can use && better answer
                    bestFit = 100 - (ans[j].sum + v[i]);
                    bestIdx = j;
                }
            }
            if (bestIdx == -1) { //no group can add v[i]
                ans.push_back({ v[i], vector<int>{v[i]} });
            } else { //have a best group for add v[i]
                ans[bestIdx].v.push_back(v[i]); //push in vector group j
                ans[bestIdx].sum += v[i]; //add v[i] in sum
            }
        }
        //sort vector of each group ans 
        for (int i = 0;i < ans.size();i++) {
            sort(ans[i].v.begin(), ans[i].v.end());
        }
        sort(ans.begin(), ans.end()); //sort sum and vector
        //output
        for (int i = 0;i < ans.size();i++) {
            for (int j = 0;j < ans[i].v.size();j++) {
                cout << ans[i].v[j] << " "; 
            }
            cout << endl;
        }
    }

    return 0;
}