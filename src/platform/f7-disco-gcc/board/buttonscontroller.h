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


class ButtonsController : public interface::ButtonIrq, public interface::ButtonsControllerCallbackCaller{
public:
	ButtonsController();
	virtual ~ButtonsController();

	void onIrq();
	bool registerCallback(interface::ButtonsControllerCallbackProvider * callbackProvider,
	                                  interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod);
};

#endif /* F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_ */
