#include <iostream>
#include <string>

using namespace std;
int main()
{
	string num;
	cin >> num;
	int sum = 0;
	for (int i = 0; i < num.size(); i++)
		sum += (num[i] - '0');
	string ans = to_string(sum);
	for (int i = 0; i < ans.size(); i++)
	{
		switch (ans[i])
		{
		case '0': {
			if (i == ans.size() - 1)
				cout << "zero" << endl;
			else
				cout << "zero ";
			break;

		}
		case '1': {
			if (i == ans.size() - 1)
				cout << "one" << endl;
			else
				cout << "one ";
			break;

		}
		case '2': {
			if (i == ans.size() - 1)
				cout << "two" << endl;
			else
				cout << "two ";
			break;

		}
		case '3': {
			if (i == ans.size() - 1)
				cout << "three" << endl;
			else
				cout << "three ";
			break;
		}
		case '4': {
			if (i == ans.size() - 1)
				cout << "four" << endl;
			else
				cout << "four ";
			break;
		}
		case '5': {
			if (i == ans.size() - 1)
				cout << "five" << endl;
			else
				cout << "five ";
			break;
		}
		case '6': {
			if (i == ans.size() - 1)
				cout << "six" << endl;
			else
				cout << "six ";
			break;
		}
		case '7': {
			if (i == ans.size() - 1)
				cout << "seven" << endl;
			else
				cout << "seven ";
			break;
		}
		case '8': {
			if (i == ans.size() - 1)
				cout << "eight" << endl;
			else
				cout << "eight ";
			break;
		}
		case '9': {
			if (i == ans.size() - 1)
				cout << "nine" << endl;
			else
				cout << "nine ";
			break;
		}
		}
	}
	return 0;
}