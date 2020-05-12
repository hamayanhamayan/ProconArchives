//https://codeforces.com/contest/1349/problem/A
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
vector<int> makePrimes(int n) { // [2,n]
    vector<int> res, pr(n + 1, 1);
    pr[0] = pr[1] = 0;
    rep(p, 2, sqrt(n) + 2) if (pr[p]) for (int x = p * 2; x <= n; x += p) pr[x] = 0;
    rep(p, 2, n + 1) if (pr[p]) res.push_back(p);
    return res;
}
ll fastpow(ll x, ll n) {
    ll ret = 1;
    while (0 < n) {
        if ((n % 2) == 0) x *= x, n >>= 1;
        else ret *= x, --n;
    }
    return ret;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[101010];
map<int, int> eps[201010];
vector<int> cnt[201010];
//---------------------------------------------------------------------------------------------------
int x[201010];
void pre() {
    auto ep = makePrimes(200000);

    rep(i, 1, 201010) x[i] = i;
    fore(p, ep) {
        for (int i = p; i < 201010; i += p) {
            int cnt = 0;
            while (x[i] % p == 0) {
                x[i] /= p;
                cnt++;
            }
            if (0 < cnt) eps[i][p] = cnt;
        }
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    pre();

    cin >> N;
    rep(i, 0, N) cin >> A[i];

    rep(i, 0, N) fore(p, eps[A[i]]) cnt[p.first].push_back(p.second);

    ll ans = 1;
    rep(i, 1, 201010) if (0 < cnt[i].size()) {
        int M = cnt[i].size();
        if (M <= N - 2) continue;
        sort(all(cnt[i]));

        if (M == N - 1) ans *= fastpow(i, cnt[i][0]);
        else ans *= fastpow(i, cnt[i][1]);
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
