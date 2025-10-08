struct PairHash {
  size_t operator()(const pair<ll, ll>& p) const noexcept {
    size_t h1 = hash<ll>{}(p.first);
    size_t h2 = hash<ll>{}(p.second);
    return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
  }
};
// this is how to declare unordered maps
// unordered_map<pair<ll,ll>,pair<ll,ll>,PairHash>m;
 // unordered_map<pair<ll,ll>, ll, PairHash> m;
// also works for un_ordered set;
