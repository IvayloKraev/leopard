#include <stddef.h>

typedef int command_t;
typedef void(*action_t)(void*);

typedef struct {
  command_t command;
  action_t action;
} Action;

class Actions {
private:
  size_t num;
  size_t capacity;
  action_t defaultAction;
  Action* actionsArr;
public:
  Actions(action_t defaultAction);
  ~Actions();
  void resizeTo(size_t capacity);
  void registerCommandAction(command_t command, action_t action);
  void executeCommandAction(command_t command, void* actionParams);
  void executeDefaultAction(void* actionParams);
};
