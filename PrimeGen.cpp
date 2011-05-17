#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;


bool IsZero(int i) {return (i == 0);}


vector<int>::iterator primes (int n, vector<int>* ints) 
{
	if (n==2) 
	{
		ints->push_back(2);
		vector<int>::iterator l = ints->end();
		return l;
	}
	else if (n < 2) 	
	{
		vector<int>::iterator l = ints->end();
		return l;
	}
	for (int i = 3; i < n+1; i = i + 2) 
	{
		ints->push_back(i);
	}
	float mroot = pow(n,0.5);
	float half = (n+1)/2-1;
	float i = 0;
	float m = 3;
	float j;
	while (m <= mroot) 
	{
		if (ints->at(i) != 0) 
		{
			j = (m*m-3)/2;
			ints->at(j) = 0;
			while (j < half)
			{
				ints->at(j) = 0;
				j+=m;
			}
		}
		i = i + 1;
		m=2*i+3;
	}
	ints->insert(ints->begin(), 2);
	vector<int>::iterator l; 
	l = ints->erase(remove_if(ints->begin(), ints->end(), IsZero), ints->end());
	return l;
}

int main() 
{
	int n=1000000;
	//cout << "please enter a number" << endl;
	//cin >> n;
	vector<int> integerss;
	vector<int>* ints = &integerss;
	vector<int>::iterator l;
	vector<int>::iterator q;
	l = primes(n, ints);
	q = ints->begin();
	int i = 0;
	//cout << ints->size() << endl;
	//remove_if(ints->begin(), ints->end(), IsZero);
	 
	while (( q != l)) 
	{
		cout << *q << endl;
		q++;
	}
	
	return 0;
}	
