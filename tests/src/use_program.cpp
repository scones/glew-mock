/*
 * use_program.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class use_program_test : public base_fixture {};


TEST_F(use_program_test, is_reachable) {
  glUseProgram(1);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glUseProgram");
}


TEST_F(use_program_test, has_correct_params) {
  glUseProgram(1);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("program"), t_arg(1));
}

