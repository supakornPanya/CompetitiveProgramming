//!sol
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     cout << "Hello World." << endl;
//     cout << "We're using C++." << endl;
// }

//!sol 2 
#include <iostream>
#include <string>

int main() {
    std::string t = "Hello World.";

    for (char c : t) {
        std::cout.put(c);
    }

    std::cout.put('\n');

    std::string t1 = "We're using C++.";

    for (char c : t1) {
        std::cout.put(c);
    }

    std::cout.flush();
    return 0;
}