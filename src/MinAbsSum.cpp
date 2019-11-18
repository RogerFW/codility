// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <numeric>
#include <climits>
#include <stdlib.h>
#include <cmath>
#include <bitset>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int N = A.size();
    std::for_each(A.begin(), A.end(), [](int &n){ n = abs(n); });
    //get the sum
    //if(A.size() < 1)
    //   return 0;
    //if(A.size() < 2)
    //   return A[0];
    int sum = std::accumulate(A.begin(), A.end(), 0);
    //cout << sum << endl;
    //for(int i)
    //create container for possible values
    int lowest_max_sum = sum;
    //int S[A.size()] = {1};
    for(int i = 0;i < pow(2, N);i++)
    {
        //cout << i << endl;
        std::string binary = std::bitset<32>(i).to_string();
        //cout << binary.substr(32-A.size(), 32) << endl;
        std::string sub_bin = binary.substr(32-A.size(), 32);
        int total = 0;
        for(int j = 0;j < N;j++)
        {
            if(sub_bin[j] == '0')
               total = total-A[j];
            else
               total = total+A[j];
        }
        if(abs(total) < lowest_max_sum)
        {
            lowest_max_sum = abs(total);
        }
    }
    return lowest_max_sum;
    /*for(int i = 0;i < A.size();i++)
    {
        if((S[i] == 1)&&((sum - 2*A[i]) > 0)
        {
            lowest_max_sum = min(lowest_max_sum, sum - 2*A[i])
        }
    }
    return lowest_max_sum;*/
}
