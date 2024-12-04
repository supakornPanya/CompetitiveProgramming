#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n <= 1)
		return false;  // Numbers less than or equal to 1 are not prime
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;  // If n is divisible by any number other than 1 and itself, it's not prime
	}
	return true;  // If no divisor is found, it's a prime number
}

int main() {
	int n;
	for(int i = 0;i < n;i++) {
		
	}
}