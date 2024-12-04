#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> m;
    
    //input
    for (int i = 0;i < n;i++) {
        string name; int cost; cin >> name >> cost;
        m[name] = cost;
    }
    string s, t = ""; 
    cin.ignore(); getline(cin, s);
    vector<string> country;
    for (char c : s) {
        if(c == ' '){
            country.push_back(t);
            t = "";
        } else if(c == '-') {
            t = "";
        } else {
            t += c;
        }
    }
    country.push_back(t);

    for(string s:country) { cout << s << " "; } cout << endl;

    //compute
    int sum = 0;
    for(int i = 1;i < country.size();i++){
        if(country[i] != country[i - 1]) sum += m[country[i]];
    }

    //out put
    cout << sum;
}