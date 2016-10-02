/** mode.h  - Image Name Management
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-25
 */

#include <string>
#include <sstream>
#include <iomanip>
#include "imagename.h"

namespace PhotoMgr {
  // public
  ImageName::ImageName(const std::string &device_name, const std::string &group_name, unsigned index) {
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

  void ImageName::set_index(unsigned index) {
    this->_index        = index;
  }

  std::string ImageName::get_imagename() {
    std::ostringstream  image_name;
    image_name  << _device_name << "_"
                << _group_name << "_"
                << std::setw(4) << std::setfill('0') << std::internal << _index;
    return image_name.str();
  }
} // namespace PhotoMgr
