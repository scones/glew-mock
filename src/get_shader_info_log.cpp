/*
 * get_shader_info_log.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_get_shader_info_log(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog) {
  s_stub.register_call("glGetShaderInfoLog", {
    {"shader", t_arg(shader)},
    {"maxLength", t_arg(maxLength)},
    {"length", t_arg(length)},
    {"infoLog", t_arg(infoLog)}
  });
}


void (* __glewGetShaderInfoLog) (GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog) = glew_mock_get_shader_info_log;

