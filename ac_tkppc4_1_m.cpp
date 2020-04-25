//https://atcoder.jp/contests/tkppc4-1/tasks/tkppc4_1_m
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
//---------------------------------------------------------------------------------------------------
#define rabbit "Rabbit"
#define human "Human"
string ask(vector<int> v) {
	int K = v.size();
	printf("? %d", K);
	fore(x, v) printf(" %d", x + 1);
	printf("\n");
	fflush(stdout);

	string s; cin >> s;
	return s;
}
// [l,r]
string askRange(int l, int r) {
	vector<int> v;
	rep(i, l, r + 1) v.push_back(i);
	return ask(v);
}
void answer(int x, int y) {
	printf("! %d %d\n", x + 1, y + 1);
	fflush(stdout);
}
//---------------------------------------------------------------------------------------------------
void naive(int l, int r) {
	int x, y;

	{
		int ok = l, ng = r + 1;
		while (ok + 1 != ng) {
			int md = (ok + ng) / 2;
			if (askRange(md, r) == rabbit) ok = md;
			else ng = md;
		}
		x = ok;
	}

	{
		int ng = x, ok = r;
		while (ng + 1 != ok) {
			int md = (ng + ok) / 2;
			if (askRange(x, md) == rabbit) ok = md;
			else ng = md;
		}
		y = ok;
	}

	answer(x, y);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;

	if (N <= 4090) {
		naive(0, N - 1);
		return;
	}

	if (askRange(0, 3999) == rabbit) {
		naive(0, 3999);
		return;
	}

	if (askRange(4000, N - 1) == rabbit) {
		naive(4000, N - 1);
		return;
	}
	
	int x, y;
	{
		int ok = 0, ng = 4000;
		while (ok + 1 != ng) {
			int md = (ok + ng) / 2;
			if (askRange(md, N - 1) == rabbit) ok = md;
			else ng = md;
		}
		x = ok;
	}
	{
		int ng = 3999, ok = N - 1;
		while (ng + 1 != ok) {
			int md = (ng + ok) / 2;
			if (askRange(0, md) == rabbit) ok = md;
			else ng = md;
		}
		y = ok;
	}
	answer(x, y);
}








/* ///////////////////////// writeup1 start
# 前提知識
///////////////////////// writeup2 start
今までWA解法を垂れ流していました。
ご指摘いただき、修正しました。ありがとうございます。

インタラクティブ問題への取り組み方はそんなに多くない。
なので、順番に可能性を考えていくと解ける場合が多い。
二分探索で解いていこう。
うさぎになる左右最小の区間が分かれば、その両端が答えになる。
これは、左右どちらも二分探索していけば、答えられる。
…と思うがこれは最大13回＋13回で26回必要になる。
これは回数オーバー。
だが、これは後で使えるので、naive関数として別にしておく。
naive(l,r)は、[l,r]の範囲に効果のあるドロップが2つともあるときに解く関数としている。

重要な考察として、N=6000であるが、「N≦2^11+2^12」であるということ。
つまり、適切に2つに分けることで、二分探索の回数を11回+12回にすることができる。
これがすごい大事。
Nが4090以下であれば、普通に解けるので、naive関数で解いておこう。
4090としているのは、別に4000とかでもいいのだが、2グループに分けてた時、片方があまりに個数が少ないとバグりそうだから。

まずは区間を[0,3999]と[4000,N-1]に分ける。
そして、最初に[0,3999]に対してクエリを行う。
ここでRabbitであれば、この区間にドロップが2つあるので、この区間に対してnaive関数を使う。
こうすると、最初の1回と、naive関数で12回×2が行われるので25回でOK。

[0,3999]がRabbitじゃない場合は、[4000,N-1]でクエリを行う。
これでRabbitであれば、この区間に対してnaive関数を使う。
これで最初の2回と、naive関数で11回×2が行われるので、24回でOK。

どちらもRabbitではない場合は、どちらの区間にもそれぞれ1つずつ食べるべきドロップがあるということ。
なので、どちらの区間に対しても片方の区間を完全に含んだ状態で二分探索して、ドロップの場所を特定する。
最初に2回、[0,3999]で12回、[4000,N-1]で11回となって、25回でOK。
///////////////////////// writeup2 end */
