#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "NthFibonacciGenerator.cpp"

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long MOD = 1e6 + 7;

vector<long long> fibonacci_sequence(6*MOD + 2);

void judge(long long n, long long ans) {
    bool is_correct = false;
    // logic to check if answer is correct 

    NthFibonacci fibGen;
    long long expected_answer = fibGen.nthFibonacciNumber(n - 1, MOD);

    is_correct = expected_answer == ans;

    // cout << "Expected: " << expected_answer << " " << "Got: " << ans << "\n";
    if (is_correct) {
        cout << "Test Case: " << GREEN << "Passed" << "\n" << WHITE;
    } else {
        cout << "Test Case: " << RED << "Failed" << "\n" << WHITE;
    }
}

void solve(long long period) {
    bool verify_answers = true;
    // Nth fibonacci using periodicity 
    // MOD (modulous) == 1e9 
    // Range : 1 <= N <= 1e9
    long long n; cin >> n;
    long long n_copy = n;

    n %= period; // Since the function is periodic with a period of 'period'

    long long nth_fibonacci = fibonacci_sequence[n];
    if (verify_answers) {
        judge(n_copy, nth_fibonacci);
    } else {
        cout << nth_fibonacci << "\n";    
    }
}

long long find_periodicity(long long M) {

    // For a function to be periodic, there must be at least two consecutive points that repeat.
    // It is known that the Fibonacci sequence modulo 'm' is periodic with a period of at most 6*m.
    fibonacci_sequence[0] = 0;
    fibonacci_sequence[1] = 1;
    for (long long i = 2; i <= 6*M + 1; ++i) {
        fibonacci_sequence[i] = (fibonacci_sequence[i-1] + fibonacci_sequence[i-2]) % MOD;
        if(
            fibonacci_sequence[i - 1] == 0
            and 
            fibonacci_sequence[i] == 1
        ) return i - 1;
    }

    return -1; // Should never reach here 
}

int main() {
    long long period = find_periodicity(MOD);
    long long t; cin >> t; while(t--)
    solve(period);
}