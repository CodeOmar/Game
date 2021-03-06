/**************************************************************************************************
 * Title:         Message.cpp
 * Author:        Omar Stefan Evans
 * Created on:    2013-11-12
 * Description:   <#Description#>
 * Purpose:       <#Purpose#>
 * Modifications: <#Modifications#>
 **************************************************************************************************/

#include "Message.h"

namespace evansbros {
    namespace game {

        Message::Message() : type(MessageType::GENERIC)
        {
            /* Intentionally Left Blank */
        }

#if (!defined _MSC_VER || _MSC_VER > 1800)
        Message::Message(ButtonEventType buttonEventType, ButtonID buttonID)
        : type(MessageType::BUTTON), buttonEvent(buttonEventType, buttonID)
        {
            /* Intentionally Left Blank */
        }

        Message::Message(MouseEventType mouseEventType, Point2D mouseLocation)
        : type(MessageType::MOUSE), mouseEvent(mouseEventType, mouseLocation)
        {
            /* Intentionally Left Blank */
        }

        Message::Message(ViewportEventType viewportEventType, Size2D size)
        : type(MessageType::VIEWPORT), viewportEvent(viewportEventType, size)
        {
            /* Intentionally Left Blank */
        }
#else
        Message::Message(ButtonEventType buttonEventType, ButtonID buttonID)
		: type(MessageType::BUTTON)
        {
            buttonEvent.type = buttonEventType;
            buttonEvent.id = buttonID;
        }

        Message::Message(MouseEventType mouseEventType, Point2D mouseLocation)
		: type(MessageType::MOUSE)
        {
            mouseEvent.type = mouseEventType;
            mouseEvent.location = mouseLocation;
        }

        Message::Message(ViewportEventType viewportEventType, Size2D size)
        : type(MessageType::VIEWPORT)
        {
            viewportEvent.type = viewportEventType;
            viewportEvent.size = size;
        }
#endif

        MessageType Message::getType() const
        {
            return type;
        }

        ButtonEvent Message::getButtonEvent() const
        {
            if (type != MessageType::BUTTON) {
                throw MessageExceptions::InvalidOperation("This message is not a ButtonEvent");
            }
            return buttonEvent;
        }

        MouseEvent Message::getMouseEvent() const
        {
            if (type != MessageType::MOUSE) {
                throw MessageExceptions::InvalidOperation("This message is not a MouseEvent");
            }
            return mouseEvent;
        }

        ViewportEvent Message::getViewportEvent() const
        {
            if (type != MessageType::VIEWPORT) {
                throw MessageExceptions::InvalidOperation("This message is not a ViewportEvent");
            }
            return viewportEvent;
        }
        
    }
}
