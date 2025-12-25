class Foo {
private: 
    mutex mtx;
    condition_variable cv;
    int state = 0;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] {return state == 1;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] {return state == 2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};