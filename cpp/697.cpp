class Solution
{
  public:
    int findShortestSubArray(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int res = nums.size();
        map<int, int> startIndex, countnumber;
        int len = nums.size(), fre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (startIndex.count(nums[i]) == 0)
                startIndex[nums[i]] = i;
            countnumber[nums[i]]++;
            if (countnumber[nums[i]] == fre)
            {
                len = min(len, i - startIndex[nums[i]] + 1);
            }
            if (countnumber[nums[i]] > fre)
            {
                len = i - startIndex[nums[i]] + 1;
                fre = countnumber[nums[i]];
            }
        }
        return len;
    }
};