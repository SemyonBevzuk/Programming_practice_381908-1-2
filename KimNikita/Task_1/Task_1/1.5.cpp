#include "Time.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <deque>

using namespace std;


int main()
{
	Time t1, t2(13, 12, 11), t3(t2), t4("23:45:00");
	cout << "t1: ";
	t1.get_time();
	cout << "t2: ";
	t2.get_time();
	cout << "t3: ";
	t3.get_time();
	cout << "t4: ";
	t4.get_time();
	cout << "t1 += t4 - t3" << endl;
	t1 += t4 - t3;
	cout << "t1: ";
	t1.get_time();
	Time t5;
	cout << "t5: ";
	cin >> t5;
	cout << "t5 -= t1" << endl;
	t5 -= t1;
	cout << "t5: ";
	cout << t5 << endl;
	if (t4 > t5)
	{
		cout << "t4 > t5" << endl;
		cout << "t2+t5: ";
		cout << t2 + t5 << endl;
	}
	else
	{
		cout << "t4 <= t5" << endl;
		cout << "t2-t5: ";
		cout << t2 - t5 << endl;
	}
	return 0;
}