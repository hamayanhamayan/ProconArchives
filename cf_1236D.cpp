//http://codeforces.com/contest/1236/problem/D
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
// StaticHealthy2DSegtree
#define def 0
using V = int;
V comp(V& l, V& r) { return l+r; };
struct SegTree { //[l,r)
    int NV;
    vector<V> val;
    void init(int n) {
        NV = 1;
        while (NV < n) NV *= 2;
        val = vector<V>(NV * 2, def);
    }
    V get(int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return def; if (x <= l&&r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp(a, b);
    }
    V get(int x, int y) { return get(x, y, 0, NV, 1); }
    void update(int i, V v) { i += NV; val[i] = v; while (i>1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
    void compupdate(int i, V v) { update(i, comp(v, val[i + NV])); }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};

struct StaticHealthy2DSegTree {
    int NV;
    vector<SegTree> st;
    vector<vector<int>> index;
    
    void init(vector<vector<pair<int,V>>> &v) {
        int n = v.size();
        NV = 1; while (NV < n) NV *= 2;
        index.resize(2 * NV);
        rep(i, 0, n) fore(p, v[i]) index[i + NV].push_back(p.first);
        rrep(i, NV * 2 - 1, 1) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            fore(j, index[i]) index[i / 2].push_back(j);
        }
        st.resize(2 * NV);
        rep(i, 1, NV * 2) st[i].init(index[i].size());
        
        rep(i, 0, n) fore(p, v[i]) {
            int j = lower_bound(index[i + NV].begin(), index[i + NV].end(), p.first) - index[i + NV].begin();
            st[i + NV].update(j, p.second);
        }

        rrep(i, NV * 2 - 1, 2) {
            rep(j, 0, index[i].size()) {
                V v = st[i][j];
                
                int k = lower_bound(index[i / 2].begin(), index[i / 2].end(), index[i][j]) - index[i / 2].begin();
                st[i / 2].compupdate(k, v);
            }
        }
    }
    V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
        assert(k < NV * 2);
        assert(l < r);
        if (r <= sx or tx <= l) return def;
        if (sx <= l and r <= tx) {
            int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].get(syy, tyy);
        }
        int md = (l + r) / 2;
        V le = get(sx, tx, sy, ty, k * 2, l, md);
        V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
        return comp(le, ri);
    }
    V get(int sx, int tx, int sy, int ty) {
        return get(sx, tx, sy, ty, 1, 0, NV);
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














int H, W, K;
StaticHealthy2DSegTree st;
enum { UP = 0, RIGHT, DOWN, LEFT };
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
	cin >> H >> W >> K;
	vector<vector<pair<int, int>>> dic(W, vector<pair<int, int>>());
	rep(k, 0, K) {
		int y, x; cin >> y >> x; y--; x--;
		dic[x].push_back({ y, 1 });
	}
	st.init(dic);

	int x = 0, y = 0, dir = RIGHT;
	int sx = 0, sy = 0, tx = W - 1, ty = H - 1;

	while (1) {
		while (sx < tx and ty - sy + 1 == st.get(tx, tx + 1, sy, ty + 1)) tx--;
		if (st.get(sx, tx + 1, sy, sy + 1) != 0) return no;
		if (sy == ty) return yes;
		if (st.get(sx, tx + 1, sy + 1, ty + 1) == 1LL * (tx - sx + 1) * (ty - sy)) return yes;
		sy++;

		while (sy < ty and tx - sx + 1 == st.get(sx, tx + 1, ty, ty + 1)) ty--;
		if (st.get(tx, tx + 1, sy, ty + 1) != 0) return no;
		if (sx == tx) return yes;
		if (st.get(sx, tx, sy, ty + 1) == 1LL * (tx - sx) * (ty - sy + 1)) return yes;
		tx--;

		while (sx < tx and ty - sy + 1 == st.get(sx, sx + 1, sy, ty + 1)) sx++;
		if (st.get(sx, tx + 1, ty, ty + 1) != 0) return no;
		if (sy == ty) return yes;
		if (st.get(sx, tx + 1, sy, ty) == 1LL * (tx - sx + 1) * (ty - sy)) return yes;
		ty--;

		while (sy < ty and tx - sx + 1 == st.get(sx, tx + 1, sy, sy + 1)) sy++;
		if (st.get(sx, sx + 1, sy, ty + 1) != 0) return no;
		if (sx == tx) return yes;
		if (st.get(sx + 1, tx + 1, sy, ty + 1) == 1LL * (tx - sx) * (ty - sy + 1)) return yes;
		sx++;
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
