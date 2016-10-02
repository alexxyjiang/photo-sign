/** version.cpp - Collect All Version Information
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#include <stdio.h>
#include "gflags/gflags.h"
#include "version.h"

using google::SetVersionString;

namespace PhotoMgr {
  void set_photomgr_version() {
    SetVersionString(PHOTOMGR_VERSION);
  }

  void print_all_version_info() {
    printf("Photo Manager Version: %s\n", PHOTOMGR_VERSION.c_str());
  }
} // namespace PhotoMgr
