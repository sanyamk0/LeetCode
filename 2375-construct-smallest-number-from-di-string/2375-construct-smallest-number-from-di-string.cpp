class Solution {
public:
    int find(string pattern, int currentPosition, int usedDigitsMask,
             int currentNum) {
        if (currentPosition > pattern.size())
            return currentNum;
        int result = INT_MAX;
        int lastDigit = currentNum % 10;
        bool shouldIncrement =
            currentPosition == 0 || pattern[currentPosition - 1] == 'I';
        for (int currentDigit = 1; currentDigit <= 9; ++currentDigit) {
            if ((usedDigitsMask & 1 << currentDigit) == 0 &&
                currentDigit > lastDigit == shouldIncrement)
                result = min(result, find(pattern, currentPosition + 1,
                                          usedDigitsMask | 1 << currentDigit,
                                          currentNum * 10 + currentDigit));
        }
        return result;
    }
    string smallestNumber(string pattern) {
        return to_string(find(pattern, 0, 0, 0));
    }
};