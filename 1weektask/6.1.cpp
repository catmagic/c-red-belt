#include "test_runner.h"
#include <vector>
using namespace std;



template <typename T>
class Table
{
public:
    Table(size_t i,size_t j)
    {
        table.resize(i);
        for(auto & row: table)
        {
            row.resize(j);
        }
        size_.first=i;
        size_.second=j;
    }
    vector<T>& operator[](int i)
    {
        return table[i];
    }
    const vector<T> operator[](int i)const
    {
        return table[i];
    }
    void Resize(size_t i,size_t j)
    {
        table.resize(i);
        for(auto & row: table)
        {
            row.resize(j);
        }

        size_.first=i;
        size_.second=j;
    }
    pair<size_t,size_t> Size()const
    {
        return size_;
    }
    private:
    vector<vector<T>> table;
    pair<size_t,size_t> size_;
};

// Реализуйте здесь шаблонный класс Table

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
