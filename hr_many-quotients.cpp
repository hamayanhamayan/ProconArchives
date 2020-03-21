//https://www.hackerrank.com/contests/75th/challenges/many-quotients
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
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












ll N;
//---------------------------------------------------------------------------------------------------
ll opt() {
    ll sq = sqrt(N);

    map<ll, ll> idx;
    rep(d, -10, 10) {
        ll x = sq + d;
        if (1 <= x && x <= N) idx[N / x] = x;
    }

    ll A = 0;
    ll pre = -1;
    fore(p, idx) {
        if (0 <= pre && pre + 1 < p.first) {
            A = p.second;
            break;
        }
        pre = p.first;
    }

    if (A == 0) {
        pre = -1;
        fore(p, idx) {
            if (0 <= pre && pre + 1 == p.first) A = p.second;
            pre = p.first;
        }
    }

    return A + N / (A + 1);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    cout << opt() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
死ぬほどバグった。
分母を1からNまで増やして商を見てみると、途中から5,4,3,2,1のように差が1になっていく。
しかも、それまでは商が被らない。
商が減らないのがAまでで、差が1になるのがA+1からであるとすると、答えはA+N/(A+1)となる。

そんなAを計算するのが大変。
sqrt(N)らへんにあるのは分かるので、sqrt関数で求めたら、その周辺で差が2以上となってるラインを探していく。
最も分母が大きくて、差が2以上となるラインがあればそこを採用すればいい。
存在しない場合は、差が1で最も分母が小さいラインを採用すればいい。
これでAを求めたら、計算式より答えも求まる。
///////////////////////// writeup2 end */
//　