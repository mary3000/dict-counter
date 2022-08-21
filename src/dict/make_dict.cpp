#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>

#include <fmt/core.h>
#include <dict/make_dict.hpp>

void MakeDict(std::istream& is, std::ostream& os) {
  std::string line;

  std::unordered_map<std::string, uint64_t> dict;

  if (!is.eof() && !is.bad()) {
    while (std::getline(is, line)) {
      std::transform(line.begin(), line.end(), line.begin(),
                     [](unsigned char c) { return std::tolower(c); });
      std::string token;
      for (char c : line) {
        if (!isalpha(c)) {
          if (!token.empty()) {
            dict[token]++;
            token = "";
          }
        } else {
          token += c;
        }
      }
      if (!token.empty()) {
        dict[token]++;
      }
    }

    struct Token {
      std::string word;
      uint64_t count;

      Token(std::string word_, uint64_t count_)
          : word(std::move(word_)), count(count_) {
      }

      bool operator<(const Token& other) const {
        return count > other.count ||
               (count == other.count && word < other.word);
      }
    };

    std::vector<Token> tokens;
    tokens.reserve(dict.size());
    for (auto& [word, count] : dict) {
      if (word.empty()) {
        continue;
      }
      tokens.emplace_back(word, count);
    }

    std::sort(tokens.begin(), tokens.end());

    for (auto& token : tokens) {
      os << token.count << " " << token.word << std::endl;
    }
  } else {
    throw std::runtime_error("Couldn't open the file");
  }
}

void MakeDict(const std::string& in, const std::string& out) {
  std::ifstream ifs(in, std::ifstream::in);
  std::ofstream ofs(out, std::ifstream::out);
  MakeDict(ifs, ofs);
}
