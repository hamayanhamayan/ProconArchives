//https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_f
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/




int N, M;
int w, x, y, z;
//---------------------------------------------------------------------------------------------------
vector<pair<int, ll>> E[2][101010];
vector<ll> solve(int n, int s, bool isRev) {
    vector<ll> res(n + 1, infl);
    res[s] = 0;
    vector<int> ord;
    rep(i, 0, n + 1) ord.push_back(i);
    if(isRev) reverse(all(ord));
    
    fore(cu, ord) {
        fore(p, E[isRev][cu]) {
            chmin(res[p.first], res[cu] + p.second);
        }
    }

    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    cin >> w >> x >> y >> z;

    rep(i, 0, M) {
        int c, s, t; cin >> c >> s >> t;
        E[0][s].push_back({t, c});
        E[1][t].push_back({s, c});
    }

    auto cost_w = solve(N, w, false);
    auto cost_x = solve(N, x, true);
    auto cost_y = solve(N, y, false);
    auto cost_z = solve(N, z, true);

    int st = 0;
    int gl = N + 1;

    rep(i, 1, N + 1) {
        ll c = cost_w[i] + cost_y[i];
        if(c < infl) E[0][st].push_back({i, c});
        

        c = cost_x[i] + cost_z[i];
        if(c < infl) E[0][i].push_back({gl, c});
    }

    auto cost = solve(N + 1, st, false);

    ll ans = infl;
    chmin(ans, cost_w[x] + cost_y[z]);
    chmin(ans, cost[gl]);

    if(ans == infl)
        cout << "Impossible" << endl;
    else 
        cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
有向グラフで最小コストなので、とりあえずダイクストラか。
グラフはDAGなので、ダイクストラというよりDPできそう。
いつものトポロジカルソートしてDPか？
いや、小さい順からDPすればトポソは不要か。

2つのパスを考えた時に、独立しているか、一部共有するかになる。

[f:id:hamayanhamayan:20190901092114p:plane]

一部共有する場合に一旦合流してパスが分かれて、合流するということはない。
これは、パスが分かれるときに最適な方を使えばいいためである。
独立する場合は、最短経路を求めて和を取ればいい。

パスを一部共有する場合は、状態を持つのが大変であるため、二股になっている所を解決しよう。
全ての頂点pについて、頂点w,yからのパスで合流するための最小コストはcost(w,p)+cost(y,p)である。
これはw,yを始点としたDPをすれば高速に計算できる。
同様に全ての頂点qについて、頂点x,zへ向かうパスで合流するための最小コストはcost(q,x)+cost(q,z)である。
これはx,zを終点としたDPをする。
単一終点のDPは有向辺の向きを反対にしてDPすればいい。
次にメタ頂点wyとxzを用意して、全ての頂点pについて、頂点wy→頂点pにcost(w,p)+cost(y,p)の辺を貼る。
同様に全ての頂点qについて、頂点q→頂点xzにcost(q,x)+cost(q,z)の辺を貼る。
これで頂点wyを始点、頂点xzを終点とした一本のパスだけを考えれば良くなったため、これで改めてDPすると答えが出てくる。

[f:id:hamayanhamayan:20190901092823p:plane]
///////////////////////// writeup2 end */
