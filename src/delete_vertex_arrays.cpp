/*
 * delete_vertex_arrays.cpp
 *
 *  Created on: 20.10.2013
 *      Author: scn
 */


#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_delete_vertex_arrays(GLsizei n, GLuint const *arrays) {
  s_stub.register_call("glDeleteVertexArrays", {
    {"n", t_arg(n)},
    {"arrays", t_arg(arrays)}
  });
}

void (GLAPIENTRY * __glewDeleteVertexArrays) (GLsizei n, GLuint const *arrays) = glew_mock_delete_vertex_arrays;

