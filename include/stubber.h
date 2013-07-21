/*
 * stub.h
 *
 *  Created on: 21.04.2013
 *      Author: scn
 */

#ifndef STUBBER_H_
#define STUBBER_H_

// project includes

// system includes
#include <utility>
#include <tuple>
#include <list>
#include <map>
#include <initializer_list>
#include <sstream>
#include <ostream>
#include <stdexcept>

#include <iostream>

class stubber {
  public:


  class function_call {
    public:


    class argument {
      public:


      explicit argument() :
          m_value(std::string("")) {
      }
      template<typename T>
      argument(T const & value) {
        std::ostringstream oss;
        oss << value;
        m_value = oss.str();
      }
      ~argument() = default;
      argument(argument const & right) = default;
      argument(argument&& right) {
        m_value = std::move(right.m_value);
      }

      argument & operator =(argument const & right) {
        m_value = right.m_value;
        return *this;
      }

      template<class T>
      friend inline bool operator ==(argument const & left, T const & right) {
        return left == argument(right);
      }

      friend inline bool operator ==(argument const & left,
          argument const & right) {
        return left.m_value == right.m_value;
      }

      friend inline bool operator ==(argument const & left,
          std::string const & right) {
        return left.m_value == right;
      }

      template<typename T, typename S>
      friend inline bool operator !=(T const & left, S const & right) {
        return !(left == right);
      }

      friend inline std::ostream & operator <<(std::ostream & os,
          argument const & arg) {
        os << arg.m_value;
        return os;
      }


      private:


      std::string m_value;
    };
    typedef std::map<std::string, argument> t_argument_map;
    typedef std::pair<std::string, argument> t_name_argument;

    function_call(std::string const & name,
        std::initializer_list<t_name_argument> const & arguments) :
        m_name(name), m_arguments(t_argument_map()) {
      for (auto const & item : arguments) {
        m_arguments.insert(item);
      }
    }
    ~function_call() = default;
    function_call(function_call const &) = default;
    function_call(function_call&& right) {
      m_name = std::move(right.m_name);
      m_arguments = std::move(right.m_arguments);
    }
    ;

    function_call& operator =(function_call& right) {
      m_name = right.m_name;
      m_arguments = right.m_arguments;

      return *this;
    }

    std::string const name() const {
      return m_name;
    }
    t_argument_map const & arguments() const {
      return m_arguments;
    }

    argument const & param(std::string const & name) {
      return m_arguments[name];
    }

    argument const & operator ()(std::string const & name) {
      return m_arguments[name];
    }


    private:


    std::string m_name;
    t_argument_map m_arguments;
  };
  typedef std::list<function_call> t_function_call_list;
  typedef std::map<std::string, int> t_function_int_results;
  typedef std::map<std::string, double> t_function_double_results;

  stubber(stubber&) = delete;
  stubber(stubber&&) = delete;

  static stubber * get_stub() {
    return &s_stub;
  }

  static void reset() {
    s_stub.m_function_calls.clear();
    s_stub.m_function_int_results.clear();
    s_stub.m_function_double_results.clear();
  }

  static void register_call(std::string const & name,
      std::initializer_list<function_call::t_name_argument> const & arguments)
  {
    s_stub.m_function_calls.push_back(function_call(name, arguments));
  }

  static void register_function_int_result(std::string const & function_name, int result) {
    s_stub.m_function_int_results[function_name] = result;
  }

  static void register_function_double_result(std::string const & function_name, double result) {
    s_stub.m_function_double_results[function_name] = result;
  }

  static int get_int_result(std::string const & function_name) {
    int result;
    try {
      result = s_stub.m_function_int_results.at(function_name);
    } catch (std::out_of_range const & e) {
      throw std::runtime_error("No result defined for '" + function_name + "(..)'");
    }
    return result;
  }

  static double get_double_result(std::string const & function_name) {
    double result;
    try {
      result = s_stub.m_function_double_results.at(function_name);
    } catch (std::out_of_range const & e) {
      throw std::runtime_error("No result defined for '" + function_name + "(..)'");
    }
    return result;
  }

  t_function_call_list const & function_calls() const {
    return m_function_calls;
  }


  private:


  stubber() :
    m_function_calls(t_function_call_list()),
    m_function_int_results(t_function_int_results()),
    m_function_double_results(t_function_double_results())
  {
  }
  ~stubber() = default;

  static stubber s_stub;
  t_function_call_list m_function_calls;
  t_function_int_results m_function_int_results;
  t_function_double_results m_function_double_results;
};


typedef stubber::function_call::argument t_arg;

#endif /* STUBBER_H_ */

