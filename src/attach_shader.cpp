/*
 * attach_shader.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */


#include <stubber/stubber.h>

#include <GL/glew.h>


void glew_mock_attach_shader(GLuint program, GLuint shader) {
  s_stub.register_call("glAttachShader", {
    {"program", t_arg(program)},
    {"shader", t_arg(shader)}
  });
}


void (* __glewAttachShader) (GLuint program, GLuint shader) = glew_mock_attach_shader;

