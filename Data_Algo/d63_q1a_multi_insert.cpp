#include <iostream>
#include <vector>
using namespace std;

void multiple_add(vector<int>& v, int value, int position, int count) {
    int idx = v.size() - 1;
    v.resize(v.size() + count);
    int upper = (position == 0) ? count - 1 : position + count - 1;
    for(int i = v.size() - 1;i >= 0;i--) {
        if(position <= i && i <= upper){
            v[i] = value;
        } else {
            v[i] = v[idx]; idx--;
        }
    }       
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, value, position, count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    multiple_add(v, value, position, count);
    
    cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
    for (auto& x : v) cout << x << " ";
    cout << endl;
}