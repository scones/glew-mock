/*
 * compile_shader.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_compile_shader(GLuint shader) {
  s_stub.register_call("glCompileShader", {
    {"shader", t_arg(shader)}
  });
}


void (GLAPIENTRY * __glewCompileShader) (GLuint shader) = glew_mock_compile_shader;

