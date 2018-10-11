 #ifndef __LIBRARY_H
 #define __LIBRARY_H 201609
 #include "patron.h"
 #include "publication.h"

 #include <iostream>
 #include <string>
 #include <vector>

 using namespace std;


 class Library {
   public:
     void add_publication(Publication pub);
     void add_patron(Patron pat);

     void check_out(int publication_index, int patron_index);
     void check_in(int publication_index);

     string publication_to_string(int publication_index);
     string patron_to_string(int patron_index);

     int number_of_publications();
     int number_of_patrons();

     void easter_egg();
   private:
     vector<Publication> publications;
     vector<Patron> patrons;
 };
 #endif
