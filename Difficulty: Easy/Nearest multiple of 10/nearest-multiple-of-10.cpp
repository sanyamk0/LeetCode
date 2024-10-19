//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.length();
        if (n == 1) {
            char digit = str[0];
            if (digit >= '5') return "10";
            else return "0";
        }
        int last_digit = str[n - 1] - '0';
        str.pop_back();
        if (last_digit > 5) {
            int i = n - 2;
            while (i >= 0 && str[i] == '9') {
                str[i] = '0';
                i--;
            }
            if (i >= 0)
                str[i]++;
            else
                str = "1" + str;
        }
        str += '0';
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends