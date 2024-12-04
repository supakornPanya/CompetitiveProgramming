#include <bits/stdc++.h>
using namespace std;

void oprS(vector<string>& c1, vector<string> c2, int n) {
    for (int i = 0;i < n / 2;i++) { //for even index
        c1[i * 2] = c2[i];
    }
    for (int i = 0;i < n / 2;i++) { //for odd index
        c1[i * 2 + 1] = c2[n / 2 + i];
    }
}

int main() {
    
    int n; cin >> n;
    vector<string> cards(n);
    for (int i = 0;i < n;i++) { cin >> cards[i]; }
    cout << "cards : " << endl;
    for (int i = 0;i < n;i++) { cout << cards[i] << " "; }
    cout << endl;

    //operation
    string opr; 
    cin.ignore(); getline(cin, opr); 
    //cin.ignore() == skip buffer because cin will left over new line then getline will get new line 
    //cin >> opr;
    cout << "opr : " << opr << endl;
    for (char c : opr) {
        if (c == 'C') {
            for (int i = 0;i < n / 2;i++) {
                swap(cards[i], cards[i + (n / 2)]);
            }
        } else if (c == 'S') {
            oprS(cards, cards, n);
        }
    }

    //out put
    for (int i = 0;i < n;i++) { cout << cards[i] << " "; }

    return 0;
}