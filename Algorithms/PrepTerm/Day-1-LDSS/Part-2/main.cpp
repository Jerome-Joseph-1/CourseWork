#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long judge(string &binaryString, long long n) {
  long long numberOfDenseSubstrings = 0;
  for (long long i = 0; i < n; i++) {
    long long count = 0;
    for (long long j = i; j < n; j++) {
      count += binaryString[j] == '1' ? 1 : -1;
      if (count > 0)
        numberOfDenseSubstrings++;
    }
  }

  return numberOfDenseSubstrings;
}

long long mergeSubarrays(vector<long long> &prefix, long long l, long long r) {
  long long LStart = l, RStart = l + (r - l) / 2 + 1;
  long long i = LStart, j = RStart, p = 0;
  long long count = 0;

  vector<long long> sortedSubArray(r - l + 1);
  while (i < RStart and j <= r) {
    if (prefix[i] < prefix[j]) {
      sortedSubArray[p++] = prefix[i++];
      count += r - j  + 1;
    } else {
      sortedSubArray[p++] = prefix[j++];
    }
  }

  while (i < RStart) {
    sortedSubArray[p++] = prefix[i++];
  }

  while (j <= r) {
    sortedSubArray[p++] = prefix[j++];
  }

  for (long long i = l; i <= r; i++) {
    prefix[i] = sortedSubArray[i - l];
  }

  return count;
}

long long mergeSort(vector<long long> &prefix, long long l, long long r) {
  long long count = 0;
  if (l < r) {
    long long mid = l + (r - l) / 2;
    long long l1 = mergeSort(prefix, l, mid);
    long long l2 = mergeSort(prefix, mid + 1, r);
    count = l1 + l2 + mergeSubarrays(prefix, l, r);
  } else if (prefix[l] > 0) {
    count++;
  }
  return count;
}

void solve() {
  bool validateAnswers = true;

  long long n;
  cin >> n;
  string binaryString;
  cin >> binaryString;

  vector<long long> prefix(n);
  binaryString[0] == '1' ? prefix[0] = 1 : prefix[0] = -1;

  for (long long i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + (binaryString[i] == '0' ? -1 : 1);
  }

  long long totalDenseSubstrings = mergeSort(prefix, 0, n - 1);
  if (validateAnswers) {
    long long expectedAnswer = judge(binaryString, n);
    cout << "Test Case: "
         << (expectedAnswer == totalDenseSubstrings ? "Passed" : "Failed") << "\tExpected: " << expectedAnswer << ", Found: " << totalDenseSubstrings << "\n";
  } else
    cout << mergeSort(prefix, 0, n - 1) << "\n";
}

// void debug() {
//   long long n; cin >> n;
//   vector<long long> nums(n);
//   for (long long i = 0; i < n; i++) {
//     cin >> nums[i];
//   }
//   mergeSort(nums, 0, n - 1);

//   for(auto it: nums) cout << it << " ";
//   cout << "\n";
// }

int main() {
  long long t;
  cin >> t;
  while (t--)
    solve();
}