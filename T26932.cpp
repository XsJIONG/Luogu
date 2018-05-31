#include <bits/stdc++.h>
using namespace std;

unsigned long long mmax,l,n,w[1100];
float v,t[1100],f[1100],tmps,tmpw;
int main() {
    cin>>mmax>>l>>n;
    w[0]=0;
    for(int i=1;i<=n;i++) {
    	cin>>tmps>>tmpw;
        w[i]=w[i-1]+tmps;
		t[i]=l/tmpw*60;
    }
    for(int i=1;i<=n;i++) f[i]=2147483647;
    f[0]=0;
	float mm;
    for(int i=1;i<=n;i++) {
    	mm=-2147483647;
        for(int j=i;j>=1;j--) {
            if(w[i]-w[j-1]>mmax) break;
            if (t[j]>mm) mm=t[j];
            f[i]=min(f[i],f[j-1]+mm);
        }
    }
    printf("%.1lf\n",f[n]);
    return 0;
}
