class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxValueWithIndex = values[0];
        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, values[j] + maxValueWithIndex - j);
            maxValueWithIndex = max(maxValueWithIndex, values[j] + j);
        }
        return maxScore;
    }
};