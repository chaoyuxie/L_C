class Solution
{
  public:
    bool checkPossibility(vector<int> &nums)
    {
        int prev = nums[0];
        int cout = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (prev > nums[i])
            {
                if (cout++)
                    return false;
                if (i - 2 < 0 || nums[i - 2] <= nums[i])
                    prev = nums[i];
            }
            else
                prev = nums[i];
        }
        return true;
    }
};