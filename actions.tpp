#ifndef ACTIONS_TPP
#define ACTIONS_TPP

template<typename CommandType>
Actions<CommandType>::Actions(IAction* defaultAction)
    : num(0), capacity(0), defaultAction(defaultAction), actionsArr(nullptr) {
}

template<typename CommandType>
Actions<CommandType>::~Actions() {
    delete[] actionsArr;
}

template<typename CommandType>
void Actions<CommandType>::registerCommandAction(
    const CommandType& command,
    IAction* action
) {
    if (num >= capacity) {
        resizeTo(capacity == 0 ? 2 : capacity * 2);
    }

    actionsArr[num] = Action<CommandType>(command, action);
    num++;
}

template<typename CommandType>
void Actions<CommandType>::executeCommandAction(
    const CommandType& command,
    void* params
) {
    for (size_t i = 0; i < num; i++) {
        if (actionsArr[i].matches(command)) {
            actionsArr[i].execute(params);
            return;
        }
    }

    executeDefaultAction(params);
}

template<typename CommandType>
void Actions<CommandType>::executeDefaultAction(void* params) {
    if (defaultAction != nullptr) {
        defaultAction->execute(params);
    }
}

template<typename CommandType>
void Actions<CommandType>::resizeTo(size_t newCapacity) {
    Action<CommandType>* newArr = new Action<CommandType>[newCapacity];

    for (size_t i = 0; i < num; i++) {
        newArr[i] = actionsArr[i];
    }

    delete[] actionsArr;
    actionsArr = newArr;
    capacity = newCapacity;
}

#endif