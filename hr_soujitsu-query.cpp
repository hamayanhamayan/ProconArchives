//https://www.hackerrank.com/contests/wasedajitsugyo-scienceclub-festival-contest2019/challenges/soujitsu-query
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
//        Welcome to My Coding Space! @hamayanhamayan
//---------------------------------------------------------------------------------------------------

int Q;
int X[1010101], Y[1010101];
map<int, int> cnt;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> Q;

    set<int> used;
    rep(q, 0, Q) {
        int t;
        cin >> t;

        if (t == 1) {
            int a;
            cin >> a;
            used.insert(a);
            cnt[a]++;
        } else {
            if (used.size() < 2) continue;

            auto ite = used.rbegin();
            ite++;
            int a = *ite;

            ll ans = 1LL * a * cnt[a];
            printf("%lld\n", ans);
        }
    }
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
集合に含まれる数を保持したsetも持ちながら2番目の数を特定しよう。
要素の個数はmapで持っておけばいい。
10^9を超える可能性があるので、long longで答えること。
///////////////////////// writeup2 end */
