#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, qr, qc, count, tmp;
    cin >> n >> k >> qr >> qc;
    tmp = 2 * n + 1 - (qr + qc);
    tmp = tmp > n ? 2 * n - tmp : tmp;
    count = 2 * (n - 1) + tmp + n - 2 - abs(qr - qc);
    vi mindis(8, n);
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (a == qr) //horizontal attacking
        {
            tmp = abs(qc - b);
            if (b < qc && tmp < mindis[0]) //left
            {
                cout << "Left\n";
                count -= mindis[0] = !n ? mindis[0] - tmp : b;
                mindis[0] = qc - b;
            }
            else if (b > qc && tmp < mindis[1]) //right
            {
                cout << "Right\n";
                count -= mindis[1] = !n ? mindis[1] - tmp: n - b + 1;
                mindis[1] = b - qc;
            }
        }
        else if (b == qc) //vertical
        {
            tmp = abs(qr - a);
            if (a < qr && tmp < mindis[2]) //down
            {
                cout << "Down\n";

                count -= mindis[2] = !n ? mindis[2] - tmp: a;
                mindis[2] = qr - a;
            }
            else if (a > qr && tmp < mindis[3]) //up
            {
                cout << "Up\n";

                count -= mindis[3] = !n ? mindis[3] - tmp: n - a + 1;
                mindis[3] = a - qr;
            }
        }
        else
        {
            tmp = abs(qr - a);
            if (qr + qc == a + b) // (\ diagonal)
            {
                if (qr < a && tmp < mindis[4]) //top-left
                {
                    cout << "Top-Left\n";

                    count -= mindis[4] = !n ? mindis[4] - tmp: min(n - a, b - 1) + 1;
                    mindis[4] = tmp;
                }
                else if (qr > a && tmp < mindis[5]) //bottom-right
                {
                    cout << "Bottom-Right\n";

                    count -= mindis[5] = !n ? mindis[5] - tmp: min(a - 1, n - b) + 1;
                    mindis[5] = tmp;
                }
            }
            else if (qr - qc == a - b) // (/ diagonal)
            {
                if (qr < a && tmp < mindis[6]) //top-right
                {
                    cout << "Top-Right\n";
                    count -= mindis[6] = !n ? mindis[6] - tmp: min(n - a, n - b) + 1;
                    mindis[6] = tmp;
                }
                else if (qr > a && tmp < mindis[7]) //bottom-left
                {
                    cout << "Bottom-Left\n";
                    count -= mindis[7] = !n ? mindis[7] - tmp: min(a - 1, b - 1) + 1;
                    mindis[7] = tmp;
                }
            }
        }
    }
    cout << count;
    return 0;
}

/*
100 100
54 30
48 36
38 46
60 24
70 14
54 36
54 24
60 30
48 30
71 50
14 97
47 31
29 68
90 10
36 85
63 24
32 13
64 57
45 57
86 19
43 86
68 72
29 25
48 59
38 78
45 16
40 92
76 85
40 10
65 16
71 18
90 40
65 45
10 37
19 82
42 56
46 60
94 14
34 36
95 49
78 67
86 23
28 12
95 57
38 19
61 49
67 42
28 25
38 28
91 20
90 86
81 19
18 43
29 69
36 20
72 75
39 50
17 92
48 25
20 79
82 57
58 50
94 70
17 19
73 20
45 12
19 89
45 12
59 74
63 71
32 23
67 85
24 25
18 61
97 50
70 37
30 10
39 90
75 58
58 34
47 62
28 28
79 34
73 80
93 36
25 45
48 75
42 13
18 69
35 21
18 87
57 19
26 92
94 34
84 48
61 95
62 89
59 74
50 40
36 37
95 62

62
*/