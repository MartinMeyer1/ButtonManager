/*
 * buttonscontroller.h
 *
 *  Created on: 25 mars 2020
 *      Author: meyer
 */

#ifndef F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_
#define F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_


#include "interface\buttonirq.h"
#include "interface\buttonscontrollercallbackcaller.h"
#include "xf\include\xf\behavior.h"
#include "main.h"


class ButtonsController : public interface::ButtonIrq, public interface::ButtonsControllerCallbackCaller, public XFBehavior{
public:
	//singleton pattern
	static ButtonsController& getInstance()
	{
		static ButtonsController instance;
		return instance;
	}

	//from interfaces
	virtual void onIrq();
	bool registerCallback(interface::ButtonsControllerCallbackProvider * callbackProvider,
	                                  interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod);


protected:
	ButtonsController();
	virtual ~ButtonsController();
	ButtonsController(const ButtonsController&){}
	void operator=(const ButtonsController&){}


	virtual XFEventStatus processEvent();								///< Remplementation from XFBehavior

	void doCheckButtons();

	/**
	 * Timeout identifier(s) for this state machine
	 */
	typedef enum
	{
		_evTimeout = 1,	///< Timeout id for WAIT
	} eEventId;

	/**
	 * Enumeration used to have a unique identifier for every
	 * state in the state machine.
	 */
	typedef enum
	{
		STATE_UNKNOWN = 0,			///< Unknown state
		STATE_INITIAL = 1,			///< Initial state
		STATE_CHECK_BUTTONS = 2,	///< check button state
		STATE_DEBOUNCE	 = 3		///< debounce state
	} eMainState;

	eMainState _currentState;		///< Attribute indicating currently active state

private:
	//to store the old button state
	GPIO_PinState button_state[4];

	//callback pattern
	interface::ButtonsControllerCallbackProvider* callbackProvider;
	interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod;

};

#endif /* F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_ */
