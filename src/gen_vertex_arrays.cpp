/*
 * gen_vertex_arrays.cpp
 *
 *  Created on: 20.10.2013
 *      Author: scn
 */


#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_gen_vertex_arrays(GLsizei n, GLuint* arrays) {
  s_stub.register_call("glGenVertexArrays", {
    {"n", t_arg(n)},
    {"arrays", t_arg(arrays)}
  });
  *arrays = s_stub.get_function_parameter_return<int>("glGenVertexArrays", "arrays");
}

void (GLAPIENTRY * __glewGenVertexArrays) (GLsizei n, GLuint* arrays) = glew_mock_gen_vertex_arrays;

