/** mode.h  - Global Settings Support
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#ifndef _PHOTOMGR_MODE_H_
#define _PHOTOMGR_MODE_H_

#include "gflags/gflags.h"
#include "singleton.h"

DECLARE_uint32(mode);

namespace PhotoMgr {
  enum ModeType {
    MODE_VERSION  = 0,
    MODE_RENAME   = 1
  };

  class ModeController: public Singleton {
  private:
    ModeType  _type;
  public:
    void set_type();
    void set_type(const ModeType& type);
    const ModeType& get_type();
  };
} // namespace PhotoMgr

#endif // _PHOTOMGR_MODE_H_
