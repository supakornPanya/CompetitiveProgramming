#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

//passssssssssssssssssssssssssssssssssssssssssssssssssss
void change_1(std::stack<std::vector<std::queue<int>>>& a, int from, int to)
{
    //get stack
    std::vector<std::vector<std::queue<int>>> a1; //all value in stack
    while (!a.empty()) {
        a1.push_back(a.top());
        a.pop();
    }

    for (int i = 0;i < a1.size();i++) { //vector -> vector -> queue<int>
        for (int j = 0;j < a1[i].size();j++) { //vector -> queue<int>
            for (int k = 0;k < a1[i][j].size();k++) { //queue<int>
                int tmp = a1[i][j].front(); //pick
                a1[i][j].pop(); //pop
                if (tmp == from) tmp = to; // change data
                a1[i][j].push(tmp); // push
            }
        }
    }

    //push stack
    for (int i = a1.size() - 1;i >= 0;i--) {
        a.push(a1[i]);
    }
}

//passssssssssssssssssssssssssssssssssssssssssssssssssss
void change_2(std::map<string, std::pair<std::priority_queue<int>, int>>& a, int from, int to) {
    for (auto& it : a) {
        auto value = it.second; //value of this map

        //first value--------------------------------
        std::priority_queue<int> a1 = value.first;
        //push value in pq to temp
        std::vector<int> temp;
        while (!a1.empty()) {
            temp.push_back(a1.top());
            a1.pop();
        }
        //push value in temp to a1
        for (int i = 0;i < temp.size();i++) {
            if (temp[i] == from) temp[i] = to;
            a1.push(temp[i]);
        }

        //second value--------------------------------
        int a2 = value.second;
        if (a2 == from) a2 = to;

        //make pair--------------------------------
        it.second = make_pair(a1, a2);
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>>& a, int from, int to) {
    //copy--------------------------------
    std::vector <std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> tmp;
    for (auto& it1 : a) {//travel in set
        //list<int>--------------------------------
        std::list<int> a1 = it1.first;
        for (auto& it2 : a1) {
            if (it2 == from) it2 = to;
        }

        //map<int, pair<int,string>>--------------------------------
        std::map<int, std::pair<int, string>> a2 = it1.second;
        std::vector<int> key;
        std::vector<std::pair<int, string>> value;
        for (auto& it2 : a2) { //copy to vector
            int temp1 = (it2.first == from) ? to : it2.first;
            key.push_back(temp1);
            std::pair<int, string> temp2 = it2.second;
            if (temp2.first == from) temp2.first = to;
            value.push_back(temp2);
        }

        std::map<int, std::pair<int, string>> a22;
        for (int i = 0;i < key.size();i++) { //plaste to a22
            int key1 = key[i];
            std::pair<int, string> value1 = value[i];
            a22[key1] = value1;
        }
        a2 = a22;

        //make pair--------------------------------
        auto x = make_pair(a1, a2);
        tmp.push_back(x);
    }

    //plaste--------------------------------
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> newA;
    for(int i = 0;i < tmp.size();i++) {
        newA.insert(tmp[i]);
    }
    a = newA;
}

#endif
