#include <iostream>

class MyClass {
public:
    MyClass() {
        m_refCount = 1;
    }

    virtual ~MyClass() {
        if (--m_refCount == 0) {
            delete m_ptr;
        }
    }

    MyClass* addRef() {
        m_refCount++;
        return this;
    }

    void release() {
        delete this;
    }

    void setValue(int value) {
        m_value = value;
    }

    int getValue() const {
        return m_value;
    }

private:
    int m_refCount;
    int m_value;
};

int main() {
    MyClass* p1 = new MyClass();
    MyClass* p2 = p1->addRef();
    MyClass* p3 = p1->addRef();

    p1->setValue(42);

    std::cout << p1->getValue() << std::endl;
    std::cout << p2->getValue() << std::endl;
    std::cout << p3->getValue() << std::endl;

    p1->release();
    p2->release();
    p3->release();

    return 0;
}