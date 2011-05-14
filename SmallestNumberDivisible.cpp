#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>

using namespace std;

/*       Function Prototypes       */
void NumOfPrimes(float numOfInts, vector<float>* ints);
float PrimeFactor(float numOfInts, vector<float>* pow, vector<float>* ints);

/*********************************************************
 ** Input Arguments: numOfInt (Int)                     **
 ** Output Variable: SmallestValue (Int)                **
 ** Calling Methods: NumOfPrimes                        **
 **                                                     **
 **                                                     **
 **                                                     **
 ** Purpose: This is the main program. It will call     **
 **          all of the other programs in order to      **
 **          to determine the smallest number that      **
 **          is divisible by all integers ranging       **
 **          from 1 to n, where n represents a value    **
 **          that is stored in numOfInt and is recieved **
 **          via keyboard from the user.                **
 *********************************************************/

int main()
{
	// This variable holds the number that is input by the user and
	// represents the the largest value that is going to divide
	// into our final number
	float numOfInt;

	// This variable holds the number of prime numbers that exist up
	// to the square root of the numOfInt value
	float numOfPrimeNumbers;


	cout << "Please enter an integer greater than 1" << endl;

	cin >> numOfInt;
	
	vector<float> integers;
	vector<float>* ints = &integers;

	vector<float> powers;
	vector<float>* pows = &powers;
	
	float answer = 0.0;
	
	NumOfPrimes( numOfInt, ints);
	cout << "This is inbetween NumOfPrimes and PrimeFactor" << endl;	

	answer = PrimeFactor(numOfInt, pows, ints);
	return 0;
}

/*********************************************************
 ** Input Arguments:  numOfInt (float)                  **
 **		      ints (vector<float>)              **
 ** Output Variables: None                              **
 ** Calling Methods:  None                              **
 **							**			
 **    						        **	
 **						        **
 ** Purpose: This method will search from 1 to n and    **
 **          return a list containing all of the primes **
 **          up to n using the Sieve of Eratosthenes    **
 **          algorithm.					**		
 **							**
 *********************************************************/
void NumOfPrimes( float numOfInts, vector<float>* ints) {

	// This loop fills the array ints with all numbers from
	// 1 to numOfInt
	for ( int i = 1; i<=numOfInts; i++)
	{
		ints->push_back(i);
		
	}

	// This loop removes all non-primes from
	// the  numOfInt
	for (float j = 2; j<= numOfInts; j++) {
		float k = j + j;
		for (k; k<= numOfInts; k=k+j) {			
				ints->at(k-1) = 0;			
		}
	}
	
	vector<float> primeshere;
	vector<float>* primes = &primeshere;
	int k = 0;

	// This loop assigns all of the primes in order
	// to the primeshere vector.
	for (float i = 0; i<numOfInts; i++) {
		if (ints->at(i) != 0) {
		primes->push_back(ints->at(i));
		k++;
		} 
	}

	// This loop prints primeshere out
	// uncomment to print out the primes
	//for (float i = 0; i<k; i++) {
	//	cout << primes->at(i) << endl;
	//}
	return;
}
/*********************************************************/

/*********************************************************
 ** Input Variables: numOfInt (float)  			**
 ** 		     pows (vector<float>*)		**
 **  		     ints (vector<float>*)		**
 ** Output Variables: answer (float)			**
 ** Calling Methods: none				**
 ** 							**
 ** This method will go through each number 1 - n and   **
 ** find the prime factors of each number. If there are **
 ** more prime numbers in one number from 1 - n than in **
 ** another number, that number is placed in pows       **
 ** instead. e.g. 4 has 2-twos but 8 has 3 therefore    **
 ** 3 will be stored in the twos place of pows instead  **
 ** of 2 or 5. After the maximum number of primes are   **
 ** placed in the pows vector, they are all multiplied  **
 ** together and that is the answer. The smallest       **
 ** number divisible by 1 - n.                          **
 ** 							**
 *********************************************************/
float PrimeFactor(float numOfInt, vector<float>* pows, vector<float>* ints) 
{
	// This holds the answer in the form of a float
	float answer = 1;
	// This vector of floats holds the number of each digits power
    	// to test against the power vector.
	vector<float> test;
	// This loop initializes the test and pow* vectors with 0
	for (int n = 0; n <= ints->size(); n++) 
	{
		test.push_back(0);
		pows->push_back(0);
	}
	for (int i = 0; i < ints->size(); i++) {
	cout << "ints " << ints->at(i) << endl;
	}
	// This loop moves from 2 to n
        for (int i = 1; i <= numOfInt; i++) 
	{
		
		// This sets k = to i so k can be manipulated without
 		// changing i
		float k = i;
		// 
		// This loop finds the prime factors for each number i
		for (int j = 1; j < ints->size(); j++) 
		{
			cout << "j is: " << j << "and ints is: " << ints->at(j) << endl;
			if (ints->at(j) != 0) 
			{
				// determines if k % ints->at(j) = 0
				if ( fmodf(k, ints->at(j)) == 0)
				{
					// Increase the power number at test(j)
					test.at(j)++;
					// decrease k by the prime factor
					k = k/ints->at(j);
					// start back at the prime factor 2 and 
					// reiterate
					j = 0;
				}
			} 
		}
		// This loop sets the new power
		for (int j = 1; j < ints->size(); j++)
		{
			if (test.at(j) > pows->at(j))
			{
				pows->at(j) = test.at(j);
			}	
		test.at(j) = 0;	
		}		
	}
	// This loop displays the power at each int
	for (int j = 0; j < ints->size(); j++) 
	{
		if (ints->at(j) != 0) {
			float a = ints->at(j);
			answer = answer * pow(a, pows->at(j) );
		}
	}
	cout.precision(0);	
	cout << fixed << answer << endl;
	return answer;
}
