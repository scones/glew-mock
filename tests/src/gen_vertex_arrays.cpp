/*
 * gen_vertex_arrays.cpp
 *
 *  Created on: 20.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class gen_vertex_arrays_test : public base_fixture {
  protected:

  int m_result;
  void SetUp() {
    base_fixture::SetUp();
    m_result = 9;
    s_stub.register_function_result("glGenVertexArrays", m_result);
    s_stub.register_function_parameter_return("glGenVertexArrays", "arrays", m_result);
  }
};


TEST_F(gen_vertex_arrays_test, is_reachable) {
  GLuint id = 0;
  glGenVertexArrays(1, &id);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glGenVertexArrays");
}


TEST_F(gen_vertex_arrays_test, has_correct_params) {
  GLuint id = 0;
  glGenVertexArrays(1, &id);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("n"), t_arg(1));
  ASSERT_EQ(first_invocation.param("arrays"), t_arg(&id));
}


TEST_F(gen_vertex_arrays_test, hash_correct_return) {
  GLuint id = 0;
  glGenVertexArrays(1, &id);
  ASSERT_EQ(m_result, id);
}

