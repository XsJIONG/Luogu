//Xs.JIONG 2018.5.29
//Chino±£ÓÓ£¬´úÂëÎŞBug 

#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <math.h>
using namespace std;

string s;
int len;
bool is[1002][1002];
int d[1002];
int main() {
	int T;
	cin>>T;
	while (T--) {
		cin>>s;
		len=s.length();
		for (int i=1;i<=len;i++) memset(is[i],0,sizeof(bool)*(len+1));
		for (float i=1;i<=len;i+=0.5)
		for (int j=0;i+j<=len&&i-j>=1;j++)
			if (s[int(floor(i-j))-1]==s[int(ceil(i+j))-1]) is[int(floor(i-j))][int(ceil(i+j))]=1; else break;
		for (int i=1;i<=len;i++) d[i]=i;
		for (int i=2;i<=len;i++)
		for (int j=0;j<i;j++)
			if (is[j+1][i])
				d[i]=min(d[i],d[j]+1);
		cout<<d[len]<<endl;
	}
	return 0;
}
