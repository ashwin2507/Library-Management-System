 #ifndef __PATRON_H
 #define __PATRON_H 201609
 #include <iostream>
 #include <string>

 using namespace std;

 class Patron {
   public:
     Patron(string patron_name, string patron_phone_number) 
       : name(patron_name), number(patron_phone_number) {}
     Patron() : name("unknown"), number("unknown") {}

     string to_string();

     string get_patron_name();
     string get_patron_phone_number();

   private:
     string name;
     string number;
 };
 #endif
