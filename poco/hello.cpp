#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"
#include <iostream>

using Poco::BasicEvent;
using Poco::delegate;
//https://pocoproject.org/docs/00100-GuidedTour.html
class Source
{
public:
    BasicEvent<int> theEvent;

    void fireEvent(int n)
    {
        theEvent(this, n);
    }
};

class Target
{
public:
    void onEvent(const void* pSender, int& arg)
    {
        std::cout << "onEvent: " << arg << std::endl;
    }
};

int main(int argc, char** argv)
{
    Source source;
    Target target1, target2;

    source.theEvent += delegate(&target1, &Target::onEvent);
    source.theEvent += delegate(&target2, &Target::onEvent);

    source.fireEvent(42);
    source.fireEvent(23);

    source.theEvent -= delegate(&target1, &Target::onEvent);
    source.theEvent -= delegate(&target2, &Target::onEvent);

    source.fireEvent(42);

    return 0;
}