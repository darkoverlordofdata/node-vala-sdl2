/* ApplicationListener.c generated by valac 0.34.9, the Vala compiler
 * generated from ApplicationListener.gs, do not modify */


#include <glib.h>
#include <glib-object.h>


#define SDX_TYPE_APPLICATION_LISTENER (sdx_application_listener_get_type ())
#define SDX_APPLICATION_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_APPLICATION_LISTENER, sdxApplicationListener))
#define SDX_IS_APPLICATION_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_APPLICATION_LISTENER))
#define SDX_APPLICATION_LISTENER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_APPLICATION_LISTENER, sdxApplicationListenerIface))

typedef struct _sdxApplicationListener sdxApplicationListener;
typedef struct _sdxApplicationListenerIface sdxApplicationListenerIface;

struct _sdxApplicationListenerIface {
	GTypeInterface parent_iface;
	void (*create) (sdxApplicationListener* self);
	void (*resize) (sdxApplicationListener* self, gint width, gint height);
	void (*render) (sdxApplicationListener* self);
	void (*pause) (sdxApplicationListener* self);
	void (*resume) (sdxApplicationListener* self);
	void (*dispose) (sdxApplicationListener* self);
};



GType sdx_application_listener_get_type (void) G_GNUC_CONST;
void sdx_application_listener_create (sdxApplicationListener* self);
void sdx_application_listener_resize (sdxApplicationListener* self, gint width, gint height);
void sdx_application_listener_render (sdxApplicationListener* self);
void sdx_application_listener_pause (sdxApplicationListener* self);
void sdx_application_listener_resume (sdxApplicationListener* self);
void sdx_application_listener_dispose (sdxApplicationListener* self);


void sdx_application_listener_create (sdxApplicationListener* self) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_LISTENER_GET_INTERFACE (self)->create (self);
}


void sdx_application_listener_resize (sdxApplicationListener* self, gint width, gint height) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_LISTENER_GET_INTERFACE (self)->resize (self, width, height);
}


void sdx_application_listener_render (sdxApplicationListener* self) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_LISTENER_GET_INTERFACE (self)->render (self);
}


void sdx_application_listener_pause (sdxApplicationListener* self) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_LISTENER_GET_INTERFACE (self)->pause (self);
}


void sdx_application_listener_resume (sdxApplicationListener* self) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_LISTENER_GET_INTERFACE (self)->resume (self);
}


void sdx_application_listener_dispose (sdxApplicationListener* self) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_LISTENER_GET_INTERFACE (self)->dispose (self);
}


static void sdx_application_listener_base_init (sdxApplicationListenerIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType sdx_application_listener_get_type (void) {
	static volatile gsize sdx_application_listener_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_application_listener_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxApplicationListenerIface), (GBaseInitFunc) sdx_application_listener_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType sdx_application_listener_type_id;
		sdx_application_listener_type_id = g_type_register_static (G_TYPE_INTERFACE, "sdxApplicationListener", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (sdx_application_listener_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&sdx_application_listener_type_id__volatile, sdx_application_listener_type_id);
	}
	return sdx_application_listener_type_id__volatile;
}



