//https://yukicoder.me/problems/no/913
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
class ConvexHullDynamic
{
	typedef long long coef_t;
	typedef long long coord_t;
	typedef long long val_t;

	/*
	* Line 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
	* and 'xLeft' which is intersection with previous line in hull(first line has -INF)
	*/
private:
	struct Line
	{
		coef_t a, b;
		double xLeft;

		enum Type
		{
			line, maxQuery, minQuery
		} type;
		coord_t val;

		explicit Line(coef_t aa = 0, coef_t bb = 0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}

		val_t valueAt(coord_t x) const { return a * x + b; }

		friend bool areParallel(const Line& l1, const Line& l2) { return l1.a == l2.a; }

		friend double intersectX(const Line& l1, const Line& l2) { return areParallel(l1, l2) ? INFINITY : 1.0 * (l2.b - l1.b) / (l1.a - l2.a); }

		bool operator<(const Line& l2) const
		{
			if (l2.type == line)
				return this->a < l2.a;
			if (l2.type == maxQuery)
				return this->xLeft < l2.val;
			if (l2.type == minQuery)
				return this->xLeft > l2.val;
		}
	};


	bool isMax; //whether or not saved envelope is top(search of max value)
public:
	std::set< Line > hull;  //envelope itself

private:
	/*
	* INFO:        Check position in hull by iterator
	* COMPLEXITY:  O(1)
	*/
	bool hasPrev(std::set< Line >::iterator it) { return it != hull.begin(); }

	bool hasNext(std::set< Line >::iterator it) { return it != hull.end() && std::next(it) != hull.end(); }

	/*
	* INFO:        Check whether line l2 is irrelevant
	* NOTE:        Following positioning in hull must be true
	*              l1 is next left to l2
	*              l2 is right between l1 and l3
	*              l3 is next right to l2
	* COMPLEXITY:  O(1)
	*/
	bool irrelevant(const Line& l1, const Line& l2, const Line& l3) { return intersectX(l1, l3) <= intersectX(l1, l2); }

	bool irrelevant(std::set< Line >::iterator it)
	{
		return hasPrev(it) && hasNext(it)
			&& (isMax && irrelevant(*std::prev(it), *it, *std::next(it))
				|| !isMax && irrelevant(*std::next(it), *it, *std::prev(it)));
	}

	/*
	* INFO:        Updates 'xValue' of line pointed by iterator 'it'
	* COMPLEXITY:  O(1)
	*/
	std::set< Line >::iterator updateLeftBorder(std::set< Line >::iterator it)
	{
		if (isMax && !hasPrev(it) || !isMax && !hasNext(it))
			return it;

		double val = intersectX(*it, isMax ? *std::prev(it) : *std::next(it));
		Line buf(*it);
		it = hull.erase(it);
		buf.xLeft = val;
		it = hull.insert(it, buf);
		return it;
	}

public:
	explicit ConvexHullDynamic(bool isMax = false) : isMax(isMax) {}

	/*
	* INFO:        Adding line to the envelope
	*              Line is of type 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
	* COMPLEXITY:  Adding N lines(N calls of function) takes O(N*log N) time
	*/
	void addLine(coef_t a, coef_t b)
	{
		//find the place where line will be inserted in set
		Line l3 = Line(a, b);
		auto it = hull.lower_bound(l3);

		//if parallel line is already in set, one of them becomes irrelevant
		if (it != hull.end() && areParallel(*it, l3)) {
			if (isMax && it->b < b || !isMax && it->b > b)
				it = hull.erase(it);
			else
				return;
		}

		//try to insert
		it = hull.insert(it, l3);
		if (irrelevant(it)) {
			hull.erase(it);
			return;
		}

		//remove lines which became irrelevant after inserting line
		while (hasPrev(it) && irrelevant(std::prev(it))) hull.erase(std::prev(it));
		while (hasNext(it) && irrelevant(std::next(it))) hull.erase(std::next(it));

		//refresh 'xLine'
		it = updateLeftBorder(it);
		if (hasPrev(it))
			updateLeftBorder(std::prev(it));
		if (hasNext(it))
			updateLeftBorder(std::next(it));
	}

	val_t getBest(coord_t x) const
	{
		Line q;
		q.val = x;
		q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;

		auto bestLine = hull.lower_bound(q);
		if (isMax) --bestLine;
		return bestLine->valueAt(x);
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[201010];
ll B[201010];
//---------------------------------------------------------------------------------------------------
void f(int L, int R, vector<ll>& ans, bool isRev = false) {
	if (L + 1 == R) {
		chmin(ans[L], 1LL + A[L]);
		return;
	}

	int md = (L + R) / 2;
	if (isRev and (R - L) % 2 == 1) md++;
	f(L, md, ans, isRev);
	f(md, R, ans, isRev);

	ConvexHullDynamic cht;
	rep(i, md, R) cht.addLine(-2LL * (i + 1), 1LL * (i + 1) * (i + 1) + B[i]);
	
	ll mi = infl;
	rep(i, L, md) {
		ll cst = cht.getBest(i) + 1LL * i * i;
		if (i) cst -= B[i - 1];
		chmin(mi, cst);
		chmin(ans[i], mi);
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	vector<ll> normal(N, infl);
	B[0] = A[0];
	rep(i, 1, N) B[i] = B[i - 1] + A[i];
	f(0, N, normal);

	reverse(A, A + N);

	vector<ll> rev(N, infl);
	B[0] = A[0];
	rep(i, 1, N) B[i] = B[i - 1] + A[i];
	f(0, N, rev, true);

	rep(i, 0, N) printf("%lld\n", min(normal[i], rev[N - 1 - i]));
}





/* ///////////////////////// writeup1 start
# 前提知識
- [列の分割統治](https://www.hamayanhamayan.com/entry/2017/05/21/234616)
- [CHT](https://www.hamayanhamayan.com/entry/2017/03/20/234711)
///////////////////////// writeup2 start
分割統治+CHTで解く。
こういう系の問題に初めて取り組む場合は、まずは「列の分割統治」と「CHT」について学ぼう。
この2つが理解できていれば、今回の想定解を理解するのは難しくない。
逆に理解できないと理解できない。よりかんたんな問題でなれることをおすすめする。


分割統治をしながら求めていく。
f(L, R) := [L,R)の区間で木iを燃やしたときの悲しさの最小値を考える
分割用にmd=(L+R)/2とする。
まず、分割前提でf(L,md)とf(md,R)は別途考えるとすると、
f(L,R)で考えるべきケースはmdを通るケースになる。
分割統治で使う考え方として、左側を全探索して、右側のまとめて考えるというのがある。
今回もこれで木iを左端として、右端を右側でまとめて考える。
この部分でCHTを使おう。
細かな式変形は[公式解説](https://yukicoder.me/problems/no/913/editorial)が詳しい。
考えによっては自分のようにl-kではなく、l+1-kで考える必要があるので注意。
あとはセオリー通りにやっていこう。

自分の実装では実装を少しサボり反転して2回行っている。
このときは、mdをいじらないと反転しない場合と一致しないので、注意。
///////////////////////// writeup2 end */
