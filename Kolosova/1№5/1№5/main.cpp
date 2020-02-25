#include <iostream>
#include "Time.h"
using namespace std;
int main() {
	Time t1, t2(14, 11, 34), t3(t2);
	cout << t1 << ' ' << t2 << ' ' << t3 << endl;
	t1 = t2 + t3;
	t2 -= t1;
	t3 = t1 - t2;
	cout << t1 << ' ' << t2 << ' ' << t3 << endl;
	t1 += 86400; //+ 1day
	t2 -= 86400; //-1 day
	t3 = t2 + 3670; //+1hr 1m 10s
	cout << t1 << ' ' << t2 << ' ' << t3 << endl;
	cout << ((t1 > t2) ? "t1>t2" : "t1<t2") << endl;;
	t3 = t2 - t1;
	t1 += t3;
	cout << t1<<' '<<t2<<' '<<((t1 >= t2) ? "t1>=t2" : "t1<t2") << endl;
	t2 += 10;
	cout<< ((t1 != t2) ? "t1!=t2" : "t1==t2") << endl;
	cin >> t1;
	cout << t1;
}