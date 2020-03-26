/*
 * buttonscontroller.cpp
 *
 *  Created on: 25 mars 2020
 *      Author: meyer
 */

#include <board/buttonscontroller.h>
#include "main.h"

ButtonsController::ButtonsController() {
	// TODO Auto-generated constructor stub

}

ButtonsController::~ButtonsController() {
	// TODO Auto-generated destructor stub
}

void ButtonsController::onIrq() {
}

bool ButtonsController::registerCallback(
		interface::ButtonsControllerCallbackProvider* callbackProvider,
		interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) {
}

XFEventStatus ButtonsController::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;
	eMainState _oldState;

	_oldState = _currentState;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){
			//GEN(XFNullTransition());

			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_CHECK_BUTTONS:

		if(getCurrentEvent()->getId()==evButtonIrq){
			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_DEBOUNCE:

		//if (/*getCurrentEvent()->getEventType() == XFEvent::NullTransition ||*/
		//(getCurrentEvent()->getEventType() == XFEvent::Timeout &&
		//getCurrentTimeout()->getId() == evTimeout)){

		if(getCurrentEvent()->getId()==evTimeout){
			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	}

	//on entry actions
	if(_currentState != _oldState){
	switch(_currentState){
		case STATE_CHECK_BUTTONS:
			doCheckButtons();
			break;
		case STATE_DEBOUNCE:
			scheduleTimeout(evTimeout, 100);
			break;
		}
	}

	return eventStatus;
}

void ButtonsController::doCheckButtons() {
	//GPIO_PIN_SET or RESET
	if(HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port,BUTTON_0_Pin)!=button_state[0]){

	}
	if(HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port,BUTTON_1_Pin)!=button_state[1]){

	}
	if(HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port,BUTTON_2_Pin)!=button_state[2]){

	}
	if(HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port,BUTTON_3_Pin)!=button_state[3]){

	}

	button_state[0]=HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port,BUTTON_0_Pin);
	button_state[1]=HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port,BUTTON_1_Pin);
	button_state[2]=HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port,BUTTON_2_Pin);
	button_state[3]=HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port,BUTTON_3_Pin);
}
