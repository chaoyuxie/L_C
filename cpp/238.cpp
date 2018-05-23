class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result;
        int temp, left = 1;
        result.push_back(1);
        for (int i = 1; i < nums.size(); i++)
        {
            left *= nums[i - 1];
            result.push_back(left);
        }
        int right = 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            right *= nums[i + 1];
            result[i] *= right;
        }
        return result;
    }
};