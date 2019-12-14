//https://yukicoder.me/problems/no/921
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














int N, A[101010], dp[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	
	rep(i, 0, N) {
		int ma = 0;
		if (0 < i and A[i - 1] == A[i]) chmax(ma, dp[i]);
		if (0 <= i - 1) chmax(ma, dp[i - 1]);
		if (0 <= i - 2) chmax(ma, dp[i - 2]);
		dp[i + 1] = ma + 1;
	}

	int ans = 0;
	rep(i, 0, N + 1) chmax(ans, dp[i]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
同じ大きさの場合は消えないので全部ずんだ餅にできる。
基本的には、「ず餅ず餅」みたいな感じにすればよさそう。
影響するのは2つ前くらいなので、ちょっと前くらいを見ればいい。
DP[i] := 最後にi番目のずんだ餅を食べたときにずんだ餅にできる最大個数
DP[i] = i番目の餅の個数 + max(DP[i - 2], DP[i - 3])が更新式になる。
A[i]=A[i-1]を満たすならば、DP[i] = i番目の餅の個数 + max(DP[i - 2], DP[i - 3], DP[i - 1])もOK
4個前を最後に使うパターンは2個前を使えば最大になるので、これ以降は考える必要はない。
///////////////////////// writeup2 end */
