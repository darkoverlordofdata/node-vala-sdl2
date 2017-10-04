/* Screen.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from Screen.gs, do not modify */


#include <glib.h>
#include <glib-object.h>


#define SDX_TYPE_SCREEN (sdx_screen_get_type ())
#define SDX_SCREEN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_SCREEN, sdxScreen))
#define SDX_IS_SCREEN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_SCREEN))
#define SDX_SCREEN_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_SCREEN, sdxScreenIface))

typedef struct _sdxScreen sdxScreen;
typedef struct _sdxScreenIface sdxScreenIface;

struct _sdxScreenIface {
	GTypeInterface parent_iface;
	void (*show) (sdxScreen* self);
	void (*render) (sdxScreen* self);
	void (*resize) (sdxScreen* self, gint width, gint height);
	void (*pause) (sdxScreen* self);
	void (*resume) (sdxScreen* self);
	void (*hide) (sdxScreen* self);
	void (*dispose) (sdxScreen* self);
};



GType sdx_screen_get_type (void) G_GNUC_CONST;
void sdx_screen_show (sdxScreen* self);
void sdx_screen_render (sdxScreen* self);
void sdx_screen_resize (sdxScreen* self, gint width, gint height);
void sdx_screen_pause (sdxScreen* self);
void sdx_screen_resume (sdxScreen* self);
void sdx_screen_hide (sdxScreen* self);
void sdx_screen_dispose (sdxScreen* self);


void sdx_screen_show (sdxScreen* self) {
	g_return_if_fail (self != NULL);
	SDX_SCREEN_GET_INTERFACE (self)->show (self);
}


void sdx_screen_render (sdxScreen* self) {
	g_return_if_fail (self != NULL);
	SDX_SCREEN_GET_INTERFACE (self)->render (self);
}


void sdx_screen_resize (sdxScreen* self, gint width, gint height) {
	g_return_if_fail (self != NULL);
	SDX_SCREEN_GET_INTERFACE (self)->resize (self, width, height);
}


void sdx_screen_pause (sdxScreen* self) {
	g_return_if_fail (self != NULL);
	SDX_SCREEN_GET_INTERFACE (self)->pause (self);
}


void sdx_screen_resume (sdxScreen* self) {
	g_return_if_fail (self != NULL);
	SDX_SCREEN_GET_INTERFACE (self)->resume (self);
}


void sdx_screen_hide (sdxScreen* self) {
	g_return_if_fail (self != NULL);
	SDX_SCREEN_GET_INTERFACE (self)->hide (self);
}


void sdx_screen_dispose (sdxScreen* self) {
	g_return_if_fail (self != NULL);
	SDX_SCREEN_GET_INTERFACE (self)->dispose (self);
}


static void sdx_screen_base_init (sdxScreenIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType sdx_screen_get_type (void) {
	static volatile gsize sdx_screen_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_screen_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxScreenIface), (GBaseInitFunc) sdx_screen_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType sdx_screen_type_id;
		sdx_screen_type_id = g_type_register_static (G_TYPE_INTERFACE, "sdxScreen", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (sdx_screen_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&sdx_screen_type_id__volatile, sdx_screen_type_id);
	}
	return sdx_screen_type_id__volatile;
}


