//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        int s=0,e=n-1;
        int cnt=0;
        while(s<e){
            int sum=arr[s]+arr[e];
            if(sum==target){
                cnt++;
                int tempst=s+1;;
                int tempend=e;
                while(arr[tempst]==arr[s] && tempst<tempend){
                    cnt++;
                    tempst++;
                }
                tempst=s,tempend=e-1;
                while(arr[tempend]==arr[e] && tempst<tempend){
                    cnt++;
                    tempend--;
                }
                s++;
                e--;
            }else if(sum<target){
                s++;
            }else{
                e--;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends