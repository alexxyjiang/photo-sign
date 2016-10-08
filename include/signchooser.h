/** signchooser.h - Choose the right sign for photo
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-10-07
 */

#ifndef _PHOTOMGR_SIGNCHOOSER_H_
#define _PHOTOMGR_SIGNCHOOSER_H_

#include <string>
#include <vector>
#include "FreeImagePlus.h"
#include "signconf.h"

namespace PhotoMgr {
  class ColorMgr {
  private:
    const fipImage  *_p_image;
  public:
    ColorMgr(const fipImage *p_image);
    void set_fip_image(const fipImage *p_image);
    RGBQUAD mean_color() const;
    double color_distance(const ColorMgr &other) const;
  };

  class SignDrawer {
  private:
    std::vector<fipImage *> _vec_sign_library;
  public:
    SignDrawer();
    void clear_library();
    int load_library(const std::string &base_path);
    int sign_photo(fipImage *p_dest, const fipImage *p_src, const sign_conf_t sign_conf);
  };

  class SignPhotoMgr {
  private:
    std::string _photo_path;
    std::string _sign_path;
  public:
    SignPhotoMgr(const std::string &photo_path, const std::string &sign_path);
    void set_photo_path(const std::string &photo_path);
    void set_sign_path(const std::string &sign_path);
    int sign_all_photos(const sign_conf_t sign_conf);
  };
} // namespace PhotoMgr

#endif // _PHOTOMGR_SIGNCHOOSER_H_
