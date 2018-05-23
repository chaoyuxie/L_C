///////////////////////////////////////////////////////////////////////////////////
//使用两个set变量，其中一个存储数据并用来判断num-k和num+k是否在数据中
//若存在，则insert
///////////////////////////////////////////////////////////////////////////////////

class Solution
{
  public:
    int findPairs(vector<int> &nums, int k)
    {
        set<int> lookup, result;
        if (k < 0)
            return 0;
        for (const auto &num : nums)
        {
            if (lookup.count(num - k))
                result.insert(num - k);
            if (lookup.count(num + k))
                result.insert(num);
            lookup.insert(num);
        }
        return result.size();
    }
};