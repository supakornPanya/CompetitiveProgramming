#include <bits/stdc++.h>
using namespace std;

struct A {
    double long num, point;
    string name;
    bool operator < (const A& other) const {
        if (num != other.num) return num > other.num;
        if (point != other.point) return point > other.point;
        if (name != other.name) return name > other.name;
    }
};

struct R {
    double long remainder; string name;
    bool operator < (const R& other) const {
        if (remainder != other.remainder) return remainder < other.remainder;
        if (name != other.name) return name > other.name;
    }
};

int main() {
    vector<A> ans; //answer
    vector<R> rem; //remainder
    double long sum = 0;
    //input and find average 
    while (true) {
        string name; cin >> name;
        if (name == "END") break;
        double point; cin >> point;

        sum += point;
        ans.push_back({ 0, point, name });
    }
    double long avr = sum / 100;

    //find num(ans[i].num) and remainder of each team(rem)
    int sumNum = 0; //sum all number of council(person)
    for (int i = 0;i < ans.size();i++) {
        double long num = ans[i].point / avr;
        sumNum += int(num); //floor num
        ans[i].num = int(num); //floor num
        rem.push_back({ int(num) - num, ans[i].name });
    }

    //case number of council < 100
    if (sumNum < 100) sort(rem.begin(), rem.end());
    for (int i = 0;i < 100 - sumNum;i++) { //loop for find add number of council
        string name = rem[i].name;
        for (int j = 0;j < ans.size();j++) { //find name that consistant with max remainder
            if (ans[j].name == name) {
                ans[j].num++;
                break;
            }
        }
    }

    //output
    sort(ans.begin(), ans.end());
    for (int i = 0;i < ans.size();i++) {
        if(ans[i].num == 0) return 0;
        cout << ans[i].name << " " << ans[i].num << " " << ans[i].point << endl;
    }

    return 0;
}