class ZeroEvenOdd {
private:
    int n;
    int state;
    condition_variable cv;
    mutex mtx;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        state = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return state == 0; }); 
            printNumber(0);
            if (i % 2 == 0) {
                state = 2;
            } else {
                state = 1;
            }

            cv.notify_all();
        }
        
    }

    void even(function<void(int)> printNumber) { 
        for (int i = 2; i <= n; i+=2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return state == 2; });
            printNumber(i);
            state =0; 

            cv.notify_all();
        } 
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+=2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return state == 1; });
            printNumber(i);
            state =0; 

            cv.notify_all();
        }
    }
};