//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), sum = 0;
        vector<int> rearranged;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            rearranged.push_back(arr[n - 1 - i]);
            if (i != n - 1 - i)
                rearranged.push_back(arr[i]);
        }
        for (int i = 0; i < n; ++i)
            sum += abs(rearranged[i] - rearranged[(i + 1) % n]);
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends