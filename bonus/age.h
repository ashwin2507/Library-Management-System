
 #ifndef __AGE_H
 #define __AGE_H 201609
 #include "string"
 using namespace std;

 class Age {
   public:
     Age(int val) : value(val) { }

     static const int children = 0;
     static const int teen = 1;
     static const int adult = 2;
     static const int restricted = 3;

     static const int num_ages = 4;

     string to_string() {
       switch(value) {
         case(children):return "children";
         case(teen):return "teen";
         case(adult):return "adult";
         case(restricted):return "restricted";
         default: return "UNKNOWN";
       }
     }
   private:
     int value;
 };
 #endif
