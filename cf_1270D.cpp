//https://codeforces.com/contest/1270/problem/D
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
//---------------------------------------------------------------------------------------------------
bool debug = false;
vector<int> dv = { -1, 9, 0, 1, 2 };
int M = 3;
pair<int,int> ask(vector<int> v) {
	printf("?");
	fore(x, v) printf(" %d", x);
	printf("\n");
	fflush(stdout);

	if (debug) {
		vector<pair<int,int>> v2;
		fore(i, v) v2.push_back({ dv[i], i });
		sort(all(v2));
		return { v2[M - 1].second, v2[M - 1].first };
	}

	int pos, apos; cin >> pos >> apos;
	return { pos, apos };
}
void answer(int m) {
	printf("! %d\n", m);
	fflush(stdout);
}
// [st,st+K+1) without [without]
pair<int, int> ask_without(int st, int without) {
	vector<int> v;
	rep(i, st, st + K + 1) if(i != without) v.push_back(i);
	return ask(v);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;

	vector<pair<int, int>> results;
	results.push_back({ -1,-1 });
	rep(i, 1, K + 2) results.push_back(ask_without(1, i));

	int A = results[K+1].second;
	int Apos = results[K+1].first;

	int B = results[Apos].second;
	int Bpos = results[Apos].first;

	if (A < B) {
		int less = 0;
		rep(i, 1, K + 1) if (i != Apos) {
			if (results[i].second != A) less++;
		}
		answer(less + 1);
	}
	else {
		int less = 0;
		rep(i, 1, K + 1) if (i != Apos) {
			if (results[i].second == A) less++;
		}
		answer(less + 1);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
リアクティブといえば二分探索であるが、二分探索が適用できそうな感じは無い。
制約も二分探索を示唆していないので、なにか別の方針で行くしか無い。
なにも思いつかない。
どうしよう。

こういうときは、最悪なパターンを考えるのがいい。
与えられたサンプルが最悪なパターンになっている、K=N-1の時が一番厄介。
これは、例えばK=2であるならば、わかっていない所にクエリを行っていくことで、
N-1個の要素を特定することができる。
K=N-1の時は、2個しか特定することができないので、一番制約が強いように見える。
あと一つ重要なのが「これが分かれば全部に適用できる」という所である。
K=N-1でなくても、NをK+1としてクエリを実行することでMを特定することができる。

さて、K=N-1である時は、クエリを実行するパターンがそもそもN通りしかない。
クエリはN回が上限なので、実行できるパターンは全て実行できる。
要素i以外を聞いた結果をresults[i]として保存しておこう。

K+1以外を与えたクエリで答えとして{Apos, A}が帰ってきたとする。
次に、Apos以外を与えたクエリで答えとして{Bpos, B}が帰ってきたとする。
1つだけ入れ替えているので、AとBは全体を昇順に並べたときに隣り合っている。
A<BかA>Bの可能性があるので、場合分けして考える。

A<Bの時に、K+1とApos以外の場所について、それ以外を与えたクエリの結果を見る。
それ以外の所にあった数を抜いて、K+1の所にあった数を入れているので、
結果がもしAで無いならば、それ以外の所にあった数はA未満ということになる。
この個数を数えてless個ならば、Aはless+1番目ということになる。
このようにAよりも小さい数の個数を数えることで、Mの値を特定していく。

A>Bの時もほぼ同様であるが、抜いた数がA未満であるかは、抜いたクエリの結果が
AであるときにA未満である。
///////////////////////// writeup2 end */
