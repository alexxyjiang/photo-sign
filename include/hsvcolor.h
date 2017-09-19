/** hsvcolor.h - Support RGB & HSV color convert
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2017-09-19
 */

#ifndef _PHOTOMGR_HSVCOLOR_H_
#define _PHOTOMGR_HSVCOLOR_H_

#include "FreeImagePlus.h"

namespace PhotoMgr {
  struct HSVACOLOR {
    double  h;
    double  s;
    double  v;
    uint8_t a;
  };

  HSVACOLOR convert_rgba2hsva(const RGBQUAD rgba_color);
  RGBQUAD   convert_hsva2rgba(const HSVACOLOR hsva_color);
  HSVACOLOR reversed_hsva_color(const HSVACOLOR hsva_color);

} // namespace PhotoMgr

#endif // _PHOTOMGR_HSVCOLOR_H_
