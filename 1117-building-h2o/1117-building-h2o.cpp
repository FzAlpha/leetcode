class H2O {
private:
    int hcount;
    int ocount;
    condition_variable cv;
    mutex mtx;

public:
    H2O() {
        hcount =0;
        ocount =0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
       
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this] {return hcount<2;});
            releaseHydrogen();
            hcount++;
            if(hcount == 2 && ocount == 1){
                hcount = 0;
                ocount =0;
            }
            cv.notify_all();
        
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        
    }

    void oxygen(function<void()> releaseOxygen) {
        
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this] {return ocount<1;});
            releaseOxygen();
            ocount++;
            if(hcount == 2 && ocount == 1){
                hcount = 0;
                ocount = 0;
            }
            cv.notify_all();
        
        // releaseOxygen(); outputs "O". Do not change or remove this line.
        
    }
};