/*
 * create_shader.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class create_shader_test : public base_fixture {
  protected:

  int m_result;
  void SetUp() {
    base_fixture::SetUp();
    m_result = 7;
    s_stub.register_function_result("glCreateShader", m_result);
  }
};


TEST_F(create_shader_test, is_reachable) {
  glCreateShader(1);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glCreateShader");
}


TEST_F(create_shader_test, has_correct_params) {
  glCreateShader(2);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("type"), t_arg(2));
}

TEST_F(create_shader_test, returns_correctly) {
  ASSERT_EQ(m_result, glCreateShader(3));
}

