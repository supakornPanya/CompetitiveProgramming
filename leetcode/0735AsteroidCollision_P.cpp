#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int x : asteroids) {
            if (x > 0) { //not collision
                st.push(x);
            } else { //may be collision

                //!!case
                //1)left positive right negative
                //  1.1)left == right
                //  1.2)left < right
                //  1.3)left > right
                //      ->drop right so don't do anything
                //2)left negative right negative

                //!(1.2)
                //left positive right negative && left < abs(right) 
                //->pop left -> right still -> may be pop new left
                while (!st.empty() && st.top() > 0 && st.top() < abs(x)) {
                    st.pop();
                }

                //case : st is empty
                //!(2)
                //case : too<0 -> left negative and right negative -> <-O <-O
                if (st.empty() || st.top() < 0) {
                    st.push(x);
                }

                //!(1.1)
                //case : left == right -> pop left, drop right
                if (!st.empty() && abs(x) == st.top()) {
                    st.pop();
                }
            }
        }

        //push stack to vector
        vector<int> ans(st.size());
        for (int i = ans.size() - 1;i >= 0;i--) {
            ans[i] = st.top(); st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids = { 5,10,-5 };
    vector<int> ans = sol.asteroidCollision(asteroids);

    cout << "ans : " << endl;
    for (int x : ans) {
        cout << x << ", ";
    }
}