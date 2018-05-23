class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0;
        for (auto &num : nums)
        {
            if (num)
                swap(nums[left++], num);
        }
    }
};