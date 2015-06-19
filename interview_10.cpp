#include <iostream>
#include <cstdlib>

using namespace std;

class B
{
    private:
        int data;
    public:
        B(){
            cout << "contructed by constructor" << endl;
        };
        ~B(){
            cout << "destructed by destructor" << endl;
        };
        B(int i): data(i){
            cout << "constructed by value" << endl;
        };
};
B play(B b){
    return b;
};
int main(){
    B temp = play(5); // implicitly construct B by B(5) when calling play
    return EXIT_SUCCESS;
}
