//https://www.hackerrank.com/contests/eeic-programming-contest-0/challenges/count-zero-1-1
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
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












ll P, N;
//---------------------------------------------------------------------------------------------------
// dp[dgt][isless][morethan0][cnt0][modP]
ll dp[2][2][2][12][10000];
void digitDP() {
	dp[0][0][0][0][0] = 1;
	string S = to_string(N);
	int len = S.length();
	rep(d, 0, len) {
		int dgt = d % 2;
		int dgt2 = 1 - dgt;
		int c = S[d] - '0';

		rep(isless, 0, 2) rep(morethan0, 0, 2) rep(cnt0, 0, 11) rep(modP, 0, P) dp[dgt2][isless][morethan0][cnt0][modP] = 0;

		rep(isless, 0, 2) rep(morethan0, 0, 2) rep(cnt0, 0, 11) rep(modP, 0, P) {
			rep(nxt, 0, 10) {
				if (isless == 0 and c < nxt) break;
				int isless2 = isless;
				if (nxt < c) isless2 = 1;

				int morethan02 = morethan0;
				if (0 < nxt) morethan02 = 1;

				int cnt02 = cnt0;
				if (nxt == 0 and morethan0 == 1) cnt02++;

				int modP2 = (modP * 10 + nxt) % P;

				dp[dgt2][isless2][morethan02][cnt02][modP2] += dp[dgt][isless][morethan0][cnt0][modP];
			}
		}
	}

	ll ans = 0;
	rep(isless, 0, 2) rep(cnt0, 1, 11) ans += dp[len % 2][isless][1][cnt0][0] * cnt0;
	cout << ans << endl;
}
//---------------------------------------------------------------------------------------------------
void naive() {
	ll ans = 0;
	rep(d, 1, N) {
		if (N < d * P) break;
		ll x = d * P;
		while (0 < x) {
			if (x % 10 == 0) ans++;
			x /= 10;
		}
	}
	cout << ans << endl;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> P;
	
	if (P < 10000) digitDP();
	else naive();
}





/* ///////////////////////// writeup1 start
# 前提知識
- [桁DP](https://www.hamayanhamayan.com/entry/2017/04/23/212728)
///////////////////////// writeup2 start
難しいぞ。
どこから手を付ければいいだろうか。

とりあえず、極端な例で解けるか考えてみる。
P=1, N=10^10ではどうやって解こうか。
使えそうな性質として、関数fは最高10にしかならない。
でも、0を上手く抜き出す方法が思いつかない。
総和を求めよとあるが、0×0となる個数+1×1となる個数+...とやれば上手くやれる。
桁DPか？それで行けそうだ。
dp[dgt][isless][morethan0][cnt0][modP] := dgt桁まで確定していて、基準より小さいかがislessで、0よりも既に大きいかがmorethan0で、0がcnt0個あって、Pで割った余りがmodPである組み合わせ
これが分かれば、解けそう。
P=1, N=10^10ならこれでも解ける。
良さそうな方針に見える。

もとの問題に戻ってみると、Pがあまりに大きいとDPテーブルが大きくなりすぎる問題が出てきた。
だが、よくよく考えると、Pが大きい場合はPの倍数を全列挙してもそんなに数が出てこない。
なので、Pが基準より小さいなら桁DPで、大きいなら全列挙で解けそう。
全探索ができそうな基準でいうと10^6くらいなら余裕なので、基準は10^4が良いだろう。
それより小さいなら桁DPしよう。
///////////////////////// writeup2 end */
