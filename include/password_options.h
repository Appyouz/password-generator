#ifndef PASSWORD_OPTIONS_H
#define PASSWORD_OPTIONS_H
#include <cstddef>
class PasswordOptions {
public:
  PasswordOptions(int argc, char* argv[]);

  size_t getPasswordLength();

private:
  std::size_t passwordLength{};
};

#endif // PASSWORD_OPTIONS_H
