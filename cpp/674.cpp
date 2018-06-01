class Solution
{
  public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int max_length = 1, length = 1;
        if (nums.size() == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                max_length = max(++length, max_length);
            else
                length = 1;
        }
        return max_length;
    }
};