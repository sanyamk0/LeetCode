//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
         int index = 0, sign = 1, result = 0;
        while (s[index] == ' ')
            index++;
        if (s[index] == '+' || s[index] == '-') {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }
        while (s[index] != '\0' && isdigit(s[index])) {
            int digit = s[index] - '0';
            if (result > (std::numeric_limits<int>::max() - digit) / 10)
                return (sign == 1)
                                ? std::numeric_limits<int>::max()
                                : std::numeric_limits<int>::min();
            result = result * 10 + digit;
            index++;
        }
        return result * sign;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends