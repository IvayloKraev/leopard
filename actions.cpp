#include "actions.hpp"

Actions::Actions(action_t defaultAction)
  : num(0), capacity(0), defaultAction(defaultAction), actionsArr(nullptr) {
}

Actions::~Actions() {
  delete[] actionsArr;
}

void Actions::resizeTo(size_t capacity) {
  Action* newArr = new Action[capacity];

  for (size_t i = 0; i < num; i++) {
    newArr[i] = this->actionsArr[i];
  }

  delete[] this->actionsArr;
  this->actionsArr = newArr;
  this->capacity = capacity;
}

void Actions::registerCommandAction(command_t command, action_t action) {
  if (this->num >= this->capacity) {
    resizeTo(this->capacity == 0 ? 2 : this->capacity * 2);
  }

  this->actionsArr[num].command = command;
  this->actionsArr[num].action = action;
  num++;
}

void Actions::executeCommandAction(command_t command, void* actionParams) {
  for (size_t i = 0; i < num; i++) {
    if (actionsArr[i].command == command) {
      if (actionsArr[i].action != nullptr) {
        actionsArr[i].action(actionParams);
      }
      return;
    }
  }

  executeDefaultAction(actionParams);
}

void Actions::executeDefaultAction(void* actionParams) {
  if (defaultAction != nullptr) {
    defaultAction(actionParams);
  }
}