//https://atcoder.jp/contests/past202004-open/tasks/past202004_j
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














string S;
int idx = 0;
//---------------------------------------------------------------------------------------------------
string parse() {
	if (S[idx] == '(') {
		idx++;
		string res = parse();
		idx++;

		string ser = res;
		reverse(all(ser));
		return res + ser + parse();
	}
	else if ('a' <= S[idx] && S[idx] <= 'z') {
		string res = S.substr(idx, 1);
		idx++;
		res += parse();
		return res;
	}
	return "";
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	S += "#";
	cout << parse() << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [構文解析](https://www.hamayanhamayan.com/entry/2018/07/13/085956)
///////////////////////// writeup2 start
この問題は適切に構文解析を行えるかを問う問題。
構文解析の一番単純な手法として再帰で行う方法がある。
説明がとても難しいのだが、先頭から順番に見ていって、(が出てきたら、
再帰を1回行って、(???)の???の部分の文字列を取得する。
取得した文字列がresだとしたら、それを反転させた文字列serを作って、(???)の評価結果としてres+serを返す。
普通の文字ならその文字+それ以降の文字で再帰を続けていく。
これを続けていくといい。
あと、注意すべき点として、先頭から見ていったときにindexが行き過ぎてしまうことがあるので、
番兵として末尾に#を自分はつけている。
（=の方が見た目クールだけど）
///////////////////////// writeup2 end */
