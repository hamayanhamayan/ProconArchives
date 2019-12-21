//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_e
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
bool match(char c, string s)
{
	rep(i, 0, s.length()) if (s[i] == c) return true;
	return false;
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













int N; string E; char A;
enum { R, S, P };
string op[2] = { "+-", "*" };
int idx = 0;
int mod = 1000000007;
int buf[1001010][3];
//---------------------------------------------------------------------------------------------------
int r, s, p;
inline void add(int x, int y) {
	r = (1LL * buf[x][R] * buf[y][R] + 1LL * buf[x][R] * buf[y][S] + 1LL * buf[x][S] * buf[y][R]) % mod;
	s = (1LL * buf[x][S] * buf[y][S] + 1LL * buf[x][S] * buf[y][P] + 1LL * buf[x][P] * buf[y][S]) % mod;
	p = (1LL * buf[x][P] * buf[y][P] + 1LL * buf[x][P] * buf[y][R] + 1LL * buf[x][R] * buf[y][P]) % mod;

	buf[x][R] = r;
	buf[x][S] = s;
	buf[x][P] = p;
}
inline void sub(int x, int y) {
	r = (1LL * buf[x][R] * buf[y][R] + 1LL * buf[x][R] * buf[y][P] + 1LL * buf[x][P] * buf[y][R]) % mod;
	s = (1LL * buf[x][S] * buf[y][S] + 1LL * buf[x][S] * buf[y][R] + 1LL * buf[x][R] * buf[y][S]) % mod;
	p = (1LL * buf[x][P] * buf[y][P] + 1LL * buf[x][P] * buf[y][S] + 1LL * buf[x][S] * buf[y][P]) % mod;

	buf[x][R] = r;
	buf[x][S] = s;
	buf[x][P] = p;
}
inline void mul(int x, int y) {
	r = (1LL * buf[x][R] * buf[y][R] + 1LL * buf[x][P] * buf[y][S] + 1LL * buf[x][S] * buf[y][P]) % mod;
	s = (1LL * buf[x][S] * buf[y][S] + 1LL * buf[x][R] * buf[y][P] + 1LL * buf[x][P] * buf[y][R]) % mod;
	p = (1LL * buf[x][P] * buf[y][P] + 1LL * buf[x][S] * buf[y][R] + 1LL * buf[x][R] * buf[y][S]) % mod;

	buf[x][R] = r;
	buf[x][S] = s;
	buf[x][P] = p;
}
//---------------------------------------------------------------------------------------------------
int parse(string& s, int& i, int x)
{
	if (x == 2)
	{
		if (s[i] == '(')
		{
			i++;
			auto ans = parse(s, i, 0);
			i++;
			return ans;
		}
		else if (s[i] == '?') {
			i++;
			buf[idx][R] = buf[idx][S] = buf[idx][P] = 1;
			idx++;
			return idx - 1;
		}
		else if (s[i] == 'R') {
			i++;
			buf[idx][R] = 1;
			idx++;
			return idx - 1;
		}
		else if (s[i] == 'S') {
			i++;
			buf[idx][S] = 1;
			idx++;
			return idx - 1;
		}
		else {
			i++;
			buf[idx][P] = 1;
			idx++;
			return idx - 1;
		}
	}
	else
	{
		auto ans = parse(s, i, x + 1);

		while (op[x].find(s[i]) != string::npos)
		{
			switch (s[i])
			{
			case '+': i++; add(ans, parse(s, i, x + 1)); break;
			case '-': i++; sub(ans, parse(s, i, x + 1)); break;
			case '*': i++; mul(ans, parse(s, i, x + 1)); break;
			}
		}

		return ans;
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> E >> A;
	E += "=";
	int i = 0;
	auto ans = parse(E, i, 0);

	if (A == 'R') cout << buf[ans][R] << endl;
	else if (A == 'S') cout << buf[ans][S] << endl;
	else cout << buf[ans][P] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ICPCを感じる。
構文解析が要求される問題。

【20点】
知識ゼロでここまで通すのが相当難しい。
逆にここを超えられれば、考える余地が出てくる。
まずは、構文解析器を作ろう。
今後のためにも再帰関数で作るやつで作れるようになっておこう。
できれば、今回求められるように優先度に対応したものが作れるといい。
これが、作れれば後は?に入れるパターンを全探索して、結果を見ればいい。
もし、本番知識ゼロで本番ここまで来れたら、かなり凄いと思う。

【満点解法】
40点解法が思いつかなかったので、満点解法。
20点解法で作った構文解析器では、RSPのいずれかを結果として返すと思うが、
その代わりに(Rとなる組み合わせ、Sとなる組み合わせ、Pとなる組み合わせ)を結果として返すことにする。
組み合わせを上手くマージしていきながら、最終的な結果を求めていく。
DPっぽい（木DPっぽい）考え方を適用させた感じになる。
この辺は構文解析器が完全に作れるようになってからでも良いかもしれない。

と思って組んだら、TLEで40点になりました。
↓
慣れ親しんだmodintを捨ててintで実装し直した。
↓
でもまだ駄目。
vectorのコピーコストかな？と思い、add,sub,mulを参照渡しにして頑張る。
↓
だめ。vector使ってるのが悪い？
クラスにすればいい？
↓
はいだめー。わかりました。ちゃんとバッファ作って動的確保とかしないようにしますー
これ通せる中高生おる？？？？と書きかけたけど、すぐ反例が思いついてしまう。
↓
あっ…もしかして、私の構文解析器遅すぎ…？
ん？いや、全く関係ないここか…？
完

余談。
JOIに本気に取り組んでいる人は中高生だと思うが、構文解析は大学のプロコンICPCでの必修科目である。
今回のようにBNFで文法が与えられて解いていく問題はICPCに向けて勉強していくのもいいだろう。
（自分もライブラリ無しではかけないんですけどね）
///////////////////////// writeup2 end */
