#include "genre.h"
#include <iostream>
using namespace std;

int main() {

  Genre m1(Genre::performance);
  if (m1.to_string() != "performance") {
    cerr << "performance failed: got " << m1.to_string() << endl;
    return 1;
  }

  return 0;
}
