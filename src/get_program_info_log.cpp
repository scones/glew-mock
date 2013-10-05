/*
 * get_program_info_log.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>
#include <cstring>
#include <iostream>


void glew_mock_get_program_info_log(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog) {
  s_stub.register_call("glGetProgramInfoLog", {
    {"program", t_arg(program)},
    {"maxLength", t_arg(maxLength)},
    {"length", t_arg(length)},
    {"infoLog", t_arg(infoLog)}
  });
  if (length) {
    *length = s_stub.get_function_parameter_return<int>("glGetProgramInfoLog", "length");
  }
  std::strcpy(infoLog, s_stub.get_function_parameter_return<char*>("glGetProgramInfoLog", "infoLog"));
}


void (* __glewGetProgramInfoLog) (GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog) = glew_mock_get_program_info_log;

