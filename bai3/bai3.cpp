#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define ULL unsigned long long
#define P 1000000007
using namespace std;

bool valid(ULL a, ULL b, ULL p) {
	return (double(p) / double(a)) >= b;
}

int main() {
	int n;
	ULL k, a;
	int ans = 0;
	scanf("%d %llu", &n, &k);
	vector<ULL> A, B;
	A.push_back(1);
	B.push_back(1);
	for (int i = 0; i < n/2; i++) {
		scanf("%llu", &a);
		int m = A.size();
		for (int j = 0; j < m; j++) {
			if (valid(a, A[j], k)) {
				A.push_back(a * A[j]);
				//printf("%llu\n", a*A[j]);
			}
		}
	}
	for (int i = n/2; i < n; i++) {
		scanf("%llu", &a);
		int m = B.size();
		for (int j = 0; j < m; j++) {
			if (valid(a, B[j], k)) {
				B.push_back(a * B[j]);
				//printf("%llu\n", a*B[j]);
			}
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int j = B.size() - 1;
	for (int i = 0; i < A.size(); i++) {
		while(!valid(A[i], B[j], k)) {
			j--;
		}
		ans += (j+1);
	}
	ans--;
	printf("%d\n", ans);
}
