#ifndef DRONE_STATE_MACHINE_HPP
#define DRONE_STATE_MACHINE_HPP

#include <string>

class DroneStateMachine {
public:
    enum class State {
        Idle,
        Patrol,
        Investigate,
        Extinguish,
        Return,
        Manual
    };

    DroneStateMachine();

    void update();
    void setState(State newState);
    State getCurrentState() const;
    std::string getCurrentStateName() const;

private:
    State currentState;
    void handleIdleState();
    void handlePatrolState();
    void handleInvestigateState();
    void handleExtinguishState();
    void handleReturnState();
    void handleManualState();
};

#endif // DRONE_STATE_MACHINE_HPP