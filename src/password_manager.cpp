#include "password_manager.h"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <unordered_set>
bool PasswordManager::meetsRequirements(const std::string &password) {
  bool hasUppercase{false};
  bool hasLowercase{false};
  bool hasSymbol{false};
  bool hasDigit{false};
  std::unordered_set<char> symbols{'!', '@', '#', '$', '%', '^', '&',
                                   '*', '(', ')', '-', '=', '{', '}'};
  for (auto c : password) {
    if (std::isupper(c)) {
      hasUppercase = true;
    } else if (std::islower(c)) {
      hasLowercase = true;
    } else if (symbols.find(c) != symbols.end()) {
      hasSymbol = true;
    } else if (std::isdigit(c)) {
      hasDigit = true;
    }
  }

  return hasUppercase && hasLowercase && hasSymbol && hasDigit;
}
std::string PasswordManager::generatePassword(const std::string &map,
                                              size_t passwordLength,
                                              size_t maxAttempts) {
  std::string password;
  for (size_t attempt = 0; attempt < maxAttempts; ++attempt) {
    password.clear();
    for (size_t i = 0; i < passwordLength; ++i) {
      password += map[std::rand() % map.size()];
    }
    if (meetsRequirements(password)) {
      return password; // Return the generated password if it meets the
                       // requirements
    }
  }

  return " ";
}
