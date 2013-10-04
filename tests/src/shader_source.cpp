/*
 * shader_source.cpp
 *
 *  Created on: 04.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class shader_source_test : public base_fixture {
  protected:

  int m_result;
  void SetUp() {
    base_fixture::SetUp();
    m_result = 7;
  }
};


TEST_F(shader_source_test, is_reachable) {
  char const * some_source = "foo";
  GLint some_length = 3;
  glShaderSource(1, 2, &some_source, &some_length);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glShaderSource");
}


TEST_F(shader_source_test, has_correct_params) {
  char const * some_source = "foo";
  GLint some_length = 3;
  glShaderSource(1, 2, &some_source, &some_length);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("shader"), t_arg(1));
  ASSERT_EQ(first_invocation.param("count"), t_arg(2));
  ASSERT_EQ(first_invocation.param("string"), t_arg(&some_source));
  ASSERT_EQ(first_invocation.param("length"), t_arg(&some_length));
}

