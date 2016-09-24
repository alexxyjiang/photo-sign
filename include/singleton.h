/** singleton.h - Singleton Pattern Support
 *  @author:  Alex.J. (alexxyjiang@gmail.com)
 *  @date:    2016-09-24
 */

#ifndef _PHOTOMGR_SINGLETON_H_
#define _PHOTOMGR_SINGLETON_H_

namespace PhotoMgr {
  class Singleton {
    static Singleton *p_instance;

    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    void operator=(const Singleton&);

  public:
    static Singleton* get_instance();
  };
} // namespace PhotoMgr

#endif // _PHOTOMGR_SINGLETON_H_
