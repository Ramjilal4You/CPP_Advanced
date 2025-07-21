#include <iostream>
#include <memory>

using namespace std;

template <class T>
class mySharedPtr{
    T* ptr;
    size_t* counter;
public:
    mySharedPtr(T* p = nullptr){
        cout<<"mySharedPtr()\n";
        ptr = p;
        counter = new size_t(1);
    }

    mySharedPtr(mySharedPtr& obj){
        cout<<"copy ctor called\n";
        this->ptr=obj.ptr;
        this->counter=obj.counter;
        (*this->counter)++;
    }

    //move copy ctor
    mySharedPtr(mySharedPtr&& obj){
        cout<<"move copy ctor called\n";
        this->ptr=obj.ptr;
        this->counter=obj.counter;
        obj.ptr=nullptr;    //as ownership transfered to this ptr
        obj.counter=nullptr;
    }

    //copy assignment operator
    mySharedPtr& operator=(mySharedPtr&obj){    
        cout<<"assignment operator called\n";
        if(&obj != this){
            // if target pointer alraedy points to the some other location
            if(this->ptr!=nullptr){
                (*this->counter)--;
                cleanUp();  //if counter is 0 then, resource wll be deleted
            }

            this->ptr=obj.ptr;
            this->counter=obj.counter;
            (*obj.counter)++;
        }
        return *this;
    }

    mySharedPtr& operator=(mySharedPtr&& obj){
        cout<<"move assignment operator called\n";
        if(&obj != this){
            // if target pointer alraedy points to the some other location
            if(this->ptr!=nullptr){
                (*this->counter)--;
                cleanUp();  //if counter is 0 then, resource wll be deleted
            }

            //apply move semantic rule
            this->ptr=obj.ptr;
            obj.ptr=nullptr;

            this->counter=obj.counter;  //no need to increament or decreament counter here
            obj.counter=nullptr;
        }
        return *this;
    }

    T& operator*(){return *ptr;}
    T* operator->(){return ptr;}
    size_t use_count(){return counter==nullptr?0:*counter;}

    ~mySharedPtr(){
        cout<<"~mySharedPtr() : ";
        if(this->counter!=nullptr)
            *counter=0;

        cleanUp();
    }

    void cleanUp(){
        //delete resource if counter is 0
        if(this->counter!=nullptr && *counter==0){
            delete ptr;
            delete counter;
            cout<<" deleted\n";
        }
        else
            cout<<"already deleted\n";
    }
};


class Emp{
public:
    Emp(){cout<<"Emp ctor called\n";}
    ~Emp(){cout<<"Emp dtor called\n";}
    void show(){cout<<"Emp::Show()\n";}
};


int main(){  
    //shared pointer

    // shared_ptr<Emp> ptr1(new Emp);
    // shared_ptr<Emp> ptr2, ptr3, ptr4=ptr1;
    // ptr3=ptr4;
    // ptr2 = move(ptr1);
    // ptr2->show();
    // shared_ptr<Emp> ptr5(new Emp);
    // cout<<ptr2.use_count()<<endl;
    // cout<<ptr1.use_count()<<endl;
    // cout<<ptr3.use_count()<<endl;
    // cout<<ptr4.use_count()<<endl;
    // cout<<ptr5.use_count()<<endl;


    // mySharedPtr<Emp> ptr1(new Emp);
    // mySharedPtr<Emp> ptr2, ptr3, ptr4=ptr1;
    // ptr3=ptr4;
    // ptr2 = move(ptr1);
    // ptr2->show();
    // mySharedPtr<Emp> ptr5(new Emp);
    // cout<<ptr2.use_count()<<endl;
    // cout<<ptr1.use_count()<<endl;
    // cout<<ptr3.use_count()<<endl;
    // cout<<ptr4.use_count()<<endl;
    // cout<<ptr5.use_count()<<endl;


    // shared_ptr<Emp> ptr1(new Emp);
    // shared_ptr<Emp> ptr2=ptr1;
    // ptr1=ptr2;
    // shared_ptr<Emp> ptr3(new Emp);
    // ptr2=move(ptr3);

    // cout<<ptr1.use_count()<<endl;
    // cout<<ptr2.use_count()<<endl;
    // cout<<ptr3.use_count()<<endl;

    mySharedPtr<Emp> ptr1(new Emp);
    cout<<ptr1.use_count()<<endl;
    mySharedPtr<Emp> ptr3(new Emp);
    ptr1=move(ptr3);

    cout<<ptr1.use_count()<<endl;
    cout<<ptr3.use_count()<<endl;

    mySharedPtr<Emp> ptr4 = move(ptr1);
    cout<<ptr1.use_count()<<endl;
    cout<<ptr4.use_count()<<endl;

return 0;
}