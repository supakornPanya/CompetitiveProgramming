#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,vector<string>> m;

    //input
    string s, start, end;
    while(getline(cin, s)){
        //split string s by ' '
        string temp = "";
        for(char c : s) {
            if(c == ' ') {
                start = temp;
                temp = "";
            } else {
                temp += c;
            }
        }
        end = temp;
        m[start].push_back(end);
        m[end].push_back(start);
    }
    m[end].pop_back(); //last in put start = "" -> pop ""


    // cout << "map : " << endl;
    // for(auto it = m.begin();it != m.end();it++) {
    //     cout << it->first << "(" << it->second.size() << ") : ";
    //     for(int i = 0;i < it->second.size();i++) {
    //         cout << it->second[i] << " ";
    //     }cout << endl;
    // }

    //process
    vector<string> ans;
    string q = end;
    //loop start1 for find end1
    // cout << "start1 find end1 : " << endl;
    for(int i = 0;i < m[q].size();i++) {
        // cout << m[q][i] << " ";
        ans.push_back(m[q][i]);
    }
    cout << endl;
    //loop end1:start2 to end2
    int n = ans.size();
    // cout << "n : " << n << endl;
    for(int i = 0;i < n;i++) { //loop each end1:start2 
        string start = ans[i];
        // cout << start << " : ";
        for (int j = 0;j < m[start].size();j++) { //loop start2:end1
            ans.push_back(m[start][j]);
            // cout << m[start][j] << " ,";
        }
        // cout << endl;
    }

    //output
    string prev = "";
    ans.push_back(q);
    sort(ans.begin(), ans.end());
    for(int i = 0;i < ans.size();i++) {
        if(ans[i] != prev) {
            cout << ans[i] << endl;
            prev = ans[i];
        }
    }

    return 0;
}