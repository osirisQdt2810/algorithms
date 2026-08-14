#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

class FooBar {
    private:
        enum State {
            foo_state,
            bar_state,
            unknown
        };

    private:
        int n;
        mutex m_mtx;
        atomic<State> m_currState{unknown};
        condition_variable m_cvBarReady, m_cvFooReady;

        sem_t m_fooSem, m_barSem;

    public:
        FooBar(int n) {
            this->n = n;

            sem_init(&m_fooSem, 0, 1);
            sem_init(&m_barSem, 0, 0);
        }
        
        void foo2(function<void()> printFoo) {
            for (int i = 0; i < n; i++) {
                
                // printFoo() outputs "foo". Do not change or remove this line.
                printFoo();
                m_currState.store(State::bar_state);
                m_cvBarReady.notify_one();
                unique_lock lock(m_mtx);
                m_cvFooReady.wait(lock, [&](){return m_currState == State::foo_state;});                
            }
        }

        void foo(function<void()> printFoo) {
            for (int i = 0; i < n; i++) {
                sem_wait(&m_fooSem);
                // printFoo() outputs "foo". Do not change or remove this line.
                printFoo();
                sem_post(&m_barSem);             
            }
        }

        void bar(function<void()> printBar) {
            for (int i = 0; i < n; i++) {
                sem_wait(&m_barSem);
                // printFoo() outputs "foo". Do not change or remove this line.
                printBar();
                sem_post(&m_fooSem);     
            }
        }
};


int main(){
    int n = 2;
    FooBar* cls = new FooBar(n);

    thread foo = thread(&FooBar::foo, cls, [](){printf("foo");});
    thread bar = thread(&FooBar::bar, cls, [](){printf("bar");});

    foo.join();
    bar.join();



    return 0;
}