//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;
        int max_area = 0, tp, area_with_top, i = 0;
        while (i < n) {
            if (s.empty() || arr[i] >= arr[s.top()]) {
                s.push(i++);
            } else {
                tp = s.top();
                s.pop();
                area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }
        while (!s.empty()) {
            tp = s.top();
            s.pop();
            area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
        return max_area;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends