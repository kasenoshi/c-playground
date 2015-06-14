#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

class CDemo {
    public:
        CDemo():str(NULL) {};
        ~CDemo()
        {
            if(str) delete[] str;
        };
        char *str;
};
int main(){
    CDemo d1;
    d1.str = new char[32];
    strcpy(d1.str, "trend micro");
    vector<CDemo> *a1 = new vector<CDemo>();
    a1->push_back(d1); /* do shallow copy since there's no copy constructor for CDemo, al[0].str shares the same locationwith d1.str */
    delete a1; /* also destroy d1.str */

    return EXIT_SUCCESS;
} /* since d1 is local variable, destroy d1.str again, ERROR */
