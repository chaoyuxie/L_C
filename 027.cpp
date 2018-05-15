class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(const auto& num:nums)
        {
            if(num != val)
            {
                nums[index++] = num;
            }
        }
        return index;
    }
};