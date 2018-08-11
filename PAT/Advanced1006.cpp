#include <string>
#include <iostream>

using namespace std;
struct Student {
	string ID;
	string start;
	string end;
};



int main()
{
	int N;
	cin >> N;
	string openTime = "23:59:59";
	string closeTime = "00:00:00";
	string stuOpen, stuClose;


	while (N--)
	{
		Student stu;
		cin >> stu.ID >> stu.start >> stu.end;
		if (stu.start < openTime)
		{
			openTime = stu.start;
			stuOpen = stu.ID;
		}
		if (stu.end > closeTime)
		{
			closeTime = stu.end;
			stuClose = stu.ID;
		}
	}
	cout << stuOpen << " " << stuClose << endl;
	return 0;
}