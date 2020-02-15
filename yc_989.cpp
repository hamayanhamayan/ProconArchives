//https://yukicoder.me/problems/no/989
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














int N, M, K; char op;
ll B[101010], A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K >> op;
	rep(i, 0, M) cin >> B[i];
	rep(i, 0, N) cin >> A[i];

	sort(A, A + N);
	sort(B, B + M);

	ll ans = 0;
	rep(i, 0, N) {
		int ng = -1, ok = M;
		while (ng + 1 != ok) {
			int md = (ng + ok) / 2;

			ll res = A[i] + B[md];
			if (op == '*') res = A[i] * B[md];

			if (K <= res) ok = md;
			else ng = md;
		}
		ans += M - ok;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
///////////////////////// writeup2 start
どこから手を付けようかという感じだが、何かを全探索して解きたいところ。
A[i]について全探索したときに、条件を満たすB[i]の個数が高速に計算できれば、
その個数の総和をとって答えとできる。
これは割と良い方針に見える。

A[i]×B[j]を考えたときに条件を満たすB[j]はある数以上になることが分かる。
つまり、単調性を持つ。
配列Bはソートしても問題ないので、二分探索をして、条件を満たす・満たさないの境界線を見つけよう。
この単調性は、opが和でも積でも同様なので、同じロジックが使える。
///////////////////////// writeup2 end */
