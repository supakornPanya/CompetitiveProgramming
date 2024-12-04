#include <bits/stdc++.h>
using namespace std;

struct A {
    double per, weight, value;
    bool operator<(const A& other) const {
        if (per != other.per) return per < other.per;
        if (weight != other.weight) return weight < other.weight;
        return value < other.value;
    }
};

int main() {
    double w, n; cin >> w >> n;
    priority_queue<A> pq;
    vector<double> val;
    for (int i = 0;i < n;i++) {
        double v; cin >> v;
        val.push_back(v);
    }
    for (int i = 0;i < n;i++) {
        double w1; cin >> w1;
        double per = val[i] / w1;
        pq.push({ per,w1, val[i] });
    }

    double myW = 0;
    double myVal = 0;
    while (!pq.empty()) {
        if (myW + pq.top().weight > w) break;
        // cout << vw.top().first << " " << vw.top().second << '\n';
        myW += pq.top().weight;
        myVal += pq.top().value;
        pq.pop();
    }
    if (!pq.empty()) {
        // cout << "in this case " << '\n';
        double wUsed = w - myW;
        double perc = (wUsed / pq.top().weight);
        // cout << myVal << " " << wUsed << " " << perc << " " << pq.top().value << '\n';
        myVal += (perc * pq.top().value);
        // cout << myVal << '\n';
    }

    cout << fixed << setprecision(4) << myVal << '\n';
}