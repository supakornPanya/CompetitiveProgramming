#include <bits/stdc++.h>
using namespace std;

//slow because have many if 
/*
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m = { {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},
                                {10,"X"},{40,"XL"},{50,"L"},{90,"XC"},
                                {100,"C"},{400,"CD"},{500,"D"},{900,"CM"},
                                {1000,"M"} };

        string ans = "";
        if (1000 <= num && num < 4000) {
            while (num >= 1000) {
                ans += m[1000];
                num -= 1000;
            }
        }
        if (100 <= num && num < 1000) {
            if (num >= 900) { ans += m[900]; num -= 900; }
            if (num >= 500) { ans += m[500]; num -= 500; }
            if (num >= 400) { ans += m[400]; num -= 400; }
            while (num >= 100) {
                ans += m[100];
                num -= 100;
            }
        }
        if (10 <= num && num < 100) {
            if (num >= 90) { ans += m[90]; num -= 90; }
            if (num >= 50) { ans += m[50]; num -= 50; }
            if (num >= 40) { ans += m[40]; num -= 40; }
            while (num >= 10) {
                ans += m[10];
                num -= 10;
            }
        }
        if (0 < num && num < 10) {
            if (num >= 9) { ans += m[9]; num -= 9; }
            if (num >= 5) { ans += m[5]; num -= 5; }
            if (num >= 4) { ans += m[4]; num -= 4; }
            while (num >= 1) {
                ans += m[1];
                num -= 1;
            }
        }
        return ans;
    }
};
*/

//faster : faster because loop each key until key can not substact num, 
//         slow because using map->O(logN)
/*
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m = { {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},
                                {10,"X"},{40,"XL"},{50,"L"},{90,"XC"},
                                {100,"C"},{400,"CD"},{500,"D"},{900,"CM"},
                                {1000,"M"} };
        string ans = "";
        auto it = m.end(); it--;
        while (num) {
            int key = it->first; string value = it->second;
            while (num >= key) {
                //cout << it->first << " : " << it->second << endl;
                //cout << "num: " << num << ", ans: " << ans << endl;
                ans += value;
                num -= key;
            }
            it--;
        }
        return ans;
    }
};
*/

//fastest : faster because loop each key until key can not substact num,
//          using array access->O(1) 
class Solution {
public:
    string intToRoman(int num) {
        int key[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string value[] = { "I", "IV" ,"V","IX","X" ,"XL" ,"L" ,"XC" ,"C","CD","D","CM","M" };
        string ans = "";
        int i=12;
        while (num) {
            while (num >= key[i]) {
                //cout << it->first << " : " << it->second << endl;
                //cout << "num: " << num << ", ans: " << ans << endl;
                ans += value[i];
                num -= key[i];
            }
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int num = 9;
    string ans = sol.intToRoman(num);
    cout << ans;
}