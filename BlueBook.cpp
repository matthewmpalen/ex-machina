// BlueBook code decryption (C++ implementation)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Computes primes using sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<int> x(n);
    fill(x.begin(), x.end(), 1);
    x[1] = 0;

    for (int i = 2; i < n/2; i++) {
        int j = 2 * i;

        while (j < n) {
            x[j] = 0;
            j = j + i;
        }
    }

    return x;
}

// Find nth prime
int prime(int n, vector<int> x) {
    int i = 1;
    int j = 1;

    while (j <= n) {
        if (x[i] == 1) {
            j++;
        }
        i++;
    }

    return i - 1;
}

int main() {
    // Compute BlueBook unlock code
    vector<int> x = sieve(10000);

    int code[4] = {1206, 301, 384, 5};
    int key[4] = {1, 1, 2, 2};

    for (auto i : {73, 83, 66, 78, 32, 61, 32}) {
        cout << static_cast<char>(i);
    }

    for (int i = 0; i < 4; i++) {
        cout << prime(code[i], x) - key[i];
    }

    cout << endl;

    return 0;
}
