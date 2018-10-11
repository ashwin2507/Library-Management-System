#include "patron.h"
#include "publication.h"
#include "library.h"

int main() {
  Library library;

  bool passed = true;

  //
  // Test adding patrons
  //
  Patron larry("Larry", "817-555-1111");
  Patron curly("Curly", "817-555-2222");
  Patron moe("Moe", "817-555-3333");

  if (library.number_of_patrons() != 0) {
    passed = false;
    cerr << "Started with " << library.number_of_patrons() << " patrons" << endl;
  }

  library.add_patron(larry);
  library.add_patron(curly);
  library.add_patron(moe);

  if (library.number_of_patrons() != 3) {
    passed = false;
    cerr << "Ended with " << library.number_of_patrons() << " patrons (expected 3)" << endl;
  }

  if (library.patron_to_string(2) != "Moe (817-555-3333)") {
    passed = false;
    cerr << "Patron 3 is " << library.patron_to_string(2) << " (not Moe)" << endl;
  }

  //
  // Test adding publications
  //

  Publication foundation("Foundation", "Isaac Asimov", "1942", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation_empire("Foundation and Empire", "Isaac Asimov", "1943", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation2("Second Foundation", "Isaac Asimov", "1944", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication war("War of the Worlds", "Jeff Wayne", "1977",
      Genre::performance, Media::audio, Age::teen, "9780711969148");
  Publication wonka("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
      Genre::performance, Media::video, Age::children, "0142410314");

  if (library.number_of_publications() != 0) {
    passed = false;
    cerr << "Started with " << library.number_of_publications() << " publications" << endl;
  }

  library.add_publication(foundation);
  library.add_publication(foundation_empire);
  library.add_publication(foundation2);
  library.add_publication(war);
  library.add_publication(wonka);

  if (library.number_of_publications() != 5) {
    passed = false;
    cerr << "ended with " << library.number_of_publications() << " publications (expected 5)" << endl;
  }

  if (library.publication_to_string(0) != 
      "\"Foundation\" by Isaac Asimov, 1942 (adult fiction book) ISBN: 0385177259") {
    passed = false;
    cerr << "Foundation string from publication_to_string doesn't match" << endl;
  }

  //
  // Test check out and check in
  //

  library.check_out(1, 1);

  string expected = "\"Foundation and Empire\" by Isaac Asimov, 1943 (adult fiction book) ISBN: 0385177259\nChecked out to Curly (817-555-2222)";
  string actual = library.publication_to_string(1);
  if (actual != expected) {
    passed = false;
    cerr << "String from publication_to_string doesn't match after check out" << endl;
    cerr << "  Expected: " << expected << endl;
    cerr << "  Actual:   " << actual << endl;
  }

  library.check_in(1);
  expected = "\"Foundation and Empire\" by Isaac Asimov, 1943 (adult fiction book) ISBN: 0385177259";
  actual = library.publication_to_string(1);
  if (actual != expected) {
    passed = false;
    cerr << "String from publication_to_string doesn't match after check in" << endl;
    cerr << "  Expected: " << expected << endl;
    cerr << "  Actual:   " << actual << endl;
  }


  //
  // Show results
  //
  if (!passed) {
    cout << "fail" << endl;
    return -1;
  }

  return 0;
}
