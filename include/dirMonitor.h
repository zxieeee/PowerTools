#pragma once
#include "../include/core.h"
#include "../include/global.h"
#include "core.h"

class DirMonitor : public fileOperations {
public:
  void startMonitoring(const std::vector<std::string> &SOURCE);
  ~DirMonitor() {}
  static std::unique_ptr<DirMonitor> create();
};
