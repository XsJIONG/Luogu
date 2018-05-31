#include <iostream>
using namespace std;

namespace Problem {
	int n;
	int f[100];
	bool s[100];
	bool lf[100],rf[100];
	int cc=0;
	void ReadData() {
		cin>>n;
	}
	void DWHFXNSAZXJHASBSHgsafdsf(int d) {
		if (d==n+1) {
			if (cc<=2) {
				for (int i=1;i<=n;i++) cout<<f[i]<<' ';
				cout<<endl;
			}
			cc++;
			return;
		}
		for (int i=1;i<=n;i++) {
			if (s[i]||lf[d-i+n]||rf[d+i]) continue;
			s[i]=1;
			lf[d-i+n]=1;
			rf[d+i]=1;
			f[d]=i;
			DWHFXNSAZXJHASBSHgsafdsf(d+1);
			s[i]=0;
			lf[d-i+n]=0;
			rf[d+i]=0;
		}
	}
	int Solve() {
		ReadData();
		DWHFXNSAZXJHASBSHgsafdsf(1);
		cout<<cc<<endl;
		return 0;
	}
}

int main() {
	return Problem::Solve();
}
