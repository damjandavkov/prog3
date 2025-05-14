#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool match(string& s, string& p)
{
    int n = s.size(), m = p.size();
    vector<vector<bool> > dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i].resize(m + 1);
        for (int j = 0; j <= m; j++)
        {
            if (!i)
            {
                if (!j)
                    dp[i][j] = 1;
                else if (p[j - 1] != '*')
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j - 1];
            }
            else
            {
                if (!j)
                    dp[i][j] = 0;
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                else
                    dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s, p;
    cin >> s >> p;
    if (match(s, p))
        cout << "Match";
    else
        cout << "No Match";
    return 0;
}
