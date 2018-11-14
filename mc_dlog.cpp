#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "HashTable.h"



HashTable Ord = HashTable();

int order(int x, int n)
{
	for(int i=0; i<=sqrt(n); i++)
	{
		int random = rand() % n;

		int y = (int) pow( x, random) % n;

	 	if(Ord.check(y)==true)
	 	{
	 		int index = Ord.hash_function(y);

	 		if( (random-index) > 0 || (index-random) > 0 )
	 		{
	 			if( (random-index) > (index-random) )
	 			{
	 				return (random-index);
	 			}
	 			if( (index-random) > (random-index) )
	 			{
	 				return (index-random);
	 			}
	 		}
	 		else
	 		{
	 			continue;
	 		}
	 	}
	 	else
	 	{
	 		Ord.insert( y, random );
	 	}
 	}
 	return n-1;
}

HashTable A = HashTable();
HashTable B = HashTable();

int discrete(int x, int n, int a)
{
	for(int i=0; i<=sqrt(n); i++)
	{
		int random = rand() % n;

		int z = (int) pow( x, random) % n;

		int y = a * z;

		if(B.check(y)==true)
		{
			int index2 = (B.hash_function(y) - random);
			return index2;
		}
		else
		{
			A.insert( y, random );
		}

		int random2 = rand() % n;

		if(A.check(z)==true)
		{
			int index3 = random2 - A.hash_function(z);
			return index3;
		}
		else
		{
			B.insert( y, random2);
		}
	}
	return 0;
}

int combine(int x, int n, int a)
{
	int s = order(x , n);

	int t = discrete(x, n, a);

	int u = t % s;

	if( u < 0 )
	{
		u = u + s;
		return u;
	}
	else
	{
		return u;
	}
}

int main(int argc, char** argv)
{
	if(argc>4)
	{
		cout<<"The amount of parameters is incorrect, please try again.";
	}
	else
	{
		int x, n, a;
        stringstream(argv[1]) >> x;
        stringstream(argv[2]) >> n;
        stringstream(argv[3]) >> a;
        int d=1;
        int e=1;
        int b = combine(x, n, a);
        cout << b << endl;
        int f = order(d, e);
        cout << f << endl;
    }
    return 0;
}
/* Implement mc_dlog in this file */



//intialises table to size of  1
