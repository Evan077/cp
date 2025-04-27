ll mult(ll a, ll b) {
  return ((a * b) % mod);
} 
ll inv(ll a) {
  return rais_to_power(a, mod - 2);
}
ll divide(ll a, ll b) {
  return mult(a, inv(b));
}
ll nCr(ll n, ll r) {
  if(n < r) return 0;
  return divide(fct[n], mult(fct[r], fct[n - r]));
}
