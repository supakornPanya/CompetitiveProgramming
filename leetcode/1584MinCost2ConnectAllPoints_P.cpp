#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());
        for(int i = 0;i < points.size();i++) {
            for(int j = 0;j < points.size();j++) {
                if(i == j) continue;
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({cost, j});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> inTree(points.size(), false);
        int ans = 0;

        while(!pq.empty()) {
            int nowW = pq.top().first;
            int nowU = pq.top().second;
            pq.pop();

            if(inTree[nowU]) continue;

            inTree[nowU] = true;
            ans += nowW;
            for(pair<int,int> next : adj[nowU]) {
                if(inTree[next.second]) continue;
                pq.push({next.first, next.second});
            }
        }
        return ans;
    }
};

