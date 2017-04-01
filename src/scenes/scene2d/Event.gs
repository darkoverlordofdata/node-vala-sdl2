/**
 * Event.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses sdx.utils

namespace sdx.scenes.scene2d

    interface EventListener : Object
        def abstract handle(event: Event): bool

    class Event: Object implements Poolable
        stage: private Stage
        targetActor: private Actor
        listenerActor: private Actor
        capture: private bool
        bubbles: private bool
        handled: private bool
        stopped: private bool
        cancelled: private bool

        def handle()
            handled = true

        def cancel()
            cancelled = true
            stopped = true
            handled = true

        def stop()
            stopped = true

        def reset()
            stage = null
            targetActor = null
            listenerActor = null
            capture = false
            bubbles = true
            handled = false
            stopped = false
            cancelled = false


        def getTarget(): Actor
            return targetActor

        def setTarget(targetActor:Actor)
            this.targetActor = targetActor

        def getListenerActor(): Actor
            return listenerActor

        def setListenerActor(listenerActor:Actor)
            this.listenerActor = listenerActor

        def getBubbles(): bool
            return bubbles

        def setBubbles(bubbles: bool)
            this.bubbles = bubbles

        def isHandled(): bool
            return handled

        def isStopped(): bool
            return stopped

        def isCancelled(): bool
            return cancelled

        def setCapture(capture:bool)
            this.capture = capture

        def isCapture(): bool
            return capture

        def setStage(stage: Stage)
            this.stage = stage

        def getStage(): Stage
            return stage
            