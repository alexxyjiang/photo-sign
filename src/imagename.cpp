/** imagename.cpp - Image Name Management
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <dirent.h>
#include "FreeImagePlus.h"
#include "imagename.h"

namespace PhotoMgr {
  // public
  ImageName::ImageName(const std::string &device_name, const std::string &group_name, const unsigned index) {
    set_device_name(device_name);
    set_group_name(group_name);
    set_index(index);
  }

  void ImageName::set_device_name(const std::string &device_name) {
    this->_device_name  = device_name;
  }

  void ImageName::set_group_name(const std::string &group_name) {
    this->_group_name   = group_name;
  }

  void ImageName::set_index(const unsigned index) {
    this->_index        = index;
  }

  std::string ImageName::get_imagename() {
    std::ostringstream  image_name;
    image_name  << _device_name << "_"
                << _group_name << "_"
                << std::setw(4) << std::setfill('0') << std::internal << _index;
    return image_name.str();
  }

  // public
  ImagePathFormatName::ImagePathFormatName(const std::string &path_name) {
    set_path_name(path_name);
  }

  void ImagePathFormatName::set_path_name(const std::string &path_name) {
    this->_path_name  = path_name;
  }

  std::string ImagePathFormatName::get_format_extension() {
    FREE_IMAGE_FORMAT fiformat  = fipImage::identifyFIF(_path_name.c_str());
    switch(fiformat) {
      case FIF_JPEG:
        return "JPG";
      case FIF_PNG:
        return "PNG";
      case FIF_RAW:
        return "NEF";
      case FIF_UNKNOWN:
      default:
        return "UNKNOWN";
    }
  }

  // public
  PathImageNameMgr::PathImageNameMgr(const std::string &base_path) {
    set_base_path(base_path);
  }

  void PathImageNameMgr::set_base_path(const std::string &base_path) {
    this->_base_path  = base_path;
  }

  void PathImageNameMgr::clear_mapping() {
    _file_name_mapping.clear();
  }

  unsigned PathImageNameMgr::scan_base_path(const std::string &group_name) {
    DIR *dp;
    struct dirent *ep;
    std::string inner_device_name;
    std::string inner_group_name;
    std::vector<std::string>  vstr;
    std::string inner_orig_name;
    std::string inner_rename_name;

    unsigned count = 0u;
    dp  = opendir(_base_path.c_str());
    if (dp) {
      while (NULL != (ep = readdir(dp))) {
        std::string orig_name(ep->d_name);
        ImagePathFormatName ipfname(orig_name);
        if (group_name != "") {
          inner_group_name  = group_name;
        } else {
          inner_group_name  = DEFAULT_GROUP_NAME;
        }
        inner_device_name = DEFAULT_DEVICE_NAME;

        if (ipfname.get_format_extension() != "UNKNOWN") {
          std::istringstream  istrs(orig_name);
          std::ostringstream  ostrs;
          std::string         str;
          vstr.clear();
          while (std::getline(istrs, str, '.')) {
            vstr.push_back(str);
          }
          for (unsigned i=0; i<vstr.size()-1; ++i) {
            ostrs << vstr[i];
            if (i>0) {
              ostrs << '.';
            }
          }
          inner_orig_name = ostrs.str();
          if (_file_name_mapping.find(inner_orig_name) != _file_name_mapping.end()) {
            inner_rename_name = _file_name_mapping.at(inner_orig_name);
          } else {
            ImageName iname(inner_device_name, inner_group_name, ++count);
            inner_rename_name = iname.get_imagename();
            _file_name_mapping[inner_orig_name] = inner_rename_name;
          }
          // rename(orig_name.c_str(), (inner_rename_name + "." + ipfname.get_format_extension()).c_str());
        }
      }
      closedir(dp);
      return count;
    } else {
      return 0;
    }
  }
} // namespace PhotoMgr
