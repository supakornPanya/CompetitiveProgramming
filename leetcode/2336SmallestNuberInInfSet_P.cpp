#include <bits/stdc++.h>
using namespace std;

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
class SmallestInfiniteSet {
private: 
    vector<bool> flag; //have this num in set will be flag[num] = false
    int i = 1; // point to smallest flag
public:
    SmallestInfiniteSet() : flag(1010, false) {}

    int popSmallest() {
        flag[i] = true;
        int prev = i; i++;
        while (flag[i]) { i++; } // find new smallest 
        return prev;
    }

    void addBack(int num) {
        flag[num] = false;
        i = min(num, i);
    }
};

int main() {
    //it must create each command by myself so I am lazy run this class in leet code
}