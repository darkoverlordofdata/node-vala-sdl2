/* Layout.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from Layout.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>


#define SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT (sdx_scenes_scene2d_utils_layout_get_type ())
#define SDX_SCENES_SCENE2D_UTILS_LAYOUT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT, sdxscenesscene2dutilsLayout))
#define SDX_SCENES_SCENE2D_UTILS_IS_LAYOUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT))
#define SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT, sdxscenesscene2dutilsLayoutIface))

typedef struct _sdxscenesscene2dutilsLayout sdxscenesscene2dutilsLayout;
typedef struct _sdxscenesscene2dutilsLayoutIface sdxscenesscene2dutilsLayoutIface;

struct _sdxscenesscene2dutilsLayoutIface {
	GTypeInterface parent_iface;
	void (*layout) (sdxscenesscene2dutilsLayout* self);
	void (*invalidate) (sdxscenesscene2dutilsLayout* self);
	void (*invalidateHierarchy) (sdxscenesscene2dutilsLayout* self);
	void (*validate) (sdxscenesscene2dutilsLayout* self);
	void (*pack) (sdxscenesscene2dutilsLayout* self);
	void (*setFillParent) (sdxscenesscene2dutilsLayout* self, gboolean fillParent);
	void (*setLayoutEnabled) (sdxscenesscene2dutilsLayout* self, gboolean enabled);
	gdouble (*getMinWidth) (sdxscenesscene2dutilsLayout* self);
	gdouble (*getMinHeight) (sdxscenesscene2dutilsLayout* self);
	gdouble (*getPrefWidth) (sdxscenesscene2dutilsLayout* self);
	gdouble (*getPrefHeight) (sdxscenesscene2dutilsLayout* self);
	gdouble (*getMaxWidth) (sdxscenesscene2dutilsLayout* self);
	gdouble (*getMaxHeight) (sdxscenesscene2dutilsLayout* self);
};



GType sdx_scenes_scene2d_utils_layout_get_type (void) G_GNUC_CONST;
void sdx_scenes_scene2d_utils_layout_layout (sdxscenesscene2dutilsLayout* self);
void sdx_scenes_scene2d_utils_layout_invalidate (sdxscenesscene2dutilsLayout* self);
void sdx_scenes_scene2d_utils_layout_invalidateHierarchy (sdxscenesscene2dutilsLayout* self);
void sdx_scenes_scene2d_utils_layout_validate (sdxscenesscene2dutilsLayout* self);
void sdx_scenes_scene2d_utils_layout_pack (sdxscenesscene2dutilsLayout* self);
void sdx_scenes_scene2d_utils_layout_setFillParent (sdxscenesscene2dutilsLayout* self, gboolean fillParent);
void sdx_scenes_scene2d_utils_layout_setLayoutEnabled (sdxscenesscene2dutilsLayout* self, gboolean enabled);
gdouble sdx_scenes_scene2d_utils_layout_getMinWidth (sdxscenesscene2dutilsLayout* self);
gdouble sdx_scenes_scene2d_utils_layout_getMinHeight (sdxscenesscene2dutilsLayout* self);
gdouble sdx_scenes_scene2d_utils_layout_getPrefWidth (sdxscenesscene2dutilsLayout* self);
gdouble sdx_scenes_scene2d_utils_layout_getPrefHeight (sdxscenesscene2dutilsLayout* self);
gdouble sdx_scenes_scene2d_utils_layout_getMaxWidth (sdxscenesscene2dutilsLayout* self);
gdouble sdx_scenes_scene2d_utils_layout_getMaxHeight (sdxscenesscene2dutilsLayout* self);


void sdx_scenes_scene2d_utils_layout_layout (sdxscenesscene2dutilsLayout* self) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->layout (self);
}


void sdx_scenes_scene2d_utils_layout_invalidate (sdxscenesscene2dutilsLayout* self) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->invalidate (self);
}


void sdx_scenes_scene2d_utils_layout_invalidateHierarchy (sdxscenesscene2dutilsLayout* self) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->invalidateHierarchy (self);
}


void sdx_scenes_scene2d_utils_layout_validate (sdxscenesscene2dutilsLayout* self) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->validate (self);
}


void sdx_scenes_scene2d_utils_layout_pack (sdxscenesscene2dutilsLayout* self) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->pack (self);
}


void sdx_scenes_scene2d_utils_layout_setFillParent (sdxscenesscene2dutilsLayout* self, gboolean fillParent) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->setFillParent (self, fillParent);
}


void sdx_scenes_scene2d_utils_layout_setLayoutEnabled (sdxscenesscene2dutilsLayout* self, gboolean enabled) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->setLayoutEnabled (self, enabled);
}


gdouble sdx_scenes_scene2d_utils_layout_getMinWidth (sdxscenesscene2dutilsLayout* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->getMinWidth (self);
}


gdouble sdx_scenes_scene2d_utils_layout_getMinHeight (sdxscenesscene2dutilsLayout* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->getMinHeight (self);
}


gdouble sdx_scenes_scene2d_utils_layout_getPrefWidth (sdxscenesscene2dutilsLayout* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->getPrefWidth (self);
}


gdouble sdx_scenes_scene2d_utils_layout_getPrefHeight (sdxscenesscene2dutilsLayout* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->getPrefHeight (self);
}


gdouble sdx_scenes_scene2d_utils_layout_getMaxWidth (sdxscenesscene2dutilsLayout* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->getMaxWidth (self);
}


gdouble sdx_scenes_scene2d_utils_layout_getMaxHeight (sdxscenesscene2dutilsLayout* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE (self)->getMaxHeight (self);
}


static void sdx_scenes_scene2d_utils_layout_base_init (sdxscenesscene2dutilsLayoutIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType sdx_scenes_scene2d_utils_layout_get_type (void) {
	static volatile gsize sdx_scenes_scene2d_utils_layout_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_scenes_scene2d_utils_layout_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxscenesscene2dutilsLayoutIface), (GBaseInitFunc) sdx_scenes_scene2d_utils_layout_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType sdx_scenes_scene2d_utils_layout_type_id;
		sdx_scenes_scene2d_utils_layout_type_id = g_type_register_static (G_TYPE_INTERFACE, "sdxscenesscene2dutilsLayout", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (sdx_scenes_scene2d_utils_layout_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&sdx_scenes_scene2d_utils_layout_type_id__volatile, sdx_scenes_scene2d_utils_layout_type_id);
	}
	return sdx_scenes_scene2d_utils_layout_type_id__volatile;
}


