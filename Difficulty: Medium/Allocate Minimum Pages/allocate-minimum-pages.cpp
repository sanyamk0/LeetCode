//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canAllocate(const vector<int>& books, int maxPages, int students) {
        int studentCount = 1;
        int allocatedPages = 0;
        for (const auto& pages : books) {
            if (allocatedPages + pages > maxPages) {
                studentCount++;
                allocatedPages = pages;
                if (studentCount > students) {
                    return false;
                }
            } else {
                allocatedPages += pages;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n)
            return -1;
        int totalPages = 0;
        int maxPages = INT_MIN;
        for (int i = 0; i < n; i++) {
            totalPages += arr[i];
            maxPages = max(maxPages, arr[i]);
        }
        int start = maxPages, end = totalPages;
        int result = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canAllocate(arr, mid, k)) {
                result = min(result, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends