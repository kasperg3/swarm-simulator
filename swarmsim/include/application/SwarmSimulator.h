#ifndef SWARMSIM_H
#define SWARMSIM_H

#pragma once
#include <memory>
#include <string>

#include "../core/Log.h"
#include "../sim/Simulator.h"
#include "../ui/SimulatorView.h"

namespace SwarmSim
{
    class SwarmSimulator
    {
    public:
        SwarmSimulator(bool hl, std::map<std::string, Robot *> robots, std::list<Widget *> widgetList);
        SwarmSimulator(bool hl, std::shared_ptr<EnvironmentState> state, std::list<Widget *> widgetList);

        ~SwarmSimulator();

        void addRobot(Robot *robot);
        bool hasRobot(std::string rId);
        bool shouldClose();
        void loop();
        void loopOnce();
        void setRobotPosition(std::string, glm::dvec3);

        std::shared_ptr<Simulator> getSimulator();

    private:
        bool mHeadless;
        std::unique_ptr<SimulatorView> mSimulatorView;
        std::shared_ptr<Simulator> mSimulator;

        void customLog(int msgType, const char *text, va_list args);
    };

} // namespace SwarmSim

#endif // SWARMSIM_H
