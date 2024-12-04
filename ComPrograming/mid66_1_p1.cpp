#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;

    if (a < 100) {
        //left
        do {
            if (b < c) {
                a += pow(b, 2) + pow(c, 2);
                if (a % 10 == 5) {
                    break;
                } else {
                    if (a % 2 == 0) {
                        b++;
                    } else {
                        c--;
                    }
                }
            } else {
                break;
            }
        } while (a / (b * c) <= 20);
    }

    //right
    else {
        if (a < b) {
            if (b < c) {
                a = a + 3;
                b = a + c;
                c = b + a;
            } else if (a < c) {
                a = 2 * a;
                b = a + b;
                c = b + c;
            } else {
                a = c + a;
                b = 2 * b;
                c = b - a;
            }
        } else {
            if(c > a) {
                a = 3 * b;
                b = c + a;
                c = a + b;
            } else if (b > c) {
                a = b + c;
                b = 7 * a;
                c = b - a;
            } else {
                a = c - 5;
                b = a - b;
                c = 3 * b;
            }
        }
    }

    cout << a << " " << b << " " << c;

    return 0;
}