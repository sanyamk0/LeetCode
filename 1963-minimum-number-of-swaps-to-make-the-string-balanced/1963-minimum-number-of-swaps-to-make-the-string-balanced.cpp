class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int minBalance = 0;
        for (char c : s) {
            if (c == '[')
                balance++;
            else
                balance--;
            minBalance = min(minBalance, balance);
        }
        return (1 - minBalance) / 2;
    }
};