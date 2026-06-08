class FooBar {
private:
    int n;
    bool islastfoo;
    condition_variable cv;
    mutex mtx;

public:
    FooBar(int n) {
        this->n = n;
        islastfoo = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return !islastfoo;});

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            islastfoo = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock , [this]{return islastfoo;});
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            islastfoo = false;
            cv.notify_all();

        }
    }
};