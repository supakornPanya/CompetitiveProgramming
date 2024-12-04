#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,vector<string>> idM; //key:id value:city
    map<string,vector<pair<int,string>>> cityM; //key:city value:order,id

    //input
    int n; cin >> n;
    for(int i = 0;i < n;i++) {
        string id; cin >> id;
        // cout << "id : " << id << ", ";
        while(true) {
            string city; cin >> city;
            if(city == "*") break;
            idM[id].push_back(city); 
            cityM[city].push_back({i, id});
            // cout << city << " ";
        }
        // cout << endl;
    }

    //question
    set<pair<int,string>> ans;
    string q; cin >> q;
    for(int i = 0;i < idM[q].size();i++) { //loop each city in id(q)
        string city = idM[q][i];
        // cout << "city : " << city << ", ";
        for(int j = 0;j < cityM[city].size();j++) { //loop each id in city from id(q)
            string id = cityM[city][j].second;
            int order = cityM[city][j].first;
            if(id != q) ans.insert({order, id});
            // cout << id << ", ";
        }
        // cout << endl;
    }

    //output
    if(ans.size() == 0) { cout << ">> Not Found"; return 0; }
    for(auto it = ans.begin();it != ans.end();it++) {
        cout << ">> " << it->second << endl;
    }

    return 0;
}