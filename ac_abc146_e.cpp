//https://atcoder.jp/contests/abc146/tasks/abc146_e
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














int N, K, A[201010];
int sm[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 1, N + 1) cin >> A[i];

	if (K == 1) {
		cout << 0 << endl;
		return;
	}

	map<int, int> cnt;
	cnt[0] = 1;
	sm[0] = 0;

	rep(i, 1, N + 1) sm[i] = (sm[i - 1] + A[i]) % K;

	ll ans = 0;
	rep(R, 1, N + 1) {
		int x = (((sm[R] - R) % K) + K) % K;
		ans += cnt[x];
		cnt[x]++;
		if (0 <= R - K + 1) {
			int y = (((sm[R - K + 1] - (R - K + 1)) % K) + K) % K;
			cnt[y]--;

		}
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まずは常套手段として、右端を全探索して条件を満たす左端を探すことにしよう。
連続する和について考えるので、累積和を考えれば良さそう。
和をKで割った余りについて考えるので、累積和を考える場合でもmodKでカウントしておけばいい。
累積和基準で考えると、区間の和はsm[R]-sm[L]と考えることができる。
modKで考えると、sm[R]-sm[L]=要素の数となればいい。
要素の数もR,Lで表記できるので、sm[R]-sm[L]=R-Lである。
ここで、右端が固定されているので、sm[R]-R=sm[L]-Lを満たすRが抽出できればいい。
なので、「cnt[x] := sm[L]-L=xとなる個数」を作りながら数え上げることが可能。

注意点として、要素の数がK以上となった場合は、条件を常に満たさないので、
要素の数がK以上となるものから順番にcntから消していく必要がある。
K=1がコーナーケース。
///////////////////////// writeup2 end */
