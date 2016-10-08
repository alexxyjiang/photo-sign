/** mode.cpp  - Global Settings Support
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#include "gflags/gflags.h"
#include "mode.h"

DEFINE_uint32(mode, 0u, "photo manager work mode");

namespace PhotoMgr {
  // public
  void ModeController::set_type() {
    ModeType mode = ModeType(FLAGS_mode);
    set_type(mode);
  }

  void ModeController::set_type(const ModeType& type) {
    this->_type = type;
  }

  const ModeType& ModeController::get_type() {
    return _type;
  }
} // namespace PhotoMgr
