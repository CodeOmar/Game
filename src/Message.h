/**************************************************************************************************
 * Title:         Message.h
 * Author:        Omar Stefan Evans
 * Created on:    2013-11-12
 * Description:   <#Description#>
 * Purpose:       <#Purpose#>
 * Modifications: <#Modifications#>
 **************************************************************************************************/

#pragma once

#include "types.h"

#include "ButtonEvent.h"
#include "MouseEvent.h"
#include "ViewportEvent.h"

#include <stdexcept>
namespace evansbros {
	namespace game {

		namespace MessageExceptions {
			class InvalidOperation : public std::runtime_error {
			public:
				InvalidOperation(string what) : std::runtime_error(what) {}
			};
		}

		enum class MessageType : natural {
			GENERIC,
			BUTTON,
			MOUSE,
            VIEWPORT
		};

		class Message {
			MessageType type;
			union {
				ButtonEvent buttonEvent;
				MouseEvent mouseEvent;
                ViewportEvent viewportEvent;
			};

		public:
			Message();
			Message(ButtonEventType buttonEventType, ButtonID buttonID);
			Message(MouseEventType mouseEventType, Point2D mouseLocation);
            Message(ViewportEventType viewportEventType, Size2D size);

			MessageType getType() const;
			ButtonEvent getButtonEvent() const;
			MouseEvent getMouseEvent() const;
            ViewportEvent getViewportEvent() const;
		};
        
	}
}