#include "gflags/gflags.h"
#include "FreeImagePlus.h"
#include "mode.h"
#include "signconf.h"
#include "signchooser.h"
#include "version.h"

using google::ParseCommandLineFlags;
using PhotoMgr::ModeController;
using PhotoMgr::SignPhotoMgr;
using PhotoMgr::sign_conf_t;
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
      break;
    case PhotoMgr::MODE_SIGN:
      SignPhotoMgr  spmgr(argv[1], argv[2]);
      sign_conf_t   sign_conf;
      sign_conf.min_sign_margin = 90;
      sign_conf.scale_rate      = 1;
      sign_conf.sign_posi       = PhotoMgr::BOTTOM_RIGHT;
      sign_conf.sign_rate       = 0.2361;
      spmgr.sign_all_photos(sign_conf);
      break;
  }

  return 0;
}
