//https://www.hackerrank.com/contests/wasedajitsugyo-scienceclub-festival-contest2019/challenges/cut-the-sequence-into-three
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
template<typename Func>
int findMin(int L, int R, Func f) { //[L, R)
    int lo = L - 1, hi = R - 1;
    while (lo + 1 != hi) {
        int mi = (lo + hi) / 2;
        if (f(mi) <= f(mi + 1)) hi = mi;
        else lo = mi;
    }
    return hi;
}











int N, A[101010];
//---------------------------------------------------------------------------------------------------
ll sm[101010];
void pre() {
    sm[0] = A[0];
    rep(i, 1, N) sm[i] = sm[i - 1] + A[i];
}
ll get(int L, int R) { // [L, R]
    if (L > R) return 0;
    ll res = sm[R];
    if(0 < L) res -= sm[L - 1];
    return res;
}
//---------------------------------------------------------------------------------------------------
int ss;
ll f(int s, int t) {
    ll ma = -1;
    chmax(ma, get(0, s));
    chmax(ma, get(s + 1, t));
    chmax(ma, get(t + 1, N - 1));

    ll mi = infl;
    chmin(mi, get(0, s));
    chmin(mi, get(s + 1, t));
    chmin(mi, get(t + 1, N - 1));

    return ma - mi;
}
//---------------------------------------------------------------------------------------------------
void _main()
{
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    pre();

    ll ans = infl;
    rep(s, 0, N) {
        ss = s;
        int opt_t = findMin(s, N, [](int t) {
            return f(ss, t);
        });
        chmin(ans, f(s, opt_t));
    }
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難しい問題に見える。
取り組み方がパッと思いつかないので、とりあえず全探索。
stの選ぶ場所を全探索すると、累積和を使ってO(N^2)が達成できる。
sを固定にするとtは下に凸の関数になってたりしないかなー。
Full Feedbackだし、出して通れば嬉しいなーと思うと通る。
///////////////////////// writeup2 end */
