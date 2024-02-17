#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <cstddef>
#include <string>
class PasswordManager {
public:
  std::string generatePassword(const std::string &map, size_t passwordLength,
                               size_t maxAttempts);
  bool meetsRequirements(const std::string &password);
};

#endif // PASSWORD_MANAGER_H
