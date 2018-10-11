
 #ifndef __MEDIA_H
 #define __MEDIA_H 201609
 #include "string"
 using namespace std;

 class Media {
   public:
     Media(int val) : value(val) { }

     static const int book = 0;
     static const int periodical = 1;
     static const int newspaper = 2;
     static const int audio = 3;
     static const int video = 4;

     static const int num_media = 5;

     string to_string() {
       switch(value) {
         case(book):return "book";
         case(periodical):return "periodical";
         case(newspaper):return "newspaper";
         case(audio):return "audio";
         case(video):return "video";
         default: return "UNKNOWN";
       }
     }
   private:
     int value;
 };
 #endif
