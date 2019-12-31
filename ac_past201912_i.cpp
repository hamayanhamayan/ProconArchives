//https://atcoder.jp/contests/past201912-open/tasks/past201912_i
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
int MSK[1010], C[1010];
ll dp[1 << 10];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, M) {
		string S;
		cin >> S >> C[i];
		fore(c, S) {
			MSK[i] <<= 1;
			if (c == 'Y') MSK[i] |= 0x01;
		}
	}

	rep(msk, 0, 1 << N) dp[msk] = infl;
	dp[0] = 0;
	rep(msk, 0, 1 << N) rep(i, 0, M) chmin(dp[msk | MSK[i]], dp[msk] + C[i]);
	
	ll ans = dp[(1 << N) - 1];
	if (ans == infl) cout << -1 << endl;
	else cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [bitDP](https://www.hamayanhamayan.com/entry/2017/07/16/130151)
///////////////////////// writeup2 start
bitDPを知らないと解くのは難しい。
もしわからない場合は、bitdpでググって概要を理解してきて欲しい。

さて、bitDPを使うと分かっていればそんなに難しく無いだろう。
dp[msk] := 部品を集合msk分持っているときに必要な金額の最小値
あるセットを複数買ってしまう可能性を心配するかもしれないが、同じセットを2回買うと、
必ず無駄になってしまうので、特に考える必要はない。
///////////////////////// writeup2 end */
