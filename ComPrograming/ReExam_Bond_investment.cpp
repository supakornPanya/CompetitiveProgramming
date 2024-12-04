#include <bits/stdc++.h>
using namespace std;

struct A {
    string n; //name
    int y, m; //year, money
    bool operator < (const A& other) const {
        if (n != other.n) return n < other.n;
        if (y != other.y) return y < other.y;
        return m < other.m;
    }
};

struct B {
    int m;
    string n;
    bool operator < (const B& other) const {
        if (m != other.m) return m > other.m;
        return n < other.n;
    }
};


string namee(string data) {
    string ans = "";
    for (int i = 0;i < data.size() - 4;i++) {
        ans += data[i];
    }
    return ans;
}

int main() {
    multimap<string, pair<int, int>> m1; //name : {money, year}
    vector<A> v1;
    string s;
    while (getline(cin, s)) {
        if (s.size() == 4) break;
        string data = "";
        for (int j = 0;j < s.size();j++) {
            if (s[j] == ' ') break;
            else data += s[j];
        }
        string m = "";
        for (int j = data.size();j < s.size();j++) {
            m += s[j];
        }
        int money = stoi(m);
        string name = namee(data);
        int year = (data[data.size() - 4] - '0') * 10 + (data[data.size() - 3] - '0');
        v1.push_back({ name, year, money });
    }
    sort(v1.begin(), v1.end());

    int year = (s[2] - '0') * 10 + (s[3] - '0');
    vector<B> v2; //money, name
    // cout << "v1 : " << v1.size() << endl; 
    // cout << "year : " << year << endl;
    for (int i = 0;i < v1.size();i++) {
        // cout << v1[i].n << " " << v1[i].y << " " << v1[i].m << endl;
        if(v1[i].y <= year) {
            if(i != 0 && v1[i].n == v2[v2.size() - 1].n) {
                v2[v2.size() - 1].m += v1[i].m;
            } else {
                v2.push_back({v1[i].m, v1[i].n});
            }
        }
    }

    // cout << "ans : __________" << endl;
    sort(v2.begin(), v2.end());
    for (int i = 0;i < v2.size();i++) {
        cout << v2[i].n << " " << v2[i].m << endl;
    }

}