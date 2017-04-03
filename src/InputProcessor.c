/* InputProcessor.c generated by valac 0.34.7, the Vala compiler
 * generated from InputProcessor.gs, do not modify */


#include <glib.h>
#include <glib-object.h>


#define SDX_TYPE_INPUT_PROCESSOR (sdx_input_processor_get_type ())
#define SDX_INPUT_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_INPUT_PROCESSOR, sdxInputProcessor))
#define SDX_IS_INPUT_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_INPUT_PROCESSOR))
#define SDX_INPUT_PROCESSOR_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_INPUT_PROCESSOR, sdxInputProcessorIface))

typedef struct _sdxInputProcessor sdxInputProcessor;
typedef struct _sdxInputProcessorIface sdxInputProcessorIface;

struct _sdxInputProcessorIface {
	GTypeInterface parent_iface;
	gboolean (*keyDown) (sdxInputProcessor* self, gint keycode);
	gboolean (*keyUp) (sdxInputProcessor* self, gint keycode);
	gboolean (*keyTyped) (sdxInputProcessor* self, gchar character);
	gboolean (*touchDown) (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
	gboolean (*touchUp) (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
	gboolean (*touchDragged) (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer);
	gboolean (*mouseMoved) (sdxInputProcessor* self, gint screenX, gint screenY);
	gboolean (*scrolled) (sdxInputProcessor* self, gint amount);
};



GType sdx_input_processor_get_type (void) G_GNUC_CONST;
gboolean sdx_input_processor_keyDown (sdxInputProcessor* self, gint keycode);
gboolean sdx_input_processor_keyUp (sdxInputProcessor* self, gint keycode);
gboolean sdx_input_processor_keyTyped (sdxInputProcessor* self, gchar character);
gboolean sdx_input_processor_touchDown (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
gboolean sdx_input_processor_touchUp (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
gboolean sdx_input_processor_touchDragged (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer);
gboolean sdx_input_processor_mouseMoved (sdxInputProcessor* self, gint screenX, gint screenY);
gboolean sdx_input_processor_scrolled (sdxInputProcessor* self, gint amount);


gboolean sdx_input_processor_keyDown (sdxInputProcessor* self, gint keycode) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->keyDown (self, keycode);
}


gboolean sdx_input_processor_keyUp (sdxInputProcessor* self, gint keycode) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->keyUp (self, keycode);
}


gboolean sdx_input_processor_keyTyped (sdxInputProcessor* self, gchar character) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->keyTyped (self, character);
}


gboolean sdx_input_processor_touchDown (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->touchDown (self, screenX, screenY, pointer, button);
}


gboolean sdx_input_processor_touchUp (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->touchUp (self, screenX, screenY, pointer, button);
}


gboolean sdx_input_processor_touchDragged (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->touchDragged (self, screenX, screenY, pointer);
}


gboolean sdx_input_processor_mouseMoved (sdxInputProcessor* self, gint screenX, gint screenY) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->mouseMoved (self, screenX, screenY);
}


gboolean sdx_input_processor_scrolled (sdxInputProcessor* self, gint amount) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_INPUT_PROCESSOR_GET_INTERFACE (self)->scrolled (self, amount);
}


static void sdx_input_processor_base_init (sdxInputProcessorIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType sdx_input_processor_get_type (void) {
	static volatile gsize sdx_input_processor_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_input_processor_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxInputProcessorIface), (GBaseInitFunc) sdx_input_processor_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType sdx_input_processor_type_id;
		sdx_input_processor_type_id = g_type_register_static (G_TYPE_INTERFACE, "sdxInputProcessor", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (sdx_input_processor_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&sdx_input_processor_type_id__volatile, sdx_input_processor_type_id);
	}
	return sdx_input_processor_type_id__volatile;
}



