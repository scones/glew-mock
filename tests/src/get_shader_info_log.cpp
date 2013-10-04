/*
 * compile_shader.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class get_shader_info_log_test : public base_fixture {};


TEST_F(get_shader_info_log_test, is_reachable) {
  int length = 1;
  char info_log[] = "foo";
  glGetShaderInfoLog(1, 2, &length, info_log);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glGetShaderInfoLog");
}


TEST_F(get_shader_info_log_test, has_correct_params) {
  int length = 1;
  char info_log[] = "foo";
  glGetShaderInfoLog(1, 2, &length, info_log);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("shader"), t_arg(1));
  ASSERT_EQ(first_invocation.param("maxLength"), t_arg(2));
  ASSERT_EQ(first_invocation.param("length"), t_arg(&length));
  ASSERT_EQ(first_invocation.param("infoLog"), t_arg(info_log));
}

