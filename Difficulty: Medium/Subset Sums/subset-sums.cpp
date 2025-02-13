//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void helper(int i, vector<int> ds, vector<vector<int>> &ans, vector<int> nums){
        if(i >= nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        helper(i + 1, ds, ans, nums);
        ds.pop_back();
        helper(i + 1, ds, ans, nums);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> ds, res;
        helper(0, ds, ans,arr);
        for(auto it : ans){
            int sum = 0;
            for(auto i : it){
                sum += i;
            }
            res.push_back(sum);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends