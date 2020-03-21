//https://yukicoder.me/problems/no/1013
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














int N, K, P[101010];
ll nxt[31][101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> P[i];

	rep(cu, 0, N) nxt[0][cu] = P[cu];
	rep(p, 1, 31) rep(cu, 0, N) nxt[p][cu] = nxt[p - 1][cu] + nxt[p - 1][(cu + nxt[p - 1][cu]) % N];

	rep(i, 0, N) {
		ll ans = i + 1;
		int cu = i;
		rep(p, 0, 31) {
			int msk = 1 << p;
			if (K & msk) {
				ans += nxt[p][cu];
				cu = (cu + nxt[p][cu]) % N;
			}
		}
		printf("%lld\n", ans);
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- ダブリング
///////////////////////// writeup2 start
ダブリングを知らないと、この発想は難しいかもしれない。
知らない場合は、検索して学んできてほしい。

「K回行動を行ってどの要素に移動しているか」というのはダブリングで解決できる一般的な問題パターンである。
しかし、ちょっと工夫が必要。

nxt[p][cu] := cu番目の要素にいて、2^p回の行動を行うことで何個分移動するか
移動先ではなくて、移動する距離を保持するテーブルを作る。
すると、更新式は`nxt[p][cu] = nxt[p - 1][cu] + nxt[p - 1][ (cu + nxt[p - 1][cu]) % N ]`となる。
このテーブルさえ作ってしまえば、後は、各クエリでK回分これを使って移動距離を計算していけばいい。
///////////////////////// writeup2 end */
