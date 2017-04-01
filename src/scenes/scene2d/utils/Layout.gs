/**
 * Layout.gs
 *
 * 
 *
 */
[indent=4]
namespace sdx.scenes.scene2d.utils

    interface Layout : Object
        def abstract layout()
        def abstract invalidate()
        def abstract invalidateHierarchy()
        def abstract validate()
        def abstract pack()
        def abstract setFillParent(fillParent: bool)
        def abstract setLayoutEnabled(enabled: bool)
        def abstract getMinWidth(): double
        def abstract getMinHeight(): double
        def abstract getPrefWidth(): double
        def abstract getPrefHeight(): double
        def abstract getMaxWidth(): double
        def abstract getMaxHeight(): double
        