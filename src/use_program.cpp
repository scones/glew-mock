/*
 * use_program.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */


#include <stubber/stubber.h>

#include <GL/glew.h>


void glew_mock_use_program(GLuint program) {
  s_stub.register_call("glUseProgram", {
    {"program", t_arg(program)}
  });
}


void (* __glewUseProgram) (GLuint program) = glew_mock_use_program;

