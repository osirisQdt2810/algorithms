#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

class FizzBuzz {
    private:
        int n;

    public:
        FizzBuzz(int n) {
            this->n = n;
        }

        // printFizz() outputs "fizz".
        void fizz(function<void()> printFizz) {
            
        }

        // printBuzz() outputs "buzz".
        void buzz(function<void()> printBuzz) {
            
        }

        // printFizzBuzz() outputs "fizzbuzz".
        void fizzbuzz(function<void()> printFizzBuzz) {
            
        }

        // printNumber(x) outputs "x", where x is an integer.
        void number(function<void(int)> printNumber) {
            
        }
};
int main(){
    int n = 10;
    FizzBuzz* cls = new FizzBuzz(n);

    thread t1 = thread(&FizzBuzz::fizz, cls, [](){cout << "fizz";});
    thread t2 = thread(&FizzBuzz::buzz, cls, [](){cout << "buzz";});
    thread t3 = thread(&FizzBuzz::fizzbuzz, cls, [](){cout << "fizzbuzz";});
    thread t4 = thread(&FizzBuzz::number, cls, [](int i){cout << i;});

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}