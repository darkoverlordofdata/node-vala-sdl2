/* Drawable.c generated by valac 0.34.7, the Vala compiler
 * generated from Drawable.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>


#define SDX_SCENES_SCENE2D_UTILS_TYPE_DRAWABLE (sdx_scenes_scene2d_utils_drawable_get_type ())
#define SDX_SCENES_SCENE2D_UTILS_DRAWABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_DRAWABLE, sdxscenesscene2dutilsDrawable))
#define SDX_SCENES_SCENE2D_UTILS_IS_DRAWABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_DRAWABLE))
#define SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_DRAWABLE, sdxscenesscene2dutilsDrawableIface))

typedef struct _sdxscenesscene2dutilsDrawable sdxscenesscene2dutilsDrawable;
typedef struct _sdxscenesscene2dutilsDrawableIface sdxscenesscene2dutilsDrawableIface;

#define SDX_GRAPHICS_S2D_TYPE_BATCH (sdx_graphics_s2d_batch_get_type ())
#define SDX_GRAPHICS_S2D_BATCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_S2D_TYPE_BATCH, sdxgraphicss2dBatch))
#define SDX_GRAPHICS_S2D_BATCH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_S2D_TYPE_BATCH, sdxgraphicss2dBatchClass))
#define SDX_GRAPHICS_S2D_IS_BATCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_S2D_TYPE_BATCH))
#define SDX_GRAPHICS_S2D_IS_BATCH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_S2D_TYPE_BATCH))
#define SDX_GRAPHICS_S2D_BATCH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_S2D_TYPE_BATCH, sdxgraphicss2dBatchClass))

typedef struct _sdxgraphicss2dBatch sdxgraphicss2dBatch;
typedef struct _sdxgraphicss2dBatchClass sdxgraphicss2dBatchClass;

struct _sdxscenesscene2dutilsDrawableIface {
	GTypeInterface parent_iface;
	void (*draw) (sdxscenesscene2dutilsDrawable* self, sdxgraphicss2dBatch* batch, gdouble x, gdouble y, gdouble width, gdouble height);
	gdouble (*getLeftWidth) (sdxscenesscene2dutilsDrawable* self);
	void (*setLeftWidth) (sdxscenesscene2dutilsDrawable* self, gdouble leftWidth);
	gdouble (*getRightWidth) (sdxscenesscene2dutilsDrawable* self);
	void (*setRightWidth) (sdxscenesscene2dutilsDrawable* self, gdouble rightWidth);
	gdouble (*getTopHeight) (sdxscenesscene2dutilsDrawable* self);
	void (*setTopHeight) (sdxscenesscene2dutilsDrawable* self, gdouble topHeight);
	gdouble (*getBottomHeight) (sdxscenesscene2dutilsDrawable* self);
	void (*setBottomHeight) (sdxscenesscene2dutilsDrawable* self, gdouble bottomHeight);
	gdouble (*getMinWidth) (sdxscenesscene2dutilsDrawable* self);
	void (*setMinWidth) (sdxscenesscene2dutilsDrawable* self, gdouble minWidth);
	gdouble (*getMinHeight) (sdxscenesscene2dutilsDrawable* self);
	void (*setMinHeight) (sdxscenesscene2dutilsDrawable* self, gdouble minHeight);
};



gpointer sdx_graphics_s2d_batch_ref (gpointer instance);
void sdx_graphics_s2d_batch_unref (gpointer instance);
GParamSpec* sdx_graphics_s2d_param_spec_batch (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void sdx_graphics_s2d_value_set_batch (GValue* value, gpointer v_object);
void sdx_graphics_s2d_value_take_batch (GValue* value, gpointer v_object);
gpointer sdx_graphics_s2d_value_get_batch (const GValue* value);
GType sdx_graphics_s2d_batch_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_utils_drawable_get_type (void) G_GNUC_CONST;
void sdx_scenes_scene2d_utils_drawable_draw (sdxscenesscene2dutilsDrawable* self, sdxgraphicss2dBatch* batch, gdouble x, gdouble y, gdouble width, gdouble height);
gdouble sdx_scenes_scene2d_utils_drawable_getLeftWidth (sdxscenesscene2dutilsDrawable* self);
void sdx_scenes_scene2d_utils_drawable_setLeftWidth (sdxscenesscene2dutilsDrawable* self, gdouble leftWidth);
gdouble sdx_scenes_scene2d_utils_drawable_getRightWidth (sdxscenesscene2dutilsDrawable* self);
void sdx_scenes_scene2d_utils_drawable_setRightWidth (sdxscenesscene2dutilsDrawable* self, gdouble rightWidth);
gdouble sdx_scenes_scene2d_utils_drawable_getTopHeight (sdxscenesscene2dutilsDrawable* self);
void sdx_scenes_scene2d_utils_drawable_setTopHeight (sdxscenesscene2dutilsDrawable* self, gdouble topHeight);
gdouble sdx_scenes_scene2d_utils_drawable_getBottomHeight (sdxscenesscene2dutilsDrawable* self);
void sdx_scenes_scene2d_utils_drawable_setBottomHeight (sdxscenesscene2dutilsDrawable* self, gdouble bottomHeight);
gdouble sdx_scenes_scene2d_utils_drawable_getMinWidth (sdxscenesscene2dutilsDrawable* self);
void sdx_scenes_scene2d_utils_drawable_setMinWidth (sdxscenesscene2dutilsDrawable* self, gdouble minWidth);
gdouble sdx_scenes_scene2d_utils_drawable_getMinHeight (sdxscenesscene2dutilsDrawable* self);
void sdx_scenes_scene2d_utils_drawable_setMinHeight (sdxscenesscene2dutilsDrawable* self, gdouble minHeight);


void sdx_scenes_scene2d_utils_drawable_draw (sdxscenesscene2dutilsDrawable* self, sdxgraphicss2dBatch* batch, gdouble x, gdouble y, gdouble width, gdouble height) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->draw (self, batch, x, y, width, height);
}


gdouble sdx_scenes_scene2d_utils_drawable_getLeftWidth (sdxscenesscene2dutilsDrawable* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->getLeftWidth (self);
}


void sdx_scenes_scene2d_utils_drawable_setLeftWidth (sdxscenesscene2dutilsDrawable* self, gdouble leftWidth) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->setLeftWidth (self, leftWidth);
}


gdouble sdx_scenes_scene2d_utils_drawable_getRightWidth (sdxscenesscene2dutilsDrawable* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->getRightWidth (self);
}


void sdx_scenes_scene2d_utils_drawable_setRightWidth (sdxscenesscene2dutilsDrawable* self, gdouble rightWidth) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->setRightWidth (self, rightWidth);
}


gdouble sdx_scenes_scene2d_utils_drawable_getTopHeight (sdxscenesscene2dutilsDrawable* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->getTopHeight (self);
}


void sdx_scenes_scene2d_utils_drawable_setTopHeight (sdxscenesscene2dutilsDrawable* self, gdouble topHeight) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->setTopHeight (self, topHeight);
}


gdouble sdx_scenes_scene2d_utils_drawable_getBottomHeight (sdxscenesscene2dutilsDrawable* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->getBottomHeight (self);
}


void sdx_scenes_scene2d_utils_drawable_setBottomHeight (sdxscenesscene2dutilsDrawable* self, gdouble bottomHeight) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->setBottomHeight (self, bottomHeight);
}


gdouble sdx_scenes_scene2d_utils_drawable_getMinWidth (sdxscenesscene2dutilsDrawable* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->getMinWidth (self);
}


void sdx_scenes_scene2d_utils_drawable_setMinWidth (sdxscenesscene2dutilsDrawable* self, gdouble minWidth) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->setMinWidth (self, minWidth);
}


gdouble sdx_scenes_scene2d_utils_drawable_getMinHeight (sdxscenesscene2dutilsDrawable* self) {
	g_return_val_if_fail (self != NULL, 0.0);
	return SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->getMinHeight (self);
}


void sdx_scenes_scene2d_utils_drawable_setMinHeight (sdxscenesscene2dutilsDrawable* self, gdouble minHeight) {
	g_return_if_fail (self != NULL);
	SDX_SCENES_SCENE2D_UTILS_DRAWABLE_GET_INTERFACE (self)->setMinHeight (self, minHeight);
}


static void sdx_scenes_scene2d_utils_drawable_base_init (sdxscenesscene2dutilsDrawableIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType sdx_scenes_scene2d_utils_drawable_get_type (void) {
	static volatile gsize sdx_scenes_scene2d_utils_drawable_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_scenes_scene2d_utils_drawable_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxscenesscene2dutilsDrawableIface), (GBaseInitFunc) sdx_scenes_scene2d_utils_drawable_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType sdx_scenes_scene2d_utils_drawable_type_id;
		sdx_scenes_scene2d_utils_drawable_type_id = g_type_register_static (G_TYPE_INTERFACE, "sdxscenesscene2dutilsDrawable", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (sdx_scenes_scene2d_utils_drawable_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&sdx_scenes_scene2d_utils_drawable_type_id__volatile, sdx_scenes_scene2d_utils_drawable_type_id);
	}
	return sdx_scenes_scene2d_utils_drawable_type_id__volatile;
}



