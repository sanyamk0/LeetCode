//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i-1]){
                int num = arr[i];
                if(num == 0)
                    continue;
                arr[i-1] = 2 * num;
                arr[i] = 0;
            }
        }
        int i = 0, j = 1;
        while(i < n && j < n){
            if(arr[i] == 0 && arr[j] != 0){
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else if(arr[i] != 0 && arr[j] == 0)
                i++;
            else
                j++;
        }
        return arr;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends