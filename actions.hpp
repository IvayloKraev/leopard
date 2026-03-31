#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <stddef.h>

#include "iaction.hpp"
#include "action.hpp"

template<typename CommandType>
class Actions {
public:
  Actions(IAction* defaultAction);
  Actions(const Actions&) = delete;
  ~Actions();

  Actions& operator=(const Actions&) = delete;

  void registerCommandAction(const CommandType& command, IAction* action);
  void executeCommandAction(const CommandType& command, void* actionParams);
  void executeDefaultAction(void* actionParams);
private:
  size_t num;
  size_t capacity;
  IAction* defaultAction;
  Action<CommandType>* actionsArr;
  void resizeTo(size_t capacity);
};

#include "actions.tpp"

#endif