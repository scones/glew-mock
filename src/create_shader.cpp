/*
 * create_shader.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>


GLuint glew_mock_create_shader(GLenum type) {
  s_stub.register_call("glCreateShader", {
    {"type", t_arg(type)}
  });
  return s_stub.get_result<GLenum>("glCreateShader");
}

GLuint (*__glewCreateShader) (GLenum type) = glew_mock_create_shader;

