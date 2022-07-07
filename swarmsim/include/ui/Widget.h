#ifndef WIDGET_H
#define WIDGET_H

#pragma once
#include "EnvironmentState.h"
namespace SwarmSim {
class Widget {
   public:
    virtual void draw() = 0;
    virtual void update(std::shared_ptr<EnvironmentState>) = 0;

   protected:
    void dragFloat(const char *name, float *value, float steps, float min, float max);
    void begin(const char *widgetName);
    void end();
    bool button(const char *);
};
}  // namespace SwarmSim

#endif