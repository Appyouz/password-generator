#include "cxxopts.hpp"
#include "password_manager.h"
#include "password_options.h"
#include <ctime>
#include <iostream>

int main(int argc, char *argv[]) {
  std::srand(static_cast<unsigned>(time(nullptr)));

  PasswordOptions passwordOptions{argc, argv};
  const size_t passwordLength =
      passwordOptions.getPasswordLength(); // Define the length of the password

  if (passwordLength < 16) {
    std::cout << "Password length less than default value. Using default "
                 "length (16).\n";
    // passwordLength = 16;
  }
  if (passwordLength >= 16) {
    std::string map = "234567890-=qwertyuiop{}asdfghjklzxcvbnm"
                      "!@#$%^&*()ASDFGHJKLQWERTYUIOPZXCVBNM";

    constexpr size_t maxAttempts =
        100; // Maximum number of attempts to generate a password

    PasswordManager passwordmanager{};
    std::string password =
        passwordmanager.generatePassword(map, passwordLength, maxAttempts);
    if (!password.empty()) {
      std::cout << "Generated password: " << password << '\n';
    } else {
      std::cerr << "Failed to generate a valid password within the maximum "
                   "number of attempts."
                << '\n';
    }
  }
  return 0;
}
