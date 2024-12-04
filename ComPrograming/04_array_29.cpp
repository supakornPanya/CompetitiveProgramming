#include <bits/stdc++.h>
using namespace std;

struct A {
    int x1, y1, x2, y2;
};

int main() {
    int n; cin >> n;
    vector<A> v;
    for (int i = 0;i < n;i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({ x1, y1, x2, y2 });
    }

    //brute force each rectangle
    int area = INT_MIN;
    vector<pair<int, int>> ans;
    for (int i = 0;i < n - 1;i++) {
        for (int j = i + 1;j < n;j++) {

            // cout << "i : " << i << ", j : " << j << endl;
            // //xi1, yi1, xi2, yi2
            // cout << v[i].x1 << " " << v[i].y1 << " " << v[i].x2 << " " << v[i].y2 << endl;
            // //xj1, yj1, xj2, yj2
            // cout << v[j].x1 << " " << v[j].y1 << " " << v[j].x2 << " " << v[j].y2 << endl;

            //check is overlapping ??
            bool iINj_x = (v[j].x1 <= v[i].x1 && v[i].x1 <= v[j].x2) || (v[j].x1 <= v[i].x2 && v[i].x2 <= v[j].x2); // (xi1 or xi2) is in range of (xj1 to xj2)
            bool iINj_y = (v[j].y1 <= v[i].y1 && v[i].y1 <= v[j].y2) || (v[j].y1 <= v[i].y2 && v[i].y2 <= v[j].y2); // (yi1 or yi2) is in range of (yj1 to yj2)
            bool jINi_x = (v[i].x1 <= v[j].x1 && v[j].x1 <= v[i].x2) || (v[i].x1 <= v[j].x2 && v[j].x2 <= v[i].x2); // (xj1 or xj2) is in range of (xi1 to xi2)
            bool jINi_y = (v[i].y1 <= v[j].y1 && v[j].y1 <= v[i].y2) || (v[i].y1 <= v[j].y2 && v[j].y2 <= v[i].y2); // (yj1 or yj2) is in range of (yi1 to yi2)
            if ((iINj_x && iINj_y) || (jINi_x && jINi_y)) {
                int W_Overlap = min(v[i].x2, v[j].x2) - max(v[i].x1, v[j].x1); // min(right : xi2,xj2) - max(left : xi1,xj1)
                int H_Overlap = min(v[i].y2, v[j].y2) - max(v[i].y1, v[j].y1); // min(top : yi2,yj2) - max(bottom : yi1,yj1)
                if (W_Overlap * H_Overlap == 0) continue; // case area == 0 -> skip
                // cout << "this area : " << W_Overlap * H_Overlap << endl;
                if (W_Overlap * H_Overlap > area) { //new area > old area -> pop old
                    ans.clear();
                    ans.push_back({ i, j }); //push ans  
                }
                if (W_Overlap * H_Overlap == area) { //new area == old area -> add to answer
                    ans.push_back({ i, j }); //push ans  
                }
                area = max(area, W_Overlap * H_Overlap);


            }
        }
        // cout << "-----------------> " << endl;
    }

    //out put
    if (ans.size() == 0) {
        cout << "No overlaps";
        return 0;
    }

    cout << "Max overlapping area = " << area << endl;
    for (pair<int, int> x : ans) {
        cout << "rectangles " << x.first << " and " << x.second << endl;
    }

    return 0;
}