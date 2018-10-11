
 #ifndef __GENRE_H
 #define __GENRE_H 201609
 #include <iostream>
 using namespace std;

 class Genre {
   public:
     Genre(int val) : value(val) { }

     static const int fiction = 0;
     static const int nonfiction = 1;
     static const int selfhelp = 2;
     static const int performance = 3;

     static const int num_genres = 4;

     string to_string() {
       switch(value) {
         case(fiction):return "fiction";
         case(nonfiction):return "nonfiction";
         case(selfhelp):return "selfhelp";
         case(performance):return "performance";
         default: return "UNKNOWN";
       }
     }
   private:
     int value;
 };
 #endif
