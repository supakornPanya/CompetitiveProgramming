#include <bits/stdc++.h>
using namespace std;

//!sol : monotonic stack
//increasing stack POV = button to top
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; //stack save index
        vector<int> ans(temperatures.size());

        for (int i = temperatures.size() - 1;i >= 0;i--) {
            
            cout << "temperatures[i] : " << temperatures[i] << endl;

            //pop until can push new element while stack is monotone
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                cout << " pop : " << st.top() << " " << temperatures[st.top()] << endl;
                st.pop();                
            }

            //in case stack is empty.it mean not have some index greater than now element
            if (st.empty()) {
                cout << " st empty" << endl;
                st.push(i);
                ans[i] = 0;
            }
            //in case have some element in stack after maintain stack.it mean have some element greater than now element and nearest 
            else {
                cout << " !st.empty -> st.top() : " << st.top() << " " << temperatures[st.top()] << endl;
                ans[i] = st.top() - i;
                st.push(i); 
            }
        }

        return ans;
    }
};

//!sol short and fit version
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> st; //stack save index
//         vector<int> ans(temperatures.size());

//         for (int i = temperatures.size() - 1;i >= 0;i--) {
//             while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
//                 st.pop();
//             }
//             ans[i] = (st.empty()) ? 0 : st.top() - i;
//             st.push(i);
//         }
//         return ans;
//     }
// };

int main() {
    Solution sol;
    vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
    vector<int> ans = sol.dailyTemperatures(temperatures);

    cout << "ans : " << endl;
    for (int x : ans) { cout << x << " "; }
}