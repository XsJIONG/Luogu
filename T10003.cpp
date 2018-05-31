#include <iostream>
using namespace std;

int n; long long z=0;
void dg(int i) {
	z++;
	for (int j=1;j<=i/2;j++) dg(j);
}
int main() {
	cin>>n;
	dg(n);
	cout<<z<<endl;
	return 0;
}
