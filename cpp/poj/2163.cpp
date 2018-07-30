#include <iostream>
#include <string>
using namespace std;
const int MAXN = 26;
int acount[MAXN];
int main()
{
    string s;
    int max, line = 0;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (isupper(s[i]))
            {
                acount[s[i] - 'A']++;
            }
        }

        if (++line % 4 == 0)
        {
            //line++;
            max = 0;
            for (int j = 0; j < MAXN; j++)
            {
                if (acount[j] > max)
                    max = acount[j];
            }
            for (int i = max; i > 0; i--)
            {
                for (int j = 0; j < MAXN; j++)
                {
                    if (acount[j] >= i)
                        cout << "* ";
                    else
                        cout << "  ";
                }
                cout << endl;
            }
            for (int j = 0; j < MAXN; j++)
            {
                cout << (char)(j + 'A') << " ";
            }
            cout << endl;
        }
    }
}