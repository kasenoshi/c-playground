struct Test
{
    Test (int){};
    Test (){};
    void fun(){};
};
int main(){
    Test a(1);
    a.fun();
    Test b(); /* compiler will think this is a function declaration returns b */
    //Test b; /* use this instead */
    b.fun();
}
