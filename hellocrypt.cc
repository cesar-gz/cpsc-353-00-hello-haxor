// Cesar Gutierrez
// CPSC 353-02
// 2022-07-12
// cesarg7@csu.fullerton.edu
// @cesar-gz
//
// Lab 00-00
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

  /*
  std::cout << "I have " << argc << " number of arguments.\n";
  for(int i = 0; i < argc; i++){
    std::cout << i << " : " << argv[i] << "\n";
  }
  */

  if (argc < 3) {
    std::cout << "Please provide two arguments.\n"; 
    std::cout << "The first argument is the salt defined as two ASCII characters.\n";
    std::cout << "The second argument is a word you'd like to encrypt.\n";
    std::cout << "Exiting.\n";
    return 1;
  }

  char* crypted_text = crypt(argv[1], argv[2]);
  std::cout << "The cipher text is \"" << crypted_text << "\"\n";

  return 0;
}
