/*
 * get_shaderiv.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */


#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_get_shaderiv(GLuint shader, GLenum pname, GLint *params) {
  s_stub.register_call("glGetShaderiv", {
    {"shader", t_arg(shader)},
    {"pname", t_arg(pname)},
    {"params", t_arg(params)}
  });
  *params = s_stub.get_function_parameter_return<int>("glGetShaderiv", "params");
}


void (*__glewGetShaderiv) ( GLuint shader, GLenum pname, GLint *params) = glew_mock_get_shaderiv;

