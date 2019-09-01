//This program is compiled in c++ language...
using namespace std;
#include<iostream>
#define max 5
template<typename t>
class stack
{
public:
t data[max];
int current=0;
void push()
{
    cin>>data[current++];
}
void pop()
{
    current--;
}
void show()
{
    for(int i=0;i<current;i++)
    {
        cout<<data[i]*2<<" ";
    }
    cout<<endl;
}
};



int main()