#include <vector>
#include <string>
struct Node
{
    int prev_num;
    char operation;
    int following_num;
};
template <typename T>
class iterable
{
private:
    std::vector<T> vect;

public:
    iterable(std::vector<T> vect)
    {
        this->vect = vect;
    }
    bool contains(T t)
    {
        for (auto i = vect.begin(); i != vect.end(); i++)
        {
            if (*i == t)
            {
                return true;
            }
        }
        return false;
    }
};

std::vector<char> num_vector = {
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
};
std::vector<char> space_vector = {
    ' ',
    '\t',
    '\n',
    '\0',
};
std::vector<char> operator_vector = {
    '+',
    '-',
    '*',
    '/',
};
