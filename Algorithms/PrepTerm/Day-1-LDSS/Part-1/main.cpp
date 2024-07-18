#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

long long judge(long long n, string& binaryString) {
  // A brute force solutions to check the answers
  long long expectedOutput = 0;

  for (long long i = 0; i < n; i++) {
    long long count = 0;
    for (long long j = i; j < n; j++) {
      count += ((binaryString[j] == '1') ? 1: -1);
      if(count > 0)
        expectedOutput = max(expectedOutput, j - i + 1);
    }
  }
  return expectedOutput;
}

void solve() {
  // Compares the answer with the brute force answer if set to true ('validateAnswers = True')
  bool validateAnswers = true;
  // Given a binary string s
  // Find the largest substring that has count(1) > count(0)
  long long n;
  cin >> n;
  string binaryString = "";
  cin >> binaryString;
  long long r_sum = 0;
  long long longestSubstring = 0, startIndex = 0;
  unordered_map<long long, long long> previouslyFoundAt;
  // vector<pair<long long, long long>> temp;

  for (long long i = 0; i < n; ++i) {
    if (binaryString[i] == '1') ++r_sum;
    else --r_sum;

    if (r_sum > 0) {
      longestSubstring = max(i + 1, longestSubstring);
    } else {
      if (previouslyFoundAt.find(r_sum - 1) != previouslyFoundAt.end()) {
        startIndex = previouslyFoundAt[r_sum - 1];
        longestSubstring = max(longestSubstring, i - startIndex);
      }
      if (previouslyFoundAt.find(r_sum) == previouslyFoundAt.end()) {
        previouslyFoundAt[r_sum] = i;
        // temp.push_back({r_sum, i});
      }
    }
  }

  long long actualOutput = longestSubstring;
  if(validateAnswers) {
    long long expectedOutput = judge(n, binaryString);
    cout << "Test Case: " << ( expectedOutput == actualOutput ? "Passed": "Failed") << "\tExpected: " << expectedOutput <<", Found: " << actualOutput << "\n";
  }
  else
    cout << actualOutput << "\n";
}

int main() {
  long long t;
  cin >> t;
  while (t--)
    solve();
}