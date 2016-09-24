/** singleton.cpp - Singleton Pattern Support
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-24
 */

#include "singleton.h"

namespace PhotoMgr {
  //private
  Singleton* Singleton::p_instance;
  Singleton::Singleton(){}
  Singleton::~Singleton(){}
  Singleton::Singleton(const Singleton&){}
  void Singleton::operator=(const Singleton&){}

  //public
  Singleton* Singleton::get_instance() {
    if (!p_instance) {
      p_instance  = new Singleton();
    }
    return p_instance;
  }
} // namespace PhotoMgr
