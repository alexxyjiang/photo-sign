/** signconf.cpp  - Provide configuration for photo sign
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-10-07
 */

#include "gflags/gflags.h"
#include "signconf.h"

DEFINE_bool(auto_sign_scale, false, "enable auto sign scale");

namespace PhotoMgr {
  // SignPosiMgr - public
  SignPosiMgr::SignPosiMgr(const image_size_t &photo_size, const image_size_t &sign_size, const sign_conf_t &sign_conf) {
    set_photo_size(photo_size);
    set_sign_size(sign_size);
    set_sign_conf(sign_conf);
  }

  void SignPosiMgr::set_photo_size(const PhotoMgr::image_size_t &photo_size) {
    this->_photo_size = photo_size;
  }

  void SignPosiMgr::set_sign_size(const PhotoMgr::image_size_t &sign_size) {
    this->_sign_size  = sign_size;
  }

  void SignPosiMgr::set_sign_conf(const PhotoMgr::sign_conf_t &sign_conf) {
    this->_sign_conf  = sign_conf;
  }

  int SignPosiMgr::calc_sign_posi() {
    // possibility check
    if (_photo_size.width < _sign_size.width + 2 * _sign_conf.min_sign_margin) {
      return -1;
    }
    if (_photo_size.height < _sign_size.height + 2 * _sign_conf.min_sign_margin) {
      return -1;
    }
    if (_sign_conf.sign_rate < -1e-6 || _sign_conf.sign_rate > 1 + 1e-6) {
      return -1;
    }

    // calculate margin
    unsigned distance_x = unsigned(_photo_size.width * _sign_conf.sign_rate + 0.5);
    unsigned distance_y = unsigned(_photo_size.height * _sign_conf.sign_rate + 0.5);

    unsigned margin_x   = distance_x - _sign_size.width / 2;
    unsigned margin_y   = distance_y - _sign_size.height / 2;

    if (FLAGS_auto_sign_scale) {
      unsigned  scale_x = margin_x / _sign_size.width   + 1;
      unsigned  scale_y = margin_y / _sign_size.height  + 1;
      _sign_conf.scale_rate = scale_x < scale_y ? scale_x : scale_y;
      margin_x  -= _sign_size.width   * (_sign_conf.scale_rate - 1);
      margin_y  -= _sign_size.height  * (_sign_conf.scale_rate - 1);
      margin_x  = margin_x < _sign_conf.min_sign_margin ? _sign_conf.min_sign_margin : margin_x;
      margin_y  = margin_y < _sign_conf.min_sign_margin ? _sign_conf.min_sign_margin : margin_y;
    } else {
      margin_x  = margin_x < _sign_conf.min_sign_margin ? _sign_conf.min_sign_margin : margin_x;
      margin_y  = margin_y < _sign_conf.min_sign_margin ? _sign_conf.min_sign_margin : margin_y;
    }

    // decide final position
    switch(_sign_conf.sign_posi) {
      case TOP_LEFT:
        _sign_x0  = margin_x;
        _sign_y1  = _photo_size.height - margin_y;
        _sign_x1  = _sign_x0 + _sign_size.width   * _sign_conf.scale_rate;
        _sign_y0  = _sign_y1 - _sign_size.height  * _sign_conf.scale_rate;
        break;
      case TOP_RIGHT:
        _sign_x1  = _photo_size.width - margin_x;
        _sign_y1  = _photo_size.height - margin_y;
        _sign_x0  = _sign_x1 - _sign_size.width   * _sign_conf.scale_rate;
        _sign_y0  = _sign_y1 - _sign_size.height  * _sign_conf.scale_rate;
        break;
      case BOTTOM_LEFT:
        _sign_x0  = margin_x;
        _sign_y0  = margin_y;
        _sign_x1  = _sign_x0 + _sign_size.width   * _sign_conf.scale_rate;
        _sign_y1  = _sign_y0 + _sign_size.height  * _sign_conf.scale_rate;
        break;
      case BOTTOM_RIGHT:
      case DEFAULT:
      default:
        _sign_x1  = _photo_size.width - margin_x;
        _sign_y0  = margin_y;
        _sign_x0  = _sign_x1 - _sign_size.width   * _sign_conf.scale_rate;
        _sign_y1  = _sign_y0 + _sign_size.height  * _sign_conf.scale_rate;
    }

    return 0;
  }

  sign_conf_t SignPosiMgr::sign_conf() {
    return _sign_conf;
  }

  unsigned SignPosiMgr::sign_x0() {
    return _sign_x0;
  }

  unsigned SignPosiMgr::sign_x1() {
    return _sign_x1;
  }

  unsigned SignPosiMgr::sign_y0() {
    return _sign_y0;
  }

  unsigned SignPosiMgr::sign_y1() {
    return _sign_y1;
  }
} // namespace PhotoMgr
