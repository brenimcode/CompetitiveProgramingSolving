#include <bits/stdc++.h>
using namespace std;

#define NMAX 100

int dp[NMAX][NMAX * 100]; // DP table
int arr[NMAX];            // Array of values
int n, totalSum;

bool findSubset(int n, int targetSum) {
    // Initializing the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= targetSum; j++) {
            dp[i][j] = 0;
        }
    }

    // Base case: a subset sum of 0 is always possible
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][targetSum];
}

void printSubset(int n, int targetSum) {
    vector<int> subset;
    int i = n, j = targetSum;

    while (i > 0 && j > 0) {
        // If dp[i-1][j] is false, it means arr[i-1] is included in the subset
        if (dp[i - 1][j] == 0 && j >= arr[i - 1]) {
            subset.push_back(arr[i - 1]);
            j -= arr[i - 1]; // Reduce the target sum by arr[i-1]
        }
        i--; // Move to the previous item
    }

    cout << "Subset with the required sum: ";
    for (int value : subset) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    // Input: number of elements in the array and the array itself
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate total sum of the array
    totalSum = accumulate(arr, arr + n, 0);

    // If total sum is odd, it's impossible to split it into two equal subsets
    if (totalSum % 2 != 0) {
        cout << "It is not possible to split the array into two subsets with equal sum." << endl;
        return 0;
    }

    int targetSum = totalSum / 2;

    // Check if there's a subset with sum equal to targetSum (totalSum / 2)
    if (findSubset(n, targetSum)) {
        cout << "A subset with the required sum exists." << endl;
        printSubset(n, targetSum);
    } else {
        cout << "No subset with the required sum exists." << endl;
    }

    return 0;
}
