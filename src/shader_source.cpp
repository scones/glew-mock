/*
 * shader_source.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_shader_source(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) {
  s_stub.register_call("glShaderSource", {
      {"shader", t_arg(shader)},
      {"count", t_arg(count)},
      {"string", t_arg(string)},
      {"length", t_arg(length)}
  });
}


void (GLAPIENTRY * __glewShaderSource) (GLuint shader, GLsizei count, const GLchar** strings, const GLint* lengths) = glew_mock_shader_source;

