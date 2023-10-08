namespace modop {
	int madd(int a, int b) {
	  return (a + b) % mod;
	}
	int msub(int a, int b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	int mmul(int a, int b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	int mpow(int base, int exp) {
	  int res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	int minv(int base) {
	  return mpow(base, mod - 2);
	}
	int mdiv(int a, int b) {
	  return mmul(a, minv(b));
	}
	
	const int FACTORIAL_SIZE = 1.1e6;
	int fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	bool __factorials_generated__ = 0;
	void gen_factorial(int n) {
		__factorials_generated__ = 1;
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
		}
		ifact[n] = minv(fact[n]);
		for (int i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	int nck(int n, int k) {
		if (!__factorials_generated__) {
			cerr << "Call gen_factorial you dope" << endl;
			exit(1);
		}
		if (k < 0 || n < k) return 0;
		int den = (ifact[k] * ifact[n - k]) % mod;
		return (den * fact[n]) % mod;
	}
}

using namespace modop;
