/* ClickListener.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from ClickListener.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>


#define SDX_SCENES_SCENE2D_TYPE_EVENT_LISTENER (sdx_scenes_scene2d_event_listener_get_type ())
#define SDX_SCENES_SCENE2D_EVENT_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_EVENT_LISTENER, sdxscenesscene2dEventListener))
#define SDX_SCENES_SCENE2D_IS_EVENT_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_EVENT_LISTENER))
#define SDX_SCENES_SCENE2D_EVENT_LISTENER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_SCENES_SCENE2D_TYPE_EVENT_LISTENER, sdxscenesscene2dEventListenerIface))

typedef struct _sdxscenesscene2dEventListener sdxscenesscene2dEventListener;
typedef struct _sdxscenesscene2dEventListenerIface sdxscenesscene2dEventListenerIface;

#define SDX_SCENES_SCENE2D_TYPE_EVENT (sdx_scenes_scene2d_event_get_type ())
#define SDX_SCENES_SCENE2D_EVENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_EVENT, sdxscenesscene2dEvent))
#define SDX_SCENES_SCENE2D_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_TYPE_EVENT, sdxscenesscene2dEventClass))
#define SDX_SCENES_SCENE2D_IS_EVENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_EVENT))
#define SDX_SCENES_SCENE2D_IS_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_TYPE_EVENT))
#define SDX_SCENES_SCENE2D_EVENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_TYPE_EVENT, sdxscenesscene2dEventClass))

typedef struct _sdxscenesscene2dEvent sdxscenesscene2dEvent;
typedef struct _sdxscenesscene2dEventClass sdxscenesscene2dEventClass;

#define SDX_SCENES_SCENE2D_TYPE_INPUT_LISTENER (sdx_scenes_scene2d_input_listener_get_type ())
#define SDX_SCENES_SCENE2D_INPUT_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_INPUT_LISTENER, sdxscenesscene2dInputListener))
#define SDX_SCENES_SCENE2D_INPUT_LISTENER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_TYPE_INPUT_LISTENER, sdxscenesscene2dInputListenerClass))
#define SDX_SCENES_SCENE2D_IS_INPUT_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_INPUT_LISTENER))
#define SDX_SCENES_SCENE2D_IS_INPUT_LISTENER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_TYPE_INPUT_LISTENER))
#define SDX_SCENES_SCENE2D_INPUT_LISTENER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_TYPE_INPUT_LISTENER, sdxscenesscene2dInputListenerClass))

typedef struct _sdxscenesscene2dInputListener sdxscenesscene2dInputListener;
typedef struct _sdxscenesscene2dInputListenerClass sdxscenesscene2dInputListenerClass;
typedef struct _sdxscenesscene2dInputListenerPrivate sdxscenesscene2dInputListenerPrivate;

#define SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER (sdx_scenes_scene2d_utils_click_listener_get_type ())
#define SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, sdxscenesscene2dutilsClickListener))
#define SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, sdxscenesscene2dutilsClickListenerClass))
#define SDX_SCENES_SCENE2D_UTILS_IS_CLICK_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER))
#define SDX_SCENES_SCENE2D_UTILS_IS_CLICK_LISTENER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER))
#define SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, sdxscenesscene2dutilsClickListenerClass))

typedef struct _sdxscenesscene2dutilsClickListener sdxscenesscene2dutilsClickListener;
typedef struct _sdxscenesscene2dutilsClickListenerClass sdxscenesscene2dutilsClickListenerClass;
typedef struct _sdxscenesscene2dutilsClickListenerPrivate sdxscenesscene2dutilsClickListenerPrivate;

#define SDX_SCENES_SCENE2D_TYPE_INPUT_EVENT (sdx_scenes_scene2d_input_event_get_type ())
#define SDX_SCENES_SCENE2D_INPUT_EVENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_INPUT_EVENT, sdxscenesscene2dInputEvent))
#define SDX_SCENES_SCENE2D_INPUT_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_TYPE_INPUT_EVENT, sdxscenesscene2dInputEventClass))
#define SDX_SCENES_SCENE2D_IS_INPUT_EVENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_INPUT_EVENT))
#define SDX_SCENES_SCENE2D_IS_INPUT_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_TYPE_INPUT_EVENT))
#define SDX_SCENES_SCENE2D_INPUT_EVENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_TYPE_INPUT_EVENT, sdxscenesscene2dInputEventClass))

typedef struct _sdxscenesscene2dInputEvent sdxscenesscene2dInputEvent;
typedef struct _sdxscenesscene2dInputEventClass sdxscenesscene2dInputEventClass;

#define SDX_SCENES_SCENE2D_TYPE_ACTOR (sdx_scenes_scene2d_actor_get_type ())
#define SDX_SCENES_SCENE2D_ACTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_ACTOR, sdxscenesscene2dActor))
#define SDX_SCENES_SCENE2D_ACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_TYPE_ACTOR, sdxscenesscene2dActorClass))
#define SDX_SCENES_SCENE2D_IS_ACTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_ACTOR))
#define SDX_SCENES_SCENE2D_IS_ACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_TYPE_ACTOR))
#define SDX_SCENES_SCENE2D_ACTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_TYPE_ACTOR, sdxscenesscene2dActorClass))

typedef struct _sdxscenesscene2dActor sdxscenesscene2dActor;
typedef struct _sdxscenesscene2dActorClass sdxscenesscene2dActorClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _sdxscenesscene2dEventListenerIface {
	GTypeInterface parent_iface;
	gboolean (*handle) (sdxscenesscene2dEventListener* self, sdxscenesscene2dEvent* event);
};

struct _sdxscenesscene2dInputListener {
	GObject parent_instance;
	sdxscenesscene2dInputListenerPrivate * priv;
};

struct _sdxscenesscene2dInputListenerClass {
	GObjectClass parent_class;
};

struct _sdxscenesscene2dutilsClickListener {
	sdxscenesscene2dInputListener parent_instance;
	sdxscenesscene2dutilsClickListenerPrivate * priv;
};

struct _sdxscenesscene2dutilsClickListenerClass {
	sdxscenesscene2dInputListenerClass parent_class;
};

struct _sdxscenesscene2dutilsClickListenerPrivate {
	gint _button;
	gint _tapCount;
	gdouble _touchDownX;
	gdouble _touchDownY;
	gint _pressedPointer;
	gint _pressedButton;
	gdouble _tapSquareSize;
	gboolean pressed;
	gboolean over;
	gboolean cancelled;
	gint visualPressedTime;
	gint tapCountInterval;
	gint lastTapTime;
};


static gpointer sdx_scenes_scene2d_utils_click_listener_parent_class = NULL;
static gdouble sdx_scenes_scene2d_utils_click_listener__visualPressedDuration;
static gdouble sdx_scenes_scene2d_utils_click_listener__visualPressedDuration = 0.1;

GType sdx_scenes_scene2d_event_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_event_listener_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_input_listener_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_utils_click_listener_get_type (void) G_GNUC_CONST;
#define SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, sdxscenesscene2dutilsClickListenerPrivate))
enum  {
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_DUMMY_PROPERTY,
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_BUTTON,
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_COUNT,
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TOUCH_DOWN_X,
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TOUCH_DOWN_Y,
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_PRESSED_POINTER,
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_PRESSED_BUTTON,
	SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_SQUARE_SIZE
};
sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_new (void);
sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_construct (GType object_type);
sdxscenesscene2dInputListener* sdx_scenes_scene2d_input_listener_new (void);
sdxscenesscene2dInputListener* sdx_scenes_scene2d_input_listener_construct (GType object_type);
sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_new_with_button (gint button);
sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_construct_with_button (GType object_type, gint button);
void sdx_scenes_scene2d_utils_click_listener_set_button (sdxscenesscene2dutilsClickListener* self, gint value);
GType sdx_scenes_scene2d_input_event_get_type (void) G_GNUC_CONST;
gboolean sdx_scenes_scene2d_utils_click_listener_touchDown (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, gint button);
void sdx_scenes_scene2d_utils_click_listener_touchUp (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, gint button);
void sdx_scenes_scene2d_utils_click_listener_touchDragged (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer);
GType sdx_scenes_scene2d_actor_get_type (void) G_GNUC_CONST;
void sdx_scenes_scene2d_utils_click_listener_enter (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, sdxscenesscene2dActor* fromActor);
void sdx_scenes_scene2d_utils_click_listener_exit (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, sdxscenesscene2dActor* toActor);
void sdx_scenes_scene2d_utils_click_listener_cancel (sdxscenesscene2dutilsClickListener* self);
gint sdx_scenes_scene2d_utils_click_listener_get_pressedPointer (sdxscenesscene2dutilsClickListener* self);
void sdx_scenes_scene2d_utils_click_listener_clicked (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gdouble x, gdouble y);
gboolean sdx_scenes_scene2d_utils_click_listener_isOver (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dActor* actor, gdouble x, gdouble y);
sdxscenesscene2dActor* sdx_scenes_scene2d_actor_hit (sdxscenesscene2dActor* self, gdouble x, gdouble y, gboolean touchable);
gboolean sdx_scenes_scene2d_actor_isDescendantOf (sdxscenesscene2dActor* self, sdxscenesscene2dActor* actor);
gboolean sdx_scenes_scene2d_utils_click_listener_inTapSquare (sdxscenesscene2dutilsClickListener* self, gdouble x, gdouble y);
gdouble sdx_scenes_scene2d_utils_click_listener_get_touchDownX (sdxscenesscene2dutilsClickListener* self);
gdouble sdx_scenes_scene2d_utils_click_listener_get_touchDownY (sdxscenesscene2dutilsClickListener* self);
gdouble sdx_scenes_scene2d_utils_click_listener_get_tapSquareSize (sdxscenesscene2dutilsClickListener* self);
void sdx_scenes_scene2d_utils_click_listener_invalidateTapSquare (sdxscenesscene2dutilsClickListener* self);
gboolean sdx_scenes_scene2d_utils_click_listener_isPressed (sdxscenesscene2dutilsClickListener* self);
gboolean sdx_scenes_scene2d_utils_click_listener_isVisualPressed (sdxscenesscene2dutilsClickListener* self);
void sdx_scenes_scene2d_utils_click_listener_setTapCountInterval (sdxscenesscene2dutilsClickListener* self, gdouble tapCountInterval);
gdouble sdx_scenes_scene2d_utils_click_listener_get_visualPressedDuration (void);
void sdx_scenes_scene2d_utils_click_listener_set_visualPressedDuration (gdouble value);
gint sdx_scenes_scene2d_utils_click_listener_get_button (sdxscenesscene2dutilsClickListener* self);
gint sdx_scenes_scene2d_utils_click_listener_get_tapCount (sdxscenesscene2dutilsClickListener* self);
void sdx_scenes_scene2d_utils_click_listener_set_tapCount (sdxscenesscene2dutilsClickListener* self, gint value);
gint sdx_scenes_scene2d_utils_click_listener_get_pressedButton (sdxscenesscene2dutilsClickListener* self);
void sdx_scenes_scene2d_utils_click_listener_set_tapSquareSize (sdxscenesscene2dutilsClickListener* self, gdouble value);
static void sdx_scenes_scene2d_utils_click_listener_finalize (GObject * obj);
static void _vala_sdx_scenes_scene2d_utils_click_listener_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_sdx_scenes_scene2d_utils_click_listener_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_construct (GType object_type) {
	sdxscenesscene2dutilsClickListener * self = NULL;
	self = (sdxscenesscene2dutilsClickListener*) sdx_scenes_scene2d_input_listener_construct (object_type);
	return self;
}


sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_new (void) {
	return sdx_scenes_scene2d_utils_click_listener_construct (SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER);
}


sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_construct_with_button (GType object_type, gint button) {
	sdxscenesscene2dutilsClickListener * self = NULL;
	gint _tmp0_;
	self = (sdxscenesscene2dutilsClickListener*) sdx_scenes_scene2d_input_listener_construct (object_type);
	_tmp0_ = button;
	sdx_scenes_scene2d_utils_click_listener_set_button (self, _tmp0_);
	return self;
}


sdxscenesscene2dutilsClickListener* sdx_scenes_scene2d_utils_click_listener_new_with_button (gint button) {
	return sdx_scenes_scene2d_utils_click_listener_construct_with_button (SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, button);
}


gboolean sdx_scenes_scene2d_utils_click_listener_touchDown (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, gint button) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (event != NULL, FALSE);
	result = FALSE;
	return result;
}


void sdx_scenes_scene2d_utils_click_listener_touchUp (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, gint button) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (event != NULL);
}


void sdx_scenes_scene2d_utils_click_listener_touchDragged (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (event != NULL);
}


void sdx_scenes_scene2d_utils_click_listener_enter (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, sdxscenesscene2dActor* fromActor) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (event != NULL);
	g_return_if_fail (fromActor != NULL);
}


void sdx_scenes_scene2d_utils_click_listener_exit (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gfloat x, gfloat y, gint pointer, sdxscenesscene2dActor* toActor) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (event != NULL);
	g_return_if_fail (toActor != NULL);
}


void sdx_scenes_scene2d_utils_click_listener_cancel (sdxscenesscene2dutilsClickListener* self) {
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_pressedPointer;
	if (_tmp0_ == (-1)) {
		self->priv->cancelled = TRUE;
		self->priv->pressed = FALSE;
	}
}


void sdx_scenes_scene2d_utils_click_listener_clicked (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dInputEvent* event, gdouble x, gdouble y) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (event != NULL);
}


gboolean sdx_scenes_scene2d_utils_click_listener_isOver (sdxscenesscene2dutilsClickListener* self, sdxscenesscene2dActor* actor, gdouble x, gdouble y) {
	gboolean result = FALSE;
	sdxscenesscene2dActor* hit = NULL;
	sdxscenesscene2dActor* _tmp0_;
	gdouble _tmp1_;
	gdouble _tmp2_;
	sdxscenesscene2dActor* _tmp3_;
	gboolean _tmp4_ = FALSE;
	sdxscenesscene2dActor* _tmp5_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (actor != NULL, FALSE);
	_tmp0_ = actor;
	_tmp1_ = x;
	_tmp2_ = y;
	_tmp3_ = sdx_scenes_scene2d_actor_hit (_tmp0_, _tmp1_, _tmp2_, TRUE);
	hit = _tmp3_;
	_tmp5_ = hit;
	if (_tmp5_ == NULL) {
		_tmp4_ = TRUE;
	} else {
		sdxscenesscene2dActor* _tmp6_;
		sdxscenesscene2dActor* _tmp7_;
		gboolean _tmp8_;
		_tmp6_ = hit;
		_tmp7_ = actor;
		_tmp8_ = sdx_scenes_scene2d_actor_isDescendantOf (_tmp6_, _tmp7_);
		_tmp4_ = !_tmp8_;
	}
	if (_tmp4_) {
		gdouble _tmp9_;
		gdouble _tmp10_;
		gboolean _tmp11_;
		_tmp9_ = x;
		_tmp10_ = y;
		_tmp11_ = sdx_scenes_scene2d_utils_click_listener_inTapSquare (self, _tmp9_, _tmp10_);
		result = _tmp11_;
		_g_object_unref0 (hit);
		return result;
	}
	result = TRUE;
	_g_object_unref0 (hit);
	return result;
}


gboolean sdx_scenes_scene2d_utils_click_listener_inTapSquare (sdxscenesscene2dutilsClickListener* self, gdouble x, gdouble y) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gdouble _tmp1_;
	gboolean _tmp3_ = FALSE;
	gdouble _tmp4_;
	gdouble _tmp5_;
	gdouble _tmp6_;
	gdouble _tmp7_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp1_ = self->priv->_touchDownX;
	if (_tmp1_ == ((gdouble) (-1))) {
		gdouble _tmp2_;
		_tmp2_ = self->priv->_touchDownY;
		_tmp0_ = _tmp2_ == ((gdouble) (-1));
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		result = FALSE;
		return result;
	}
	_tmp4_ = x;
	_tmp5_ = self->priv->_touchDownX;
	_tmp6_ = fabs (_tmp4_ - _tmp5_);
	_tmp7_ = self->priv->_tapSquareSize;
	if (_tmp6_ < _tmp7_) {
		gdouble _tmp8_;
		gdouble _tmp9_;
		gdouble _tmp10_;
		gdouble _tmp11_;
		_tmp8_ = y;
		_tmp9_ = self->priv->_touchDownY;
		_tmp10_ = fabs (_tmp8_ - _tmp9_);
		_tmp11_ = self->priv->_tapSquareSize;
		_tmp3_ = _tmp10_ < _tmp11_;
	} else {
		_tmp3_ = FALSE;
	}
	result = _tmp3_;
	return result;
}


void sdx_scenes_scene2d_utils_click_listener_invalidateTapSquare (sdxscenesscene2dutilsClickListener* self) {
	g_return_if_fail (self != NULL);
	self->priv->_touchDownX = (gdouble) (-1);
	self->priv->_touchDownY = (gdouble) (-1);
}


gboolean sdx_scenes_scene2d_utils_click_listener_isPressed (sdxscenesscene2dutilsClickListener* self) {
	gboolean result = FALSE;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->pressed;
	result = _tmp0_;
	return result;
}


gboolean sdx_scenes_scene2d_utils_click_listener_isVisualPressed (sdxscenesscene2dutilsClickListener* self) {
	gboolean result = FALSE;
	gboolean _tmp0_;
	gint _tmp1_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->pressed;
	if (_tmp0_) {
		result = TRUE;
		return result;
	}
	_tmp1_ = self->priv->visualPressedTime;
	if (_tmp1_ <= 0) {
		result = FALSE;
		return result;
	}
	self->priv->visualPressedTime = 0;
	result = FALSE;
	return result;
}


void sdx_scenes_scene2d_utils_click_listener_setTapCountInterval (sdxscenesscene2dutilsClickListener* self, gdouble tapCountInterval) {
	gdouble _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = tapCountInterval;
	self->priv->tapCountInterval = (gint) (_tmp0_ * 1000000000L);
}


gdouble sdx_scenes_scene2d_utils_click_listener_get_visualPressedDuration (void) {
	gdouble result;
	gdouble _tmp0_;
	_tmp0_ = sdx_scenes_scene2d_utils_click_listener__visualPressedDuration;
	result = _tmp0_;
	return result;
}


void sdx_scenes_scene2d_utils_click_listener_set_visualPressedDuration (gdouble value) {
	gdouble _tmp0_;
	_tmp0_ = value;
	sdx_scenes_scene2d_utils_click_listener__visualPressedDuration = _tmp0_;
}


gint sdx_scenes_scene2d_utils_click_listener_get_button (sdxscenesscene2dutilsClickListener* self) {
	gint result;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_button;
	result = _tmp0_;
	return result;
}


void sdx_scenes_scene2d_utils_click_listener_set_button (sdxscenesscene2dutilsClickListener* self, gint value) {
	g_return_if_fail (self != NULL);
	if (sdx_scenes_scene2d_utils_click_listener_get_button (self) != value) {
		gint _tmp0_;
		_tmp0_ = value;
		self->priv->_button = _tmp0_;
		g_object_notify ((GObject *) self, "button");
	}
}


gint sdx_scenes_scene2d_utils_click_listener_get_tapCount (sdxscenesscene2dutilsClickListener* self) {
	gint result;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_tapCount;
	result = _tmp0_;
	return result;
}


void sdx_scenes_scene2d_utils_click_listener_set_tapCount (sdxscenesscene2dutilsClickListener* self, gint value) {
	g_return_if_fail (self != NULL);
	if (sdx_scenes_scene2d_utils_click_listener_get_tapCount (self) != value) {
		gint _tmp0_;
		_tmp0_ = value;
		self->priv->_tapCount = _tmp0_;
		g_object_notify ((GObject *) self, "tapCount");
	}
}


gdouble sdx_scenes_scene2d_utils_click_listener_get_touchDownX (sdxscenesscene2dutilsClickListener* self) {
	gdouble result;
	gdouble _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0);
	_tmp0_ = self->priv->_touchDownX;
	result = _tmp0_;
	return result;
}


gdouble sdx_scenes_scene2d_utils_click_listener_get_touchDownY (sdxscenesscene2dutilsClickListener* self) {
	gdouble result;
	gdouble _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0);
	_tmp0_ = self->priv->_touchDownY;
	result = _tmp0_;
	return result;
}


gint sdx_scenes_scene2d_utils_click_listener_get_pressedPointer (sdxscenesscene2dutilsClickListener* self) {
	gint result;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_pressedPointer;
	result = _tmp0_;
	return result;
}


gint sdx_scenes_scene2d_utils_click_listener_get_pressedButton (sdxscenesscene2dutilsClickListener* self) {
	gint result;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_pressedButton;
	result = _tmp0_;
	return result;
}


gdouble sdx_scenes_scene2d_utils_click_listener_get_tapSquareSize (sdxscenesscene2dutilsClickListener* self) {
	gdouble result;
	gdouble _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0);
	_tmp0_ = self->priv->_tapSquareSize;
	result = _tmp0_;
	return result;
}


void sdx_scenes_scene2d_utils_click_listener_set_tapSquareSize (sdxscenesscene2dutilsClickListener* self, gdouble value) {
	g_return_if_fail (self != NULL);
	if (sdx_scenes_scene2d_utils_click_listener_get_tapSquareSize (self) != value) {
		gdouble _tmp0_;
		_tmp0_ = value;
		self->priv->_tapSquareSize = _tmp0_;
		g_object_notify ((GObject *) self, "tapSquareSize");
	}
}


static void sdx_scenes_scene2d_utils_click_listener_class_init (sdxscenesscene2dutilsClickListenerClass * klass) {
	sdx_scenes_scene2d_utils_click_listener_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (sdxscenesscene2dutilsClickListenerPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_sdx_scenes_scene2d_utils_click_listener_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_sdx_scenes_scene2d_utils_click_listener_set_property;
	G_OBJECT_CLASS (klass)->finalize = sdx_scenes_scene2d_utils_click_listener_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_BUTTON, g_param_spec_int ("button", "button", "button", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_COUNT, g_param_spec_int ("tapCount", "tapCount", "tapCount", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TOUCH_DOWN_X, g_param_spec_double ("touchDownX", "touchDownX", "touchDownX", -G_MAXDOUBLE, G_MAXDOUBLE, (gdouble) (-1), G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TOUCH_DOWN_Y, g_param_spec_double ("touchDownY", "touchDownY", "touchDownY", -G_MAXDOUBLE, G_MAXDOUBLE, (gdouble) (-1), G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_PRESSED_POINTER, g_param_spec_int ("pressedPointer", "pressedPointer", "pressedPointer", G_MININT, G_MAXINT, -1, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_PRESSED_BUTTON, g_param_spec_int ("pressedButton", "pressedButton", "pressedButton", G_MININT, G_MAXINT, -1, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_SQUARE_SIZE, g_param_spec_double ("tapSquareSize", "tapSquareSize", "tapSquareSize", -G_MAXDOUBLE, G_MAXDOUBLE, (gdouble) 14, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void sdx_scenes_scene2d_utils_click_listener_instance_init (sdxscenesscene2dutilsClickListener * self) {
	self->priv = SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_GET_PRIVATE (self);
	self->priv->_touchDownX = (gdouble) (-1);
	self->priv->_touchDownY = (gdouble) (-1);
	self->priv->_pressedPointer = -1;
	self->priv->_pressedButton = -1;
	self->priv->_tapSquareSize = (gdouble) 14;
}


static void sdx_scenes_scene2d_utils_click_listener_finalize (GObject * obj) {
	sdxscenesscene2dutilsClickListener * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, sdxscenesscene2dutilsClickListener);
	G_OBJECT_CLASS (sdx_scenes_scene2d_utils_click_listener_parent_class)->finalize (obj);
}


GType sdx_scenes_scene2d_utils_click_listener_get_type (void) {
	static volatile gsize sdx_scenes_scene2d_utils_click_listener_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_scenes_scene2d_utils_click_listener_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxscenesscene2dutilsClickListenerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_scenes_scene2d_utils_click_listener_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxscenesscene2dutilsClickListener), 0, (GInstanceInitFunc) sdx_scenes_scene2d_utils_click_listener_instance_init, NULL };
		GType sdx_scenes_scene2d_utils_click_listener_type_id;
		sdx_scenes_scene2d_utils_click_listener_type_id = g_type_register_static (SDX_SCENES_SCENE2D_TYPE_INPUT_LISTENER, "sdxscenesscene2dutilsClickListener", &g_define_type_info, 0);
		g_once_init_leave (&sdx_scenes_scene2d_utils_click_listener_type_id__volatile, sdx_scenes_scene2d_utils_click_listener_type_id);
	}
	return sdx_scenes_scene2d_utils_click_listener_type_id__volatile;
}


static void _vala_sdx_scenes_scene2d_utils_click_listener_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	sdxscenesscene2dutilsClickListener * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, sdxscenesscene2dutilsClickListener);
	switch (property_id) {
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_BUTTON:
		g_value_set_int (value, sdx_scenes_scene2d_utils_click_listener_get_button (self));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_COUNT:
		g_value_set_int (value, sdx_scenes_scene2d_utils_click_listener_get_tapCount (self));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TOUCH_DOWN_X:
		g_value_set_double (value, sdx_scenes_scene2d_utils_click_listener_get_touchDownX (self));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TOUCH_DOWN_Y:
		g_value_set_double (value, sdx_scenes_scene2d_utils_click_listener_get_touchDownY (self));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_PRESSED_POINTER:
		g_value_set_int (value, sdx_scenes_scene2d_utils_click_listener_get_pressedPointer (self));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_PRESSED_BUTTON:
		g_value_set_int (value, sdx_scenes_scene2d_utils_click_listener_get_pressedButton (self));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_SQUARE_SIZE:
		g_value_set_double (value, sdx_scenes_scene2d_utils_click_listener_get_tapSquareSize (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_sdx_scenes_scene2d_utils_click_listener_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	sdxscenesscene2dutilsClickListener * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_SCENES_SCENE2D_UTILS_TYPE_CLICK_LISTENER, sdxscenesscene2dutilsClickListener);
	switch (property_id) {
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_BUTTON:
		sdx_scenes_scene2d_utils_click_listener_set_button (self, g_value_get_int (value));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_COUNT:
		sdx_scenes_scene2d_utils_click_listener_set_tapCount (self, g_value_get_int (value));
		break;
		case SDX_SCENES_SCENE2D_UTILS_CLICK_LISTENER_TAP_SQUARE_SIZE:
		sdx_scenes_scene2d_utils_click_listener_set_tapSquareSize (self, g_value_get_double (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


