#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H


struct InputListener
{
    virtual void HandleClick();
    virtual void HandleDelta();
};

#endif // INPUTLISTENER_H
