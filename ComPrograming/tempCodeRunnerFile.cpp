#include <bits/stdc++.h>
using namespace std;

struct A{
    int pass;
    int penalty;
    string name;
    bool operator<(const A& other) const {
        if(pass != other.pass) return pass < other.pass;
        if(penalty != other.penalty) return penalty > other.penalty;
        return name > other.name;
    }
};

int main() {
    int n; cin >> n;
    map<string, pair<int,int>> team; 
    //NameTeam -> (number of pass problem, penalty)
    map<pair<int,string>, pair<bool,int>> problem; 
    //(NameProblem, NameTeam) -> (this problem in this team is pass?, number of problem that not pass)
    for (int i = 0;i < n;i++) {
        int time, prob; string nameTeam; char pass;
        cin >> time >> nameTeam >> prob >> pass;
        
        if(pass == 'T') {
            if (problem[{prob, nameTeam}].first == false) {
                team[nameTeam].first += 1;
                team[nameTeam].second += (problem[{prob, nameTeam}].second) * 20;
                team[nameTeam].second += time;
            }
            problem[{prob, nameTeam}].first = true;
        } else {
            problem[{prob, nameTeam}].second += 1;
        }
    }

    priority_queue<A> pq;
    for(auto it = team.begin();it != team.end();it++) {
        A temp = {it->second.first, it->second.second, it->first};
        pq.push(temp);
    }

    size_t cnt = 0;
    while (!pq.empty() && cnt < 3) {
        A prev = pq.top(); pq.pop(); cnt++;
        cout << prev.name << " " << prev.pass << " " << prev.penalty << '\n';
        while(!pq.empty() && pq.top().pass == prev.pass && pq.top().penalty == prev.penalty) {
            A prev = pq.top(); pq.pop(); cnt++;
            cout << prev.name << " " << prev.pass << " " << prev.penalty <<'\n';
        }
    }
    return 0;
}