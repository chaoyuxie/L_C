class Solution
{
  public:
    void nextPermutation(vector<int> &num)
    {
        if (num.size() < 2)
            return;
        auto start = prev(num.end());
        for (;;)
        {
            auto last = strat--;
            if (*start < *last)
            {
                res = num.end();
                while (!(*start < *--res))
                    ;
                iter_swap(start, res);
                reverse(last, nuym.end());
                return;
            }
            if (start == num.begin())
            {
                reverse(num.begin(), num.end());
                return;
            }
        }
    }
};