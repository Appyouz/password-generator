#include "password_manager.h"
#include <iostream>
#include <ctime>
int main(int argc, char *argv[]) {
  std::srand(static_cast<unsigned>(time(nullptr)));

  std::string map = "234567890-=qwertyuiop{}asdfghjklzxcvbnm"
                    "!@#$%^&*()ASDFGHJKLQWERTYUIOPZXCVBNM";

  constexpr size_t passwordLength = 16; // Define the length of the password
  constexpr size_t maxAttempts =
      100; // Maximum number of attempts to generate a password

  PasswordManager passwordmanager{};
  std::string password = passwordmanager.generatePassword(map, passwordLength, maxAttempts);
  if (!password.empty()) {
    std::cout << "Generated password: " << password << '\n';
  } else {
    std::cerr << "Failed to generate a valid password within the maximum "
                 "number of attempts."
              << '\n';
  }

  return 0;
}
