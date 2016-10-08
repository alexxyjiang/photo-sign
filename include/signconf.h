/** signconf.h  - Provide configuration for photo sign
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-10-07
 */

#ifndef _PHOTOMGR_SIGNCONF_H_
#define _PHOTOMGR_SIGNCONF_H_

namespace PhotoMgr {
  enum SignPosition {
    DEFAULT       = 0,
    TOP_LEFT      = 1,
    TOP_RIGHT     = 2,
    BOTTOM_LEFT   = 3,
    BOTTOM_RIGHT  = 4
  };

  struct sign_conf_t {
    unsigned      min_sign_margin;
    SignPosition  sign_posi;
    double        sign_rate;
  };

  struct image_size_t {
    unsigned  width;
    unsigned  height;
  };

  class SignPosiMgr {
  private:
    image_size_t  _photo_size;
    image_size_t  _sign_size;
    sign_conf_t   _sign_conf;
    unsigned      _sign_x0;
    unsigned      _sign_x1;
    unsigned      _sign_y0;
    unsigned      _sign_y1;
  public:
    SignPosiMgr(const image_size_t &photo_size, const image_size_t &sign_size, const sign_conf_t &sign_conf);
    void set_photo_size(const image_size_t &photo_size);
    void set_sign_size(const image_size_t &sign_size);
    void set_sign_conf(const sign_conf_t &sign_conf);
    int calc_sign_posi();
    unsigned sign_x0();
    unsigned sign_x1();
    unsigned sign_y0();
    unsigned sign_y1();
  };
} // namespace PhotoMgr

#endif // _PHOTOMGR_SIGNCONF_H_
