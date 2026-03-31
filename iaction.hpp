#ifndef IACTIONS_HPP
#define IACTIONS_HPP

class IAction {
public:
    virtual ~IAction() {}
    virtual void execute(void* params = nullptr) = 0;
};

#endif