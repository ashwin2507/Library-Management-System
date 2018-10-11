#include "publication.h"
#include "patron.h"
#include <iostream>
using namespace std;

int main() {
  string expected = "\"The Firm\" by John Grisham, 1991 (adult fiction book) ISBN: 0440245923";
  string expected_co = "\"The Firm\" by John Grisham, 1991 (adult fiction book) ISBN: 0440245923\nChecked out to Professor Rice (817-555-1212)";

  string name = "Professor Rice";
  string number = "817-555-1212";

  Patron patron(name, number);

  bool passed = true;

  //
  // Test constructor
  //

  Publication publication(
     "The Firm", 
     "John Grisham", 
     "1991", 
     Genre::fiction,
     Media::book,
     Age::adult,
     "0440245923"
  );

  if (publication.to_string() != expected) {
    cerr << "Constructor fail: got '" << publication.to_string() 
         << "' but expecting '" << expected << "'" << endl;
    passed = false;
  }

  //
  // Test check_out(patron)
  //
  publication.check_out(patron);

  if (!publication.is_checked_out()) {
    cerr << "is_checked_out() reported false after check_out(patron)" << endl;
    passed = false;
  }
    
  if (publication.to_string() != expected_co) {
    cerr << "Check out fail: got '" << publication.to_string() 
         << "' but expecting '" << expected_co << "'" << endl;
    passed = false;
  }

  //
  // Test check_in()
  //

  publication.check_in();

  if (publication.is_checked_out()) {
    cerr << "is_checked_out() reported true after check_in()" << endl;
    passed = false;
  }
    
  if (publication.to_string() != expected) {
    cerr << "Check in fail: got '" << publication.to_string() 
         << "' but expecting '" << expected << "'" << endl;
    passed = false;
  }

  //
  // Report results
  //

  if (!passed) {
    cerr << "fail" << endl;
    return -1;
  }

  return 0;
}
