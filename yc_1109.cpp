//https://yukicoder.me/problems/no/1109
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














int N, T[12];
vector<int> ds = { 0, 2, 4, 5, 7, 9, 11 };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> T[i];

	vector<int> ans;
	rep(D, 0, 12) {
		set<int> rest;
		rep(i, 0, N) rest.insert(T[i]);
		fore(d, ds) rest.erase((D + d) % 12);

		if (rest.empty()) ans.push_back(D);
	}

	if (ans.size() == 1) cout << ans[0] << endl;
	else cout << -1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
全てのDについて全探索しよう。
あるDの音階が含まれるかどうかを判定する。

setを使うのがオススメ。
setに配列Tを全部入れて、
Dの音階に含まれる音を消せるだけ消したときに、
setが空になれば、その音階だけで構成されてるので、答えとしてカウントする。

答えがただ1つならそれを答えて、そうでないなら-1を答える。
///////////////////////// writeup2 end */
