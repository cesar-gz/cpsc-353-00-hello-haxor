// Tuffy Titan
// CPSC 353-01
// 2021-06-04
// tuffy.titan@csu.fullerton.edu
// @tuffytitan
//
// Assignment 00
//
// Demonstrate the traditional use of crypt.
//

#include <cstdlib>
#include <iostream>
#include <string>

#if defined(__linux__)
#include <crypt.h>
#elif defined(__FreeBSD__)
#include <unistd.h>
#elif defined(__APPLE__) && defined(__MACH__)
#include <unistd.h>
#else
#pragma message("Missing header for crypt().")
#endif

#if defined(_WIN32) || defined(_WIN64)
#pragma message("Windoze is not supported.")
#endif

/// Demonstrate the traditional use of
/// [crypt](https://en.wikipedia.org/wiki/Crypt_(C))
/// which implements
/// [DES](https://en.wikipedia.org/wiki/Data_Encryption_Standard).
/// Given a user provided salt and clear text, use crypt and print
/// the cipher text.

/// professor wants us to stick to C strings, and not C++ strings
/// man crypt
/// is a manual page for crypt code

int main(int argc, char const* argv[]) {

  if(argc < 3){
    std::cout << "You need to provide two arguments.\n";
    std::cout << "The first is the password\n";
    std::cout << "The second is the salt expressed as two letters.\n";
    return 1;
  }

  std::cout << "I have " << argc << " number of arguments.\n";
  for(int i = 0; i < argc; i++){
    std::cout << i << " : " << argv[i] << "\n";
  }

  //char *crypted_text = crypt("foo", "aa");
  //std::cout << crypted_text << "\n";

  char *crypted_text = crypt(argv[1], argv[2]);
  std::cout << crypted_text << "\n";

  return 0;
}
