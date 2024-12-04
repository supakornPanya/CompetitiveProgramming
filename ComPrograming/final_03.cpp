#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    map<string, set<string>> mp;

    //set man with division
    for (int i = 0;i < n;i++) {
        string name, division;
        cin >> name >> division;
        mp[division].insert(name);
    }

    //each operand
    for (int i = 0;i < m;i++) {
        int opr; cin >> opr;

        //opr == 1, O(N * (logN ^ 2))
        if (opr == 1) {
            string name, division;
            cin >> name >> division;

            //find name in division for erase
            bool found = false;
            for (auto& m : mp) { // O(NlogN)
                auto& sett = m.second;
                auto it = sett.find(name); // O(logN)
                if (it != sett.end()) {
                    //cout << " -> " << m.first << " " << *it << endl; 
                    m.second.erase(it); // O(logN)
                    found = true;
                    break;
                }
            }
            if (!found) {
                mp[division].insert(name);
            }

            //find division for insert name
            mp[division].insert(name);
        }
        //opr == 2, O(N * (logN ^ 2))
        else {
            string division1, division2;
            cin >> division1 >> division2;
            //insert name from division1 to division2
            //cout << "opr2 : ";
            for (auto name : mp[division1]) { //loop name in division1, O(NlogN)
                //cout << name << " ";
                mp[division2].insert(name); // O(logN)
            }
            //cout << endl;

            mp.erase(division1); // O(logN)
        }
    }

    //out put
    for (auto it = mp.begin();it != mp.end();it++) {
        cout << it->first << " : "; //division
        for (auto name : it->second) { //name
            cout << name << " ";
        }
        cout << endl;
    }

    return 0;
}


//?? implement by DSU
// #include <bits/stdc++.h>
// using namespace std;

// string find1(string name, map<string,string>& mpName, map<string, string>& mpDiv){
//     if (name == mpName[name]) {
//         return name;
//     } else {

//         mpName[name] = find1(name, mpName, mpDiv);
//     }
// }

// int main() {
//     int n, m; cin >> n >> m;
//     map<string, string> mpName, mpDiv;

//     //set man with division
//     for (int i = 0;i < n;i++) {
//         string name, division;
//         cin >> name >> division;
//         mpName[name] = name;
//         mpDiv[name] = division;
//     }

//     //each operand
//     for (int i = 0;i < m;i++) {
//         int opr; cin >> opr;

//         //opr == 1
//         if (opr == 1) {
//             string name, division;
//             cin >> name >> division;

//             string nameH = find1(name, mpName, mpDiv);
//         }
//         //opr == 2
//         else {
//             string division1, division2;
//             cin >> division1 >> division2;
            
//         }
//     }

//     //out put
//     for (auto it = mp.begin();it != mp.end();it++) {
//         cout << it->first << " : "; //division
//         for (auto name : it->second) { //name
//             cout << name << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }