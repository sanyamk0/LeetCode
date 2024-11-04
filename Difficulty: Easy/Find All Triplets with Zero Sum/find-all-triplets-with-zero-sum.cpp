//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        set<vector<int>> resSet;
        unordered_map<int, vector<pair<int, int>>> mp;
        int n = arr.size();
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                mp[arr[i] + arr[j]].push_back({i, j});
        for (int i = 0; i < n; i++) {
            if (mp.count(-arr[i])) {
                for (auto &p : mp[-arr[i]]) {
                    if(p.first == i || p.second == i) continue;
                    vector<int> curr = {p.first, p.second, i};
                    sort(begin(curr), end(curr));
                    resSet.insert(curr);
                }
            }
        }
        vector<vector<int> > res(begin(resSet), end(resSet));
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends