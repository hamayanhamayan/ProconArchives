//https://atcoder.jp/contests/abc173/tasks/abc173_b
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














int N;
string S[101010];
vector<string> v = { "AC", "WA", "TLE", "RE" };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> S[i];

	map<string, int> C;
	rep(i, 0, N) C[S[i]]++;

	fore(x, v) printf("%s x %d\n", x.c_str(), C[x]);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実装問題。
問題に書かれている文字列を間違えて記載してしまうのは一番悲しいので、
必ずコピペで持ってこよう。
あとは、4種類についてはmapでカウントして、それぞれ答える。
mapはstringをkeyにできるので便利。覚えておこう。
///////////////////////// writeup2 end */
