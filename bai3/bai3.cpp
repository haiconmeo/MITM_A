#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <fstream>
#include <ctime>
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
	ofstream outfile;
   	outfile.open("text10.in");
   	outfile << n<<endl;
    outfile << k<<endl;
	vector<ULL> A, B;
	A.push_back(1);
	B.push_back(1);
	srand(time(NULL));
	for (int i = 0; i < n/2; i++) {
		a = (k /(rand()%100))/ rand() %20000000;
		outfile<<a<<endl;
		int m = A.size();
		for (int j = 0; j < m; j++) {
			if (valid(a, A[j], k)) {
				A.push_back(a * A[j]);
				//printf("%llu\n", a*A[j]);
			}
		}
	}
	for (int i = n/2; i < n; i++) {
		
		a = (k /(rand()%100))/ rand() %20000000;
		outfile<<a<<endl;
		int m = B.size();
		for (int j = 0; j < m; j++) {
			if (valid(a, B[j], k)) {
				B.push_back(a * B[j]);
				//printf("%llu\n", a*B[j]);
			}
		}
	}
	outfile.close();
	outfile.open("text10.out");
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
	outfile << ans;
	outfile.close();
	printf("%d\n", ans);
}
