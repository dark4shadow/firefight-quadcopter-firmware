#include <gtest/gtest.h>
#include "core/drone_state_machine.hpp"

class DroneStateMachineTest : public ::testing::Test {
protected:
    DroneStateMachine drone;

    void SetUp() override {
        drone = DroneStateMachine();
    }
};

TEST_F(DroneStateMachineTest, InitialStateIsIdle) {
    EXPECT_EQ(drone.getCurrentState(), DroneState::Idle);
}

TEST_F(DroneStateMachineTest, TransitionToPatrol) {
    drone.startPatrol();
    EXPECT_EQ(drone.getCurrentState(), DroneState::Patrol);
}

TEST_F(DroneStateMachineTest, TransitionToInvestigate) {
    drone.startInvestigate();
    EXPECT_EQ(drone.getCurrentState(), DroneState::Investigate);
}

TEST_F(DroneStateMachineTest, TransitionToExtinguish) {
    drone.startExtinguish();
    EXPECT_EQ(drone.getCurrentState(), DroneState::Extinguish);
}

TEST_F(DroneStateMachineTest, TransitionToReturn) {
    drone.startReturn();
    EXPECT_EQ(drone.getCurrentState(), DroneState::Return);
}

TEST_F(DroneStateMachineTest, ReturnToIdleAfterExtinguish) {
    drone.startExtinguish();
    drone.completeExtinguish();
    EXPECT_EQ(drone.getCurrentState(), DroneState::Idle);
}

TEST_F(DroneStateMachineTest, BatteryLowTriggersReturn) {
    drone.setBatteryLevel(15); // Assuming 15 is below the low battery threshold
    drone.checkBatteryStatus();
    EXPECT_EQ(drone.getCurrentState(), DroneState::Return);
}

TEST_F(DroneStateMachineTest, ManualControlOverridesAuto) {
    drone.startPatrol();
    drone.enableManualControl();
    EXPECT_EQ(drone.getCurrentState(), DroneState::Manual);
}