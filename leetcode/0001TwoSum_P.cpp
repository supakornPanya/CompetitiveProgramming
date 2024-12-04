#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, vector<int>> m;
        //m[value]=index
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            m[x].push_back(i);
        }
        //loop find target
        for (int i = 0; i < nums.size(); i++)
        {
            int want = target - nums[i];
            //same value
            if (want == nums[i] && m[nums[i]].size() > 1)
            {
                return {m[nums[i]][0], m[nums[i]][1]};
            }
            //different value
            auto it = m.find(want);
            if (want != nums[i] && it != m.end())
            {
                return {m[nums[i]][0], m[want][0]};
            }
        }
        return {};
    }
};

int main()
{   
    //test casse
    vector<int> nums{-500000000, 2, 4, -500000000};
    int target = -1000000000;

    //check the result
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    for (int index : result)
    {
        cout << index << " ";
    }
    return 0;
}