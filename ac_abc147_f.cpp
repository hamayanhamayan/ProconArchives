//https://atcoder.jp/contests/abc147/tasks/abc147_f
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
struct SectionStructure {
    set<pair<ll, ll>> buf;
    SectionStructure() {
        buf.insert({ -infl, -infl });
        buf.insert({ infl , infl });
    }
    void add(ll l, ll r) {
        auto ite = buf.lower_bound({ l, -infl });

        if (ite->first == infl) { // 大きいやつが無い
            ite--;
            if (ite->second <= l) { // 被ってないなら追加
                buf.insert({ l, r });
            }
            else { // 被ってるならそれとくっつける
                ll L = ite->first;
                ll R = ite->second;

                buf.erase(ite);
                buf.insert({ L, max(r, R) });
            }
        }
        else { // 被ってるのがある
            auto pre = buf.upper_bound({ r, -infl });
            auto pp = pre;
            pp--;

            ll L = min(l, ite->first);
            ll R = max(r, pp->second);

            ite--;
            if (ite->second <= l) { // 被ってないなら追加
                ite++;
            }
            else { // 被ってるならそれとくっつける
                L = ite->first;
            }

            buf.erase(ite, pre);
            buf.insert({ L, R });
        }
    }
    set<pair<ll, ll>>::iterator get(ll x) {
        auto ite = buf.lower_bound({ x, -infl });

        if (ite->first == infl) return buf.end();
        if (ite->second < x) return buf.end();
        return ite;
    }
    set<pair<ll, ll>>::iterator end() { return buf.end(); }
    int check(ll a, ll b) {
        if (a > b) swap(a, b);
        auto aa = buf.upper_bound({ a, infl });
        aa--;
        if (aa->first == -infl) return false;
        return b <= aa->second;
    }
    void print() {
        printf("<>\n");
        for (auto p : buf) printf("[%d,%d]\n", p.first, p.second);
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














ll N, X, D;
//---------------------------------------------------------------------------------------------------
ll solve() {
	if (D == 0) {
		if (X == 0) return 1;
		return N + 1;
	}
	if (D < 0) {
		D *= -1;
		X *= -1;
	}

	map<int, SectionStructure> m;

	rep(M, 0, N + 1) {
		int offset = (((1LL * X * M) % D) + D) % D;

		ll L = (1LL * X * M) / D + 1LL * (0 + M - 1) * M / 2;
		ll R = (1LL * X * M) / D + 1LL * (N - 1 + N - 1 - M + 1) * M / 2;

		m[offset].add(L, R);
	}

	ll ans = 0;
	fore(p, m) {
		ll pre = -infl;
		fore(section, p.second.buf) {
			if (abs(section.first) == infl) continue;
			if (section.first == pre) ans--;
			ans += section.second - section.first + 1;
			pre = section.second;
		}
	}
	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> X >> D;
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
全体の総和は変わらないので、SかTのパターンを考えればよさそう。
Sのパターンを数えることにする。

組み合わせがちょっと多いので、何かを全探索したい。
高橋君が取る要素の個数を全探索しよう。
高橋くんがM個取ったとすると、総和がMX+?Dとなる。
ここで?Dが取る範囲を雑に考えると最小～最大になるんじゃないかなと想像できる。
つまり、0,D,2D,3D,...と小さい方からA個取ったもの～大きい方からA個取ったものが取りうる範囲である。

これで組み合わせが求まりそうだが、かぶっている所を引かないと行けない。
これを高速に求めるのも難しいのだが、総和がMX+?Dの形になっていてDずつ変化する区間なので、
Dで割ってやって区間を管理したくなる。
だが、MXによって、始点が若干異なるので、その所が問題。
これはMX mod Dで別々に区間を管理することにすれば解決する。

あとは、mod Dするので、Dをしっかり場合分けする必要がある。
D=0のときは別途頑張り、D<0のときは、特にD=-D, X=-xとしても問題ないので、それで対応する。
///////////////////////// writeup2 end */
