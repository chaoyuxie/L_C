#include <iostream>
#include <string>

using namespace std;

int main()
{
    string r;
    int n;
    while (cin >> r >> n)
    {
        int i = 1, p;
        for (; i < 6; i++)
            if (r[i] == '.')
                p = i; //找出小数点所在
        r.erase(p, 1); //先去掉小数点
        string ans;
        ans.resize(1024, 0);
        for (i = 0; i < 5; i++)
            ans[i] = r[4 - i] - 48; //数字倒排
        r = ans;
        int l = 5;
        for (i = 1; i < n; i++)
        {
            string tmp;
            tmp = ans;
            ans = "";
            ans.resize(1024, 0);
            for (int j = 0; j < 5; j++, l++)
            {
                for (int k = 0; k < l; k++)
                    ans[k + j] += r[j] * tmp[k];
                for (int k = 0; k < l; k++)
                    if (ans[k] >= 10)
                    {
                        if (k == l - 1)
                            l++;
                        ans[k + 1] += ans[k] / 10;
                        ans[k] %= 10;
                    }
            } //逐位相乘 注意进位
        }
        ans.insert(n * (5 - p), 1, '.'); //插入小数点
        int k = l;
        while (0 == ans[k])
            --k;
        int j = 0;
        while (0 == ans[j])
            ++j; //去掉首尾多余的零
        if ('.' == ans[j])
            ++j; //去掉多余的小数点
        for (; k >= j; k--)
            ans[k] == '.' ? cout << '.' : cout << ans[k] - 0; //最后正序输出
        cout << endl;
    }
    return 0;
}