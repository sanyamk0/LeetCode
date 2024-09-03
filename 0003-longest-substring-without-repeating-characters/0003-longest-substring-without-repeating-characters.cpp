class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int maxLength = 0, start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char rightChar = s[i];
            if (mp.find(rightChar) != mp.end())
            {
                start = max(start, mp[rightChar] + 1);
            }
            mp[rightChar] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};