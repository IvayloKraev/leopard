#ifndef ACTION_TPP
#define ACTION_TPP

template<typename CommandType>
Action<CommandType>::Action(const CommandType& cmd, IAction* cb)
    : command(cmd), callback(cb) {
}

template<typename CommandType>
bool Action<CommandType>::matches(const CommandType& other) const {
    return command == other;
}

template<typename CommandType>
void Action<CommandType>::execute(void* params) const {
    if (callback != nullptr) {
        callback->execute(params);
    }
}

#endif