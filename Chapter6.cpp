#include <iostream>

using namespace std;

template<class T>
class compare
{
public:
    compare(T a,T b)
    {
        x=a;
        y=b;
    }
    
    T max();
private:    
    T x;
    T y;
};

template<class T>
T compare<T>::max()
{
    return x>y?x:y;
}

int main()
{
    compare<int> c1(2,5);
    cout<<c1.max()<<endl;
    compare<double> c2(2.3,5.3);
    cout<<c2.max()<<endl;
    
    cout<<endl;
    return 0;
}