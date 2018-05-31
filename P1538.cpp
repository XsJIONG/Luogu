#include <bits/stdc++.h>
#define SPACE ' '
#define HORIZONTAL '-'
#define VERTICAL '|'
using namespace std;

bool DATA[10][7]={
  {1,1,1,0,1,1,1},
  {0,0,1,0,0,1,0},
  {1,0,1,1,1,0,1},
  {1,0,1,1,0,1,1},
  {0,1,1,1,0,1,0},
  {1,1,0,1,0,1,1},
  {1,1,0,1,1,1,1},
  {1,0,1,0,0,1,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};
int k;
int top=0;
int a[257];
void ph() {
	for (int i=0;i<k;i++) putchar(HORIZONTAL);
}
void ps() {
	putchar(SPACE);
}
void pss() {
	for (int i=0;i<k;i++) putchar(SPACE);
}
void pv() {
	putchar(VERTICAL);
}
void writeln() {
	putchar('\n');
}
void findH(int ds) {
	for (int i=1;i<=top;i++) {
		ps();
		if (DATA[a[i]][ds]) ph(); else pss();
		ps();
		if (i!=top) ps(); 
	}
	writeln();
}
void findV(int x, int y) {
	for (int i=0;i<k;i++) {
		for (int i=1;i<=top;i++) {
			if (DATA[a[i]][x]) pv(); else ps();
			pss();
			if (DATA[a[i]][y]) pv(); else ps();
			if (i!=top) ps();
		}
		writeln();
	}
}
int main() {
	cin>>k;
	char c;
	getchar();
	scanf("%c",&c);
	while (isdigit(c)) {
		a[++top]=c-'0';
		scanf("%c",&c);
	}
	findH(0);
	findV(1,2);
	findH(3);
	findV(4,5);
	findH(6);
	return 0;
}
