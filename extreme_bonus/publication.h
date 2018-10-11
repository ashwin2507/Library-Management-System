 #ifndef __PUBLICATION_H
 #define __PUBLICATION_H 201609
 #include "patron.h"
 
 #include "media.h"
 #include "genre.h"
 #include "age.h"

 #include <iostream>
 #include <string>

 using namespace std;


 class Publication {
   public:
     Publication(string p_title, 
                 string p_author, 
                 string p_copyright,
                 Genre p_genre, 
                 Media p_media, 
                 Age p_target_age,
                 string p_isbn) : 

                 title(p_title), 
                 author(p_author),
                 copyright(p_copyright), 
                 genre(p_genre), 
                 media(p_media),
                 target_age(p_target_age), 
                 isbn(p_isbn), 
                 patron(Patron()),
                 checked_out(false) { }

     bool is_checked_out();

     void check_out(Patron& patron);
     void check_in();

     string to_string();

     // Thrown on check_in if publication isn't checked out
     //   or on cheeck_out if publication is already checked out
     class Invalid_transaction { }; 

   private:
     string title;
     string author;
     string copyright;
     Genre genre;
     Media media;
     Age target_age;
     string isbn;
     Patron patron;
     bool checked_out;
 };
 #endif
