#include <dict/make_dict.hpp>
#include <gtest/gtest.h>

void CheckDict(const std::string &input, const std::string &expected_output) {
  std::istringstream in(input);
  std::ostringstream out;
  MakeDict(in, out);
  ASSERT_EQ(expected_output, out.str());
}

TEST(Dict, Simple) {
  CheckDict("aaa bbb zzz bbb aaa aaa", "3 aaa\n"
                                       "2 bbb\n"
                                       "1 zzz\n");
}

TEST(Dict, AlphabeticalOrder) {
  CheckDict("bbb ccc zzz bbb aaa ccc aaa", "2 aaa\n"
                                           "2 bbb\n"
                                           "2 ccc\n"
                                           "1 zzz\n");
}

TEST(Dict, Delimiters) {
  CheckDict("hhh    sss;ggg44364322ggg`ccc", "2 ggg\n"
                                             "1 ccc\n"
                                             "1 hhh\n"
                                             "1 sss\n");
}

TEST(Dict, CaseSensitivity) {
  CheckDict("bBB CCC zzz bbb AAA ccc aAa", "2 aaa\n"
                                           "2 bbb\n"
                                           "2 ccc\n"
                                           "1 zzz\n");
}

TEST(Dict, Empty) {
  CheckDict("", "");
}

TEST(Dict, Empty2) {
  CheckDict("546$$676><?:;|44  35242\\3454\n~234~~~~ ~~~  ", "");
}
