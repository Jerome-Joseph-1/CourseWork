#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

void judge(string& binary_string, long long k_index) {
    bool is_correct = false;

    long long count = 0;
    for (long long i = 0; i < binary_string.size(); i++) {
        if(i <= k_index) {
            count += binary_string[i] == '0';
        } else {
            count -= binary_string[i] == '1';
        }
    }

    is_correct = count ? false: true;
    if (is_correct) {
        cout << "Test Case: " << "\t" << GREEN << "Passed" << "\n" << WHITE;
    } else {
        cout << "Test Case: " << "\t" << RED << "Failed" << "\n" << WHITE;
    }
}


void solve() {
    bool verify_answers = true;

    // Given a binary string 'S' of size 'N'
    // Find an index 'K', such that 
    // Count of zeros in the [0, K] == Count of ones in [K+1, N)
    long long N; 
    string binary_string;

    cin >> N;
    cin >> binary_string;

    long long k_index = -1;
    for (long long i = 0; i < N; ++i) {
        k_index += binary_string[i] == '1' ? 1 : 0;
    }


    if (verify_answers) {
        judge(binary_string, k_index);
    } else {
        cout << k_index << "\n";
    }
}

int main() {
    long long t; cin >> t; while(t--)
    solve();
}