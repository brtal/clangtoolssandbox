#include <iostream>
#include <memory>
#include <vector>

void TakeVector1(std::vector<int> vec)
{
    // expected: probably nothing
    // actual  : (nothing)

    static constexpr int magicvalue = 10;
    vec.push_back(magicvalue);

    for (auto v : vec)
    {
        std::cout << v << std::endl;
    }
}

void TakeVector2(std::vector<int> vec)
{
    // expected: use std::move when assigning vec to vec2
    // actual  : warning: parameter 'vec' is passed by value
    //           and only copied once; consider moving it to 
    //           avoid unnecessary copies
    //           [performance-unnecessary-value-param]

    auto vec2 = vec;

    static constexpr int magicvalue = 10;
    vec2.push_back(magicvalue);

    for (auto v : vec2)
    {
        std::cout << v << std::endl;
    }
}

void TakeVector3(std::vector<int> vec)
{
    // expected: pass vec by const ref
    // actual  : the parameter 'vec' is copied for each
    //           invocation but only used as a const reference;
    //           consider making it a const reference
    //           [performance-unnecessary-value-param]

    for (auto v : vec)
    {
        std::cout << v << std::endl;
    }
}


void TryTidyCopies()
{
    {
        // expected: don't copy v
        // actual  : (nothing)
        std::vector<int> v({ 1, 2, 3 });
        TakeVector1(v);
    }

    {
        // expected: don't copy v
        // actual  : (nothing)
        std::vector<int> v({ 1, 2, 3 });
        TakeVector2(v);
    }

    {
        // expected: probably nothing if advice from TakeVector3 is taken
        // actual  : (nothing)
        std::vector<int> v({ 1, 2, 3 });
        TakeVector3(v);
    }
}
