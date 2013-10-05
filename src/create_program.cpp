/*
 * create_program.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>


GLuint glew_mock_create_program() {
  s_stub.register_call("glCreateProgram", {});
  return s_stub.get_result<GLenum>("glCreateProgram");
}

GLuint (*__glewCreateProgram) () = glew_mock_create_program;

