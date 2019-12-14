//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_b
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








int N, M, A[101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i];
	rep(k, 1, M + 1) rep(i, 0, N - 1) if (A[i] % k > A[i + 1] % k) swap(A[i], A[i + 1]);
	rep(i, 0, N) cout << A[i] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
操作は複雑だがN,Mのサイズは小さい。
全ての操作回数を考えるとNM回くらいなので、シミュレーションしても間に合う。
シミュレーションしよう。
交換はswap関数を使うと自然に書ける。
///////////////////////// writeup2 end */
