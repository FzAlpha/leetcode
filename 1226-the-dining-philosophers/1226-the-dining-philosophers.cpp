class DiningPhilosophers {
private:
    mutex forks[5];
    mutex waiter;
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher+1)%5;
        unique_lock<mutex> lock(waiter);
        forks[left].lock();
        pickLeftFork();
        forks[right].lock();
		pickRightFork();
        
        eat();
        putLeftFork();
        forks[left].unlock();
        putRightFork();
        forks[right].unlock();
    }
};