//https://yukicoder.me/problems/no/868
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
int getrandmax() {
    static uint32_t y = time(NULL);
    y ^= (y << 13); y ^= (y >> 17);
    y ^= (y << 5);
    return abs((int)y);
}
int getrand(int l, int r) { // [l, r]
    return getrandmax() % (r - l + 1) + l;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, K, A[15101]; int Q;
const int MODS_COUNT = 1;
int dp[MODS_COUNT][50101];
const int MA = 15000;
int mods[10] = { 1000000007,1000000009,1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,1000000123,1000000181 };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];
	cin >> Q;

	rep(i, 0, 101) { int a = getrand(0, 9); int b = getrand(0, 9); swap(mods[a], mods[b]); }

	rep(mo, 0, MODS_COUNT) {
		dp[mo][0] = 1;
		rep(i, 0, N) if (0 < A[i]) rrep(k, MA * 2, 0) if (k + A[i] <= MA * 2) {
			dp[mo][k + A[i]] += dp[mo][k];
			dp[mo][k + A[i]] %= mods[mo];
		}
	}

	rep(q, 0, Q) {
		int x, v; cin >> x >> v;
		x--;

		// reverse
		if (0 < A[x]) {
			rep(mo, 0, MODS_COUNT) {
				rep(k, 0, MA * 2 + 1) if (0 <= k - A[x]) {
					dp[mo][k] -= dp[mo][k - A[x]];
					dp[mo][k] += mods[mo];
					dp[mo][k] %= mods[mo];
				}
			}
		}

		// change
		A[x] = v;

		// remake
		rep(mo, 0, MODS_COUNT) {
			dp[mo][0] = 1;
			if (0 < A[x]) rrep(k, MA * 2, 0) if (k + A[x] <= MA * 2) {
				dp[mo][k + A[x]] += dp[mo][k];
				dp[mo][k + A[x]] %= mods[mo];
			}
		}

		// check
		bool ok = false;
		rep(mo, 0, MODS_COUNT) if (0 < dp[mo][K]) ok = true;
		if (ok) printf("1\n");
		else printf("0\n");
	}
}






/* ///////////////////////// writeup1 start
# 前提知識
- [戻すDP](https://www.hamayanhamayan.com/entry/2017/03/19/154334)
///////////////////////// writeup2 start
戻すDPを知っている人は、適用するだけである。
まずは、普通にDPを作ろう。
dp[i][k] := 配列Aのi番目まで使って、総和がkである組み合わせ
戻すDPをするためにはtrue/falseでは行えないので、組み合わせにして解く。
漸化式を書くとdp[i+1][k] = dp[i][k] + dp[i][k-A[i]]である。
これで作るが、配列を後ろから埋めると節約できるタイプなので、
dp[k] := 総和がkである組み合わせ
を後ろから更新する。dp[k] += 前dp[k-A[i]]を後ろからすれば問題ない。

これをベースにしてDPを「戻す」
漸化式を変形すると、dp[i][k]=dp[i+1][k] - dp[i][k-A[i]]である。
これは先頭から更新していけば、dp[k]-=dp[k-A[i]]として戻すことができる。

戻したら、A[x]をvに更新して、遷移しなおす。
これでDPが再構築できるので、組み合わせ数が0より大きければ作成可能。
mod1つだと落ちる可能性があるので、modを複数個持つとHackには弱いが、フルフィードバックだと行けそう。
と思ったら、もうチャレンジケースが追加されてた。
こういう時は、素数を複数持って乱数で選択する。
計算量も若干余裕があったので、10種から2種選ぶようにした。
と思ったらTLEしたので、1種類でいった。
///////////////////////// writeup2 end */