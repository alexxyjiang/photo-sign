/** hsvcolor.cpp - Support RGB & HSV color convert
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2017-09-19
 */

#include "hsvcolor.h"

namespace PhotoMgr {
  HSVACOLOR convert_rgba2hsva(const RGBQUAD rgba_color) {
    double  r = double(rgba_color.rgbRed / 255.0);
    double  g = double(rgba_color.rgbGreen / 255.0);
    double  b = double(rgba_color.rgbBlue / 255.0);
    uint8_t a = uint8_t(rgba_color.rgbReserved);
    double c_max = r>g ? r : g;
    c_max = c_max>b ? c_max : b;
    double c_min = r<g ? r : g;
    c_min = c_min<b ? c_min : b;

    double h;
    if (c_max - c_min < 1e-6) {
      h = 0;
    } else if (c_max == r) {
      if (g >= b) {
        h = 60.0 * double(g - b) / double(c_max - c_min);
      } else {
        h = 60.0 * double(g - b) / double(c_max - c_min) + 360.0;
      }
    } else if (c_max == g) {
      h = 60.0 * double(b - r) / double(c_max - c_min) + 120.0;
    } else {
      h = 60.0 * double(r - g) / double(c_max - c_min) + 240.0;
    }

    double s;
    if (c_max < 1e-6) {
      s = 0.0;
    } else {
      s = 1.0 - double(c_min) / double(c_max);
    }

    double v = c_max;

    HSVACOLOR res;
    res.h = h;
    res.s = s;
    res.v = v;
    res.a = a;
    return res;
  }

  RGBQUAD   convert_hsva2rgba(const HSVACOLOR hsva_color) {
    double h = hsva_color.h;
    double s = hsva_color.s;
    double v = hsva_color.v;
    uint8_t a = hsva_color.a;

    uint8_t group = uint8_t(h / 60.0) % 6;
    double f = h / 60.0 - group;
    double p = v * (1.0 - s);
    double q = v * (1.0 - f * s);
    double t = v * (1.0 - (1.0 - f) * s);

    RGBQUAD res;
    if (group == 0) {
      res.rgbRed      = BYTE(v * 255.0);
      res.rgbGreen    = BYTE(t * 255.0);
      res.rgbBlue     = BYTE(p * 255.0);
      res.rgbReserved = BYTE(a);
    } else if (group == 1) {
      res.rgbRed      = BYTE(q * 255.0);
      res.rgbGreen    = BYTE(v * 255.0);
      res.rgbBlue     = BYTE(p * 255.0);
      res.rgbReserved = BYTE(a);
    } else if (group == 2) {
      res.rgbRed      = BYTE(p * 255.0);
      res.rgbGreen    = BYTE(v * 255.0);
      res.rgbBlue     = BYTE(t * 255.0);
      res.rgbReserved = BYTE(a);
    } else if (group == 3) {
      res.rgbRed      = BYTE(p * 255.0);
      res.rgbGreen    = BYTE(q * 255.0);
      res.rgbBlue     = BYTE(v * 255.0);
      res.rgbReserved = BYTE(a);
    } else if (group == 4) {
      res.rgbRed      = BYTE(t * 255.0);
      res.rgbGreen    = BYTE(p * 255.0);
      res.rgbBlue     = BYTE(v * 255.0);
      res.rgbReserved = BYTE(a);
    } else {
      res.rgbRed      = BYTE(v * 255.0);
      res.rgbGreen    = BYTE(p * 255.0);
      res.rgbBlue     = BYTE(q * 255.0);
      res.rgbReserved = BYTE(a);
    }

    return res;
  }

  HSVACOLOR reversed_hsva_color(const HSVACOLOR hsva_color) {
    HSVACOLOR res = hsva_color;
    res.h += 180.0;
    if (res.h > 360.0) {
      res.h -= 360.0;
    }
    return res;
  }

} // namespace PhotoMgr
