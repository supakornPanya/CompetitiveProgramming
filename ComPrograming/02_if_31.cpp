// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int d1, m1, y1, d2, m2, y2;
//     cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

//     int sum = 0;
//     vector<int> m(13);
//     m[1] = 31, m[2] = 28, m[3] = 31, m[4] = 30, m[5] = 31, m[6] = 30;
//     m[7] = 31, m[8] = 31, m[9] = 30, m[10] = 31, m[11] = 30, m[12] = 31;
//     //red zone
//     sum += (m[m1] - d1 + 1); //d1 day to end day of m1 month
//     for (int i = m1 + 1;i <= 12;i++) { //sum of m1 + 1 to end month
//         sum += m[i];
//     }
//     if (m1 <= 2 && (y1 - 543) % 4 == 0) sum++;
//     //black zone
//     sum += ((y2 - y1 - 1) * 365); //day between y1 and y2
//     //blue zone
//     sum += (d2 - 1); //d2 day in month m2
//     for (int i = 1;i <= m2 - 1;i++) { //start year y1 to before month mm2
//         sum += m[i];
//     }
//     if (m2 >= 3 && (y2 - 543) % 4 == 0) sum++;

//     //output
//     cout << sum << " ";
//     cout << round((sin((2 * M_PI * sum) / 23)) * 100.0) / 100.0 << " ";
//     cout << round((sin((2 * M_PI * sum) / 28)) * 100.0) / 100.0 << " ";
//     cout << round((sin((2 * M_PI * sum) / 33)) * 100.0) / 100.0;

//     return 0;
// }


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int bd, bm, by, d, m, y;
    cin >> bd >> bm >> by >> d >> m >> y;

    by -= 543;
    y -= 543;
    int bdm2 = 28, dm2 = 28;
    if (by % 400 == 0 || by % 100 != 0 && by % 4 == 0)
        bdm2 = 29;
    if (y % 400 == 0 || y % 100 != 0 && y % 4 == 0)
        dm2 = 29;

    int bnd = 31;
    if (bm == 4 || bm == 6 || bm == 9 || bm == 11)
        bnd = 30;
    else if (bm == 2)
        bnd = bdm2;

    int d1 = (bnd - bd + 1) + (d - 1);

    if (bm < 12) d1 += 31;
    if (bm < 11) d1 += 30;
    if (bm < 10) d1 += 31;
    if (bm < 9) d1 += 30;
    if (bm < 8) d1 += 31;
    if (bm < 7) d1 += 31;
    if (bm < 6) d1 += 30;
    if (bm < 5) d1 += 31;
    if (bm < 4) d1 += 30;
    if (bm < 3) d1 += 31;
    if (bm < 2) d1 += bdm2;

    if (m > 1) d1 += 31;
    if (m > 2) d1 += dm2;
    if (m > 3) d1 += 31;
    if (m > 4) d1 += 30;
    if (m > 5) d1 += 31;
    if (m > 6) d1 += 30;
    if (m > 7) d1 += 31;
    if (m > 8) d1 += 31;
    if (m > 9) d1 += 30;
    if (m > 10) d1 += 31;
    if (m > 11) d1 += 30;

    d1 += (y - by - 1) * 365;

    double phy = sin(2 * M_PI * d1 / 23);
    double emo = sin(2 * M_PI * d1 / 28);
    double intel = sin(2 * M_PI * d1 / 33);

    phy = round(phy * 100.0) / 100.0;
    emo = round(emo * 100.0) / 100.0;
    intel = round(intel * 100.0) / 100.0;

    cout << d1 << ' ' << phy << ' ' << emo << ' ' << intel;
}
