#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	string str = to_string(a + b);
	int t = str.size();
	if ((a + b)>0)
		for (int i = str.size() - 1; i > 0; i--)
		{
			if ((t - i) % 3 == 0)
				str.insert(str.begin() + i, ',');
		}
	else
		for (int i = str.size() - 1; i > 1; i--)
		{
			if ((t - i) % 3 == 0)
				str.insert(str.begin() + i, ',');
		}
	cout << str;
	return 0;
}