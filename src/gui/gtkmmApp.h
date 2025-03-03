#include "../include/core.h"
class MyWindow : public Gtk::Window {
public:
  Gtk::Button hello_button;

  MyWindow() { setup_ui(); }

  void setup_ui() {
    set_title("Basic Application");
    set_default_size(1280, 720);

    hello_button.set_label("Click Me");
    hello_button.set_margin(20);

    // Add the button to the window
    set_child(hello_button);

    // Connect the signal
    // hello_button.signal_clicked().connect(sigc::mem_fun(*this,
    // &save(SOURCE)));

    // hello_button.signal_clicked().connect([this]() { save(SOURCE); });
  }
};
