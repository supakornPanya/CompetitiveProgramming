#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    map<int, int> m;

    int cnt = 0, x;
    while (cin >> x) {
        m[x]++;
        if (m[x] > 0 && m[abs(x - n)] > 0 && x + abs(x - n) == n) {
            if (x == abs(x - n) && m[x] < 2) {
                continue;
            }
            // cout << x << " " << abs(x - n) << " " << m[x] << endl;
            m[x]--; m[abs(x - n)]--;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}






// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	int n; cin >> n;
// 	string ss; cin.ignore(); getline(cin, ss);
// 	vector<int> v;
// 	string temp = "";
// 	map<int, int> m;
// 	for (char c : ss) {
// 		if ('0' <= c && c <= '9') {
// 			temp += c;
// 		} else {
// 			v.push_back(stoi(temp));
// 			m[stoi(temp)]++;
// 			temp = "";
// 		}
// 	}
// 	v.push_back(stoi(temp));
// 	m[stoi(temp)]++;

// 	int cnt = 0;
// 	for (int i = 0;i < v.size();i++) {
// 		if (m[x] > 0 && m[abs(x - n)] > 0 && x + abs(x - n) == n) {
// 			if (x == abs(x - n) && m[x] < 2) {
// 				continue;
// 			}
// 			// cout << x << " " << abs(x - n) << " " << m[x] << endl;
// 			m[x]--; m[abs(x - n)]--;
// 			cnt++;
// 		}
// 	}

// 	cout << cnt;
// 	return 0;
// }