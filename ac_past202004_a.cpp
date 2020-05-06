//https://atcoder.jp/contests/past202004-open/tasks/past202004_a
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














string S, T;
//---------------------------------------------------------------------------------------------------
vector<string> floors;
int f(string s) {
	rep(i, 0, 18) if (floors[i] == s) return i;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S >> T;

	rrep(i, 9, 1) floors.push_back("B" + to_string(i));
	rep(i, 1, 10) floors.push_back(to_string(i) + "F");

	int s = f(S);
	int t = f(T);

	int ans = abs(s - t);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
やり方はいろいろありそうだが、自分はフロアを下から順に0,1,2,3,...,17と番号を付けて、
それに変換して、フロアの差をとると答え。

f(s) := フロア名がsのときの番号を返す
フロア名を順番に配列に入れて置き、フロア番号が添え字となるようにしておく。
これで順番に精査していって、当てはまるものがあれば、それをフロア番号として返す。
///////////////////////// writeup2 end */
