/**
 * FocusListener.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses sdx.utils
uses sdx.scenes.scene2d
namespace sdx.scenes.scene2d.utils

    class FocusEvent: Event implements Poolable
        focused: bool
        type: FocusEventType
        relatedActor: Actor

        enum static FocusEventType
            keyboard
            scroll

        def reset() 
            super.reset()
            relatedActor = null

        def isFocused(): bool   
            return focused

        def setFocused(focused: bool)
            this.focused = focused

        def getType(): FocusEventType
            return type

        def setType(focusType: FocusEventType)
            type = focusType

        def getRelatedActor(): Actor
            return relatedActor

        def setRelatedActor(relatedActor: Actor)
            this.relatedActor = relatedActor

