//https://yukicoder.me/problems/no/1029
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














int N, K;
string S[80]; int C[80];
ll dp[4][101010];
//---------------------------------------------------------------------------------------------------
string JOI = "JOI";
int joicnt[80][3];
pair<int, int> memo[3][81][80];
pair<int, int> get(int joi, int cnt, int i) {
	if (joicnt[i][joi] < K - cnt) return { joi, cnt + joicnt[i][joi] };
	if (0 <= memo[joi][K - cnt][i].first) return memo[joi][K - cnt][i];

	pair<int, int>& m = memo[joi][K - cnt][i];

	fore(c, S[i]) {
		if (JOI[joi] == c) {
			cnt++;
			if (cnt == K) {
				joi++;
				cnt = 0;
				if (joi == 3) return m = { 3, 0 };
			}
		}
	}

	return m = { joi, cnt };
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> S[i] >> C[i];

	rep(i, 0, N) fore(c, S[i]) rep(j, 0, 3) if (c == JOI[j]) joicnt[i][j]++;

	rep(joi, 0, 4) rep(cnt, 0, K + 1) dp[joi][cnt] = infl;
	dp[0][0] = 0;
	rep(joi, 0, 3) rep(rest, 0, 81) rep(i, 0, N) memo[joi][rest][i].first = -1;

	rep(joi, 0, 3) rep(cnt, 0, K) if(dp[joi][cnt] < infl) rep(i, 0, N) {
		int joi2, cnt2;
		tie(joi2, cnt2) = get(joi, cnt, i);
		chmin(dp[joi2][cnt2], dp[joi][cnt] + C[i]);
	}

	if (dp[3][0] == infl) cout << -1 << endl;
	else cout << dp[3][0] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
ある文字列があったときに、その文字列がレベルKのJOI文字列を部分列に持つかどうかを確かめるには、
先頭から貪欲にJOIを取っていくのがいい。
この貪欲操作をDPに組み込んでとく。

dp[joi][cnt] := 貪欲にJOI文字列を取っていった場合に、最後がJOIのjoi番目がcnt個続いている状態のコスト最小値
ここからの遷移は最後にN個ある文字列のうち、どれを結合するかのN通りである。
この時の、Jが+1でOが+2でもいいし、Jが+2でOが+1でもいいみたいなことにはならない。
貪欲に先頭からJを取っていき、必要ないならOを取っていき、Iを取ればいい。
よって、単純に考えると、状態がO(K)で遷移がO(Nなので、O(NK)で間に合う。

さて、問題が遷移をどのようにして書くかという部分である。
これはget関数というのを用意して、頑張った。
JOIのjoi番目が最後にcnt個分あるときに、i番目の文字列をくっつけると、結果どこに遷移するかを返すものである。
K-cntが81以上の場合は、文字が変わることはないので、その文字列に含まれる文字数分引けばいい。
そうでないなら、シミュレーションしていけばいい。
この辺はメモ化をしておけば、全体計算量はO(NK+80N^2)で行ける。
///////////////////////// writeup2 end */
