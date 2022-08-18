#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>

#include <fmt/core.h>
#include <dict/make_dict.hpp>

void MakeDict(std::istream &is, std::ostream &os) {
  std::string line;

  std::unordered_map<std::string, uint64_t> dict;

  if (!is.eof()) {
    while (std::getline(is, line)) {
      std::regex e("[^a-zA-Z]+");
      std::regex_token_iterator<std::string::iterator> i(line.begin(),
                                                         line.end(), e, -1);
      std::regex_token_iterator<std::string::iterator> end;
      while (i != end) {
        std::string str = *i++;
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        dict[str]++;
      }
    }

    struct Token {
      std::string word;
      uint64_t count;

      Token(std::string word_, uint64_t count_)
          : word(std::move(word_)), count(count_) {}

      bool operator<(const Token &other) const {
        return count > other.count ||
               (count == other.count && word < other.word);
      }
    };

    std::vector<Token> tokens;
    tokens.reserve(dict.size());
    for (auto &[word, count] : dict) {
      if (word.empty()) {
        continue;
      }
      tokens.emplace_back(word, count);
    }

    std::sort(tokens.begin(), tokens.end());

    for (auto &token : tokens) {
      os << token.count << " " << token.word << std::endl;
    }
  } else {
    throw std::runtime_error("Couldn't open the file");
  }
}

void MakeDict(const std::string &in, const std::string &out) {
  std::ifstream ifs(in, std::ifstream::in);
  std::ofstream ofs(out, std::ifstream::out);
  MakeDict(ifs, ofs);
}
