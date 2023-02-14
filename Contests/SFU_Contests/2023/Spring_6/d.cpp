#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void impossible()
{
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    if (n % 2 == 1 && m % 2 == 1)
    {
        impossible();
    }
    else if (n % 2 == 1)
    {
        if (a < m / 2)
        {
            impossible();
        }
        a -= m / 2;
        int combinedA = a / 2;
        int combinedB = b / 2;
        // cout << combinedA << " " << combinedB << " " << c << endl;
        if (4 * (combinedA + combinedB + c) < (n - 1) * m)
        {
            impossible();
        }
        vector<vector<char>> answer(n, vector<char>(m, 'z'));
        for (int i = 0; i < m / 2; i++)
        {
            if (i % 2 == 0)
            {
                answer[n - 1][2 * i] = 'x';
                answer[n - 1][2 * i + 1] = 'x';
            }
            else
            {
                answer[n - 1][2 * i] = 'y';
                answer[n - 1][2 * i + 1] = 'y';
            }
        }
        int total = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                if (total < c)
                {
                    char val = 'b';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'a';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val;
                    answer[2 * i][2 * j + 1] = val;
                    answer[2 * i + 1][2 * j + 1] = val;
                }
                else if (total < c + combinedB)
                {
                    char val = 'e';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'c';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val;
                    answer[2 * i][2 * j + 1] = val + 1;
                    answer[2 * i + 1][2 * j + 1] = val + 1;
                }
                else
                {
                    char val = 'i';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'g';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val + 1;
                    answer[2 * i][2 * j + 1] = val;
                    answer[2 * i + 1][2 * j + 1] = val + 1;
                }
                total++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << answer[i][j];
            }
            cout << endl;
        }
    }else if (m % 2 == 1)
    {
        if (b < n / 2)
        {
            impossible();
        }
        b -= n / 2;
        int combinedA = a / 2;
        int combinedB = b / 2;
        // cout << combinedA << " " << combinedB << " " << c << endl;
        if (4 * (combinedA + combinedB + c) <  n * (m-1))
        {
            impossible();
        }
        vector<vector<char>> answer(n, vector<char>(m, 'z'));
        for (int i = 0; i < n / 2; i++)
        {
            if (i % 2 == 0)
            {
                answer[2 * i][m-1] = 'x';
                answer[2 * i + 1][m-1] = 'x';
            }
            else
            {
                answer[2 * i][m-1] = 'y';
                answer[2 * i + 1][m-1] = 'y';
            }
        }
        int total = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                if (total < c)
                {
                    char val = 'b';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'a';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val;
                    answer[2 * i][2 * j + 1] = val;
                    answer[2 * i + 1][2 * j + 1] = val;
                }
                else if (total < c + combinedB)
                {
                    char val = 'e';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'c';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val;
                    answer[2 * i][2 * j + 1] = val + 1;
                    answer[2 * i + 1][2 * j + 1] = val + 1;
                }
                else
                {
                    char val = 'i';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'g';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val + 1;
                    answer[2 * i][2 * j + 1] = val;
                    answer[2 * i + 1][2 * j + 1] = val + 1;
                }
                total++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << answer[i][j];
            }
            cout << endl;
        }
    }else
    {
        int combinedA = a / 2;
        int combinedB = b / 2;
        // cout << combinedA << " " << combinedB << " " << c << endl;
        if (4 * (combinedA + combinedB + c) <  n * m)
        {
            impossible();
        }
        vector<vector<char>> answer(n, vector<char>(m, 'z'));
        int total = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                if (total < c)
                {
                    char val = 'b';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'a';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val;
                    answer[2 * i][2 * j + 1] = val;
                    answer[2 * i + 1][2 * j + 1] = val;
                }
                else if (total < c + combinedB)
                {
                    char val = 'e';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'c';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val;
                    answer[2 * i][2 * j + 1] = val + 1;
                    answer[2 * i + 1][2 * j + 1] = val + 1;
                }
                else
                {
                    char val = 'i';
                    if ((i + j) % 2 == 0)
                    {
                        val = 'g';
                    }
                    answer[2 * i][2 * j] = val;
                    answer[2 * i + 1][2 * j] = val + 1;
                    answer[2 * i][2 * j + 1] = val;
                    answer[2 * i + 1][2 * j + 1] = val + 1;
                }
                total++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << answer[i][j];
            }
            cout << endl;
        }
    }
}