#include "iterable.h"
#include <iostream>

int present_at_index(std::vector<Node> node_vct, char target)
{
    for (int i = 0; i < node_vct.size(); ++i)
    {
        if (node_vct.at(i).operation == target)
        {
            return i;
        }
    }
    return -1;
}
int solve_equation(std::vector<Node> node_vct)
{
    int result = 0;
    while (node_vct.size() != 0)
    {
        if (present_at_index(node_vct, '*') != -1)
        {
            int index = present_at_index(node_vct, '*');
            auto it{node_vct.begin() + index};
            Node tmp_node = node_vct.at(index);
            result = tmp_node.prev_num * tmp_node.following_num;
            if (index == 0)
            {
                node_vct[index + 1].prev_num = result;
            }
            if (index == node_vct.size() - 1)
            {
                node_vct[index - 1].following_num = result;
            }
            else
            {
                node_vct[index - 1].following_num = result;
                node_vct[index + 1].prev_num = result;
            }
            node_vct.erase(it);
        }
        else if (present_at_index(node_vct, '/') != -1)
        {
            int index = present_at_index(node_vct, '/');
            auto it{node_vct.begin() + index};
            Node tmp_node = node_vct.at(index);
            result = tmp_node.prev_num / tmp_node.following_num;
            if (index == 0)
            {
                node_vct[index + 1].prev_num = result;
            }
            if (index == node_vct.size() - 1)
            {
                node_vct[index - 1].following_num = result;
            }
            else
            {
                node_vct[index - 1].following_num = result;
                node_vct[index + 1].prev_num = result;
            }
            node_vct.erase(it);
        }
        else if (present_at_index(node_vct, '-') != -1)
        {
            int index = present_at_index(node_vct, '-');
            auto it{node_vct.begin() + index};
            Node tmp_node = node_vct.at(index);
            result = tmp_node.prev_num - tmp_node.following_num;
            if (index == 0)
            {
                node_vct[index + 1].prev_num = result;
            }
            if (index == node_vct.size() - 1)
            {
                node_vct[index - 1].following_num = result;
            }
            else
            {
                node_vct[index - 1].following_num = result;
                node_vct[index + 1].prev_num = result;
            }
            node_vct.erase(it);
        }
        else if (present_at_index(node_vct, '+') != -1)
        {
            int index = present_at_index(node_vct, '+');
            auto it{node_vct.begin() + index};
            Node tmp_node = node_vct.at(index);
            result = tmp_node.prev_num + tmp_node.following_num;
            if (index == 0)
            {
                node_vct[index + 1].prev_num = result;
            }
            if (index == node_vct.size() - 1)
            {
                node_vct[index - 1].following_num = result;
            }
            else
            {
                node_vct[index - 1].following_num = result;
                node_vct[index + 1].prev_num = result;
            }
            node_vct.erase(it);
        }
    }
    return result;
}
int main()
{
    iterable<char> num_iterable = iterable<char>(num_vector);
    iterable<char> space_iterable = iterable<char>(space_vector);
    iterable<char> operator_itr = iterable<char>(operator_vector);
    std::vector<int> iv;
    std::vector<char> cv;
    std::vector<Node> node_vector;
    std::string str1, str2;
    std::cout << "Enter: ";
    std::getline(std::cin, str1);
    for (auto it = str1.begin(); it <= str1.end(); it++)
    {
        if (num_iterable.contains(*it))
        {
            str2.push_back(*it);
        }

        else if (space_iterable.contains(*it) || operator_itr.contains(*it) && !str2.empty())
        {
            if (operator_itr.contains(*it))
            {
                iv.push_back(std::stoi(str2));
                str2.clear();
                cv.push_back(*it);
            }
            else
            {
                iv.push_back(std::stoi(str2));
                str2.clear();
            }
        }
        else if (operator_itr.contains(*it))
        {
            cv.push_back(*it);
        }
    }

    for (int i = 0; i < cv.size(); ++i)
    {
        Node node = {iv.at(i), cv.at(i), iv.at(i + 1)};
        node_vector.push_back(node);
    }
    std::cout << solve_equation(node_vector);
    // get_index(node_vector);
}