/** singleton.cpp - Singleton Pattern Support
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-24
 */

#include "singleton.h"

namespace PhotoMgr {
  // private
  Singleton* Singleton::_p_instance;
  Singleton::Singleton(){}
  Singleton::~Singleton(){}
  Singleton::Singleton(const Singleton&){}
  void Singleton::operator=(const Singleton&){}

  // public
  Singleton* Singleton::get_instance() {
    if (!_p_instance) {
      _p_instance  = new Singleton();
    }
    return _p_instance;
  }
} // namespace PhotoMgr
