/** imagename.h - Image Name Management
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#ifndef _PHOTOMGR_IMAGENAME_H_
#define _PHOTOMGR_IMAGENAME_H_

#include <string>
#include <map>

namespace PhotoMgr {
  const std::string DEFAULT_DEVICE_NAME = "SDC";
  const std::string DEFAULT_GROUP_NAME  = "GRP";

  class ImageName {
  private:
    std::string _device_name;
    std::string _group_name;
    unsigned    _index;
  public:
    ImageName(const std::string &device_name, const std::string &group_name, const unsigned index);
    void set_device_name(const std::string &device_name);
    void set_group_name(const std::string &group_name);
    void set_index(const unsigned index);
    std::string get_imagename();
  };

  class ImagePathFormatName {
  private:
    std::string _path_name;
  public:
    ImagePathFormatName(const std::string &path_name);
    void set_path_name(const std::string &path_name);
    std::string get_format_extension();
  };

  class PathImageNameMgr {
  private:
    std::string                         _base_path;
    std::map<std::string, std::string>  _file_name_mapping;
  public:
    PathImageNameMgr(const std::string &base_path);
    void set_base_path(const std::string &base_path);
    void clear_mapping();
    unsigned scan_base_path(const std::string &group_name);
  };
} // namespace PhotoMgr

#endif // _PHOTOMGR_IMAGENAME_H_
