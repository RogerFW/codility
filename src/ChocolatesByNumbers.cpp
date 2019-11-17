// https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/
// 
// Task Score: 100%
// Correctness: 100%
// Performance: 100%
// Detected time complexity: Complexity
//

// Defined in Codility Chapter 12 - Euclidean Algorithm (12.2)
long long int greatestCommonDivisor(long long int a, long long int b) {
    if ((a % b) == 0) {
        return b;
    }
    return greatestCommonDivisor(b, a%b);
}

// Defined in Codility Chapter 12 - Euclidean Algorithm (12.4)
long long int leastCommonMultiple(long long int a, long long int b) {

   return (a*b)/greatestCommonDivisor(a,b); 
}

int solution(int N, int M) {
    // Algorithm
    // Find Least Common Multiple of {N, M}
    // Answer is LCM/M
    
    long long int lcm = leastCommonMultiple(N, M);
    
    return lcm/M;
}


#include <iostream>

using namespace std;

/*
https://codility.com/demo/results/trainingJZWCZJ-WXY/
Observations:
Description has given sufficient info/hint. It even tells you "(X + M) modulo N (remainder of division)" to
remind you that M*C will eventually be greater than N. It's not used for a O(log(N+M)) solution though...
In order to achieve O(log(N+M)), we have to further examine the relationship among M, N and the result. It's
easy to realize that we will meet at an empty wrapper if and only if the index of this position is LCM(M,N).
Least Common Multiple. Then the number of chocolates we ate is lcm/M.
lcm = M * N / gcd(M, N)
chocolates = lcm / M
So put them together, we have:
chocolates = N / gcd(M, N)
You definitely want to use the expression above directly. A two step approach could introduce a potential
integer overflow.
*/
int gcd(int a, int b)
{
	if (0 == a%b)
		return b;
	return gcd(b, a%b);
}
int solutionChocolatesByNumbers(int N, int M)
{
	//M/lcm --> n/gcd
	return N / gcd(N, M);
}
