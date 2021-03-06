#include <iostream>
#include <vector>
using namespace std;

namespace outer{
    vector<long int> cache;
    long int memoizationFib(int totalFibNumbers){
        for (int i = 0; i <= totalFibNumbers; i++){
            cache.push_back(0);
        }
        struct {
            long int operator()(int n){
                if (cache[n] == 0){
                    if (n == 0){
                        outer::cache[n] = 0; 
                    } else if (n == 1){
                        outer::cache[n] = 1;
                    }else {
                        outer::cache[n] = (*this)(n-1) + (*this)(n-2);
                    }
                }
                return outer::cache[n];
            }
        } innerMemoizationFib;

    return innerMemoizationFib(totalFibNumbers);
    }
};

// namespace outer{
//     vector<long int> cache;
//     long int memoizationFib(int totalFibNumbers){
//         for (int i = 0; i <= totalFibNumbers; i++){
//             cache.push_back(0);
//         }
//         struct innerFunction {
//             static long int innerMemoizationFib(int n){
//                 if (cache[n] == 0){
//                     if (n == 0){
//                         outer::cache[n] = 0;
//                     } else if (n == 1){
//                         outer::cache[n] = 1;
//                     }else {
//                         outer::cache[n] = innerMemoizationFib(n-1) + innerMemoizationFib(n-2);
//                     }
//                 }
//                 return outer::cache[n];
//             }
//         };

//     return innerFunction::innerMemoizationFib(totalFibNumbers);
//     }
// };

int main(){
    cout << outer::memoizationFib(50) << endl;
    return  0;
}
