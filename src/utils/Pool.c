/* Pool.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from Pool.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <math.h>
#include <float.h>


#define SDX_UTILS_TYPE_POOLABLE (sdx_utils_poolable_get_type ())
#define SDX_UTILS_POOLABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_UTILS_TYPE_POOLABLE, sdxutilsPoolable))
#define SDX_UTILS_IS_POOLABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_UTILS_TYPE_POOLABLE))
#define SDX_UTILS_POOLABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_UTILS_TYPE_POOLABLE, sdxutilsPoolableIface))

typedef struct _sdxutilsPoolable sdxutilsPoolable;
typedef struct _sdxutilsPoolableIface sdxutilsPoolableIface;

#define SDX_UTILS_TYPE_POOL (sdx_utils_pool_get_type ())
#define SDX_UTILS_POOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_UTILS_TYPE_POOL, sdxutilsPool))
#define SDX_UTILS_POOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_UTILS_TYPE_POOL, sdxutilsPoolClass))
#define SDX_UTILS_IS_POOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_UTILS_TYPE_POOL))
#define SDX_UTILS_IS_POOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_UTILS_TYPE_POOL))
#define SDX_UTILS_POOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_UTILS_TYPE_POOL, sdxutilsPoolClass))

typedef struct _sdxutilsPool sdxutilsPool;
typedef struct _sdxutilsPoolClass sdxutilsPoolClass;
typedef struct _sdxutilsPoolPrivate sdxutilsPoolPrivate;
#define __g_queue_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_queue_free__g_object_unref0_ (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _sdxutilsPoolableIface {
	GTypeInterface parent_iface;
	void (*reset) (sdxutilsPoolable* self);
};

struct _sdxutilsPool {
	GObject parent_instance;
	sdxutilsPoolPrivate * priv;
	gint max;
	gint peak;
	GQueue* freeObjects;
};

struct _sdxutilsPoolClass {
	GObjectClass parent_class;
	GObject* (*newObject) (sdxutilsPool* self);
};

typedef enum  {
	SDX_EXCEPTION_IllegalArgumentException,
	SDX_EXCEPTION_IllegalStateException,
	SDX_EXCEPTION_SdxRuntimeException,
	SDX_EXCEPTION_NullPointerException,
	SDX_EXCEPTION_NoSuchElementException,
	SDX_EXCEPTION_SDLException
} sdxException;
#define SDX_EXCEPTION sdx_exception_quark ()

static gpointer sdx_utils_pool_parent_class = NULL;

GType sdx_utils_poolable_get_type (void) G_GNUC_CONST;
void sdx_utils_poolable_reset (sdxutilsPoolable* self);
GType sdx_utils_pool_get_type (void) G_GNUC_CONST;
enum  {
	SDX_UTILS_POOL_DUMMY_PROPERTY
};
static void _g_object_unref0_ (gpointer var);
static void _g_queue_free__g_object_unref0_ (GQueue* self);
GObject* sdx_utils_pool_newObject (sdxutilsPool* self);
static GObject* sdx_utils_pool_real_newObject (sdxutilsPool* self);
GObject* sdx_utils_pool_obtain (sdxutilsPool* self);
void sdx_utils_pool_free (sdxutilsPool* self, GObject* object);
GQuark sdx_exception_quark (void);
void sdx_utils_pool_reset (sdxutilsPool* self, GObject* object);
void sdx_utils_pool_freeAll (sdxutilsPool* self, GObject** objects, int objects_length1);
void sdx_utils_pool_clear (sdxutilsPool* self);
gint sdx_utils_pool_getFree (sdxutilsPool* self);
sdxutilsPool* sdx_utils_pool_construct (GType object_type);
static void sdx_utils_pool_finalize (GObject * obj);


void sdx_utils_poolable_reset (sdxutilsPoolable* self) {
	g_return_if_fail (self != NULL);
	SDX_UTILS_POOLABLE_GET_INTERFACE (self)->reset (self);
}


static void sdx_utils_poolable_base_init (sdxutilsPoolableIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType sdx_utils_poolable_get_type (void) {
	static volatile gsize sdx_utils_poolable_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_utils_poolable_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxutilsPoolableIface), (GBaseInitFunc) sdx_utils_poolable_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType sdx_utils_poolable_type_id;
		sdx_utils_poolable_type_id = g_type_register_static (G_TYPE_INTERFACE, "sdxutilsPoolable", &g_define_type_info, 0);
		g_once_init_leave (&sdx_utils_poolable_type_id__volatile, sdx_utils_poolable_type_id);
	}
	return sdx_utils_poolable_type_id__volatile;
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_queue_free__g_object_unref0_ (GQueue* self) {
	g_queue_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_queue_free (self);
}


static GObject* sdx_utils_pool_real_newObject (sdxutilsPool* self) {
	g_critical ("Type `%s' does not implement abstract method `sdx_utils_pool_newObject'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


GObject* sdx_utils_pool_newObject (sdxutilsPool* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return SDX_UTILS_POOL_GET_CLASS (self)->newObject (self);
}


GObject* sdx_utils_pool_obtain (sdxutilsPool* self) {
	GObject* result = NULL;
	GObject* _tmp0_ = NULL;
	GQueue* _tmp1_;
	guint _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = self->freeObjects;
	_tmp2_ = g_queue_get_length (_tmp1_);
	if (_tmp2_ == ((guint) 0)) {
		GObject* _tmp3_;
		_tmp3_ = sdx_utils_pool_newObject (self);
		_g_object_unref0 (_tmp0_);
		_tmp0_ = _tmp3_;
	} else {
		GQueue* _tmp4_;
		gpointer _tmp5_;
		_tmp4_ = self->freeObjects;
		_tmp5_ = g_queue_pop_head (_tmp4_);
		_g_object_unref0 (_tmp0_);
		_tmp0_ = (GObject*) _tmp5_;
	}
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void sdx_utils_pool_free (sdxutilsPool* self, GObject* object) {
	GObject* _tmp0_;
	GQueue* _tmp2_;
	guint _tmp3_;
	gint _tmp4_;
	GObject* _tmp12_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (object != NULL);
	_tmp0_ = object;
	if (_tmp0_ == NULL) {
		GError* _tmp1_;
		_tmp1_ = g_error_new_literal (SDX_EXCEPTION, SDX_EXCEPTION_IllegalArgumentException, "object cannot be null.");
		_inner_error_ = _tmp1_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = self->freeObjects;
	_tmp3_ = g_queue_get_length (_tmp2_);
	_tmp4_ = self->max;
	if (_tmp3_ < ((guint) _tmp4_)) {
		GQueue* _tmp5_;
		GObject* _tmp6_;
		GObject* _tmp7_;
		gint _tmp8_;
		GQueue* _tmp9_;
		guint _tmp10_;
		gdouble _tmp11_;
		_tmp5_ = self->freeObjects;
		_tmp6_ = object;
		_tmp7_ = _g_object_ref0 (_tmp6_);
		g_queue_push_head (_tmp5_, _tmp7_);
		_tmp8_ = self->peak;
		_tmp9_ = self->freeObjects;
		_tmp10_ = g_queue_get_length (_tmp9_);
		_tmp11_ = fmax ((gdouble) _tmp8_, (gdouble) _tmp10_);
		self->peak = (gint) _tmp11_;
	}
	_tmp12_ = object;
	sdx_utils_pool_reset (self, _tmp12_);
}


void sdx_utils_pool_reset (sdxutilsPool* self, GObject* object) {
	GObject* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (object != NULL);
	_tmp0_ = object;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp0_, SDX_UTILS_TYPE_POOLABLE)) {
		GObject* _tmp1_;
		_tmp1_ = object;
		sdx_utils_poolable_reset (G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, SDX_UTILS_TYPE_POOLABLE, sdxutilsPoolable));
	}
}


void sdx_utils_pool_freeAll (sdxutilsPool* self, GObject** objects, int objects_length1) {
	GObject** _tmp0_;
	gint _tmp0__length1;
	gint _tmp17_;
	GQueue* _tmp18_;
	guint _tmp19_;
	gdouble _tmp20_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = objects;
	_tmp0__length1 = objects_length1;
	if (_tmp0_ == NULL) {
		GError* _tmp1_;
		_tmp1_ = g_error_new_literal (SDX_EXCEPTION, SDX_EXCEPTION_IllegalArgumentException, "objects cannot be null.");
		_inner_error_ = _tmp1_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp2_ = FALSE;
			_tmp2_ = TRUE;
			while (TRUE) {
				GObject** _tmp4_;
				gint _tmp4__length1;
				GObject* object = NULL;
				GObject** _tmp5_;
				gint _tmp5__length1;
				gint _tmp6_;
				GObject* _tmp7_;
				GObject* _tmp8_;
				GObject* _tmp9_;
				GQueue* _tmp10_;
				guint _tmp11_;
				gint _tmp12_;
				GObject* _tmp16_;
				if (!_tmp2_) {
					gint _tmp3_;
					_tmp3_ = i;
					i = _tmp3_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp4_ = objects;
				_tmp4__length1 = objects_length1;
				if (!(i <= (_tmp4__length1 - 1))) {
					break;
				}
				_tmp5_ = objects;
				_tmp5__length1 = objects_length1;
				_tmp6_ = i;
				_tmp7_ = _tmp5_[_tmp6_];
				_tmp8_ = _g_object_ref0 (_tmp7_);
				object = _tmp8_;
				_tmp9_ = object;
				if (_tmp9_ == NULL) {
					_g_object_unref0 (object);
					continue;
				}
				_tmp10_ = self->freeObjects;
				_tmp11_ = g_queue_get_length (_tmp10_);
				_tmp12_ = self->max;
				if (_tmp11_ < ((guint) _tmp12_)) {
					GQueue* _tmp13_;
					GObject* _tmp14_;
					GObject* _tmp15_;
					_tmp13_ = self->freeObjects;
					_tmp14_ = object;
					_tmp15_ = _g_object_ref0 (_tmp14_);
					g_queue_push_head (_tmp13_, _tmp15_);
				}
				_tmp16_ = object;
				sdx_utils_pool_reset (self, _tmp16_);
				_g_object_unref0 (object);
			}
		}
	}
	_tmp17_ = self->peak;
	_tmp18_ = self->freeObjects;
	_tmp19_ = g_queue_get_length (_tmp18_);
	_tmp20_ = fmax ((gdouble) _tmp17_, (gdouble) _tmp19_);
	self->peak = (gint) _tmp20_;
}


void sdx_utils_pool_clear (sdxutilsPool* self) {
	GQueue* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->freeObjects;
	g_queue_clear (_tmp0_);
}


gint sdx_utils_pool_getFree (sdxutilsPool* self) {
	gint result = 0;
	GQueue* _tmp0_;
	guint _tmp1_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->freeObjects;
	_tmp1_ = g_queue_get_length (_tmp0_);
	result = (gint) _tmp1_;
	return result;
}


sdxutilsPool* sdx_utils_pool_construct (GType object_type) {
	sdxutilsPool * self = NULL;
	self = (sdxutilsPool*) g_object_new (object_type, NULL);
	return self;
}


static void sdx_utils_pool_class_init (sdxutilsPoolClass * klass) {
	sdx_utils_pool_parent_class = g_type_class_peek_parent (klass);
	((sdxutilsPoolClass *) klass)->newObject = (GObject* (*) (sdxutilsPool *)) sdx_utils_pool_real_newObject;
	G_OBJECT_CLASS (klass)->finalize = sdx_utils_pool_finalize;
}


static void sdx_utils_pool_instance_init (sdxutilsPool * self) {
	self->max = 0xffff;
}


static void sdx_utils_pool_finalize (GObject * obj) {
	sdxutilsPool * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_UTILS_TYPE_POOL, sdxutilsPool);
	__g_queue_free__g_object_unref0_0 (self->freeObjects);
	G_OBJECT_CLASS (sdx_utils_pool_parent_class)->finalize (obj);
}


GType sdx_utils_pool_get_type (void) {
	static volatile gsize sdx_utils_pool_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_utils_pool_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxutilsPoolClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_utils_pool_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxutilsPool), 0, (GInstanceInitFunc) sdx_utils_pool_instance_init, NULL };
		GType sdx_utils_pool_type_id;
		sdx_utils_pool_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxutilsPool", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&sdx_utils_pool_type_id__volatile, sdx_utils_pool_type_id);
	}
	return sdx_utils_pool_type_id__volatile;
}



