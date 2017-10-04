/* InputAdapter.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from InputAdapter.gs, do not modify */


#include <glib.h>
#include <glib-object.h>


#define SDX_TYPE_INPUT_PROCESSOR (sdx_input_processor_get_type ())
#define SDX_INPUT_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_INPUT_PROCESSOR, sdxInputProcessor))
#define SDX_IS_INPUT_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_INPUT_PROCESSOR))
#define SDX_INPUT_PROCESSOR_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_INPUT_PROCESSOR, sdxInputProcessorIface))

typedef struct _sdxInputProcessor sdxInputProcessor;
typedef struct _sdxInputProcessorIface sdxInputProcessorIface;

#define SDX_TYPE_INPUT_ADAPTER (sdx_input_adapter_get_type ())
#define SDX_INPUT_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_INPUT_ADAPTER, sdxInputAdapter))
#define SDX_INPUT_ADAPTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_INPUT_ADAPTER, sdxInputAdapterClass))
#define SDX_IS_INPUT_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_INPUT_ADAPTER))
#define SDX_IS_INPUT_ADAPTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_INPUT_ADAPTER))
#define SDX_INPUT_ADAPTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_INPUT_ADAPTER, sdxInputAdapterClass))

typedef struct _sdxInputAdapter sdxInputAdapter;
typedef struct _sdxInputAdapterClass sdxInputAdapterClass;
typedef struct _sdxInputAdapterPrivate sdxInputAdapterPrivate;

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

struct _sdxInputAdapter {
	GObject parent_instance;
	sdxInputAdapterPrivate * priv;
};

struct _sdxInputAdapterClass {
	GObjectClass parent_class;
};


static gpointer sdx_input_adapter_parent_class = NULL;
static sdxInputProcessorIface * sdx_input_adapter_sdx_input_processor_parent_iface = NULL;

GType sdx_input_processor_get_type (void) G_GNUC_CONST;
GType sdx_input_adapter_get_type (void) G_GNUC_CONST;
enum  {
	SDX_INPUT_ADAPTER_DUMMY_PROPERTY
};
static gboolean sdx_input_adapter_real_keyDown (sdxInputProcessor* base, gint keycode);
static gboolean sdx_input_adapter_real_keyUp (sdxInputProcessor* base, gint keycode);
static gboolean sdx_input_adapter_real_keyTyped (sdxInputProcessor* base, gchar character);
static gboolean sdx_input_adapter_real_touchDown (sdxInputProcessor* base, gint screenX, gint screenY, gint pointer, gint button);
static gboolean sdx_input_adapter_real_touchUp (sdxInputProcessor* base, gint screenX, gint screenY, gint pointer, gint button);
static gboolean sdx_input_adapter_real_touchDragged (sdxInputProcessor* base, gint screenX, gint screenY, gint pointer);
static gboolean sdx_input_adapter_real_mouseMoved (sdxInputProcessor* base, gint screenX, gint screenY);
static gboolean sdx_input_adapter_real_scrolled (sdxInputProcessor* base, gint amount);
sdxInputAdapter* sdx_input_adapter_new (void);
sdxInputAdapter* sdx_input_adapter_construct (GType object_type);


static gboolean sdx_input_adapter_real_keyDown (sdxInputProcessor* base, gint keycode) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


static gboolean sdx_input_adapter_real_keyUp (sdxInputProcessor* base, gint keycode) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


static gboolean sdx_input_adapter_real_keyTyped (sdxInputProcessor* base, gchar character) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


static gboolean sdx_input_adapter_real_touchDown (sdxInputProcessor* base, gint screenX, gint screenY, gint pointer, gint button) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


static gboolean sdx_input_adapter_real_touchUp (sdxInputProcessor* base, gint screenX, gint screenY, gint pointer, gint button) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


static gboolean sdx_input_adapter_real_touchDragged (sdxInputProcessor* base, gint screenX, gint screenY, gint pointer) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


static gboolean sdx_input_adapter_real_mouseMoved (sdxInputProcessor* base, gint screenX, gint screenY) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


static gboolean sdx_input_adapter_real_scrolled (sdxInputProcessor* base, gint amount) {
	sdxInputAdapter * self;
	gboolean result = FALSE;
	self = (sdxInputAdapter*) base;
	result = FALSE;
	return result;
}


sdxInputAdapter* sdx_input_adapter_construct (GType object_type) {
	sdxInputAdapter * self = NULL;
	self = (sdxInputAdapter*) g_object_new (object_type, NULL);
	return self;
}


sdxInputAdapter* sdx_input_adapter_new (void) {
	return sdx_input_adapter_construct (SDX_TYPE_INPUT_ADAPTER);
}


static void sdx_input_adapter_class_init (sdxInputAdapterClass * klass) {
	sdx_input_adapter_parent_class = g_type_class_peek_parent (klass);
}


static void sdx_input_adapter_sdx_input_processor_interface_init (sdxInputProcessorIface * iface) {
	sdx_input_adapter_sdx_input_processor_parent_iface = g_type_interface_peek_parent (iface);
	iface->keyDown = (gboolean (*) (sdxInputProcessor *, gint)) sdx_input_adapter_real_keyDown;
	iface->keyUp = (gboolean (*) (sdxInputProcessor *, gint)) sdx_input_adapter_real_keyUp;
	iface->keyTyped = (gboolean (*) (sdxInputProcessor *, gchar)) sdx_input_adapter_real_keyTyped;
	iface->touchDown = (gboolean (*) (sdxInputProcessor *, gint, gint, gint, gint)) sdx_input_adapter_real_touchDown;
	iface->touchUp = (gboolean (*) (sdxInputProcessor *, gint, gint, gint, gint)) sdx_input_adapter_real_touchUp;
	iface->touchDragged = (gboolean (*) (sdxInputProcessor *, gint, gint, gint)) sdx_input_adapter_real_touchDragged;
	iface->mouseMoved = (gboolean (*) (sdxInputProcessor *, gint, gint)) sdx_input_adapter_real_mouseMoved;
	iface->scrolled = (gboolean (*) (sdxInputProcessor *, gint)) sdx_input_adapter_real_scrolled;
}


static void sdx_input_adapter_instance_init (sdxInputAdapter * self) {
}


GType sdx_input_adapter_get_type (void) {
	static volatile gsize sdx_input_adapter_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_input_adapter_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxInputAdapterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_input_adapter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxInputAdapter), 0, (GInstanceInitFunc) sdx_input_adapter_instance_init, NULL };
		static const GInterfaceInfo sdx_input_processor_info = { (GInterfaceInitFunc) sdx_input_adapter_sdx_input_processor_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType sdx_input_adapter_type_id;
		sdx_input_adapter_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxInputAdapter", &g_define_type_info, 0);
		g_type_add_interface_static (sdx_input_adapter_type_id, SDX_TYPE_INPUT_PROCESSOR, &sdx_input_processor_info);
		g_once_init_leave (&sdx_input_adapter_type_id__volatile, sdx_input_adapter_type_id);
	}
	return sdx_input_adapter_type_id__volatile;
}



