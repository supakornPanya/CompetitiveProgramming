#include <bits/stdc++.h>
using namespace std;

struct A {
    double grade;
    string pas, sub1, sub2, sub3, sub4;
    bool operator < (const A& other) {
        if (grade != other.grade) return grade > other.grade;
        if (pas != other.pas) return pas < other.pas;
        if (sub1 != other.sub1) return sub1 < other.sub1;
        if (sub2 != other.sub2) return sub2 < other.sub2;
        if (sub3 != other.sub3) return sub3 < other.sub3;
        return sub4 < other.sub4;
    }
};

int main() {
    //input subjuct
    int n; cin >> n;
    map<string, int> sub; //subject
    for (int i = 0;i < n;i++) {
        string name; int num; cin >> name >> num;
        sub[name] = num;
    }
    // cout << "sub.size() : " << sub.size() << endl;
    //input student
    cin >> n;
    vector<A> student;
    for (int i = 0;i < n;i++) {
        string pas, sub1, sub2, sub3, sub4; double grade;
        cin >> pas >> grade >> sub1 >> sub2 >> sub3 >> sub4;
        // cout << "pas : " << pas << ", grade : " << grade << ", sub1 : " << sub1 << endl;
        student.push_back({ grade, pas, sub1, sub2, sub3, sub4 });
    }
    sort(student.begin(), student.end());

    //process
    vector<pair<string,string>> ans;

    // cout << "studnet size : " << student.size() << endl;

    for(int i = 0;i < student.size();i++) {
        // cout << "grade : " << student[i].grade << ", pas : " << student[i].pas << endl;
        if(sub[student[i].sub1] > 0) {
            ans.push_back({student[i].pas, student[i].sub1 });
            sub[student[i].sub1]--;
        } else if (sub[student[i].sub2] > 0) {
            ans.push_back({ student[i].pas, student[i].sub2 });
            sub[student[i].sub2]--;
        } else if (sub[student[i].sub3] > 0) {
            ans.push_back({ student[i].pas, student[i].sub3 });
            sub[student[i].sub3]--;
        } else if (sub[student[i].sub4] > 0) {
            ans.push_back({ student[i].pas, student[i].sub4 });
            sub[student[i].sub4]--;
        }
    }
    sort(ans.begin(), ans.end());

    //output
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}