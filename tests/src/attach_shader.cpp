/*
 * attach_shader.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class attach_shader_test : public base_fixture {};


TEST_F(attach_shader_test, is_reachable) {
  glAttachShader(1, 2);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glAttachShader");
}


TEST_F(attach_shader_test, has_correct_params) {
  glAttachShader(1, 2);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("program"), t_arg(1));
  ASSERT_EQ(first_invocation.param("shader"), t_arg(2));
}

