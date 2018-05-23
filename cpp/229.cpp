class Solution
{
  public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> numbers;
        vector<int> result;
        for (const auto &num : nums)
        {
            ++numbers[num];
        }
        for (const auto &num : numbers)
        {
            if (num.second > nums.size() / 3)
                result.push_back(num.first);
        }
        return result;
    }
};