#include <iostream>
#include <cstdlib>
#include <ctime>

// generate a random number in the range of [a, b)

using namespace std;

int range_rand(int a, int b){
    srand(time(NULL));
    return a + rand() % (b - a);
}

int main(int argc, char **argv){
    int a, b;
    cin >> a;
    cin >> b;
    if(a >= b)
        return 1;
    cout << range_rand(a, b) << endl;
    return 0;
}
