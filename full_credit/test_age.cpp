
 #include "age.h"
 #include <iostream>
 using namespace std;

 int main() {

   Age m1(Age::restricted);
   if (m1.to_string() != "restricted") {
     cerr << "restricted failed: got " << m1.to_string() << endl;
     return -1;
   }

   return 0;
 }
