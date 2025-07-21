#include <iostream>
#include <memory>

using namespace std;

template <class T>
class myUniquePtr{
    T* ptr;
public:
    explicit myUniquePtr(T* p = nullptr){
        cout<<"myUniquePtr()\n";
        ptr = p;
    }

    myUniquePtr(const myUniquePtr&)=delete;
    myUniquePtr& operator=(const myUniquePtr&) = delete;

    myUniquePtr(myUniquePtr&& obj){  //move copy ctor (move semantic)
        cout<<"move copy ctor called\n";
        this->ptr=obj.ptr;
        obj.ptr=nullptr;
    }

    myUniquePtr& operator=(myUniquePtr&& obj){  //move assignment
        cout<<"move assignement called\n";
        if(&obj != this){
            if(this->ptr !=nullptr) // already having some resource
                delete this->ptr;
            this->ptr=obj.ptr;
            obj.ptr=nullptr;

        }
        return *this;
    }

    T& operator*(){return *ptr;}
    T* operator->(){return ptr;}

    ~myUniquePtr(){
        delete[] ptr;
        cout<<"~myUniquePtr()\n";
    }
};

class Emp{
public:
    void show(){cout<<"Emp::Show()\n";}
};


int main(){
    
    // myUniquePtr<int> ptr(new int);  //myUniquePtr<int> ptr= new int;    //it wont work as using explicit keyword with ctor
    // *ptr=10;

    // cout<<*ptr<<endl;

    myUniquePtr<Emp> ptr1(new Emp);
    myUniquePtr<Emp> ptr2 = move(ptr1);
    myUniquePtr<Emp> ptr3;
    ptr3 = move(ptr2);
    ptr3->show();

    // unique_ptr<Emp> ptr1(new Emp);
    // unique_ptr<Emp> ptr2;
    // ptr2 = move(ptr1);
    // ptr2->show();

return 0;
}