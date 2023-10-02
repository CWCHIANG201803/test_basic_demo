#include "../src/foo.h"
#include "gtest/gtest.h"
#include <tuple>

TEST(FooTests, twoSums)
{
    // arrange
    Foo foo;
    std::vector<int> nums = {2, 11, 18, 7, 15};
    int val = 13;
    std::vector<int> expected = {0, 1};

    std::vector<int> result = foo.twoSum(nums, val);

    ASSERT_EQ(result, expected);
}

class FooMultipleParametersTests : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>>
{
protected:
    Foo foo;
};

// TestFixtureName = FooMultipleParametersTests
// TestName = TwoSums
TEST_P(FooMultipleParametersTests, TwoSums)
{
    std::vector<int> nums = std::get<0>(GetParam());
    int n = std::get<1>(GetParam());

    std::vector<int> expected = std::get<2>(GetParam());
    ASSERT_EQ(expected, foo.twoSum(nums, n));
}

// INSTANTIATE_TEST_SUITE_P(InstantiationName,TestSuiteName,param_generator)
// InstantiationName = FooTwoSumTest
// TestFixtureName = FooMultipleParametersTests
// param_generator = ::testing::values
INSTANTIATE_TEST_SUITE_P(
    FooTwoSumTest,
    FooMultipleParametersTests,
    ::testing::Values(
        std::make_tuple(std::vector<int>{2, 11, 18, 7, 15}, 13, std::vector<int>{0, 1}),
        std::make_tuple(std::vector<int>{}, 0, std::vector<int>{}),
        std::make_tuple(std::vector<int>{2, 11, 18, 7, 15}, 25, std::vector<int>{2, 3}),
        std::make_tuple(std::vector<int>{2, 11, 18, 7, 15}, 0, std::vector<int>{})));

class FooTest : public testing::Test
{
public:
    Foo foo;
};

TEST_F(FooTest, FixtureTwoSums)
{
    std::vector<int> nums = {2, 11, 18, 7, 15};
    int val = 22;
    std::vector<int> expected = {3, 4};
    foo.twoSum(nums, val);
}

TEST_F(FooTest, FixtureFizzBuzz)
{
    int n1 = 3;
    std::vector<std::string> res1 = foo.fizzBuzz(n1);
    std::vector<std::string> exp1 = {"1", "2", "Fizz"};
    ASSERT_EQ(exp1, res1);

    int n2 = 5;
    std::vector<std::string> res2 = foo.fizzBuzz(n2);
    std::vector<std::string> exp2 = {"1", "2", "Fizz", "4", "Buzz"};
    ASSERT_EQ(exp2, res2);
}
