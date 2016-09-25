#include <stdio.h>
#include "gflags/gflags.h"
#include "mode.h"
#include "version.h"

using google::ParseCommandLineFlags;
using PhotoMgr::ModeController;
using PhotoMgr::set_photomgr_version;
using PhotoMgr::print_all_version_info;

int main(int argc, char** argv)
{
  set_photomgr_version();
  ParseCommandLineFlags(&argc, &argv, true);

  ModeController* mc  = (ModeController *)ModeController::get_instance();
  mc->set_type();
  switch(mc->get_type()) {
    case PhotoMgr::MODE_VERSION:
      print_all_version_info();
      break;
    case PhotoMgr::MODE_RENAME:
      printf("Rename\n");
    break;
  }
  return 0;
}
