/*
 * delete_shader.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class delete_shader_test : public base_fixture {};


TEST_F(delete_shader_test, is_reachable) {
  glDeleteShader(1);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glDeleteShader");
}


TEST_F(delete_shader_test, has_correct_params) {
  glDeleteShader(1);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("shader"), t_arg(1));
}

