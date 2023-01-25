class Solution {
 private:
  vector<int> sums;

 public:
  Solution(vector<int>& w) {
    for (auto v : w) {
      if (sums.size() == 0) {
        sums.push_back(v);
      } else {
        sums.push_back(v + sums.back());
      }
    }
  }

  int pickIndex() {
    int randNum = rand() % sums.back();
    auto iter = upper_bound(sums.begin(), sums.end(), randNum);
    return iter - sums.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
