//https://atcoder.jp/contests/past202005-open/tasks/past202005_m
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M;
vector<pair<int, int>> E[101010];
int s, K, t[16];
ll dp[1 << 16][16];
//---------------------------------------------------------------------------------------------------
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
int vis[101010];
void dijk(int s, vector<ll>& D) {
    rep(i, 0, N) D[i] = infl;
    rep(i, 0, N) vis[i] = 0;

    min_priority_queue<pair<ll, int>> que;

    D[s] = 0;
    que.push({ 0, s });

    while (!que.empty()) {
        auto q = que.top(); que.pop();

        ll cst = q.first;
        int cu = q.second;

        if (vis[cu]) continue;
        vis[cu] = 1;

        fore(p, E[cu]) {
            ll cst2 = cst + p.second;
            int to = p.first;

            if (chmin(D[to], cst2)) que.push({ D[to], to });
        }
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back({ b, 1 });
        E[b].push_back({ a, 1 });
    }
    cin >> s >> K;
    s--;
    rep(i, 0, K) cin >> t[i], t[i]--;

    vector<ll> fromS(N);
    dijk(s, fromS);

    vector<vector<ll>> fromTs(K, vector<ll>(N));
    rep(k, 0, K) dijk(t[k], fromTs[k]);

    rep(msk, 0, 1 << K) rep(lst, 0, K) dp[msk][lst] = infl;
    rep(k, 0, K) dp[1 << k][k] = fromS[t[k]];
    rep(msk, 0, 1 << K) rep(lst, 0, K) if (dp[msk][lst] < infl) {
        rep(nxt, 0, K) if (!(msk & (1 << nxt))) {
            chmin(dp[msk + (1 << nxt)][nxt], dp[msk][lst] + fromTs[lst][t[nxt]]);
        }
    }

    ll ans = infl;
    rep(lst, 0, K) chmin(ans, dp[(1 << K) - 1][lst]);
    cout << ans << endl;
}



/* ///////////////////////// writeup1 start
# 前提知識
- [ダイクストラ](https://www.hamayanhamayan.com/entry/2017/05/14/134606)
- [bitDP](https://www.hamayanhamayan.com/entry/2017/07/16/130151)
///////////////////////// writeup2 start
制約でK≦16というのがあるので、戦略的にここから取り組む。
bitDPだろうと仮定が立ち、問題から
dp[msk][lst] := 行商人が既にmskの町を訪れていて最後にlstの町にいるときの通行料の合計
を使って計算するのだろうと思う。

この仮定が正しいとすると、嬉しいことがある。
それは、街sと街t1,t2,...,tK以外の街はdpする上では無視して構わないことになる。
この街の間での最小通行料が分かっていれば、DPは解くことができる。

最小通行料、最短距離と言えばダイクストラかワーシャルフロイドであるが、
ワーシャルフロイドは全頂点間を網羅できるが、O(N^3)で間に合わない。
だが、今回は街sと街t1,t2,...,tKからの最短距離が分かればいいので、
それぞれでダイクストラを行うことで、DPで必要な間での最短距離を求めよう。

前提アルゴリズムが分かっていればそこまで難しくはないが、
ダイクストラを複数回行う事になれていないと、思いついてもすぐに取り組めないかもしれない。
///////////////////////// writeup2 end */
