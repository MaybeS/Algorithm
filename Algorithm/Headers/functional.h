#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <functional>
#pragma warning (disable : 4996)

typedef struct {
	int start,end,value;
}vertex_value;
vertex_value vertex_value_in()
{
	int start, end, value;
	std::cin >> start >> end >> value;
	return{ start, end, value };
}
void vertex_value_out(vertex_value v_v)
{
	std::cout << v_v.start << "," << v_v.end << "," << v_v.value << std::endl;
}
template <typename type> std::vector<type>  vector_in(long count)
{
	std::vector<type> vector;
	for (long i = 0; i < count; i++)
		vector.push_back(vertex_value_in());
	return vector;
}
template <typename type> void vector_out(std::vector<type>vector)
{
	for_each(vector.begin(), vector.end(), [=](type n)->void{ return vertex_value_out(n); } );
}
template <typename type> void vector_in(std::vector<type> * vec, long count)
{
	for (long i = 0; i < count; i++)
	{
		type temp;
		std::cin >> temp;
		vec->push_back(temp);
	}
}
template <typename type> std::vector<type>  vector_in(long count)
{
	std::vector<type> vector;
	for (long i = 0; i < count; i++)
	{
		type temp;
		std::cin >> temp;
		vector->push_back(temp);
	}
	return vector;
}

template <typename type> void vector_out(std::vector<type> vec)
{
	for (long i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << ",";
	std::cout << endl;
	return;
}
template <typename type> void swap(type *a, type *b)
{
	if (*a - *b)
		*a ^= *b ^= *a ^= *b;
}
int main(int argc, char * argv[])
{
	int number, temp = 0, ary[100001] = { 0, };
	std::cin >> number;
	std::vector<int> vec_a, vec_b;
	for (int i = 0; i < number; i++)
	{
		vector_in(&vec_a, 1);
		vector_in(&vec_b, 1);
	}
	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			if (vec_a.at(i) < vec_a.at(j))
			{
				swap(vec_a[i], vec_a[j]);
				swap(vec_b[i], vec_b[j]); 
			}
	std::vector<int> vec;
	std::for_each(vec_b.begin(), vec_b.end(), [&ary, &vec, &temp](int n)
	{
		if (vec.empty() || vec.back() < n)
		{
			vec.push_back(n);
			ary[vec.back()] = vec.size() > 1 ? vec[vec.size() - 2] : -1;
		}
		else
		{
			for (temp = 0; temp < vec.size(); temp++)
				if (vec[temp] > n) break;
			swap(vec[temp], n);
			ary[vec[temp]] = temp > 0 ? vec[temp - 1] : -1;
		}
	});
	std::cout << number - vec.size() << endl;
	temp = vec.back();
	do{
		for (int i = 0; i < vec_b.size(); i++)
			if (vec_b[i] == temp)
			{
				vec_b[i] = 0;
				break;
			}
	} while (1 + (temp = ary[temp]));
	std::for_each(vec_a.begin(), vec_a.end(), [&vec_b](int n){static int t = 0;   if (vec_b[t]) cout << n << endl; t++; });
	return 0;
}