/*
 * LedController.cpp
 *
 *  Created on: May 15, 2019
 *      Author: imarian
 */

#include <SM_LED/LedController.h>

/*						ON_CHANGE_SPEED EVENT
	*	1. If we are in idle state => can go in Start state
	*	2. If we are in start state => we can go in Change_Light state
	*	3. If we are in Change_Light state => we can go in Change_Light state (will not change current state)
	*	4. In case if we are in Stop state => is impossible to go in Change_Light state
*/
const int led_controller::LedController::ON_CHANGE_LIGHT_TRANSITIONS[] = {
	state::START,
	state::CHANGE_LIGHT,
	state::CHANGE_LIGHT,
	state_machine::state::IMPOSIBLE
};

/*							ON_STOP_EVENT
	*	1. If we are in idle state => is impossible to go in Stop state
	*	2. If we are in start state => we can go in Stop state
	*	3. If we are in Change_Light => we can in in Stop state
	*	4. If we already are in Stop state => we cannot go in Stop action
*/
const int led_controller::LedController::ON_STOP_TRANSITIONS[] = {
	state_machine::state::IMPOSIBLE,
	state::STOP,
	state::STOP,
	state_machine::state::IMPOSIBLE
};

led_controller::LedController::LedController(): m_dutyCycle(0) {
	MappedStatesToAction[0] = (state_machine::state_action::IStateAction*) (&_idle);
	MappedStatesToAction[1] = (state_machine::state_action::IStateAction*) (&_start);
	MappedStatesToAction[2] = (state_machine::state_action::IStateAction*) (&_changeLight);
	MappedStatesToAction[3] = (state_machine::state_action::IStateAction*) (&_stop);
}
/* ************** we provide three functions for our consumer **************/
void led_controller::LedController::LightUp(int howMuch) {
	EventHandler(ON_CHANGE_LIGHT_TRANSITIONS[GetCurrentState()], howMuch);
}

void led_controller::LedController::LightDown(int howMuch) {
	howMuch = -howMuch;	//we will subtract from current speed
	EventHandler(ON_CHANGE_LIGHT_TRANSITIONS[GetCurrentState()], howMuch);
}

void led_controller::LedController::Stop() {
	EventHandler(ON_STOP_TRANSITIONS[GetCurrentState()], 0);
	//Once I'm stopped - I will go in idle state
	SetCurrentState(led_controller::state::IDLE);
}

/******************** which function must be called *************************/
state_machine::state_action::IStateAction* led_controller::LedController::GetFunctionToInvocke(const int& state) {
	return MappedStatesToAction[state];
}

/* ********* through those functions we will handle our transitions *********/
void led_controller::LedController::idle(int alhpa = 0) {

}

void led_controller::LedController::start(int alpha) {
	m_dutyCycle = alpha;
	PWM_SetDutyCycle(&LED, m_dutyCycle);
}

void led_controller::LedController::changeLight(int alpha) {
	//this is the range
	if(m_dutyCycle + alpha < 0 || m_dutyCycle + alpha > 10000U)
		return;

	m_dutyCycle += alpha;
	PWM_SetDutyCycle(&LED, m_dutyCycle);
}

void led_controller::LedController::stop(int alpha = 0) {
	m_dutyCycle = 0;
	PWM_SetDutyCycle(&LED, m_dutyCycle);
}
