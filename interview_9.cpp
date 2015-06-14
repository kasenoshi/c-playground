#include <iostream>
#include <string>
using namespace std;

class base{
    private:
        int m_i;
        int m_j;
    public:
        base(int i): m_j(i), m_i(m_j){}; /* initialize member list executes according to the order of member declaration, so m_i(m_j) will be executed before m_j(i) */ 
        int get_i(){return m_i;};
        int get_j(){return m_j;};
};
int main(){
    base a(89);
    cout<< a.get_i() << endl;
    cout<< a.get_j() << endl;
}
