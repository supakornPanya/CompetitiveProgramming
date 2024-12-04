#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter) {
    vector<string> ans;
    string temp = "";
    for(int i = 0;i < line.size();i++) {
        if(line[i] == delimiter){
            if (temp != "") ans.push_back(temp);
            temp = "";
        } else {
            temp += line[i];
        }
    }
    if(temp != "") ans.push_back(temp);
    return ans;
}
int main() {
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0])) {
        cout << '(' << e << ')';
    }
}