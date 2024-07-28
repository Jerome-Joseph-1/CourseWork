#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

void judge() {
    bool is_correct = false;
    // logic to check if answer is correct 
    if (is_correct) {
        cout << "Test Case: " << GREEN << "Passed" << "\n" << WHITE;
    } else {
        cout << "Test Case: " << RED << "Failed" << "\n" << WHITE;
    }
}

void solve() {
    bool verify_answers = false;

    if (verify_answers) {
        judge();
    } else {
        
    }
}

int main() {
    long long t; cin >> t; while(t--)
    solve();
}