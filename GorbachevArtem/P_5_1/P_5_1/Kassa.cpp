#include "Kassa.h"

void Kassa::AddToCheck(const Product & P, int count)
{
	Purchase p;
	p.title = P.title;
	vec.push_back(p);
	int i = 0;
	while (vec[i].title != P.title) i++;
	vec.pop_back();
	if (i < vec.size())
	{
		vec[i].count += count;
		vec[i].result += vec[i].price * count;
	}
	else
	{
		p.price = P.price;
		p.count = count;
		p.result = p.price * p.count;
		p.disc_per = P.disc_per;
		vec.push_back(p);
	}
	cost += P.price * count;
	discount += P.price * count * P.disc_per / 100;
	result = cost - discount;
}

void Kassa::Delete(string title, int count)
{
	Purchase p;
	p.title = title;
	vec.push_back(p);
	int i = 0;
	while (vec[i].title != title) i++;
	vec.pop_back();
	if (i < vec.size())
	{
		if (count < vec[i].count)
		{
			vec[i].count -= count;
			vec[i].result -= vec[i].price * count;
			cost -= vec[i].price * count;
			discount -= vec[i].price * count * vec[i].disc_per / 100;
		}
		else
		{
			cost -= vec[i].result;
			discount -= vec[i].result * vec[i].disc_per / 100;
			int n = vec.size() - 1;
			for (i = 0; i < n; i++)
				vec[i] = vec[i + 1];
			vec.pop_back();
		}
		result = cost - discount;
	}
}

void Kassa::GenerateCheck(string file) const
{
	ofstream os;
	os.open(file);
	int size = vec.size();
	for (int i = 0; i < size; i++)
		os << vec[i] << endl;
	os << "Общая стоимость: " << cost << endl;
	os << "Суммарная скидка: " << discount << endl;
	os << "Итоговая сумма: " << result << endl;
	os.close();
}