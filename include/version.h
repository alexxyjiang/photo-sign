/** version.h - Collect All Version Information
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#ifndef _PHOTOMGR_VERSION_H_
#define _PHOTOMGR_VERSION_H_

#include <string>

namespace PhotoMgr {
  const std::string PHOTOMGR_VERSION  = "0.1";
  const std::string GFLAGS_VERSION    = "2.2.0";
  void set_photomgr_version();
  void print_all_version_info();
} // namespace PhotoMgr

#endif // _PHOTOMGR_SINGLETON_H_