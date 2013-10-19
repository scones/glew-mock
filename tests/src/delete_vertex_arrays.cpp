/*
 * delete_vertex_arrays.cpp
 *
 *  Created on: 20.10.2013
 *      Author: scn
 */


#include "base_fixture.h"

#include <GL/glew.h>

class delete_vertex_array_test : public base_fixture {};


TEST_F(delete_vertex_array_test, is_reachable) {
  GLuint id = 0;
  glDeleteVertexArrays(1, &id);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glDeleteVertexArrays");
}


TEST_F(delete_vertex_array_test, has_correct_params) {
  GLuint id = 0;
  glDeleteVertexArrays(1, &id);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("n"), t_arg(1));
  ASSERT_EQ(first_invocation.param("arrays"), t_arg(&id));
}

