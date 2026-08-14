#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

class ZeroEvenOdd {
    private:
        enum State {
            odd_state,
            even_state
        };
        int n;

        sem_t m_zeroReady, m_zeroDone;
        mutex m_mtx; condition_variable m_cv; State m_state{State::odd_state};

    public:
        ZeroEvenOdd(int n) {
            this->n = n;
            sem_init(&m_zeroReady, 0, 1);
            sem_init(&m_zeroDone, 0, 0);
        }

        // printNumber(x) outputs "x", where x is an integer.
        void zero(function<void(int)> printNumber) {
            for (int i = 1; i <= n; ++i){
                sem_wait(&m_zeroReady);
                printNumber(0);
                sem_post(&m_zeroDone);
            }
        }

        void odd(function<void(int)> printNumber) {
            for (int i = 1; i <= n; i += 2){
                unique_lock lock(m_mtx);
                m_cv.wait(lock, [&](){return m_state == State::odd_state;});
                sem_wait(&m_zeroDone);
                printNumber(i);
                m_state = State::even_state;
                m_cv.notify_one();
                sem_post(&m_zeroReady);
            }
        }

        void even(function<void(int)> printNumber) {
            for (int i = 2; i <= n; i += 2){
                unique_lock lock(m_mtx);
                m_cv.wait(lock, [&](){return m_state == State::even_state;});
                sem_wait(&m_zeroDone);
                printNumber(i);
                m_state = State::odd_state;
                m_cv.notify_one();
                sem_post(&m_zeroReady);
            }
        }
};

int main(){
    int n = 10;
    ZeroEvenOdd* cls = new ZeroEvenOdd(n);

    thread t1 = thread(&ZeroEvenOdd::zero, cls, [](int i){cout << i;});
    thread t2 = thread(&ZeroEvenOdd::even, cls, [](int i){cout << i;});
    thread t3 = thread(&ZeroEvenOdd::odd, cls, [](int i){cout << i;});

    t1.join();
    t2.join();
    t3.join();

    return 0;
}