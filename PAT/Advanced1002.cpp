#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Item {
	int expo;
	double coeff;
};
bool cmp(Item it1, Item it2)
{
	return it1.expo > it2.expo;
}
int main()
{
	int N;
	cin >> N;
	vector<Item>poly;
	while (N--)
	{
		Item it1;
		cin >> it1.expo >> it1.coeff;
		poly.push_back(it1);
	}
	cin >> N;
	while (N--)
	{
		Item it1;
		cin >> it1.expo >> it1.coeff;
		poly.push_back(it1);
	}
	sort(poly.begin(), poly.end(), cmp);
	if (poly.size() == 0)
		cout << 0;
	else if (poly.size() == 1)
		printf("1 %d %.1lf", poly[0].expo, poly[0].coeff);
	else
	{
		auto pre = poly.begin();
		auto cur = pre + 1;
		while (cur!=poly.end())
		{
			if (pre->expo == cur->expo)
			{
				cur->coeff += pre->coeff;
				pre = poly.erase(pre);
				if (pre->coeff == 0.0)
				{
					pre = poly.erase(pre);
					if (pre == poly.end())
						break;
					else
						cur = pre + 1;
				}
				else
				{
					if (pre == poly.end())
						break;
					else
						cur = pre + 1;
				}
			}
			else
			{
				pre++;
				cur++;
			}
		}
		cout << poly.size();
		for (size_t i = 0; i < poly.size(); ++i)
		{
			printf(" %d %.1lf", poly[i].expo, poly[i].coeff);
		}
	}
	return 0;
}