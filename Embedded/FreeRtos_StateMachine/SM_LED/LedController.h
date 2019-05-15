/*
 * LedController.h
 *
 *  Created on: May 15, 2019
 *      Author: imarian
 */
#include"StateMachine.h"
#include"Dave/Generated/PWM/pwm.h"

#ifndef LEDCONTROLLER_H_
#define LEDCONTROLLER_H_

namespace led_controller {

	namespace state {
		enum States {
			IDLE,
			START,
			CHANGE_LIGHT,
			STOP,
			MAX_STATE
		};
	}

	class LedController : public state_machine::StateMachine {
	public:
		LedController();

		void LightUp(int howMuch);
		void LightDown(int howMuch);
		void Stop();

	private:
		int m_dutyCycle;
		// ON SPEED_UP/SPEED_DOWN EVENTS WE DEFINE OUR TRANSITIONS
		const static int ON_CHANGE_LIGHT_TRANSITIONS[];
		const static int ON_STOP_TRANSITIONS[];

		state_machine::state_action::IStateAction* MappedStatesToAction[4];
		virtual state_machine::state_action::IStateAction* GetFunctionToInvocke(const int& state);

		//we will create functions and some handlers for our functions for each state
		void idle(int);
		state_machine::state_action::StateAction<LedController, &LedController::idle> _idle;

		void start(int);
		state_machine::state_action::StateAction<LedController, &LedController::start> _start;

		void changeLight(int);
		state_machine::state_action::StateAction<LedController, &LedController::changeLight> _changeLight;

		void stop(int);
		state_machine::state_action::StateAction<LedController, &LedController::stop> _stop;
	};
}

#endif /* LEDCONTROLLER_H_ */
