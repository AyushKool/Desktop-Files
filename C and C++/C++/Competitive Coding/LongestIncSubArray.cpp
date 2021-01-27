#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

#define N 100

size_t sum(const vi &a)
{
    size_t n = a.size();
    unsigned dp[N] = {0};
    // memset(dp, INT_MAX, n);
    dp[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[j] + a[i], dp[i]);
        }
    }

    return *max_element(dp, dp + n);
}

size_t length(const vi &a)
{
    size_t n = a.size();
    unsigned int dp[N];
    fill(dp, dp + n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    // for (size_t i = 0; i < n; i++) cout << dp[i] << ' ';
    // cout << endl;

    return *max_element(dp, dp + n);
}

size_t numOFAllLIS(const vi &a)
{
    size_t n = a.size();
    unsigned int dp[N];
    fill(dp, dp + n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i])
                dp[i] += dp[j];
        }
    }
    // for (size_t i = 0; i < n; i++) cout << dp[i] << ' ';
    // cout << endl;

    return accumulate(dp, dp + n, 0);
}

size_t numOFAllLISOfLengthK(const vi &a, int k)
{
    /*
    Approach: The idea is to use Dynamic Programming by define 2D matrix, say dp[][]. 
    dp[i][j] stores the count of increasing subsequences of size i ending with element a[j]
    */
    size_t n = a.size();
    int dp[k][n], sum = 0;
    memset(dp, 0, sizeof(dp));

    // count of increasing subsequences of size 1
    // ending at each a[i]
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;

    // building up the matrix dp[][]
    // Here 'l' signifies the size of
    // increassing subsequence of size (l+1).
    for (int l = 1; l < k; l++)
    {

        // for each increasing subsequence of size 'l+1'
        // ending with element arr[i]
        for (int i = l; i < n; i++)
        {

            // count of increasing subsequences of size 'l'
            // ending with element arr[i]
            // dp[l][i] = 0;
            for (int j = l - 1; j < i; j++)
            {
                if (a[j] < a[i])
                    dp[l][i] += dp[l - 1][j];
            }
        }
    }

    for(int i=0; i<k; ++i)
    {
        for(int j = 0; j<n; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    // sum up the count of increasing subsequences of
    // size 'k' ending at each element arr[i]
    for (int i = k - 1; i < n; i++)
        sum += dp[k - 1][i];

    // required number of increasing
    // subsequences of size k
    return sum;
}
int main()
{
    // cout << length({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11});
    // cout << length({10, 9, 2, 5, 3, 7, 101, 1});
    // cout << numOFAllLIS({3, 2, 4, 5, 4});
    cout << numOFAllLISOfLengthK({12, 8, 11, 13, 10, 15, 14, 16, 20}, 4);
}