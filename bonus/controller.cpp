#include "controller.h"
#include "view.h"
#include "library.h"
#include "publication.h"
#include "patron.h"
#include "genre.h"
#include "media.h"
#include "age.h"
#include "dialogs.h"
#include <iostream>
#include <string>

using namespace std;

void Controller::cli() {
  int cmd = -1;
  while (cmd != 0) {
    cmd = view.select_from_menu();
    execute_cmd(cmd);
  }
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add publication
    string title, author, copyright, isbn;
    int genre, media, age;
    bool cancel = false;

    title = Dialogs::input("Title?");
    if (title == "CANCEL") cancel = true;
    
    if (!cancel) author = Dialogs::input("Author?");
    if (author == "CANCEL") cancel = true;

    if (!cancel) copyright = Dialogs::input("Copyright date?");
    if (copyright == "CANCEL") cancel = true;

    if (!cancel) genre = view.select_genre();
    if (genre < 0) cancel = true;

    if (!cancel) media = view.select_media();
    if (media < 0) cancel = true;

    if (!cancel) age = view.select_age();
    if (age < 0) cancel = true;

    if (!cancel) isbn = Dialogs::input("ISBN?");
    if (isbn == "CANCEL") cancel = true;

    if (!cancel)
      library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));

 } else if (cmd == 2) { // List all publications
    view.list_publications();

 } else if (cmd == 3) { // Check out publication
    int pub, pat;

    pub = view.select_publication();

    if (pub >= 0) {
      pat = view.select_patron();

      if (pat >= 0) {
        try {
          library.check_out(pub, pat);
        } catch (Publication::Invalid_transaction e) {
          Dialogs::message("That publication is already checked out!", "ERROR");
        }
      }
    }
    
 } else if (cmd == 4) { // Check in publication
    int pub;
    pub = view.select_publication();

    if (pub >= 0) {
      try {
        library.check_in(pub);
      } catch (Publication::Invalid_transaction e) {
        Dialogs::message("That publication is already checked in!", "ERROR");
      }
    }

 } else if (cmd == 5) { // Add patron
    string name, number;
    bool cancel = false;

    name = Dialogs::input("Name?");
    if (name == "CANCEL") cancel = true;

    if (!cancel) number = Dialogs::input("Phone number?");
    if (number == "CANCEL") cancel = true;

    library.add_patron(Patron(name, number));
    
 } else if (cmd == 6) { // List all patrons
    view.list_patrons();

 } else if (cmd == 9) { // Help
    view.help();
 } else if (cmd == 0) { // Exit
 } else if (cmd == 99) { // Easter Egg
   library.easter_egg();
 } else {
   Dialogs::message("**** Invalid command - type 9 for help");
 }
}

