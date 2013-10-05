/*
 * get_programiv.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */


#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_get_programiv(GLuint program, GLenum pname, GLint *params) {
  s_stub.register_call("glGetProgramiv", {
    {"program", t_arg(program)},
    {"pname", t_arg(pname)},
    {"params", t_arg(params)}
  });
  *params = s_stub.get_function_parameter_return<int>("glGetProgramiv", "params", stubber::condition(pname));
}


void (*__glewGetProgramiv) ( GLuint program, GLenum pname, GLint *params) = glew_mock_get_programiv;

