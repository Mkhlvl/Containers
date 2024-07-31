#include <gtest/gtest.h>

#include "my_containersplus.h"

TEST(my_array, test1) {
  std::array<int, 5> a;
  my::Array<int, 5> ab;
  ASSERT_TRUE(a.size() == ab.size());
}

TEST(my_array, test2) {
  my::Array<int, 6> narr = {1, 2, 3, 4, 5, 6};
  narr.at(1) = 88;
  ASSERT_EQ(narr[1], 88);
}

TEST(my_array, test3) {
  my::Array<int, 6> narr({1, 2, 3, 4, 5, 6});
  std::array<int, 6> narr_std({1, 2, 3, 4, 5, 6});
  ASSERT_TRUE(narr.front() == narr_std.front());
}

TEST(my_array, test4) {
  my::Array<int, 9> narr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 9> narr_std = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_TRUE(narr.back() == narr_std.back());
}

TEST(my_array, test5) {
  my::Array<int, 6> narr = {1, 2, 3, 4, 5, 6};
  my::Array<int, 6> new_arr(narr);
  ASSERT_EQ(new_arr[4], narr[4]);
}

TEST(my_array, test6) {
  my::Array<int, 5> arr1 = {1, 2, 3, 4, 5};
  my::Array<int, 5> arr = {5, 4, 3, 2, 1};
  arr = std::move(arr1);
  for (auto it : arr) {
    std::cout << it << " ";
  }
}

TEST(my_array, test7) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  my::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.size() == ab.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(a.at(i) == ab.at(i));
  }
}

TEST(my_array, test8) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  my::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(*a.data() == *ab.data());
}

TEST(my_array, test9) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  my::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(*a.begin() == *ab.begin());
}

TEST(my_array, test10) {
  my::Array<int, 5> ab({1, 2, 3, 4, 5});
  std::array<int, 5> a({1, 2, 3, 4, 5});
  ASSERT_TRUE(*(a.end() - 1) == *(ab.end() - 1));
}

TEST(my_array, test11) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  my::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.empty() == ab.empty());
}

TEST(my_array, test12) {
  std::array<int, 15> a;
  my::Array<int, 15> ab;
  ASSERT_TRUE(a.max_size() == ab.max_size());
  std::array<double, 6> b;
  my::Array<double, 6> ba;
  ASSERT_TRUE(b.max_size() == ba.max_size());
  std::array<std::array<int, 100>, 6> c;
  my::Array<std::array<int, 100>, 6> ca;
  ASSERT_TRUE(c.max_size() == ca.max_size());
}

TEST(my_array, test13) {
  my::Array<int, 5> a({1, 2, 3, 4, 5});
  my::Array<int, 5> b({1, 2, 3, 4, 5});
  my::Array<int, 5> c({1, 2, 3, 4, 5});
  a.swap(b);
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(c.at(i) == a.at(i));
  }
}

TEST(my_array, test14) {
  my::Array<int, 5> ab({1, 2, 3, 4, 5});
  ab.fill(88);
  for (size_t i = 0; i < ab.size(); ++i) {
    ASSERT_TRUE(ab.at(i) == 88);
  }
}

TEST(my_array, test15) {
  my::Array<int, 9> a({1, 2, 3, 4, 5, 6, 7, 8, 9});
  my::Array<int, 9> b;
  b = std::move(a);
  ASSERT_TRUE(b.size() == 9);
  for (size_t i = 0; i < b.size(); ++i) {
    ASSERT_TRUE(b.at(i) == (int)(i + 1));
  }
}

TEST(my_array, test16) {
  my::Array<int, 9> a({1, 2, 3, 4, 5, 6, 7, 8, 9});
  my::Array<int, 9> b;
  b = a;
  ASSERT_TRUE(b.size() == 9);
  for (size_t i = 0; i < b.size(); ++i) {
    ASSERT_TRUE(b.at(i) == (int)(i + 1));
  }
}

TEST(my_array, test17) {
  my::Array<int, 0> ab = {};
  ASSERT_TRUE(ab.empty() == true);
}

TEST(my_array, test18) {
  my::Array<int, 4> ab = {1, 2, 3, 4};
  ASSERT_ANY_THROW(ab.at(10));
}
