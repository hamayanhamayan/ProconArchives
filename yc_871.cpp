//https://yukicoder.me/problems/no/871
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














int N, K; ll X[101010], A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K; K--;
    rep(i, 0, N) cin >> X[i];
    rep(i, 0, N) cin >> A[i];

    int L = K, R = K;
    queue<int> que;
    que.push(K);

    int ans = 0;
    while(!que.empty()) {
        int cu = que.front(); que.pop();
        ans++;

        int l = lower_bound(X, X + N, X[cu] - A[cu]) - X;
        int r = upper_bound(X, X + N, X[cu] + A[cu]) - X - 1;

        while (l < L) {
            L--;
            que.push(L);
        }

        while (R < r) {
            R++;
            que.push(R);
        }
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
- [BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
シミュレーションを考えてみる。
あるカエルが鳴くとそれに共鳴するのは、とある区間のカエルになる。
どこからどこまでのカエルかどうかの端点は二分探索で高速に探すことができる。
まだチェックしていないカエルがいたら、そのカエルについても共鳴するカエルの区間を求める。
これを繰り返していく。
1カエルについて共鳴調査は1回でいいため、N匹のカエルについて二分探索するので、O(NlogN)
BFSのような操作になる。
///////////////////////// writeup2 end */
