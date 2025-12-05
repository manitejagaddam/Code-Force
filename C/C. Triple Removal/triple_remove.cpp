#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Node {
    long long count0 = 0, count1 = 0;
    long long pairs0 = 0, pairs1 = 0;
    int prefix_len = 0, suffix_len = 0;
    int prefix_val = -1, suffix_val = -1;
    int len = 0;
};

Node merge(const Node& left, const Node& right) {
    if (left.len == 0) return right;
    if (right.len == 0) return left;

    Node res;
    res.len = left.len + right.len;
    res.count0 = left.count0 + right.count0;
    res.count1 = left.count1 + right.count1;
    res.pairs0 = left.pairs0 + right.pairs0;
    res.pairs1 = left.pairs1 + right.pairs1;

    if (left.suffix_val == right.prefix_val) {
        if (left.suffix_val == 0) {
            res.pairs0 += (left.suffix_len + right.prefix_len) / 2 - left.suffix_len / 2 - right.prefix_len / 2;
        } else {
            res.pairs1 += (left.suffix_len + right.prefix_len) / 2 - left.suffix_len / 2 - right.prefix_len / 2;
        }
    }

    res.prefix_val = left.prefix_val;
    res.prefix_len = left.prefix_len;
    if (left.prefix_len == left.len && left.prefix_val == right.prefix_val) {
        res.prefix_len += right.prefix_len;
    }

    res.suffix_val = right.suffix_val;
    res.suffix_len = right.suffix_len;
    if (right.suffix_len == right.len && right.suffix_val == left.suffix_val) {
        res.suffix_len += left.suffix_len;
    }
    
    return res;
}

vector<int> nums;
vector<Node> tree;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].len = 1;
        if (nums[start] == 0) {
            tree[node].count0 = 1;
        } else {
            tree[node].count1 = 1;
        }
        tree[node].prefix_len = 1;
        tree[node].suffix_len = 1;
        tree[node].prefix_val = nums[start];
        tree[node].suffix_val = nums[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return Node();
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    Node p1 = query(2 * node, start, mid, l, r);
    Node p2 = query(2 * node + 1, mid + 1, end, l, r);
    return merge(p1, p2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    nums.assign(n, 0);
    // string s;
    // cin >> s;
    for (int i = 0; i < n; ++i) {
        // a[i] = s[i] - '0';
        cin >> nums[i];
    }

    tree.assign(4 * n, Node());
    build(1, 0, n - 1);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        Node res = query(1, 0, n - 1, l - 1, r - 1);
        long long c0 = res.count0;
        long long c1 = res.count1;

        if (c0 % 3 != 0 || c1 % 3 != 0) {
            cout << -1 << "\n";
            continue;
        }

        long long p0 = res.pairs0;
        long long p1 = res.pairs1;

        long long k = c0 / 3 - p0;
        long long m = c1 / 3 - p1;
        
        long long total_ops = (c0 + c1) / 3;
        long long cost = total_ops + min(k, m);
        cout << cost << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}