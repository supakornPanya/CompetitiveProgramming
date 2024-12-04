#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
//         sort(enemyEnergies.begin(), enemyEnergies.end());
//         long long e = currentEnergy;
//         if (e >= enemyEnergies[0]) {
//             for (int i = 1;i < enemyEnergies.size();i++) {
//               e += enemyEnergies[i];
//             }
//         }
//         if(e == 0) {return 0;}
//         long long point = enemyEnergies[0] / e;
//         return point;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> enemyEnergies = { 1,2,3 };
//     int e = 0;

//     long long ans = sol.maximumPoints(enemyEnergies, e);
//     cout << "ans : " << ans;
// }
















class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        vector<pair<int, int>> v;
        int temp = 0, n = enemyEnergies.size();
        for(int i=0;i<n;i++){
            if ((enemyEnergies[i] && !enemyEnergies[i + 1]) 
                || (!enemyEnergies[i] && enemyEnergies[i + 1])){
                int start = i;
                while (i<n && ((enemyEnergies[start] && !enemyEnergies[start + 1])
                    || (!enemyEnergies[start] && enemyEnergies[start + 1]))){
                    i++;
                }
                int end = i;
                v.push_back({start, end});
            }   
        }
        int count = 0;
        pair<int, int> temp;
        for(int i=0;i<v.size();i++){
            int start = v[i].first, end = v[i].second;
            if(start == 0 && end ==n-1){

            }
        }
    }
};







//----------------------------------------------------------------------------

// class Solution {
// public:
//     int numberOfAlternatingGroups(vector<int>& colors) {
//         int count = 0;
//         for (int i = 1;i < colors.size() - 1;i++) {
//             if ((colors[i] && !colors[i - 1] && !colors[i + 1])
//                 || (!colors[i] && colors[i - 1] && colors[i + 1])) {
//                 count++;
//             }
//         }
//         int size = colors.size();
//         if ((colors[0] && !colors[1] && !colors[size - 1])
//             || (!colors[0] && colors[1] && colors[size - 1])) {
//             count++;
//         }
//         if ((colors[size - 1] && !colors[size-2] && !colors[0])
//             || (!colors[size - 1] && colors[size - 2] && colors[0])) {
//             count++;
//         }
//         return count;
//     }
// };

// int main() {
//     Solution sol;

//     cout << "ans : " << ans;
// }