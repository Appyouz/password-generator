#include "password_options.h"
#include "cxxopts.hpp"
#include <iostream>
PasswordOptions::PasswordOptions(int argc, char *argv[]) {
  // Define command-line options
  cxxopts::Options options("Password Generator", "Generate Random Passwords");
  options.add_options()("l,length", "Password length",
                        cxxopts::value<size_t>()->default_value("6"));
  // Parse command-line options
  auto result{options.parse(argc, argv)};
  passwordLength = result["length"].as<size_t>();

}
size_t PasswordOptions::getPasswordLength() { return passwordLength; }
