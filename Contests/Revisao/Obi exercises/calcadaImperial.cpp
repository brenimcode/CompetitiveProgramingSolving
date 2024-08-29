#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {
    // Variable declarations
    int n;  // Number of elements in the array
    int max_sequence_length = 0;  // The maximum length of the sequence found

    cin >> n;  // Input the number of elements
    int elements[n];  // Array to store the elements

    // Read the elements into the array
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    // Iterate over all possible pairs of elements in the array
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int A = elements[i], B = elements[j];

            int last_seen = -1;  // Track the last seen element in the sequence
            int current_sequence_length = 0;  // Length of the current sequence

            // Iterate over the array to find the longest alternating sequence of A and B
            for (int k = 0; k < n; k++) {
                if ((elements[k] != A && elements[k] != B) || elements[k] == last_seen) {
                    continue;  // Skip if the element is not A or B, or if it is the same as the last seen element
                }
                current_sequence_length++;  // Increase the length of the current sequence
                last_seen = elements[k];  // Update the last seen element
            }

            // Update the maximum sequence length found
            max_sequence_length = max(max_sequence_length, current_sequence_length);
        }
    }

    // Output the maximum sequence length
    cout << max_sequence_length << endl;

    return 0;
}
