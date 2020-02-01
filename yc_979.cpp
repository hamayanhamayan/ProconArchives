//https://yukicoder.me/problems/no/979
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
vector<int> enumdiv(int n) { 
    vector<int> S;
    for (int i = 1; 1LL*i*i <= n; i++) if (n%i == 0) { S.push_back(i); if (i*i != n) S.push_back(n / i); }
    sort(S.begin(), S.end());
    return S;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[301010];
int ma[301010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N) {
		auto ed = enumdiv(A[i]);
		fore(d, ed) if (d != A[i]) chmax(ma[A[i]], ma[d] + 1);
		chmax(ma[A[i]], 1);
	}

	int ans = 0;
	rep(i, 0, 301010) chmax(ans, ma[i]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [LIS](https://www.hamayanhamayan.com/?page=1493538812)
///////////////////////// writeup2 start
LISに問題設定が似ているので、LISに寄せた感じで考えてみる。

DPっぽくやっていく。
dp[i][x] := i番目まで考え終わっていて、末尾の値がxである最長列の長さ
dp[i+1][x]の更新を考えると、考えるべきはdp[i][y]（yはxの約数、かつxより小さい）である。
yは約数であるので、約数列挙してもO(sqrt(x))しかかからない。
これは間に合いそうな気がする。

あとは、DPテーブルがとても大きくなってしまうので、DPテーブルの節約をする必要がある。
dp[i][?]からdp[i+1][?]を更新することを考えると、ほとんどの場所はdp[i+1][x] = dp[i][x]となる。
なので、同じテーブルを使ってしまえばいい。
更新されるのは、A[i]の約数だけなので、そこだけ更新することでiの要素を減らそう。
これを行うことで全体のコピーも必要なくなり、間に合う。

下手にdpでやると考えず、
ma[x] := 末尾の値がxである最長列の長さ
を管理しながら、先頭からなめていくと考えた方がシンプルで簡単に考えられるかもしれない。
（俺も実際こっちで考えてる）
///////////////////////// writeup2 end */
