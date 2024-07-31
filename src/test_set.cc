#include <gtest/gtest.h>

#include <cstddef>
#include <set>
#include <string>

#include "my_containers.h"

void assert_set(my::Set<double>::Iterator it,
                std::set<double>::iterator it_original) {
  my::Set<double>::NodeTree* temp = it.get_ptr();
  while (temp->left != nullptr && temp->right != nullptr) {
    ++it;
    it_original++;
  }
  EXPECT_EQ(temp->data.first, *it_original);
}

TEST(constr, test1) {
  my::Set<double> first;
  std::set<double> orig_first;
  EXPECT_EQ(first.size(), orig_first.size());
}

TEST(insert, test1) {
  my::Set<double> first;
  std::set<double> orig_first;
  first.insert(1);
  orig_first.insert(1);
  first.insert(3);
  orig_first.insert(3);
  first.insert(4);
  orig_first.insert(4);
  first.insert(3);
  orig_first.insert(3);
  first.insert(6);
  orig_first.insert(6);
  auto it = first.begin();
  std::set<double>::iterator it_original = orig_first.begin();

  assert_set(it, it_original);
}

TEST(my_set_list_initializer_check, test1) {
  my::Set<double> st({11, 22, 33, 44, 88});
  std::set<double> st_original({11, 22, 33, 44, 88});
  my::Set<double>::Iterator it = st.begin();
  std::set<double>::iterator it_original = st_original.begin();

  assert_set(it, it_original);
}

TEST(my_set_constr_copy_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  my::Set<double> st_copy = st;
  my::Set<double>::Iterator it = st_copy.begin();
  std::set<double>::iterator it_original = st_original.begin();
  assert_set(it, it_original);
}

TEST(my_set_const_iter_check, test1) {
  const my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  const std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  my::Set<double>::ConstIteratorSet it = st.begin();
  auto it_original = st_original.begin();
  EXPECT_EQ(*it, *it_original);
}

TEST(my_set_constr_move_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  my::Set<double> st_2(std::move(st));
  std::set<double> st_original_2(std::move(st_original));
  my::Set<double>::Iterator it = st_2.begin();
  std::set<double>::iterator it_original = st_original_2.begin();
  assert_set(it, it_original);
}
TEST(my_set_clear_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  st.clear();
  st_original.clear();
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(my_set_empty_check, test1) {
  my::Set<double> t;
  std::set<double> t_original;
  ASSERT_EQ(t.empty(), t_original.empty());

  t.insert(1);
  t_original.insert(1);
  ASSERT_EQ(t.empty(), t_original.empty());
}

TEST(my_set_max_size_check, test1) {
  my::Set<int> st({11, 22, 33, 44, 88});
  ASSERT_EQ(st.max_size(),
            SIZE_MAX / (sizeof(my::Set<int>::Tree::NodeTree)) / 2);
}

TEST(my_set_find_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  my::Set<double>::Iterator it = st.find(22.22);
  std::set<double>::iterator it_original = st_original.find(22.22);
  EXPECT_EQ(*it, *it_original);
}

TEST(my_set_const_find_check, test1) {
  const my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  const std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  auto it = st.find(22.22);
  auto it_original = st_original.find(22.22);
  EXPECT_EQ(*it, *it_original);
}

TEST(my_set_contains_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  ASSERT_EQ(st.contains(22.22), true);
  ASSERT_EQ(st.contains(9), false);
}

TEST(my_set_erase_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  st.erase(4);
  st_original.erase(4);
  my::Set<double>::Iterator it = st.begin();
  std::set<double>::iterator it_original = st_original.begin();
  assert_set(it, it_original);
}

TEST(my_set_swap_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  my::Set<double> st2({0.1, 0.2, 0.3});
  std::set<double> st_original2({0.1, 0.2, 0.3});
  st.swap(st2);
  st_original.swap(st_original2);
  my::Set<double>::Iterator it = st.begin();
  std::set<double>::iterator it_original = st_original.begin();
  my::Set<double>::Iterator it2 = st2.begin();
  std::set<double>::iterator it2_original = st_original2.begin();
  assert_set(it, it_original);
  assert_set(it2, it2_original);
}

TEST(my_set_merge_check, test1) {
  my::Set<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::set<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  my::Set<double> st2({44.44, 88.88, 99.99});
  std::set<double> st_original2({44.44, 88.88, 99.99});
  st.merge(st2);
  st_original.merge(st_original2);
  my::Set<double>::Iterator it = st.begin();
  std::set<double>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
}
