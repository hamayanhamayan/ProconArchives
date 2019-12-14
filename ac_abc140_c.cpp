//https://atcoder.jp/contests/abc140/tasks/abc140_c
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

int N, B[101];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 1, N) cin >> B[i];

    int ans = 0;
    ans += B[1]; // A[1]
    rep(i, 2, N) ans += min(B[i - 1], B[i]); // A[2]～A[N-1]
    ans += B[N-1]; // A[N]
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
なるべくA[i]を大きくするように考えたい。
A[i]中心に考えてみると、A[i]≦min(B[i-1],B[i])を満たす必要がありそう。
最大化したいので等式の場合を考えると、A[i]=min(B[i-1],B[i])である。
これで、A[2]～A[N-1]は定まる。
あとは、A[1]とA[N]だが、それぞれB[1]とB[N-1]に依存していて、その値未満にする必要性もないので、
A[1]=B[1], A[N]=B[N-1]とする。
その時のAの総和が答え。
///////////////////////// writeup2 end */
