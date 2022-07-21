#include <iostream>

#include <queue>
#include <vector>

class Numbers
{
    private:
        std::priority_queue<int> smaller;
        std::priority_queue<int, std::vector<int>, std::greater<int>> bigger;

    public:
        Numbers() {}
        ~Numbers() {}
        void addNumber(const int& number);
        float getMedian();
};

void Numbers::addNumber(const int& number)
{
    if(smaller.empty() || smaller.top() > number)
    {
        if(!smaller.empty() && smaller.size() > bigger.size())
        {
            bigger.push(smaller.top());
            smaller.pop();
            smaller.push(number);

        } else {

            smaller.push(number);
        }

    } else {

        if(!bigger.empty() && bigger.size() > smaller.size())
        {
            smaller.push(bigger.top());
            bigger.pop();
            bigger.push(number);

        } else {

            bigger.push(number);
        }
    }
}

float Numbers::getMedian()
{
    if(smaller.empty() && bigger.empty())
        return -1;

    else if(smaller.empty() && !bigger.empty())
        return bigger.top();

    else if(!smaller.empty() && bigger.empty())
        return smaller.top();

    else if(smaller.size() == bigger.size())
        return (float)(smaller.top()+bigger.top())/2;

    else if(smaller.size() > bigger.size())
        return smaller.top();

    else
        return bigger.top();
}


int main()
{
    Numbers n;
    n.addNumber(1);
    n.addNumber(1);
    n.addNumber(1);
    n.addNumber(2);
    n.addNumber(3);
    n.addNumber(4);
    float res = n.getMedian();
    std::cout << "res = " << res << '\n';
    return 0;
}
