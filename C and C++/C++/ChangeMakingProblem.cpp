#include <bits/stdc++.h>
using namespace std;
#define INF INFINITY
typedef vector<int> vi;
#define tr(c, i) for(typeof(c.begin())i = c.begin(); i!=c.end(); i++)

const vi coins = {1, 3, 4};
map<int, pair<bool, int>> check;
map<int, pair<bool, int>> checkcount;
map<int, int> first;

int countsol(int x)
{
    if (x<0)
        return 0;
    if (x==0)
        return 1;
    if (checkcount[x].first)
        return checkcount[x].second;
    int count = 0;

    for (auto c : coins)
        if(x-c >= 0)
            count += countsol(x-c);
    checkcount[x].first = true;
    checkcount[x].second = count;
    return count;
}

int solve(int x)
{
    if (x<0)
        return INT_MAX;
    if (x == 0)
        return 0;
    if (check[x].first)
        return check[x].second;

    int best = INT_MAX;
    for (auto c : coins)
    {
        if (x-c >= 0)
        {
            int temp = solve(x - c) + 1;
            best = min(temp, best);
            if (best == temp)//temp was min
                first[x] = c;
        }
    }

    check[x].first = true;
    check[x].second = best;
    return best;
}

main()
{
    int x = 5;
    // check[0].first = 1;
    // check[0].second = 0;
    // checkcount[0].first = 1;
    // checkcount[0].second = 1;
    
    cout << solve(x) << " " << countsol(x) << endl;
    // tr(check, i)
    //     cout << i->first << " : " << i->second.first << endl;
    // tr(first, i)
    // cout << i->first << " : " << i->second << endl;
    while(x>0)
    {
        cout << first.find(x)->second << " + ";
        x -= first.find(x)->second;
    }
    
}