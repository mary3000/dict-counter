#include <fmt/core.h>
#include <dict/make_dict.hpp>


int main(int argc, char *argv[]) {
  const int arg_count = 2;
  if (argc != arg_count + 1) {
    throw std::runtime_error(fmt::format(
        "Wrong number of arguments, expected {}, got {}", arg_count, argc - 1));
  }

  MakeDict(argv[1], argv[2]);

  return 0;
}
