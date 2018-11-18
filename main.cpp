#include <iostream>

template <class T>
struct Pair{
  T first;
  T second;
};

Pair<float> solveNonLinEq(Pair<float> init, Pair<float> (*func)(Pair<float>),const float eps)
{
    unsigned counter=0;
    Pair<float> next=init;
    do{
        next=func(init);
        if (abs(next.first-init.first)<eps && abs(next.second-init.second)<eps){
            std::cout<<"solved at "<<counter<<" steps\n";
            return next;
        }
        init=next;

    }while(++counter<1000);
    std::cout<<"didn't solve at 1000 steps";
    return next;
}

Pair<float> func(Pair<float> pars)
{
    float x=pars.first;
    float y=pars.second;
    x=1-cos(y-1);
    y=0.5*(1.6-sin(x));
    Pair<float> next;
    next.first=x;
    next.second=y;
    return next;
}

int main()
{
    Pair<float> init;
    float eps=1.e-4;
    Pair<float> d;
    d=solveNonLinEq(init, func, eps);
    std::cout<<"x="<<d.first<<"  y="<<d.second<<"\n";
    // test
    std::cout<<"test\n";
    std::cout<<sin(d.first)+2*d.second-1.6<<"\n";
    std::cout<<cos(d.second-1)+d.first-1<<"\n";
    return 0;
}
