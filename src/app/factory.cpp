#include "trace/trace.h"
#include "factory.h"
#include "mdw/button/buttoneventshandler.h"
#include "platform\f7-disco-gcc\board\buttonscontroller.h"
//#include "ButtonEventsLogger.h"


void Factory_initialize()
{

    app::Factory::initialize();

}

void Factory_build()
{
    app::Factory::build();
}



// static
void app::Factory::initialize()
{
}

// static
void app::Factory::build()
{
    Trace::out("Starting program...\n\r---------------------\r");


    ButtonEventsLogger::getInstance().build();

    //starts the buttonsController state machine
    ButtonsController::getInstance().startBehavior();

    ButtonEventsHandler::getInstance().build();

    //starts the ButtonEventsLogger State machine
    ButtonEventsLogger::getInstance().startBehavior();
}
