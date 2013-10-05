/*
 * delete_program.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_delete_program(unsigned int program) {
  s_stub.register_call("glDeleteProgram", {
    {"program", t_arg(program)}
  });
}

void (GLAPIENTRY * __glewDeleteProgram) (GLuint program) = glew_mock_delete_program;

