/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
* Example: $ g++ -std=c++11 c++ source.cpp
*
* Author: Bohdan Shtepan
* GitHub: https://github.com/virtyaluk
* Site: https://modern-dev.com
*
*/

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define lli long long int
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<float> vf;
typedef vector<double> vd;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, W;
    cin >> n >> W;

    vi w(n), v(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    vvi dp(n + 1, vi(W + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j - w[i - 1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }

    set<int> best;

    for (int i = n, j = W; i > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            best.insert(i);
            j -= w[i - 1];
        }
    }

    cout << best.size() << endl;
    copy(best.begin(), best.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
