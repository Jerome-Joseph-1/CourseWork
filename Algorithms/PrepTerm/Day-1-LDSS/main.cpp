#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void solve() {
  // Given a binary string s
  // Find the largest substring that has count(1) > count(0)
  long long n;
  cin >> n;
  string binaryString = "";
  cin >> binaryString;
  long long r_sum = 0;
  long long longestSubstring = 0, startIndex = 0;
  unordered_map<long long, long long> previouslyFoundAt;
  vector<pair<long long, long long>> temp;

  for (long long i = 0; i < n; ++i) {
    if (binaryString[i] == '1')
      ++r_sum;
    else
      --r_sum;

    if (r_sum > 0) {
      longestSubstring = max(i + 1, longestSubstring);
    } else {
      if (previouslyFoundAt.find(r_sum - 1) != previouslyFoundAt.end()) {
        startIndex = previouslyFoundAt[r_sum - 1];
        longestSubstring = max(longestSubstring, i - startIndex + 1);
      }
      if (previouslyFoundAt.find(r_sum) == previouslyFoundAt.end()) {
        previouslyFoundAt[r_sum] = i;
        temp.push_back({r_sum, i});
      }
    }
  }

  cout << longestSubstring - !(longestSubstring & 1) << endl;
}

int main() {
  long long t;
  cin >> t;
  while (t--)
    solve();
}