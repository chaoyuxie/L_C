class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        int index = 0;
        for (const auto &num : nums)
        {
            if (num < target)
            {
                index++;
            }
        }
        return index;
    }
};
