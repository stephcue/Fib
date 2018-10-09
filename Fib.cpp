#include <iostream> // CPE major
#include <math.h>
using namespace std;

bool IsFib(long int num);
bool is_fibonnaci_array(long int array[], int size);

int main()
{
	long int tst[5]={6, 13, 21, 34, 55};
	bool allFib = is_fibonnaci_array(tst, 5);
	if (allFib){
		cout<<"The array contains all Fibonacci numbers"<<endl;
	} // end if
	else {
		cout<<"The array does not contain all Fibonacci numbers"<<endl;
	} // end else
	return 0;
} // end main

bool is_fibonnaci_array(long int array[], int size)
{
	 if (size == 0) return false;
    int maxValue = array[0];
    for (int i = 1; i < size; i++)
    {
		if (array[i] > maxValue){ maxValue = array[i];} // end if
    } // end for
    int first = 0;
    int second = 1;
    while (second < maxValue)
    {
        for (int i = 0; i < size; i++)
        {
			if (array[i] == first){ return true;} // end if
			if (array[i] == second){ return false;} // end if
        } // end for
        first = first + second;
        second = second + first;
    } // end while

    return false;
} // end is_fibonnaci_array

bool IsFib(long int num)
{
	double root5 = sqrt(5);
	double phi = (1 + root5)/2;

	long int idx = floor(log(num*root5)/log(phi)+0.5);
	long int u = floor(pow(phi, idx)/root5 +0.5);
	return (u == num);
} // end IsFib

