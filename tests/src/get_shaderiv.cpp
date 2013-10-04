/*
 * get_shaderiv.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class get_shaderiv_test : public base_fixture {};


TEST_F(get_shaderiv_test, is_reachable) {
  int some_param;
  glGetShaderiv(1, GL_COMPILE_STATUS, &some_param);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glGetShaderiv");
}


TEST_F(get_shaderiv_test, has_correct_params) {
  int some_param;
  glGetShaderiv(1, GL_COMPILE_STATUS, &some_param);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("shader"), t_arg(1));
  ASSERT_EQ(first_invocation.param("pname"), t_arg(GL_COMPILE_STATUS));
  ASSERT_EQ(first_invocation.param("params"), t_arg(&some_param));
}

