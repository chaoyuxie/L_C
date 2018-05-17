class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> result;
        for(const auto &num:nums)
        {
            ++result[num];
        }
        for(const auto &num:result)
        {
            if(num.second >=2 )return true;
        }
        return false;
        
    }
};