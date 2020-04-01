#ifndef FACTORY_H
#define FACTORY_H

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

// TODO: Add C++ specific includes here
//#include "statemachine01.h"
//#include "platform\f7-disco-gcc\board\buttonscontroller.h"
//#include "ButtonEventsLogger.h"

namespace app
{

class Factory
{
public:
    Factory();

    static void initialize();           ///< Initializes the factory
    static void build();                ///< Creates components and initializes relations

protected:
    // TODO: Add static attributes here
	//static StateMachine01 _task01;      ///< First instance of StateMachine01
	//static ButtonsController bc;      	///< First instance of buttonscontroller
	//static ButtonEventsHandler beh;


private:
	//ButtonEventsLogger btel;//TODO maybe constructor

};

} /* namespace app */
#endif // __cplusplus

//
// What is seen by the C and C++ compiler
//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void Factory_initialize();
void Factory_build();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FACTORY_H
