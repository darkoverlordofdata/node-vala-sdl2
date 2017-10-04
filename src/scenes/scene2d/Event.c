/* Event.c generated by valac 0.34.9, the Vala compiler
 * generated from Event.gs, do not modify */


#include <glib.h>
#include <glib-object.h>


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

#define SDX_UTILS_TYPE_POOLABLE (sdx_utils_poolable_get_type ())
#define SDX_UTILS_POOLABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_UTILS_TYPE_POOLABLE, sdxutilsPoolable))
#define SDX_UTILS_IS_POOLABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_UTILS_TYPE_POOLABLE))
#define SDX_UTILS_POOLABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_UTILS_TYPE_POOLABLE, sdxutilsPoolableIface))

typedef struct _sdxutilsPoolable sdxutilsPoolable;
typedef struct _sdxutilsPoolableIface sdxutilsPoolableIface;
typedef struct _sdxscenesscene2dEventPrivate sdxscenesscene2dEventPrivate;

#define SDX_TYPE_INPUT_ADAPTER (sdx_input_adapter_get_type ())
#define SDX_INPUT_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_INPUT_ADAPTER, sdxInputAdapter))
#define SDX_INPUT_ADAPTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_INPUT_ADAPTER, sdxInputAdapterClass))
#define SDX_IS_INPUT_ADAPTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_INPUT_ADAPTER))
#define SDX_IS_INPUT_ADAPTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_INPUT_ADAPTER))
#define SDX_INPUT_ADAPTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_INPUT_ADAPTER, sdxInputAdapterClass))

typedef struct _sdxInputAdapter sdxInputAdapter;
typedef struct _sdxInputAdapterClass sdxInputAdapterClass;

#define SDX_SCENES_SCENE2D_TYPE_STAGE (sdx_scenes_scene2d_stage_get_type ())
#define SDX_SCENES_SCENE2D_STAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_STAGE, sdxscenesscene2dStage))
#define SDX_SCENES_SCENE2D_STAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_TYPE_STAGE, sdxscenesscene2dStageClass))
#define SDX_SCENES_SCENE2D_IS_STAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_STAGE))
#define SDX_SCENES_SCENE2D_IS_STAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_TYPE_STAGE))
#define SDX_SCENES_SCENE2D_STAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_TYPE_STAGE, sdxscenesscene2dStageClass))

typedef struct _sdxscenesscene2dStage sdxscenesscene2dStage;
typedef struct _sdxscenesscene2dStageClass sdxscenesscene2dStageClass;

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

struct _sdxutilsPoolableIface {
	GTypeInterface parent_iface;
	void (*reset) (sdxutilsPoolable* self);
};

struct _sdxscenesscene2dEvent {
	GObject parent_instance;
	sdxscenesscene2dEventPrivate * priv;
};

struct _sdxscenesscene2dEventClass {
	GObjectClass parent_class;
};

struct _sdxscenesscene2dEventPrivate {
	sdxscenesscene2dStage* stage;
	sdxscenesscene2dActor* targetActor;
	sdxscenesscene2dActor* listenerActor;
	gboolean capture;
	gboolean bubbles;
	gboolean handled;
	gboolean stopped;
	gboolean cancelled;
};


static gpointer sdx_scenes_scene2d_event_parent_class = NULL;
static sdxutilsPoolableIface* sdx_scenes_scene2d_event_sdx_utils_poolable_parent_iface = NULL;

GType sdx_scenes_scene2d_event_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_event_listener_get_type (void) G_GNUC_CONST;
gboolean sdx_scenes_scene2d_event_listener_handle (sdxscenesscene2dEventListener* self, sdxscenesscene2dEvent* event);
GType sdx_utils_poolable_get_type (void) G_GNUC_CONST;
GType sdx_input_adapter_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_stage_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_actor_get_type (void) G_GNUC_CONST;
#define SDX_SCENES_SCENE2D_EVENT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_SCENES_SCENE2D_TYPE_EVENT, sdxscenesscene2dEventPrivate))
enum  {
	SDX_SCENES_SCENE2D_EVENT_DUMMY_PROPERTY
};
void sdx_scenes_scene2d_event_handle (sdxscenesscene2dEvent* self);
void sdx_scenes_scene2d_event_cancel (sdxscenesscene2dEvent* self);
void sdx_scenes_scene2d_event_stop (sdxscenesscene2dEvent* self);
static void sdx_scenes_scene2d_event_real_reset (sdxutilsPoolable* base);
sdxscenesscene2dActor* sdx_scenes_scene2d_event_getTarget (sdxscenesscene2dEvent* self);
void sdx_scenes_scene2d_event_setTarget (sdxscenesscene2dEvent* self, sdxscenesscene2dActor* targetActor);
sdxscenesscene2dActor* sdx_scenes_scene2d_event_getListenerActor (sdxscenesscene2dEvent* self);
void sdx_scenes_scene2d_event_setListenerActor (sdxscenesscene2dEvent* self, sdxscenesscene2dActor* listenerActor);
gboolean sdx_scenes_scene2d_event_getBubbles (sdxscenesscene2dEvent* self);
void sdx_scenes_scene2d_event_setBubbles (sdxscenesscene2dEvent* self, gboolean bubbles);
gboolean sdx_scenes_scene2d_event_isHandled (sdxscenesscene2dEvent* self);
gboolean sdx_scenes_scene2d_event_isStopped (sdxscenesscene2dEvent* self);
gboolean sdx_scenes_scene2d_event_isCancelled (sdxscenesscene2dEvent* self);
void sdx_scenes_scene2d_event_setCapture (sdxscenesscene2dEvent* self, gboolean capture);
gboolean sdx_scenes_scene2d_event_isCapture (sdxscenesscene2dEvent* self);
void sdx_scenes_scene2d_event_setStage (sdxscenesscene2dEvent* self, sdxscenesscene2dStage* stage);
sdxscenesscene2dStage* sdx_scenes_scene2d_event_getStage (sdxscenesscene2dEvent* self);
sdxscenesscene2dEvent* sdx_scenes_scene2d_event_new (void);
sdxscenesscene2dEvent* sdx_scenes_scene2d_event_construct (GType object_type);
static void sdx_scenes_scene2d_event_finalize (GObject* obj);


gboolean sdx_scenes_scene2d_event_listener_handle (sdxscenesscene2dEventListener* self, sdxscenesscene2dEvent* event) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_SCENES_SCENE2D_EVENT_LISTENER_GET_INTERFACE (self)->handle (self, event);
}


static void sdx_scenes_scene2d_event_listener_base_init (sdxscenesscene2dEventListenerIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType sdx_scenes_scene2d_event_listener_get_type (void) {
	static volatile gsize sdx_scenes_scene2d_event_listener_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_scenes_scene2d_event_listener_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxscenesscene2dEventListenerIface), (GBaseInitFunc) sdx_scenes_scene2d_event_listener_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType sdx_scenes_scene2d_event_listener_type_id;
		sdx_scenes_scene2d_event_listener_type_id = g_type_register_static (G_TYPE_INTERFACE, "sdxscenesscene2dEventListener", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (sdx_scenes_scene2d_event_listener_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&sdx_scenes_scene2d_event_listener_type_id__volatile, sdx_scenes_scene2d_event_listener_type_id);
	}
	return sdx_scenes_scene2d_event_listener_type_id__volatile;
}


void sdx_scenes_scene2d_event_handle (sdxscenesscene2dEvent* self) {
	g_return_if_fail (self != NULL);
	self->priv->handled = TRUE;
}


void sdx_scenes_scene2d_event_cancel (sdxscenesscene2dEvent* self) {
	g_return_if_fail (self != NULL);
	self->priv->cancelled = TRUE;
	self->priv->stopped = TRUE;
	self->priv->handled = TRUE;
}


void sdx_scenes_scene2d_event_stop (sdxscenesscene2dEvent* self) {
	g_return_if_fail (self != NULL);
	self->priv->stopped = TRUE;
}


static void sdx_scenes_scene2d_event_real_reset (sdxutilsPoolable* base) {
	sdxscenesscene2dEvent * self;
	self = (sdxscenesscene2dEvent*) base;
	_g_object_unref0 (self->priv->stage);
	self->priv->stage = NULL;
	_g_object_unref0 (self->priv->targetActor);
	self->priv->targetActor = NULL;
	_g_object_unref0 (self->priv->listenerActor);
	self->priv->listenerActor = NULL;
	self->priv->capture = FALSE;
	self->priv->bubbles = TRUE;
	self->priv->handled = FALSE;
	self->priv->stopped = FALSE;
	self->priv->cancelled = FALSE;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


sdxscenesscene2dActor* sdx_scenes_scene2d_event_getTarget (sdxscenesscene2dEvent* self) {
	sdxscenesscene2dActor* result = NULL;
	sdxscenesscene2dActor* _tmp0_ = NULL;
	sdxscenesscene2dActor* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->targetActor;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	result = _tmp1_;
	return result;
}


void sdx_scenes_scene2d_event_setTarget (sdxscenesscene2dEvent* self, sdxscenesscene2dActor* targetActor) {
	sdxscenesscene2dActor* _tmp0_ = NULL;
	sdxscenesscene2dActor* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (targetActor != NULL);
	_tmp0_ = targetActor;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->targetActor);
	self->priv->targetActor = _tmp1_;
}


sdxscenesscene2dActor* sdx_scenes_scene2d_event_getListenerActor (sdxscenesscene2dEvent* self) {
	sdxscenesscene2dActor* result = NULL;
	sdxscenesscene2dActor* _tmp0_ = NULL;
	sdxscenesscene2dActor* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->listenerActor;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	result = _tmp1_;
	return result;
}


void sdx_scenes_scene2d_event_setListenerActor (sdxscenesscene2dEvent* self, sdxscenesscene2dActor* listenerActor) {
	sdxscenesscene2dActor* _tmp0_ = NULL;
	sdxscenesscene2dActor* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (listenerActor != NULL);
	_tmp0_ = listenerActor;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->listenerActor);
	self->priv->listenerActor = _tmp1_;
}


gboolean sdx_scenes_scene2d_event_getBubbles (sdxscenesscene2dEvent* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->bubbles;
	result = _tmp0_;
	return result;
}


void sdx_scenes_scene2d_event_setBubbles (sdxscenesscene2dEvent* self, gboolean bubbles) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = bubbles;
	self->priv->bubbles = _tmp0_;
}


gboolean sdx_scenes_scene2d_event_isHandled (sdxscenesscene2dEvent* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->handled;
	result = _tmp0_;
	return result;
}


gboolean sdx_scenes_scene2d_event_isStopped (sdxscenesscene2dEvent* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->stopped;
	result = _tmp0_;
	return result;
}


gboolean sdx_scenes_scene2d_event_isCancelled (sdxscenesscene2dEvent* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->cancelled;
	result = _tmp0_;
	return result;
}


void sdx_scenes_scene2d_event_setCapture (sdxscenesscene2dEvent* self, gboolean capture) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = capture;
	self->priv->capture = _tmp0_;
}


gboolean sdx_scenes_scene2d_event_isCapture (sdxscenesscene2dEvent* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->capture;
	result = _tmp0_;
	return result;
}


void sdx_scenes_scene2d_event_setStage (sdxscenesscene2dEvent* self, sdxscenesscene2dStage* stage) {
	sdxscenesscene2dStage* _tmp0_ = NULL;
	sdxscenesscene2dStage* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stage != NULL);
	_tmp0_ = stage;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->stage);
	self->priv->stage = _tmp1_;
}


sdxscenesscene2dStage* sdx_scenes_scene2d_event_getStage (sdxscenesscene2dEvent* self) {
	sdxscenesscene2dStage* result = NULL;
	sdxscenesscene2dStage* _tmp0_ = NULL;
	sdxscenesscene2dStage* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->stage;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	result = _tmp1_;
	return result;
}


sdxscenesscene2dEvent* sdx_scenes_scene2d_event_construct (GType object_type) {
	sdxscenesscene2dEvent * self = NULL;
	self = (sdxscenesscene2dEvent*) g_object_new (object_type, NULL);
	return self;
}


sdxscenesscene2dEvent* sdx_scenes_scene2d_event_new (void) {
	return sdx_scenes_scene2d_event_construct (SDX_SCENES_SCENE2D_TYPE_EVENT);
}


static void sdx_scenes_scene2d_event_class_init (sdxscenesscene2dEventClass * klass) {
	sdx_scenes_scene2d_event_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (sdxscenesscene2dEventPrivate));
	G_OBJECT_CLASS (klass)->finalize = sdx_scenes_scene2d_event_finalize;
}


static void sdx_scenes_scene2d_event_sdx_utils_poolable_interface_init (sdxutilsPoolableIface * iface) {
	sdx_scenes_scene2d_event_sdx_utils_poolable_parent_iface = g_type_interface_peek_parent (iface);
	iface->reset = (void (*)(sdxutilsPoolable*)) sdx_scenes_scene2d_event_real_reset;
}


static void sdx_scenes_scene2d_event_instance_init (sdxscenesscene2dEvent * self) {
	self->priv = SDX_SCENES_SCENE2D_EVENT_GET_PRIVATE (self);
}


static void sdx_scenes_scene2d_event_finalize (GObject* obj) {
	sdxscenesscene2dEvent * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_SCENES_SCENE2D_TYPE_EVENT, sdxscenesscene2dEvent);
	_g_object_unref0 (self->priv->stage);
	_g_object_unref0 (self->priv->targetActor);
	_g_object_unref0 (self->priv->listenerActor);
	G_OBJECT_CLASS (sdx_scenes_scene2d_event_parent_class)->finalize (obj);
}


GType sdx_scenes_scene2d_event_get_type (void) {
	static volatile gsize sdx_scenes_scene2d_event_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_scenes_scene2d_event_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxscenesscene2dEventClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_scenes_scene2d_event_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxscenesscene2dEvent), 0, (GInstanceInitFunc) sdx_scenes_scene2d_event_instance_init, NULL };
		static const GInterfaceInfo sdx_utils_poolable_info = { (GInterfaceInitFunc) sdx_scenes_scene2d_event_sdx_utils_poolable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType sdx_scenes_scene2d_event_type_id;
		sdx_scenes_scene2d_event_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxscenesscene2dEvent", &g_define_type_info, 0);
		g_type_add_interface_static (sdx_scenes_scene2d_event_type_id, SDX_UTILS_TYPE_POOLABLE, &sdx_utils_poolable_info);
		g_once_init_leave (&sdx_scenes_scene2d_event_type_id__volatile, sdx_scenes_scene2d_event_type_id);
	}
	return sdx_scenes_scene2d_event_type_id__volatile;
}



