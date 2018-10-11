
 #include "media.h"
 #include <iostream>
 using namespace std;

 int main() {

   Media m1(Media::video);
   if (m1.to_string() != "video") {
     cerr << "video failed: got " << m1.to_string() << endl;
     return -1;
   }

   return 0;
 }
