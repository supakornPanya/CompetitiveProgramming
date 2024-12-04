#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> m;
    m["Robert"] = "Dick"; m["Dick"] = "Robert";
    m["William"] = "Bill"; m["Bill"] = "William";
    m["James"] = "Jim"; m["Jim"] = "James";
    m["John"] = "Jack"; m["Jack"] = "John";
    m["Margaret"] = "Peggy"; m["Peggy"] = "Margaret";
    m["Edward"] = "Ed"; m["Ed"] = "Edward";
    m["Sarah"] = "Sally"; m["Sally"] = "Sarah";
    m["Andrew"] = "Andy"; m["Andy"] = "Andrew";
    m["Anthony"] = "Tony"; m["Tony"] = "Anthony";
    m["Deborah"] = "Debbie"; m["Debbie"] = "Deborah";

    int n; cin >> n;
    for(int i = 0;i < n;i++) {
        string s; cin >> s;
        if(m.find(s) != m.end()) cout << m[s] << endl;
        else cout << "Not found" << endl;
    }

    return 0;
}