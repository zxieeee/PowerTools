#include "../include/config.h"

int main() {
  const std::string filename =
      "/home/himanshu/code/gtk_multimedia_organiser/include/config.conf";
  ConfigParser parsed;
  parsed.parseConfigFile(filename);

  parsed.printConfig();
  return 0;
}
