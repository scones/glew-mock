/*
 * bind_vertex_array.cpp
 *
 *  Created on: 20.10.2013
 *      Author: scn
 */


#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_bind_vertex_array(GLuint array) {
  s_stub.register_call("glBindVertexArray", {
    {"array", t_arg(array)}
  });
}

void (GLAPIENTRY * __glewBindVertexArray) (GLuint array) = glew_mock_bind_vertex_array;

