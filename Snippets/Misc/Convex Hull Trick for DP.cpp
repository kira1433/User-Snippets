// m1*x+c1 = m2*x+c2
// x = (c2-c1)/(m1-m2)
// mx+c
struct Line {
	int m, c;
	int value(int x) {
		return m*x + c;
	}
	bool better(Line l1, Line l2) {				// return true if the next line that is l2 is better than l1
		// intersection point between 2nd last line and last line.
		int numer1 = l1.c - c;
		int denom1 = m - l1.m;
		// intersection point between 2nd last line and cur line.
		int numer2 = l2.c - c;
		int denom2 = m - l2.m;
		// return true if the second intersection point <= first intersection point.
		return numer2*denom1 <= numer1*denom2;
	}
};
vi dp(N);
deque<Line> dq;
for(int i = 0; i < N; ++i) {
	while(dq.size() >= 2 && dq[0].value(h[i]) >= dq[1].value(h[i]))	dq.pop_front();

	if(dq.size())	dp[i] = dq[0].value(h[i]) + h[i]*h[i] + C;

	Line cur = {-2*h[i], dp[i] + h[i]*h[i]};
	while(dq.size() >= 2 && dq.end()[-2].better(dq.end()[-1], cur))	dq.pop_back();
	dq.push_back(cur);
}
cout << dp[N-1];