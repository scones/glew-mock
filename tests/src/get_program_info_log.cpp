/*
 * compile_program.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class get_program_info_log_test : public base_fixture {
  void SetUp() {
    base_fixture::SetUp();
    s_stub.register_function_parameter_return<int>("glGetProgramInfoLog", "length", 4);
    char some_param[] = "foo2";
    s_stub.register_function_parameter_return<char*>("glGetProgramInfoLog", "infoLog", some_param);
  }
};


TEST_F(get_program_info_log_test, is_reachable) {
  int length = 1;
  char info_log[] = "foo";
  glGetProgramInfoLog(1, 2, &length, info_log);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glGetProgramInfoLog");
}


TEST_F(get_program_info_log_test, has_correct_params) {
  int length = 1;
  char info_log[] = "foo";
  glGetProgramInfoLog(1, 2, &length, info_log);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(t_arg(1), first_invocation.param("program"));
  ASSERT_EQ(t_arg(2), first_invocation.param("maxLength"));
  ASSERT_EQ(t_arg(&length), first_invocation.param("length"));
  ASSERT_EQ(t_arg("foo"), first_invocation.param("infoLog"));
  ASSERT_EQ(std::string("foo2"), std::string(info_log));
  ASSERT_EQ(4, length);
}


TEST_F(get_program_info_log_test, should_work_with_nullptr_as_third_parameter) {
  char info_log[] = "foo";
  glGetProgramInfoLog(1, 2, nullptr, info_log);
}

