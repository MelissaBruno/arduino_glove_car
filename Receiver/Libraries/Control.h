#ifndef Control_h
#define Control_h

class ControlClass{
  public:
    ControlClass();
    void SETUP();
    void forward();
    void backward();
    void turnLeft();
    void turnRight();
    void release();
};

extern ControlClass control;

#endif
