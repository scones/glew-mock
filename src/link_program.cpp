/*
 * link_program.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */


#include "stubber/stubber.h"

#include <GL/glew.h>


void glew_mock_link_program(unsigned int program) {
  s_stub.register_call("glLinkProgram", {
    {"program", t_arg(program)}
  });
}

void (GLAPIENTRY * __glewLinkProgram) (GLuint program) = glew_mock_link_program;



