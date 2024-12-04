#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false); 
        int round = 0;
        queue<int> q;
        
        for(int i=0;i<isConnected.size();i++){
            cout<<"outer loop : " << i << "------------------" << endl;
            if(!visited[i]){
                cout << "never visited : " << i << endl;

                //bfs
                visited[i] = true; round++;
                q.push(i);
                while(!q.empty()){
                    int row = q.front(); q.pop();
                    cout << "in bfs row is : " << row <<endl;
                    for (int j = 0;j < isConnected[row].size();j++) {
                        if(isConnected[row][j] && !visited[j]){
                            q.push(j); visited[j] = true;
                        }
                    }
                }

            }
        }
        
        return round;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> isConnected = { {1,1,0},{1,1,0},{0,0,1} };
    int ans = sol.findCircleNum(isConnected);

    cout << "ans : " << ans;
}