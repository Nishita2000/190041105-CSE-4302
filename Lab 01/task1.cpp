#include<bits/stdc++.h>
using namespace std;
class Counter
{
private:
    int increment_step;
    int count;
public:
    Counter() : count(0){}
    void resetCount(void)
    {
        count=0;
    }
    void setIncrementStep(int step_val)
    {
        increment_step=step_val;
    }
    int getCount(void)
    {
        return count;
    }
    void increment(void)
    {
        count+=increment_step;
    }
    void print(void)
    {
        cout<<"Total Count : "<<getCount()<<endl;
    }
    ~Counter(){}

};
int main(void)
{
    int temp;
    Counter Cnt;
    Cnt.print();
    cout<<"Enter increment step : ";
    cin>>temp;
    Cnt.setIncrementStep(temp);
    cout<<"After incrementing :"<<endl;
    Cnt.increment();
    Cnt.print();
    cout<<"After incrementing :"<<endl;
    Cnt.increment();
    Cnt.print();
    Cnt.resetCount();
    cout<<"After Resetting :"<<endl;
    Cnt.print();
}
