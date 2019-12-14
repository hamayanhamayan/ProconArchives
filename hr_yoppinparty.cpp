//https://www.hackerrank.com/contests/wasedajitsugyo-scienceclub-festival-contest2019/challenges/yoppinparty
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

int N, M, A[101010], B[101010];
vector<int> E[101010];
//---------------------------------------------------------------------------------------------------
ll ans = -1;
void dfs(int cu, ll b_tot = 0) {
    chmax(ans, b_tot + A[cu]);
    fore(to, E[cu]) dfs(to, b_tot + B[cu]);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i] >> B[i];
    rep(i, 0, M) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        E[p].push_back(q);
    }

    dfs(0);
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ある兵士iに褒美を与えると、
A[i]+上司のB[i]+そのまた上司のB[i]+...+B[1]が得られる。
部下→上司のように辺を作ると、ある兵士から伸びる辺は1つになる。
みーちゃんからは伸びない（みーちゃんから伸びると、上司をたどってもみーちゃんにたどり着かない）
問題設定の雰囲気から、サイクルとかも無いだろうと推測。
（現実では上司関係＋先輩関係でサイクルになってる場合あるけど）

よってこれは、有向木ということになる。
全ての頂点は、上司関係遷移で全て1に集まる。
兵士を全探索して、A[i]+(兵士iの上司からみーちゃんまでのB[i]の総和)の最小値を求めよう。
(兵士iの上司からみーちゃんまでのB[i]の総和)は、dfsで探索するときに、作りながら渡していく。
dfsするときは、辺の遷移方向を反対に探索していく。
つまり、みーちゃんから始めていこう。
///////////////////////// writeup2 end */
