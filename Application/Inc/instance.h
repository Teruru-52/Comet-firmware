/*
 * instance.h
 *
 *  Created on: June 13th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include "hardware/led.h"
#include "hardware/speaker.h"
#include "hardware/ir_sensor.h"
#include "controller/controller.h"
#include "controller/tracking.h"
#include "controller/pid_controller.h"
#include "controller/trajectory.h"
#include "machine_state.h"

#include "MazeSolver_conf.h"
#include "Maze.h"
#include "mazeData.h"
#include "ShortestPath.h"
#include "Agent.h"
#include "Operation.h"

extern hardware::LED led;
extern hardware::Speaker speaker;
extern hardware::IRsensor irsensors;
extern Maze maze;
extern Maze maze_backup;
extern Agent agent;
// extern State state;
// extern undercarriage::Controller controller;

#endif // INSTANCE_H_