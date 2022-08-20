#include <chrono>

#include <fmt/core.h>
#include <dict/make_dict.hpp>

int main(int argc, char* argv[]) {
  const int arg_count = 2;
  if (argc != arg_count + 1) {
    throw std::runtime_error(fmt::format(
        "Wrong number of arguments, expected {}, got {}", arg_count, argc - 1));
  }

  auto start = std::chrono::system_clock::now();
  MakeDict(argv[1], argv[2]);
  auto end = std::chrono::system_clock::now();

  std::cout
      << "Elapsed "
      << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
      << " s" << std::endl;

  return 0;
}
