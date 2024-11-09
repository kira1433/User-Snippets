// nCk for doubles. n can go till 1e5
int mxN = 1e5+7;
double fac[mxN];
double choose(int n, int k) {
	if(k < 0 || k > n)	return 0;
	return exp(-(fac[n] - fac[k] - fac[n-k]));
}

void preprocess() {

	fac[0] = 0.0;
	for(int i = 1; i < mxN; ++i) {
		fac[i] = fac[i-1] + log(i);
	}
}