/*
 * StateMachine.cpp
 *
 *  Created on: May 15, 2019
 *      Author: imarian
 */

#include"StateMachine.h"

state_machine::StateMachine::StateMachine() : m_currentState(0) {

}

void state_machine::StateMachine::EventHandler(int state, int data) {
	if (state != state::IMPOSIBLE) {

		state_action::IStateAction* mappedStates = GetFunctionToInvocke(state);
		(mappedStates->Caller)(this, data);
		m_currentState = state; // or more elegant to call set function to be more generic
	}
}

int state_machine::StateMachine::GetCurrentState() {
	return m_currentState;
}

void state_machine::StateMachine::SetCurrentState(int state) {
	m_currentState = state;
}
