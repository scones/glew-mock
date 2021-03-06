/*
 * get_programiv.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>
#include <iostream>

class get_programiv_test : public base_fixture {
  void SetUp() {
    base_fixture::SetUp();
    s_stub.register_function_parameter_return<int>("glGetProgramiv", "params", 1);
  }
};


TEST_F(get_programiv_test, is_reachable) {
  int some_param;
  glGetProgramiv(1, GL_COMPILE_STATUS, &some_param);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ("glGetProgramiv", first_invocation.name());
}


TEST_F(get_programiv_test, has_correct_params) {
  int some_param = 3;
  glGetProgramiv(1, GL_COMPILE_STATUS, &some_param);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(t_arg(1), first_invocation.param("program"));
  ASSERT_EQ(t_arg(GL_COMPILE_STATUS), first_invocation.param("pname"));
  ASSERT_EQ(t_arg(&some_param), first_invocation.param("params"));
  ASSERT_EQ(1, some_param);
}


TEST_F(get_programiv_test, has_conditional_params) {
  s_stub.register_function_parameter_return("glGetProgramiv", "params", 7, stubber::condition(GL_COMPILE_STATUS));
  int some_param = 3;
  int some_other_param = 4;
  glGetProgramiv(1, GL_COMPILE_STATUS, &some_param);
  glGetProgramiv(1, GL_INFO_LOG_LENGTH, &some_other_param);

  auto iterator = s_stub.function_calls().begin();

  auto first_invocation  = *iterator++;
  ASSERT_EQ(t_arg(1), first_invocation.param("program"));
  ASSERT_EQ(t_arg(GL_COMPILE_STATUS), first_invocation.param("pname"));
  ASSERT_EQ(t_arg(&some_param), first_invocation.param("params"));
  ASSERT_EQ(7, some_param);

  auto second_invocation = *iterator++;
  ASSERT_EQ(t_arg(1), second_invocation.param("program"));
  ASSERT_EQ(t_arg(GL_INFO_LOG_LENGTH), second_invocation.param("pname"));
  ASSERT_EQ(t_arg(&some_other_param), second_invocation.param("params"));
  ASSERT_EQ(1, some_other_param);
}

