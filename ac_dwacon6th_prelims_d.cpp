//https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_d
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
template<int SZ> struct Counter {
	int Count[SZ];
	set<int> Kinds;
	Counter() { rep(i, 0, SZ) Count[i] = 0; }

	void Increment(int i) {
		if (Count[i] == 0) Kinds.insert(i);
		Count[i]++;
	}

	void Decrement(int i) {
		Count[i]--;
		if (Count[i] == 0) Kinds.erase(i);
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[101010];
int limit = 8;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) A[i]--;

	int originalN = N;

	vector<int> ans;
	set<int> unused;
	rep(i, 0, N) unused.insert(i);
	
	Counter<101010> counter;
	rep(i, 0, N) counter.Increment(A[i]);

	while (limit < N) {
		if (counter.Kinds.size() == 2) {
			auto ite = counter.Kinds.begin();

			int x = *ite; ite++;
			int y = *ite;

			if (counter.Count[x] == N - 1) {
				if (unused.count(x)) {
					ans.push_back(x);
					N--;
					unused.erase(x);
					counter.Decrement(A[x]);
					continue;
				}
			}

			if (counter.Count[y] == N - 1) {
				if (unused.count(y)) {
					ans.push_back(y);
					N--;
					unused.erase(y);
					counter.Decrement(A[y]);
					continue;
				}
			}
		}

		auto ite = unused.begin();

		if (0 < ans.size() and A[ans.back()] == *ite) ite++;
		ans.push_back(*ite);
		N--;
		counter.Decrement(A[*ite]);
		unused.erase(*ite);
	}

	vector<int> rest;
	rep(i, 0, N) {
		int x = *unused.begin();
		rest.push_back(x);
		unused.erase(x);
	}

	do {
		if (0 < ans.size() and A[ans.back()] == rest[0]) continue;
		bool ok = true;
		rep(i, 0, N - 1) if (A[rest[i]] == rest[i + 1]) ok = false;
		if (ok) {
			rep(i, 0, N) ans.push_back(rest[i]);
			break;
		}
	} while (next_permutation(all(rest)));

	if (ans.size() != originalN) {
		cout << -1 << endl;
		return;
	}

	rep(i, 0, originalN) {
		if(i) printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
条件を見てみると、Nが増えていくと大体作れそうな感じがする。
で、適当にdfsで全探索するとダメ。
ちゃんとやろうということか。

今回の問題のような、つくれれは何でもいいのではなく、辞書順最小のものを構築せよという問題は、常套テクがある。
先頭から貪欲に作っていくという方針である。
それを置くことでそれよりも後ろを構築可能かというのを確認しながら、先頭から辞書順最小のものをおいていく。
今回でいうと、Nがある程度ちっさくなるまでは、適当においておいても問題ない。
本番中に、その閾値をちゃんと求めるのが難しかったら、ガチャろう。

Nがある程度から小さくなった場合はどうするかであるが、全探索してしまおう。
これで通るかなーと思ったら、通らない。

コーナーケースがある。
例えば、
6 6 6 6 6 1
となっている場合は、1～5をどうおいても6がおけなくなってしまう。
このように、残りの数が1つを除いて、その1つを指している時である。
この場合は、それらを置く前に差されているものを置く必要がある。
これは指している数をどっかで数えておけば大丈夫。
///////////////////////// writeup2 end */
