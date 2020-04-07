/*
 * buttoneventshandler.h
 *
 *  Created on: 1 avr. 2020
 *      Author: meyer
 */

#ifndef BUTTON_BUTTONEVENTSHANDLER_H_
#define BUTTON_BUTTONEVENTSHANDLER_H_

#include "interface/buttonscontrollercallbackprovider.h"
#include "interface/buttoneventshandlerobserver.h"
#include "interface/buttoneventshandlersubject.h"
#include "interface/buttonscontrollercallbackcaller.h"

#include "buttonstatesm.h"

#include <list>
#include <iterator>

class ButtonEventsHandler : public interface::ButtonsControllerCallbackProvider, public interface::ButtonEventsHandlerSubject {
public:
	//singleton pattern
	static ButtonEventsHandler& getInstance()
		{
			static ButtonEventsHandler instance;
			return instance;
		}
	virtual bool subscribe(interface::ButtonEventsHandlerObserver * observer);			    ///< @brief Registers a new observer. Returns true on success.
	virtual void unsubscribe(interface::ButtonEventsHandlerObserver * observer);	        ///< @brief Un-subscribes a registered observer.

	void onButtonChanged(uint16_t buttonIndex, bool pressed);
	void build();

	virtual void notifyButtonShortPressed(ButtonIndex buttonIndex);	            ///< @brief Notifies observers about a button short pressed.
	virtual void notifyButtonLongPressed(ButtonIndex buttonIndex);              ///< @brief Notifies observers about a button long pressed.


protected:
	ButtonEventsHandler();
	virtual ~ButtonEventsHandler();

	ButtonEventsHandler(const ButtonEventsHandler&){}
	void operator=(const ButtonEventsHandler&){}
	std::list <interface::ButtonEventsHandlerObserver *> obsList;

	ButtonStateSm sm[4];//the 4 state machines for the 4 buttons


private:

};

#endif /* BUTTON_BUTTONEVENTSHANDLER_H_ */
