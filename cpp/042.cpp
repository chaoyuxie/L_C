class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)return 0;
        int count = 0;
        for(int i = 0,j = height.size()-1,maxI = height[i],maxJ = height[j]; i<j;maxI= max(maxI, height[i]),maxJ = max(maxJ, height[j]))
        {
            if(maxI < maxJ) count += maxI - height[i++];
            else count += maxJ - height[j--];
        }
        return count;
    }
};