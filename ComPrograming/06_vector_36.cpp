#include <bits/stdc++.h>
using namespace std;

struct A {
    int grade, order;
    string id;
    bool operator < (const A& other) const {
        if (grade != other.grade) return grade > other.grade;
        if (order != other.order) return order < other.order;
        return id < other.id;
    }
};

void changeGrade(string temp, vector<A>& ans) {
    //find id from temp
    string id = "";
    for(int i = 0;i < temp.size() - 1;i++) {
        id += temp[i];
    }
    //find id in vector ans, O(N)
    int idx;
    for(idx = 0;idx < ans.size();idx++) {
        if(ans[idx].id == id) break;
    }
    //change grade 
    if (temp[temp.size() - 1] == '+' && ans[idx].grade < 7) {
        ans[idx].grade++;
    }
    if (temp[temp.size() - 1] == '-' && ans[idx].grade > 0) {
        ans[idx].grade--;
    }
}

int main() {
    vector<string> g1(8);
    g1[0] = "F"; g1[1] = "D"; g1[2] = "D+"; g1[3] = "C";
    g1[4] = "C+"; g1[5] = "B"; g1[6] = "B+"; g1[7] = "A";
    map<string, int> g2;
    g2["F"] = 0; g2["D"] = 1; g2["D+"] = 2; g2["C"] = 3;
    g2["C+"] = 4; g2["B"] = 5; g2["B+"] = 6; g2["A"] = 7;
    vector<A> ans;

    //input id and grade
    int n; cin >> n;
    for (int i = 0;i < n;i++) {
        string id, grade; cin >> id >> grade;
        ans.push_back({ g2[grade], i, id });
    }

    //input change grade && change grade
    string s; cin.ignore();
    while (getline(cin, s)) {
        // split string by ' ' to push in vector change grade 
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                changeGrade(temp, ans);
                temp = "";
            } else {
                temp += c;
            }
        }
        changeGrade(temp, ans);
    }

    //out put
    sort(ans.begin(), ans.end());
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i].id << " " << g1[ans[i].grade] << endl;
    }

    return 0;
}