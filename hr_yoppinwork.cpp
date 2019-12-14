//https://www.hackerrank.com/contests/wasedajitsugyo-scienceclub-festival-contest2019/challenges/yoppinwork
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

int T, N;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> T >> N;
    vector<pair<int, int>> v;
    rep(i, 0, N) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(all(v));

    int ans = 0, t = 0;
    fore(p, v) {
        if (t <= p.second) {
            ans++;
            t = p.first;
        }
    }
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
# 前提知識
- 区間スケジューリング問題
///////////////////////// writeup2 start
この問題は、区間スケジューリング問題と呼ばれるものである。
区間スケジューリング問題では、終了時刻が早い仕事を貪欲に取ってくれば最適解が得られる。
終了時刻でソートし、とっていこう。
{終了時刻, 開始時刻}とpairでvectorに入れておき、ソートする。
///////////////////////// writeup2 end */
