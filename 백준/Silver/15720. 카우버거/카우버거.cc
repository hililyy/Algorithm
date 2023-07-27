#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> aa(a), bb(b), cc(c);

    for (int i = 0; i < a; i++) cin >> aa[i];
    for (int i = 0; i < b; i++) cin >> bb[i];
    for (int i = 0; i < c; i++) cin >> cc[i];

    sort(aa.rbegin(), aa.rend());
    sort(bb.rbegin(), bb.rend());
    sort(cc.rbegin(), cc.rend());

    int min_items = min({a, b, c});
    int total_discount = 0, total_not_discount = 0;

    for (int i = 0; i < min_items; i++) {
        total_discount += aa[i] + bb[i] + cc[i];
    }

    for (int i = min_items; i < a; i++) total_not_discount += aa[i];
    for (int i = min_items; i < b; i++) total_not_discount += bb[i];
    for (int i = min_items; i < c; i++) total_not_discount += cc[i];

    int total_price = total_discount + total_not_discount;
    int discounted_price = total_discount * 0.9 + total_not_discount;

    cout << total_price << '\n';
    cout << discounted_price;

    return 0;
}
