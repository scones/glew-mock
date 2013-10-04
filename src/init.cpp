/*
 * init.cpp
 *
 *  Created on: 24.08.2013
 *      Author: scn
 */


#include "stubber/stubber.h"

#include <GL/glew.h>

GLenum glewInit(void) {
  s_stub.register_call(__FUNCTION__, {});
  return s_stub.get_result<GLenum>(__FUNCTION__);
}

