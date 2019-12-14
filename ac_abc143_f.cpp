//https://atcoder.jp/contests/abc143/tasks/abc143_f
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














int N, A[301010];
int B[301010], C[301010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	map<int, int> cnt;
	rep(i, 0, N) cnt[A[i]]++;

	fore(p, cnt) B[p.second] += p.second;
	fore(p, cnt) C[p.second]++;

	rrep(i, 301000, 0) B[i] += B[i + 1];
	rrep(i, 301000, 0) C[i] += C[i + 1];

	rep(k, 1, N + 1) {
		int ans = 0;

		rep(cand, 1, N / k + 1) {
			int rest = N - (B[cand] - C[cand] * cand);
			if (cand * k <= rest) chmax(ans, cand);
		}
		
		printf("%d\n", ans);
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [調和級数計算量](https://www.hamayanhamayan.com/entry/2016/10/21/112009)
///////////////////////// writeup2 start
Kと答えansが固定されているときに何が起こるかを考える。
ansが固定されていると、ある種類の数は最大ans回しか使えない。
すべての種類の数についてmin(個数,ans)の総和をとったとき、これがK*ans以上であれば、そのKについてansは達成できる。
この性質までたどり着くのが長い。

あるKについて、答えとなる最大値はN/Kであり、各Kで[1,N/K]をすべて試しても計算量は、
エラトステネスの篩的に（調和級数的に）O(NlogN)になる。
よって、「すべての種類の数についてmin(個数,ans)の総和」が高速に求まれば答えを求めることができる。
これは累積和を使えばうまくやれる。
B[i] := ある種類の個数がi以上である数の個数の総和
C[i] := ある種類の個数がi以上である数が何個あるか

すべての種類の数についてmin(個数,ans)の総和 = すべての種類の数の個数の総和 - 各種類の個数がansより大きくてはみ出している分
ここで、各種類の個数がansより大きくてはみ出している分は
B[ans] - C[ans] * ans
であるため、これを全体から引く。
あとは、条件判定してやればいい。
///////////////////////// writeup2 end */
