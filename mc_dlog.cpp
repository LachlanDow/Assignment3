#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "HashTable.h"
ulint intpow(ulint base,ulint exp){
  if(exp == 0){
    return 1;
  }
  else if (exp == 1){
    return base;
  }
  else if (exp != 1){
    return base * intpow(base * base, exp / 2);
  }
  else{
    return intpow(base * base, exp / 2);
  }
}

HashTable Ord = HashTable();

ulint order(ulint x, ulint n)
{
	for(ulint i=0; i<=sqrt(n); i++)
	{


    default_random_engine  e(static_cast<ulint>(time(0)));
    uniform_int_distribution<ulint> d1(1,(n-2));

	  ulint random = d1(e);

		ulint y = intpow( x, random) % n;

	 	if(Ord.check(y)==true)
	 	{
	 		ulint index = Ord.hash_function(y);


	 			if( (random) > (index) )
	 			{
	 				return (random-index);
	 			}
	 			else if( (index) > (random) )
	 			{
	 				return (index-random);
	 			}}

	 	else
	 	 {
      Ord.insert( y, random );
	 	 }
 	return n-1;
  }
}

HashTable A = HashTable();
HashTable B = HashTable();

ulint discrete(ulint x, ulint n, ulint a)
{
  default_random_engine e(static_cast<ulint> (time(0)));
  uniform_int_distribution<ulint> d1(1,(n-2));

	for(ulint i=0; i<=sqrt(n); i++)
	{
		ulint random = d1(e);

		ulint z = intpow( x, random) % n;

		ulint y = a * z;

		if(B.check(y)==true)
		{
			ulint index2 = (B.hash_function(y) - random);
      return index2;
    }
		else
		{
			A.insert( y, random );
		}

		ulint random2 = d1(e);

    z =  intpow( x, random2);

		if(A.check(z)==true)
		{
			ulint index3 = random2 - A.hash_function(z);
      cout << index3 << endl;
      return index3;
    }
		else
		{
			B.insert( y, random2);
		}
	}
}

int combine(ulint x, ulint n, ulint a)
{
  cout << x << n <<a << endl;
	ulint s = order(x , n);
  cout << s << endl;
	ulint t = discrete(x, n, a);

	ulint u = t % s;

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
		ulint x, n, a;
        stringstream(argv[1]) >> x;
        stringstream(argv[2]) >> n;
        stringstream(argv[3]) >> a;
        cout << x << n <<a << endl;
        cout << combine(x,n,a) << endl;
    }
    return 0;
}
/* Implement mc_dlog in this file */



//ulintialises table to size of  1
