#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n, m;
vl lst;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  lst = vl(n);
  auto total = 0LL;
  for (auto&& x : lst) {
    cin >> x;
    total += x;
  }

  auto l = *max_element(lst.begin(), lst.end());
  auto r = total;
  while (l <= r) {
    auto mid = (l + r) / 2;

    auto ct = 0LL;
    auto now = 0LL;
    for (const auto& x : lst) {
      if (mid < now + x) {
        now = 0;
        ++ct;
      }

      now += x;
    }
    if (0 < now) {
      ++ct;
    }

    if (m < ct) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << l;

  return 0;
}