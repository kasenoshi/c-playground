#include <iostream>

using namespace std;

class parent{
    public:
        void func1(){
            cout << "parent func 1" << endl;
        }
        virtual void func2(){
            cout << "parent func 2" << endl;
        }
};
class child: public parent{
    public:
        void func1(){
            cout << "child func 1" << endl;
        }
        virtual void func2(){
            cout << "child func 2" << endl;
        }
};

int main(){
    parent *p = new parent();
    parent *c = new child(); 
    child *c2 = (child*)p;
    p->func1();
    p->func2();
    c->func1();
    c->func2(); //override
    c2->func1();
    c2->func2();//no override, still point to parent.func2()
}
