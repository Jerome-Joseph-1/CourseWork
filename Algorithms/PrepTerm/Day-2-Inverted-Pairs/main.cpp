#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long judge(vector<long long> &nums, long long n) {
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (nums[i] > nums[j]) {
        ++count;
      }
    }
  }

  return count;
}

long long mergeSubarrays(vector<long long> &nums, long long l, long long r) {
  long long count = 0;
  long long LStart = l, RStart = l + (r - l) / 2 + 1;
  long long i = LStart, j = RStart, p = 0;

  vector<long long> sortedSubarray(r - l + 1);
  while (i < RStart and j <= r) {
    if (nums[i] > nums[j]) {
      count += r - j + 1;
      sortedSubarray[p++] = nums[i++];
    } else {
      sortedSubarray[p++] = nums[j++];
    }
  }

  while (i < RStart) {
    sortedSubarray[p++] = nums[i++];
  }

  while (j <= r) {
    sortedSubarray[p++] = nums[j++];
  }

  for (long long i = l; i <= r; ++i) {
    nums[i] = sortedSubarray[i - l];
  }
  return count;
}

long long mergeSort(vector<long long> &nums, long long l, long long r) {
  long long count = 0;
  if (l < r) {
    long long mid = l + (r - l) / 2;
    long long L1 = mergeSort(nums, l, mid);
    long long L2 = mergeSort(nums, mid + 1, r);
    long long L3 = mergeSubarrays(nums, l, r);
    count += L1 + L2 + L3;
  }
  return count;
}

void solve() {
  bool validateAnswer = true;

  // Find the total number inverted pairs
  // An inverted pair is a pair for which i < j and a[j] > a[i]

  long long n;
  cin >> n;
  vector<long long> nums(n);

  for (long long i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  // the copy of the unmodified nums array
  // Used as an input for the judge
  vector<long long> copy(nums.begin(), nums.end());

  long long actualOutput = mergeSort(nums, 0, n - 1);
  if (validateAnswer) {
    long long expectedOutput = judge(copy, n);

    cout << "Test Case: "
         << ((expectedOutput == actualOutput) ? "Passed" : "Failed")
         << "\tExpected: " << expectedOutput << ", Found: " << actualOutput
         << "\n";
  } else
    cout << actualOutput << "\n";
}

int main() {
  long long t;
  cin >> t;
  while (t--)
    solve();
}