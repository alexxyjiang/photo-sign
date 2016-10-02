/** mode.h  - Image Name Management
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#ifndef _PHOTOMGR_IMAGENAME_H_
#define _PHOTOMGR_IMAGENAME_H_

#include <string>
#include <vector>

namespace PhotoMgr {
  const std::string DEFAULT_DEVICE_NAME = "DC";
  const std::string DEFAULT_GROUP_NAME  = "NOTSET";

  class ImageName {
  private:
    std::string _device_name;
    std::string _group_name;
    unsigned    _index;
  public:
    ImageName(const std::string &device_name, const std::string &group_name, unsigned index);
    void set_device_name(const std::string &device_name);
    void set_group_name(const std::string &group_name);
    void set_index(unsigned index);
    std::string get_imagename();
  };

  class ImagePathNameFormat {
  private:
    std::string       _path_name;
  public:
  };

  class ImageRenameMgr {
  private:
    std::vector<ImageName> _v_imgname;
  };
} // namespace PhotoMgr

#endif // _PHOTOMGR_IMAGENAME_H_
