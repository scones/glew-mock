/*
 * delete_shader.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_delete_shader(unsigned int shader) {
  s_stub.register_call("glDeleteShader", {
    {"shader", t_arg(shader)}
  });
}

void (GLAPIENTRY * __glewDeleteShader) (GLuint shader) = glew_mock_delete_shader;

