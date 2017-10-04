/**
 * FocusListener.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses sdx.utils

namespace sdx.scenes.scene2d.utils

    class abstract FocusListener : Object implements EventListener

        def handle(e: Event): bool
            var event = e as FocusEvent
            if event != null
                case (event).getType()
                    when FocusEvent.FocusEventType.keyboard
                        keyboardFocusChanged(event, event.getTarget(), event.isFocused())
                    when FocusEvent.FocusEventType.scroll
                        scrollFocusChanged(event, event.getTarget(), event.isFocused())
            return false


        def abstract keyboardFocusChanged(event: FocusEvent, actor: Actor, focused: bool)

        def abstract scrollFocusChanged(event: FocusEvent, actor: Actor, focused: bool)

