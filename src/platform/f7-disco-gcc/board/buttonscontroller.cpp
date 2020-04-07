/*
 * buttonscontroller.cpp
 *
 *  Created on: 25 mars 2020
 *      Author: meyer
 */

#include <board/buttonscontroller.h>

#include "mdw\trace\trace.h"
#include "event\evbuttonirq.h"
#include "main.h"

ButtonsController::ButtonsController() {
	_currentState = STATE_INITIAL;
	button_state[0] = GPIO_PIN_SET;
	button_state[1] = GPIO_PIN_SET;
	button_state[2] = GPIO_PIN_SET;
	button_state[3] = GPIO_PIN_SET;
	callbackMethod=0;
	callbackProvider=0;
}

ButtonsController::~ButtonsController() {

}

void ButtonsController::onIrq() {
	//create event and push it
	static evButtonIrq e;
	this->pushEvent(&e);
}

//Called by a provider
bool ButtonsController::registerCallback(
		interface::ButtonsControllerCallbackProvider* callbackProvider,
		interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) {
	this->callbackProvider=callbackProvider;
	this->callbackMethod=callbackMethod;

}

XFEventStatus ButtonsController::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;
	eMainState _oldState;

	_oldState = _currentState;

	//Transition switch
	switch(_currentState){
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType()==XFEvent::Initial){
			//Initial transition
			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_CHECK_BUTTONS:

		//on button event
		if (getCurrentEvent()->getEventType()==XFEvent::Event
				&& getCurrentEvent()->getId() == evButtonIrqId){
			//change the current state
			_currentState = STATE_DEBOUNCE;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_DEBOUNCE:

		//on timeout
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
		getCurrentTimeout()->getId() == _evTimeout){
			//change the current state
			_currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	default:
		break;
	}

	//on entry actions
	if(_currentState != _oldState){
		switch(_currentState){
			case STATE_CHECK_BUTTONS:
				doCheckButtons();
				break;
			case STATE_DEBOUNCE:
				//start a timer
				scheduleTimeout(_evTimeout, 100);
				break;

			default:
				break;
		}
	}

	return eventStatus;
}

//check if button changed and notify the provider
void ButtonsController::doCheckButtons() {

	//Button 0
	if(HAL_GPIO_ReadPin(BUTTON0_GPIO_Port,BUTTON0_Pin)!=this->button_state[0]){
		if(HAL_GPIO_ReadPin(BUTTON0_GPIO_Port,BUTTON0_Pin)==GPIO_PIN_RESET){
			(callbackProvider->*callbackMethod)(BUTTON0_Pin,true);
		}
		else{
			(callbackProvider->*callbackMethod)(BUTTON0_Pin,false);
		}

		button_state[0]=HAL_GPIO_ReadPin(BUTTON0_GPIO_Port,BUTTON0_Pin);
	}

	//Button 1
	if(HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin)!=button_state[1]){
		if(HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin)==GPIO_PIN_RESET){
			(callbackProvider->*callbackMethod)(BUTTON1_Pin,true);
		}
		else{
			(callbackProvider->*callbackMethod)(BUTTON1_Pin,false);
		}
		button_state[1]=HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin);
	}

	//Button 2
	if(HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,BUTTON2_Pin)!=button_state[2]){
		if(HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,BUTTON2_Pin)==GPIO_PIN_RESET){
			(callbackProvider->*callbackMethod)(BUTTON2_Pin,true);
		}
		else{
			(callbackProvider->*callbackMethod)(BUTTON2_Pin,false);
		}
		button_state[2]=HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,BUTTON2_Pin);
	}

	//Button 3
	if(HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,BUTTON3_Pin)!=button_state[3]){
		if(HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,BUTTON3_Pin)==GPIO_PIN_RESET){
			(callbackProvider->*callbackMethod)(BUTTON3_Pin,true);
		}
		else{
			(callbackProvider->*callbackMethod)(BUTTON3_Pin,false);
		}
		button_state[3]=HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,BUTTON3_Pin);
	}
}
