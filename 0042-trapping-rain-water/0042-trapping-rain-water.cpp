class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int l = 0, r = n - 1;
        int lMax = 0, rMax = 0;
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (lMax <= height[l]) {
                    lMax = height[l];
                } else {
                    water += lMax - height[l];
                }
                l++;
            } else {
                if (rMax <= height[r]) {
                    rMax = height[r];
                } else {
                    water += rMax - height[r];
                }
                r--;
            }
        }
        return water;

        // for(int i=0;i<n;i++){
        //     int j=i;
        //     int lMax=0,rMax=0;
        //     while(j>=0){
        //         lMax=max(lMax,height[j]);
        //         j--;
        //     }
        //     j=i;
        //     while(j<n){
        //         rMax=max(rMax,height[j]);
        //         j++;
        //     }
        //     water+=min(lMax,rMax)-height[i];
        // }
        // return water;
    }
};