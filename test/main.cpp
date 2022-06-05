#include <gtest/gtest.h>
#include "binary_search.hpp"
#include <algorithm>

struct Search : public testing::Test
{
    bool check_result(int *arr, int size)
    {
        int index = rand() % size;
        int result = binary_search(arr, 0, size - 1, arr[index]);
        return result == index;
    }

protected:
    int *random;
    int *asc;

    int random_size;
    int asc_size;

    bool check_result_random()
    {
        return check_result(random, random_size);
    }

    bool check_result_asc()
    {
        return check_result(asc, asc_size);
    }

    void SetUp() override
    {
        random_size = rand() % 1000;
        asc_size = rand() % 1000;
        random = new int[random_size];
        asc = new int[asc_size];

        for (int i = 0; i < random_size; i++)
        {
            random[i] = rand();
        }

        for (int i = 0; i < asc_size; i++)
        {
            asc[i] = rand();
        }
        std::sort(asc, asc + asc_size);
    }

    void TearDown() override
    {
        delete[] random;
        delete[] asc;
    }
};

TEST_F(Search, unsorted)
{
    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(check_result_random());
    }

    int result = binary_search(random, 0, random_size - 1, -1);
    EXPECT_EQ(result, -1);
}

TEST_F(Search, sorted)
{
    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(check_result_asc());
    }

    int result = binary_search(asc, 0, asc_size, -1);
    EXPECT_EQ(result, -1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
