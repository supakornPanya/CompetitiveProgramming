#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool q1 = false, q2 = false, q3 = false, q4 = false;
    int q1xmin = INT_MAX, q1xmax = INT_MIN, q1ymin = INT_MAX, q1ymax = INT_MIN;
    int q2xmin = INT_MAX, q2xmax = INT_MIN, q2ymin = INT_MAX, q2ymax = INT_MIN;
    int q3xmin = INT_MAX, q3xmax = INT_MIN, q3ymin = INT_MAX, q3ymax = INT_MIN;
    int q4xmin = INT_MAX, q4xmax = INT_MIN, q4ymin = INT_MAX, q4ymax = INT_MIN;
    for (int i = 0;i < n;i++) {
        int x, y; cin >> x >> y;
        if (x == 0 || y == 0) continue;
        if (x > 0 && y > 0) {
            q1 = true;
            q1xmin = min(q1xmin, x);
            q1xmax = max(q1xmax, x);
            q1ymin = min(q1ymin, y);
            q1ymax = max(q1ymax, y);
        } else if (x < 0 && y > 0) {
            q2 = true;
            q2xmin = min(q2xmin, x);
            q2xmax = max(q2xmax, x);
            q2ymin = min(q2ymin, y);
            q2ymax = max(q2ymax, y);
        } else if (x < 0 && y < 0) {
            q3 = true;
            q3xmin = min(q3xmin, x);
            q3xmax = max(q3xmax, x);
            q3ymin = min(q3ymin, y);
            q3ymax = max(q3ymax, y);
        } else if (x > 0 && y < 0) {
            q4 = true;
            q4xmin = min(q4xmin, x);
            q4xmax = max(q4xmax, x);
            q4ymin = min(q4ymin, y);
            q4ymax = max(q4ymax, y);
        }
    }

    if (!q1 && !q2 && !q3 && !q4) {
        cout << "No point in any quadrant";
        return 0;
    }

    if (q1) {
        cout << "Q1: ";
        cout << "(" << q1xmin << ", " << q1ymin << ")";
        cout << " ";
        cout << "(" << q1xmax << ", " << q1ymax << ")";
        cout << " ";
        cout << (q1xmax - q1xmin) * (q1ymax - q1ymin) << '\n';
    }
    if (q2) {
        cout << "Q2: ";
        cout << "(" << q2xmin << ", " << q2ymin << ")";
        cout << " ";
        cout << "(" << q2xmax << ", " << q2ymax << ")";
        cout << " ";
        cout << (q2xmax - q2xmin) * (q2ymax - q2ymin) << '\n';
    }
    if (q3) {
        cout << "Q3: ";
        cout << "(" << q3xmin << ", " << q3ymin << ")";
        cout << " ";
        cout << "(" << q3xmax << ", " << q3ymax << ")";
        cout << " ";
        cout << (q3xmax - q3xmin) * (q3ymax - q3ymin) << '\n';
    }
    if (q4) {
        cout << "Q4: ";
        cout << "(" << q4xmin << ", " << q4ymin << ")";
        cout << " ";
        cout << "(" << q4xmax << ", " << q4ymax << ")";
        cout << " ";
        cout << (q4xmax - q4xmin) * (q4ymax - q4ymin) << '\n';
    }
}