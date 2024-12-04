#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int count = 0;
        vector<bool> flag(rooms.size(), false);

        //add key room 0 to queue
        flag[0] = true;
        for (int i = 0;i < rooms[0].size();i++) { 
            q.push(rooms[0][i]); 
            cout << rooms[0][i] << ", ";
        }
        cout << endl;

        while (!q.empty()) {
            int key = q.front(); q.pop();

            //this room from key is never open
            if (flag[key] == false) {
                //add all key from rooms[key]
                for (int i = 0;i < rooms[key].size();i++) { 
                    if (flag[key] == false) {
                        q.push(rooms[key][i]);
                    }
                    cout << rooms[key][i] << ", "; 
                }
                cout << endl;
                flag[key] = true;
                count++;
            }
        }
        return (count == rooms.size() - 1) ? true : false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> rooms = { {1},{2},{3},{} };
    bool ans = sol.canVisitAllRooms(rooms);

    cout<<"ans : "<<ans;
}