/** version.cpp - Collect All Version Information
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#include <iostream>
#include "gflags/gflags.h"
#include "FreeImagePlus.h"
#include "version.h"

using google::SetVersionString;

namespace PhotoMgr {
  void set_photomgr_version() {
    SetVersionString(PHOTOMGR_VERSION);
  }

  void print_all_version_info() {
    std::cout << "Photo Manager Version: " << PHOTOMGR_VERSION << std::endl
              << "GFlag Version: " << GFLAGS_VERSION << std::endl
              << "FreeImage Version: " << FreeImage_GetVersion() << std::endl;
  }
} // namespace PhotoMgr
