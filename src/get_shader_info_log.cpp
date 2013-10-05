/*
 * get_shader_info_log.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>
#include <cstring>
#include <iostream>


void glew_mock_get_shader_info_log(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog) {
  s_stub.register_call("glGetShaderInfoLog", {
    {"shader", t_arg(shader)},
    {"maxLength", t_arg(maxLength)},
    {"length", t_arg(length)},
    {"infoLog", t_arg(infoLog)}
  });
  if (length) {
    *length = s_stub.get_function_parameter_return<int>("glGetShaderInfoLog", "length");
  }
  std::strcpy(infoLog, s_stub.get_function_parameter_return<char*>("glGetShaderInfoLog", "infoLog"));
}


void (* __glewGetShaderInfoLog) (GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog) = glew_mock_get_shader_info_log;

