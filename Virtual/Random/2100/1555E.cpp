#include <bits/stdc++.h>
using namespace std;

// static char buf[450 << 18];
// void* operator new(size_t s) {
// 	static size_t i = sizeof buf;
// 	assert(s < i);
// 	return (void*)&buf[i -= s];
// }
// void operator delete(void*) {}

typedef vector<int> vi;
const long long inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
    int lo, hi;
    long long mset = inf, madd = 0, val = inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = min(l->val, r->val);
		}
		else val = v[lo];
	}
	long long query(int L, int R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, long long x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void add(int L, int R, long long x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> segments;
    for (int i = 0; i < n; i++){
        vector<int> segment(3);
        scanf("%d %d %d", &segment[1], &segment[2], &segment[0]);
        segments.push_back(segment);
    }
    sort(segments.begin(), segments.end());
    vi v(m + 7);
    Node lazySegtree = Node(v, 0, v.size());
    int answer = 1e9;
    int l = 0, r = -1;
    while(r < n-1){
        while(r < n-1 && lazySegtree.query(1, m) == 0){
            r++;
            lazySegtree.add(segments[r][1], segments[r][2], segments[r][0]);
        }
        if(lazySegtree.query(1, m) != 0){
            answer = min(answer, segments[r][0] - segments[l][0]);
        }
        while(l <= r && lazySegtree.query(1, m) != 0){
            lazySegtree.add(segments[l][1], segments[l][2], -segments[l][0]);
            l++;
            if(lazySegtree.query(1, m) != 0){
                answer = min(answer, segments[r][0] - segments[l][0]);
            }
        }
    }
    printf("%d\n", answer);
}