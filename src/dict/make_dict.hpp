#pragma once

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>

#include <fmt/core.h>

void MakeDict(std::istream &is, std::ostream &os);

void MakeDict(const std::string &in, const std::string &out);
