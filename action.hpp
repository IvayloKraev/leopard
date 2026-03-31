#ifndef ACTION_HPP
#define ACTION_HPP

#include "iaction.hpp"

template<typename CommandType>
class Action {
public:
  Action() = default;
  Action(const CommandType& cmd, IAction* cb);
  ~Action() = default;
  bool matches(const CommandType& other) const;
  void execute(void* params) const;
private:
  CommandType command;
  IAction* callback;
};

#include "action.tpp"

#endif
