/* Viewport.c generated by valac 0.34.9, the Vala compiler
 * generated from Viewport.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define SDX_UTILS_VIEWPORT_TYPE_VIEWPORT (sdx_utils_viewport_viewport_get_type ())
#define SDX_UTILS_VIEWPORT_VIEWPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_UTILS_VIEWPORT_TYPE_VIEWPORT, sdxutilsviewportViewport))
#define SDX_UTILS_VIEWPORT_VIEWPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_UTILS_VIEWPORT_TYPE_VIEWPORT, sdxutilsviewportViewportClass))
#define SDX_UTILS_VIEWPORT_IS_VIEWPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_UTILS_VIEWPORT_TYPE_VIEWPORT))
#define SDX_UTILS_VIEWPORT_IS_VIEWPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_UTILS_VIEWPORT_TYPE_VIEWPORT))
#define SDX_UTILS_VIEWPORT_VIEWPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_UTILS_VIEWPORT_TYPE_VIEWPORT, sdxutilsviewportViewportClass))

typedef struct _sdxutilsviewportViewport sdxutilsviewportViewport;
typedef struct _sdxutilsviewportViewportClass sdxutilsviewportViewportClass;
typedef struct _sdxutilsviewportViewportPrivate sdxutilsviewportViewportPrivate;
typedef struct _sdxutilsviewportParamSpecViewport sdxutilsviewportParamSpecViewport;

struct _sdxutilsviewportViewport {
	GTypeInstance parent_instance;
	volatile int ref_count;
	sdxutilsviewportViewportPrivate * priv;
	gdouble worldWidth;
	gdouble worldHeight;
	gint screenX;
	gint screenY;
	gint screenWidth;
	gint screenHeight;
};

struct _sdxutilsviewportViewportClass {
	GTypeClass parent_class;
	void (*finalize) (sdxutilsviewportViewport *self);
};

struct _sdxutilsviewportParamSpecViewport {
	GParamSpec parent_instance;
};


static gpointer sdx_utils_viewport_viewport_parent_class = NULL;

gpointer sdx_utils_viewport_viewport_ref (gpointer instance);
void sdx_utils_viewport_viewport_unref (gpointer instance);
GParamSpec* sdx_utils_viewport_param_spec_viewport (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void sdx_utils_viewport_value_set_viewport (GValue* value, gpointer v_object);
void sdx_utils_viewport_value_take_viewport (GValue* value, gpointer v_object);
gpointer sdx_utils_viewport_value_get_viewport (const GValue* value);
GType sdx_utils_viewport_viewport_get_type (void) G_GNUC_CONST;
enum  {
	SDX_UTILS_VIEWPORT_VIEWPORT_DUMMY_PROPERTY
};
void sdx_utils_viewport_viewport_update (sdxutilsviewportViewport* self, gint screenWidth, gint screenHeight);
sdxutilsviewportViewport* sdx_utils_viewport_viewport_new (void);
sdxutilsviewportViewport* sdx_utils_viewport_viewport_construct (GType object_type);
static void sdx_utils_viewport_viewport_finalize (sdxutilsviewportViewport* obj);


void sdx_utils_viewport_viewport_update (sdxutilsviewportViewport* self, gint screenWidth, gint screenHeight) {
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = screenWidth;
	self->screenWidth = _tmp0_;
	_tmp1_ = screenHeight;
	self->screenHeight = _tmp1_;
}


sdxutilsviewportViewport* sdx_utils_viewport_viewport_construct (GType object_type) {
	sdxutilsviewportViewport* self = NULL;
	self = (sdxutilsviewportViewport*) g_type_create_instance (object_type);
	return self;
}


sdxutilsviewportViewport* sdx_utils_viewport_viewport_new (void) {
	return sdx_utils_viewport_viewport_construct (SDX_UTILS_VIEWPORT_TYPE_VIEWPORT);
}


static void sdx_utils_viewport_value_viewport_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void sdx_utils_viewport_value_viewport_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		sdx_utils_viewport_viewport_unref (value->data[0].v_pointer);
	}
}


static void sdx_utils_viewport_value_viewport_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = sdx_utils_viewport_viewport_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer sdx_utils_viewport_value_viewport_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* sdx_utils_viewport_value_viewport_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		sdxutilsviewportViewport* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = sdx_utils_viewport_viewport_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* sdx_utils_viewport_value_viewport_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	sdxutilsviewportViewport** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = sdx_utils_viewport_viewport_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* sdx_utils_viewport_param_spec_viewport (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	sdxutilsviewportParamSpecViewport* spec;
	g_return_val_if_fail (g_type_is_a (object_type, SDX_UTILS_VIEWPORT_TYPE_VIEWPORT), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer sdx_utils_viewport_value_get_viewport (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SDX_UTILS_VIEWPORT_TYPE_VIEWPORT), NULL);
	return value->data[0].v_pointer;
}


void sdx_utils_viewport_value_set_viewport (GValue* value, gpointer v_object) {
	sdxutilsviewportViewport* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SDX_UTILS_VIEWPORT_TYPE_VIEWPORT));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SDX_UTILS_VIEWPORT_TYPE_VIEWPORT));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		sdx_utils_viewport_viewport_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		sdx_utils_viewport_viewport_unref (old);
	}
}


void sdx_utils_viewport_value_take_viewport (GValue* value, gpointer v_object) {
	sdxutilsviewportViewport* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SDX_UTILS_VIEWPORT_TYPE_VIEWPORT));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SDX_UTILS_VIEWPORT_TYPE_VIEWPORT));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		sdx_utils_viewport_viewport_unref (old);
	}
}


static void sdx_utils_viewport_viewport_class_init (sdxutilsviewportViewportClass * klass) {
	sdx_utils_viewport_viewport_parent_class = g_type_class_peek_parent (klass);
	((sdxutilsviewportViewportClass *) klass)->finalize = sdx_utils_viewport_viewport_finalize;
}


static void sdx_utils_viewport_viewport_instance_init (sdxutilsviewportViewport * self) {
	self->ref_count = 1;
}


static void sdx_utils_viewport_viewport_finalize (sdxutilsviewportViewport* obj) {
	sdxutilsviewportViewport * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_UTILS_VIEWPORT_TYPE_VIEWPORT, sdxutilsviewportViewport);
	g_signal_handlers_destroy (self);
}


GType sdx_utils_viewport_viewport_get_type (void) {
	static volatile gsize sdx_utils_viewport_viewport_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_utils_viewport_viewport_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { sdx_utils_viewport_value_viewport_init, sdx_utils_viewport_value_viewport_free_value, sdx_utils_viewport_value_viewport_copy_value, sdx_utils_viewport_value_viewport_peek_pointer, "p", sdx_utils_viewport_value_viewport_collect_value, "p", sdx_utils_viewport_value_viewport_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (sdxutilsviewportViewportClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_utils_viewport_viewport_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxutilsviewportViewport), 0, (GInstanceInitFunc) sdx_utils_viewport_viewport_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType sdx_utils_viewport_viewport_type_id;
		sdx_utils_viewport_viewport_type_id = g_type_register_fundamental (g_type_fundamental_next (), "sdxutilsviewportViewport", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&sdx_utils_viewport_viewport_type_id__volatile, sdx_utils_viewport_viewport_type_id);
	}
	return sdx_utils_viewport_viewport_type_id__volatile;
}


gpointer sdx_utils_viewport_viewport_ref (gpointer instance) {
	sdxutilsviewportViewport* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void sdx_utils_viewport_viewport_unref (gpointer instance) {
	sdxutilsviewportViewport* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SDX_UTILS_VIEWPORT_VIEWPORT_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



