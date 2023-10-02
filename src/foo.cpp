#include "foo.h"
#include <sstream>

std::vector<int> Foo::twoSum(vector<int> &nums, int target)
{
    int N = nums.size();
    for (int i = 0; i < N; i++)
    {
        int secVal = target - nums[i];
        for (int j = 0; j < N; ++j)
        {
            if (secVal == nums[j] && secVal != nums[i])
            {
                return {i, j};
            }
        }
    }
    return {};
}

std::vector<std::string> Foo::fizzBuzz(int n)
{

    std::vector<std::string> res;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 != 0 && i % 5 != 0)
            res.push_back(std::to_string(i));
        else
        {
            std::stringstream ss;
            if (i % 3 == 0)
                ss << "Fizz";
            if (i % 5 == 0)
                ss << "Buzz";
            res.push_back(ss.str());
        }
    }
    return res;
}