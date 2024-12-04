#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        //name of each team
        string s1, s2; cin >> s1 >> s2; 

        //storage score in each team
        vector<int> t1, t2; //keep score in each game and in each team
        int p1 = 0, p2 = 0;

        //loop score in each game
        string score;
        while (true) {
            cin >> score;
            if (score == "*") break;
            int point = 0; //score of 1 team
            for (char x : score) {
                if (x == '-') { //add score for team1
                    //cout << point << " ";
                    t1.push_back(point); point = 0;
                } else { //add in each digit
                    point *= 10;
                    point += int(x - '0');
                }
            }
            t2.push_back(point); //add score for team2
            //cout << point << endl;
            if (t1[t1.size() - 1] > t2[t2.size() - 1]) p1++; else p2++; //find winner of each game
        }

        
        //out put -> team 1
        if(p1 > p2) { cout << "*"; }
        cout << s1 << " " << p1 << " " << "[ ";
        for(int x : t1) { cout << x << " "; }
        cout << "] " << endl;
        //out put -> team 2
        if (p2 > p1) { cout << "*"; }
        cout << s2 << " " << p2 << " " << "[ ";
        for (int x : t2) { cout << x << " "; }
        cout << "] " << endl;
    }
}