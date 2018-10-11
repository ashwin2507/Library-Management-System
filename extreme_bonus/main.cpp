#include <gtkmm.h>
#include "controller.h"
#include "library.h"

int main(int argc, char *argv[]) {
  Gtk::Main kit(argc, argv);
  Library library;
  Controller controller(library);
  controller.cli();
}
