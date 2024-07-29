#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// void displayMatrix(vector<vector<long long>>& matrix) {
//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 2; j++) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }

vector<vector<long long>> multiplyMatrices(vector<vector<long long>> A, vector<vector<long long>> B, long long M) {

    vector<vector<long long>> result{
        {0, 0},
        {0, 0}
    };

    result[0][0] = ((A[0][0] * B[0][0]) % M + (A[0][1] * B[1][0]) % M) % M;
    result[0][1] = ((A[0][0] * B[0][1]) % M + (A[0][1] * B[1][1]) % M) % M;
    result[1][0] = ((A[1][0] * B[0][0]) % M + (A[1][1] * B[1][0]) % M) % M;
    result[1][1] = ((A[1][0] * B[0][1]) % M + (A[1][1] * B[1][1]) % M) % M;

    return result;
}

vector<vector<long long>> fastExponentiation(vector<vector<long long>> matrix, long long exponent, long long M) {
    if(exponent == 1) return matrix;
    else if (exponent & 1) return multiplyMatrices(matrix, fastExponentiation(matrix, exponent - 1, M), M);
    return fastExponentiation(multiplyMatrices(matrix, matrix, M), exponent / 2, M);
} 

long long nthFibonacciNumber(long long n, long long M) {
    // Find the n-th Fibonacci number
    vector<vector<long long>> matrix{{1, 1}, {1, 0}};
    vector<vector<long long>> exponentiatedMatrix = fastExponentiation(matrix, n, M);
    return exponentiatedMatrix[0][0];
}

void solve() {
    long long n, M; cin >> n >> M;
    if(n > 1) 
        cout << nthFibonacciNumber(n - 1, M) << '\n';
    else
        cout << n << "\n";
}

int main() {
    long long t; cin >> t; while(t--)
    solve();
}
