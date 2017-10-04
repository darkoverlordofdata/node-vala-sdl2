/* Label.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from Label.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>


#define SDX_SCENES_SCENE2D_TYPE_ACTOR (sdx_scenes_scene2d_actor_get_type ())
#define SDX_SCENES_SCENE2D_ACTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_ACTOR, sdxscenesscene2dActor))
#define SDX_SCENES_SCENE2D_ACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_TYPE_ACTOR, sdxscenesscene2dActorClass))
#define SDX_SCENES_SCENE2D_IS_ACTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_ACTOR))
#define SDX_SCENES_SCENE2D_IS_ACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_TYPE_ACTOR))
#define SDX_SCENES_SCENE2D_ACTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_TYPE_ACTOR, sdxscenesscene2dActorClass))

typedef struct _sdxscenesscene2dActor sdxscenesscene2dActor;
typedef struct _sdxscenesscene2dActorClass sdxscenesscene2dActorClass;
typedef struct _sdxscenesscene2dActorPrivate sdxscenesscene2dActorPrivate;

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

#define SDX_SCENES_SCENE2D_TYPE_ACTION (sdx_scenes_scene2d_action_get_type ())
#define SDX_SCENES_SCENE2D_ACTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_TYPE_ACTION, sdxscenesscene2dAction))
#define SDX_SCENES_SCENE2D_ACTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_TYPE_ACTION, sdxscenesscene2dActionClass))
#define SDX_SCENES_SCENE2D_IS_ACTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_TYPE_ACTION))
#define SDX_SCENES_SCENE2D_IS_ACTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_TYPE_ACTION))
#define SDX_SCENES_SCENE2D_ACTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_TYPE_ACTION, sdxscenesscene2dActionClass))

typedef struct _sdxscenesscene2dAction sdxscenesscene2dAction;
typedef struct _sdxscenesscene2dActionClass sdxscenesscene2dActionClass;

#define SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT (sdx_scenes_scene2d_utils_layout_get_type ())
#define SDX_SCENES_SCENE2D_UTILS_LAYOUT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT, sdxscenesscene2dutilsLayout))
#define SDX_SCENES_SCENE2D_UTILS_IS_LAYOUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT))
#define SDX_SCENES_SCENE2D_UTILS_LAYOUT_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_SCENES_SCENE2D_UTILS_TYPE_LAYOUT, sdxscenesscene2dutilsLayoutIface))

typedef struct _sdxscenesscene2dutilsLayout sdxscenesscene2dutilsLayout;
typedef struct _sdxscenesscene2dutilsLayoutIface sdxscenesscene2dutilsLayoutIface;

#define SDX_SCENES_SCENE2D_UI_TYPE_WIDGET (sdx_scenes_scene2d_ui_widget_get_type ())
#define SDX_SCENES_SCENE2D_UI_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_UI_TYPE_WIDGET, sdxscenesscene2duiWidget))
#define SDX_SCENES_SCENE2D_UI_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_UI_TYPE_WIDGET, sdxscenesscene2duiWidgetClass))
#define SDX_SCENES_SCENE2D_UI_IS_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_UI_TYPE_WIDGET))
#define SDX_SCENES_SCENE2D_UI_IS_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_UI_TYPE_WIDGET))
#define SDX_SCENES_SCENE2D_UI_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_UI_TYPE_WIDGET, sdxscenesscene2duiWidgetClass))

typedef struct _sdxscenesscene2duiWidget sdxscenesscene2duiWidget;
typedef struct _sdxscenesscene2duiWidgetClass sdxscenesscene2duiWidgetClass;
typedef struct _sdxscenesscene2duiWidgetPrivate sdxscenesscene2duiWidgetPrivate;

#define SDX_SCENES_SCENE2D_UI_TYPE_LABEL (sdx_scenes_scene2d_ui_label_get_type ())
#define SDX_SCENES_SCENE2D_UI_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_UI_TYPE_LABEL, sdxscenesscene2duiLabel))
#define SDX_SCENES_SCENE2D_UI_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_UI_TYPE_LABEL, sdxscenesscene2duiLabelClass))
#define SDX_SCENES_SCENE2D_UI_IS_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_UI_TYPE_LABEL))
#define SDX_SCENES_SCENE2D_UI_IS_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_UI_TYPE_LABEL))
#define SDX_SCENES_SCENE2D_UI_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_UI_TYPE_LABEL, sdxscenesscene2duiLabelClass))

typedef struct _sdxscenesscene2duiLabel sdxscenesscene2duiLabel;
typedef struct _sdxscenesscene2duiLabelClass sdxscenesscene2duiLabelClass;
typedef struct _sdxscenesscene2duiLabelPrivate sdxscenesscene2duiLabelPrivate;

#define SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE (sdx_scenes_scene2d_ui_label_label_style_get_type ())
#define SDX_SCENES_SCENE2D_UI_LABEL_LABEL_STYLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE, sdxscenesscene2duiLabelLabelStyle))
#define SDX_SCENES_SCENE2D_UI_LABEL_LABEL_STYLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE, sdxscenesscene2duiLabelLabelStyleClass))
#define SDX_SCENES_SCENE2D_UI_LABEL_IS_LABEL_STYLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE))
#define SDX_SCENES_SCENE2D_UI_LABEL_IS_LABEL_STYLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE))
#define SDX_SCENES_SCENE2D_UI_LABEL_LABEL_STYLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE, sdxscenesscene2duiLabelLabelStyleClass))

typedef struct _sdxscenesscene2duiLabelLabelStyle sdxscenesscene2duiLabelLabelStyle;
typedef struct _sdxscenesscene2duiLabelLabelStyleClass sdxscenesscene2duiLabelLabelStyleClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SDX_UTILS_TYPE_ALIGN (sdx_utils_align_get_type ())
typedef struct _sdxscenesscene2duiLabelLabelStylePrivate sdxscenesscene2duiLabelLabelStylePrivate;

#define SDX_GRAPHICS_S2D_TYPE_FONT (sdx_graphics_s2d_font_get_type ())
#define SDX_GRAPHICS_S2D_FONT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFont))
#define SDX_GRAPHICS_S2D_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFontClass))
#define SDX_GRAPHICS_S2D_IS_FONT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_S2D_TYPE_FONT))
#define SDX_GRAPHICS_S2D_IS_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_S2D_TYPE_FONT))
#define SDX_GRAPHICS_S2D_FONT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFontClass))

typedef struct _sdxgraphicss2dFont sdxgraphicss2dFont;
typedef struct _sdxgraphicss2dFontClass sdxgraphicss2dFontClass;

#define SDX_GRAPHICS_TYPE_COLOR (sdx_graphics_color_get_type ())
#define SDX_GRAPHICS_COLOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColor))
#define SDX_GRAPHICS_COLOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColorClass))
#define SDX_GRAPHICS_IS_COLOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_TYPE_COLOR))
#define SDX_GRAPHICS_IS_COLOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_TYPE_COLOR))
#define SDX_GRAPHICS_COLOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColorClass))

typedef struct _sdxgraphicsColor sdxgraphicsColor;
typedef struct _sdxgraphicsColorClass sdxgraphicsColorClass;

#define SDX_TYPE_IAPPLICATION (sdx_iapplication_get_type ())
#define SDX_IAPPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_IAPPLICATION, sdxIApplication))
#define SDX_IS_IAPPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_IAPPLICATION))
#define SDX_IAPPLICATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_IAPPLICATION, sdxIApplicationIface))

typedef struct _sdxIApplication sdxIApplication;
typedef struct _sdxIApplicationIface sdxIApplicationIface;
#define _SDL_DestroyTexture0(var) ((var == NULL) ? NULL : (var = (SDL_DestroyTexture (var), NULL)))
#define _SDL_FreeSurface0(var) ((var == NULL) ? NULL : (var = (SDL_FreeSurface (var), NULL)))

#define SDX_GRAPHICS_S2D_TYPE_BATCH (sdx_graphics_s2d_batch_get_type ())
#define SDX_GRAPHICS_S2D_BATCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_S2D_TYPE_BATCH, sdxgraphicss2dBatch))
#define SDX_GRAPHICS_S2D_BATCH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_S2D_TYPE_BATCH, sdxgraphicss2dBatchClass))
#define SDX_GRAPHICS_S2D_IS_BATCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_S2D_TYPE_BATCH))
#define SDX_GRAPHICS_S2D_IS_BATCH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_S2D_TYPE_BATCH))
#define SDX_GRAPHICS_S2D_BATCH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_S2D_TYPE_BATCH, sdxgraphicss2dBatchClass))

typedef struct _sdxgraphicss2dBatch sdxgraphicss2dBatch;
typedef struct _sdxgraphicss2dBatchClass sdxgraphicss2dBatchClass;

struct _sdxscenesscene2dEventListenerIface {
	GTypeInterface parent_iface;
	gboolean (*handle) (sdxscenesscene2dEventListener* self, sdxscenesscene2dEvent* event);
};

struct _sdxscenesscene2dActor {
	GObject parent_instance;
	sdxscenesscene2dActorPrivate * priv;
	GeeArrayList* listeners;
	GeeArrayList* captureListeners;
	GeeArrayList* actions;
	gboolean visible;
	gdouble x;
	gdouble y;
	gdouble width;
	gdouble height;
	gdouble originX;
	gdouble originY;
	gdouble scaleX;
	gdouble scaleY;
	gdouble rotation;
};

struct _sdxscenesscene2dActorClass {
	GObjectClass parent_class;
};

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

struct _sdxscenesscene2duiWidget {
	sdxscenesscene2dActor parent_instance;
	sdxscenesscene2duiWidgetPrivate * priv;
};

struct _sdxscenesscene2duiWidgetClass {
	sdxscenesscene2dActorClass parent_class;
};

struct _sdxscenesscene2duiLabel {
	sdxscenesscene2duiWidget parent_instance;
	sdxscenesscene2duiLabelPrivate * priv;
	gchar* text;
	gint labelAlign;
	gint lineAlign;
};

struct _sdxscenesscene2duiLabelClass {
	sdxscenesscene2duiWidgetClass parent_class;
};

struct _sdxscenesscene2duiLabelPrivate {
	sdxscenesscene2duiLabelLabelStyle* _style;
};

typedef enum  {
	SDX_UTILS_ALIGN_center = 1 << 0,
	SDX_UTILS_ALIGN_top = 1 << 1,
	SDX_UTILS_ALIGN_bottom = 1 << 2,
	SDX_UTILS_ALIGN_left = 1 << 3,
	SDX_UTILS_ALIGN_right = 1 << 4,
	SDX_UTILS_ALIGN_topLeft = SDX_UTILS_ALIGN_top | SDX_UTILS_ALIGN_left,
	SDX_UTILS_ALIGN_topRight = SDX_UTILS_ALIGN_top | SDX_UTILS_ALIGN_right,
	SDX_UTILS_ALIGN_bottomLeft = SDX_UTILS_ALIGN_bottom | SDX_UTILS_ALIGN_left,
	SDX_UTILS_ALIGN_bottomRight = SDX_UTILS_ALIGN_bottom | SDX_UTILS_ALIGN_right
} sdxutilsAlign;

struct _sdxscenesscene2duiLabelLabelStyle {
	GObject parent_instance;
	sdxscenesscene2duiLabelLabelStylePrivate * priv;
	sdxgraphicss2dFont* font;
	sdxgraphicsColor* fontColor;
};

struct _sdxscenesscene2duiLabelLabelStyleClass {
	GObjectClass parent_class;
};

struct _sdxIApplicationIface {
	GTypeInterface parent_iface;
	gint (*get_width) (sdxIApplication* self);
	void (*set_width) (sdxIApplication* self, gint value);
	gint (*get_height) (sdxIApplication* self);
	void (*set_height) (sdxIApplication* self, gint value);
	SDL_Renderer* (*get_renderer) (sdxIApplication* self);
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

static gpointer sdx_scenes_scene2d_ui_label_parent_class = NULL;
static gpointer sdx_scenes_scene2d_ui_label_label_style_parent_class = NULL;

GType sdx_scenes_scene2d_actor_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_event_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_event_listener_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_action_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_utils_layout_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_ui_widget_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_ui_label_get_type (void) G_GNUC_CONST;
GType sdx_scenes_scene2d_ui_label_label_style_get_type (void) G_GNUC_CONST;
#define SDX_SCENES_SCENE2D_UI_LABEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_SCENES_SCENE2D_UI_TYPE_LABEL, sdxscenesscene2duiLabelPrivate))
enum  {
	SDX_SCENES_SCENE2D_UI_LABEL_DUMMY_PROPERTY
};
GType sdx_utils_align_get_type (void) G_GNUC_CONST;
sdxscenesscene2duiLabel* sdx_scenes_scene2d_ui_label_new (const gchar* text, sdxscenesscene2duiLabelLabelStyle* style);
sdxscenesscene2duiLabel* sdx_scenes_scene2d_ui_label_construct (GType object_type, const gchar* text, sdxscenesscene2duiLabelLabelStyle* style);
sdxscenesscene2duiWidget* sdx_scenes_scene2d_ui_widget_new (void);
sdxscenesscene2duiWidget* sdx_scenes_scene2d_ui_widget_construct (GType object_type);
void sdx_scenes_scene2d_ui_label_setStyle (sdxscenesscene2duiLabel* self, sdxscenesscene2duiLabelLabelStyle* style);
void sdx_scenes_scene2d_actor_setSize (sdxscenesscene2dActor* self, gdouble width, gdouble height);
gdouble sdx_scenes_scene2d_utils_layout_getPrefWidth (sdxscenesscene2dutilsLayout* self);
gdouble sdx_scenes_scene2d_utils_layout_getPrefHeight (sdxscenesscene2dutilsLayout* self);
void sdx_scenes_scene2d_ui_label_layout (sdxscenesscene2duiLabel* self);
GType sdx_graphics_s2d_font_get_type (void) G_GNUC_CONST;
GType sdx_graphics_color_get_type (void) G_GNUC_CONST;
SDL_Surface* sdx_graphics_s2d_font_render (sdxgraphicss2dFont* self, const gchar* text, sdxgraphicsColor* color);
GType sdx_iapplication_get_type (void) G_GNUC_CONST;
sdxIApplication* sdx_sdx_get_app (void);
SDL_Renderer* sdx_iapplication_get_renderer (sdxIApplication* self);
void sdx_sdlFailIf (gboolean cond, const gchar* reason);
gpointer sdx_graphics_s2d_batch_ref (gpointer instance);
void sdx_graphics_s2d_batch_unref (gpointer instance);
GParamSpec* sdx_graphics_s2d_param_spec_batch (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void sdx_graphics_s2d_value_set_batch (GValue* value, gpointer v_object);
void sdx_graphics_s2d_value_take_batch (GValue* value, gpointer v_object);
gpointer sdx_graphics_s2d_value_get_batch (const GValue* value);
GType sdx_graphics_s2d_batch_get_type (void) G_GNUC_CONST;
void sdx_scenes_scene2d_ui_label_draw (sdxscenesscene2duiLabel* self, sdxgraphicss2dBatch* batch, gdouble parentAlpha);
GQuark sdx_exception_quark (void);
void sdx_scenes_scene2d_utils_layout_invalidateHierarchy (sdxscenesscene2dutilsLayout* self);
sdxscenesscene2duiLabelLabelStyle* sdx_scenes_scene2d_ui_label_getStyle (sdxscenesscene2duiLabel* self);
void sdx_scenes_scene2d_ui_label_setText (sdxscenesscene2duiLabel* self, const gchar* newText);
gboolean sdx_scenes_scene2d_ui_label_textEquals (sdxscenesscene2duiLabel* self, const gchar* other);
gchar* sdx_scenes_scene2d_ui_label_getText (sdxscenesscene2duiLabel* self);
void sdx_scenes_scene2d_ui_label_setAlignment (sdxscenesscene2duiLabel* self, gint labelAlign, gint lineAlign);
void sdx_scenes_scene2d_utils_layout_invalidate (sdxscenesscene2dutilsLayout* self);
enum  {
	SDX_SCENES_SCENE2D_UI_LABEL_LABEL_STYLE_DUMMY_PROPERTY
};
sdxscenesscene2duiLabelLabelStyle* sdx_scenes_scene2d_ui_label_label_style_new (sdxgraphicss2dFont* font, sdxgraphicsColor* color);
sdxscenesscene2duiLabelLabelStyle* sdx_scenes_scene2d_ui_label_label_style_construct (GType object_type, sdxgraphicss2dFont* font, sdxgraphicsColor* color);
static void sdx_scenes_scene2d_ui_label_label_style_finalize (GObject * obj);
static void sdx_scenes_scene2d_ui_label_finalize (GObject * obj);


sdxscenesscene2duiLabel* sdx_scenes_scene2d_ui_label_construct (GType object_type, const gchar* text, sdxscenesscene2duiLabelLabelStyle* style) {
	sdxscenesscene2duiLabel * self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	sdxscenesscene2duiLabelLabelStyle* _tmp2_;
	gboolean _tmp3_ = FALSE;
	const gchar* _tmp4_;
	g_return_val_if_fail (text != NULL, NULL);
	g_return_val_if_fail (style != NULL, NULL);
	self = (sdxscenesscene2duiLabel*) sdx_scenes_scene2d_ui_widget_construct (object_type);
	_tmp0_ = text;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->text);
	self->text = _tmp1_;
	_tmp2_ = style;
	sdx_scenes_scene2d_ui_label_setStyle (self, _tmp2_);
	_tmp4_ = text;
	if (_tmp4_ != NULL) {
		const gchar* _tmp5_;
		gint _tmp6_;
		gint _tmp7_;
		_tmp5_ = text;
		_tmp6_ = strlen (_tmp5_);
		_tmp7_ = _tmp6_;
		_tmp3_ = _tmp7_ > 0;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		gdouble _tmp8_;
		gdouble _tmp9_;
		_tmp8_ = sdx_scenes_scene2d_utils_layout_getPrefWidth ((sdxscenesscene2dutilsLayout*) self);
		_tmp9_ = sdx_scenes_scene2d_utils_layout_getPrefHeight ((sdxscenesscene2dutilsLayout*) self);
		sdx_scenes_scene2d_actor_setSize ((sdxscenesscene2dActor*) self, _tmp8_, _tmp9_);
	}
	return self;
}


sdxscenesscene2duiLabel* sdx_scenes_scene2d_ui_label_new (const gchar* text, sdxscenesscene2duiLabelLabelStyle* style) {
	return sdx_scenes_scene2d_ui_label_construct (SDX_SCENES_SCENE2D_UI_TYPE_LABEL, text, style);
}


void sdx_scenes_scene2d_ui_label_layout (sdxscenesscene2duiLabel* self) {
	SDL_Surface* textSurface = NULL;
	sdxscenesscene2duiLabelLabelStyle* _tmp0_;
	sdxgraphicss2dFont* _tmp1_;
	const gchar* _tmp2_;
	sdxscenesscene2duiLabelLabelStyle* _tmp3_;
	sdxgraphicsColor* _tmp4_;
	SDL_Surface* _tmp5_;
	SDL_Texture* texture = NULL;
	sdxIApplication* _tmp6_;
	sdxIApplication* _tmp7_;
	SDL_Renderer* _tmp8_;
	SDL_Renderer* _tmp9_;
	SDL_Texture* _tmp10_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_style;
	_tmp1_ = _tmp0_->font;
	_tmp2_ = self->text;
	_tmp3_ = self->priv->_style;
	_tmp4_ = _tmp3_->fontColor;
	_tmp5_ = sdx_graphics_s2d_font_render (_tmp1_, _tmp2_, _tmp4_);
	textSurface = _tmp5_;
	_tmp6_ = sdx_sdx_get_app ();
	_tmp7_ = _tmp6_;
	_tmp8_ = sdx_iapplication_get_renderer (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = SDL_CreateTextureFromSurface (_tmp9_, textSurface);
	texture = _tmp10_;
	sdx_sdlFailIf (texture == NULL, "Unable to load image texture Label.layout!");
	_SDL_DestroyTexture0 (texture);
	_SDL_FreeSurface0 (textSurface);
}


void sdx_scenes_scene2d_ui_label_draw (sdxscenesscene2duiLabel* self, sdxgraphicss2dBatch* batch, gdouble parentAlpha) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (batch != NULL);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void sdx_scenes_scene2d_ui_label_setStyle (sdxscenesscene2duiLabel* self, sdxscenesscene2duiLabelLabelStyle* style) {
	sdxscenesscene2duiLabelLabelStyle* _tmp0_;
	sdxscenesscene2duiLabelLabelStyle* _tmp2_;
	sdxgraphicss2dFont* _tmp3_;
	sdxscenesscene2duiLabelLabelStyle* _tmp5_;
	sdxscenesscene2duiLabelLabelStyle* _tmp6_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (style != NULL);
	_tmp0_ = style;
	if (_tmp0_ == NULL) {
		GError* _tmp1_;
		_tmp1_ = g_error_new_literal (SDX_EXCEPTION, SDX_EXCEPTION_IllegalArgumentException, "style cannot be null.");
		_inner_error_ = _tmp1_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = style;
	_tmp3_ = _tmp2_->font;
	if (_tmp3_ == NULL) {
		GError* _tmp4_;
		_tmp4_ = g_error_new_literal (SDX_EXCEPTION, SDX_EXCEPTION_IllegalArgumentException, "Missing LabelStyle font.");
		_inner_error_ = _tmp4_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = style;
	_tmp6_ = _g_object_ref0 (_tmp5_);
	_g_object_unref0 (self->priv->_style);
	self->priv->_style = _tmp6_;
	sdx_scenes_scene2d_utils_layout_invalidateHierarchy ((sdxscenesscene2dutilsLayout*) self);
}


sdxscenesscene2duiLabelLabelStyle* sdx_scenes_scene2d_ui_label_getStyle (sdxscenesscene2duiLabel* self) {
	sdxscenesscene2duiLabelLabelStyle* result = NULL;
	sdxscenesscene2duiLabelLabelStyle* _tmp0_;
	sdxscenesscene2duiLabelLabelStyle* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_style;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	result = _tmp1_;
	return result;
}


void sdx_scenes_scene2d_ui_label_setText (sdxscenesscene2duiLabel* self, const gchar* newText) {
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (newText != NULL);
	_tmp0_ = self->text;
	_tmp1_ = newText;
	if (g_strcmp0 (_tmp0_, _tmp1_) == 0) {
		return;
	}
	_tmp2_ = newText;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->text);
	self->text = _tmp3_;
	sdx_scenes_scene2d_utils_layout_invalidateHierarchy ((sdxscenesscene2dutilsLayout*) self);
}


gboolean sdx_scenes_scene2d_ui_label_textEquals (sdxscenesscene2duiLabel* self, const gchar* other) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (other != NULL, FALSE);
	_tmp0_ = self->text;
	_tmp1_ = other;
	result = g_strcmp0 (_tmp0_, _tmp1_) == 0;
	return result;
}


gchar* sdx_scenes_scene2d_ui_label_getText (sdxscenesscene2duiLabel* self) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->text;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}


void sdx_scenes_scene2d_ui_label_setAlignment (sdxscenesscene2duiLabel* self, gint labelAlign, gint lineAlign) {
	gint _tmp0_;
	gint _tmp2_;
	gint _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp0_ = lineAlign;
	if (_tmp0_ == (-1)) {
		gint _tmp1_;
		_tmp1_ = labelAlign;
		lineAlign = _tmp1_;
	}
	_tmp2_ = labelAlign;
	self->labelAlign = _tmp2_;
	_tmp3_ = lineAlign;
	if ((_tmp3_ & SDX_UTILS_ALIGN_left) != 0) {
		self->lineAlign = (gint) SDX_UTILS_ALIGN_left;
	} else {
		gint _tmp4_;
		_tmp4_ = lineAlign;
		if ((_tmp4_ & SDX_UTILS_ALIGN_right) != 0) {
			self->lineAlign = (gint) SDX_UTILS_ALIGN_right;
		} else {
			self->lineAlign = (gint) SDX_UTILS_ALIGN_center;
		}
	}
	sdx_scenes_scene2d_utils_layout_invalidate ((sdxscenesscene2dutilsLayout*) self);
}


sdxscenesscene2duiLabelLabelStyle* sdx_scenes_scene2d_ui_label_label_style_construct (GType object_type, sdxgraphicss2dFont* font, sdxgraphicsColor* color) {
	sdxscenesscene2duiLabelLabelStyle * self = NULL;
	sdxgraphicss2dFont* _tmp0_;
	sdxgraphicss2dFont* _tmp1_;
	sdxgraphicsColor* _tmp2_;
	sdxgraphicsColor* _tmp3_;
	g_return_val_if_fail (font != NULL, NULL);
	g_return_val_if_fail (color != NULL, NULL);
	self = (sdxscenesscene2duiLabelLabelStyle*) g_object_new (object_type, NULL);
	_tmp0_ = font;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->font);
	self->font = _tmp1_;
	_tmp2_ = color;
	_tmp3_ = _g_object_ref0 (_tmp2_);
	_g_object_unref0 (self->fontColor);
	self->fontColor = _tmp3_;
	return self;
}


sdxscenesscene2duiLabelLabelStyle* sdx_scenes_scene2d_ui_label_label_style_new (sdxgraphicss2dFont* font, sdxgraphicsColor* color) {
	return sdx_scenes_scene2d_ui_label_label_style_construct (SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE, font, color);
}


static void sdx_scenes_scene2d_ui_label_label_style_class_init (sdxscenesscene2duiLabelLabelStyleClass * klass) {
	sdx_scenes_scene2d_ui_label_label_style_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = sdx_scenes_scene2d_ui_label_label_style_finalize;
}


static void sdx_scenes_scene2d_ui_label_label_style_instance_init (sdxscenesscene2duiLabelLabelStyle * self) {
}


static void sdx_scenes_scene2d_ui_label_label_style_finalize (GObject * obj) {
	sdxscenesscene2duiLabelLabelStyle * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_SCENES_SCENE2D_UI_LABEL_TYPE_LABEL_STYLE, sdxscenesscene2duiLabelLabelStyle);
	_g_object_unref0 (self->font);
	_g_object_unref0 (self->fontColor);
	G_OBJECT_CLASS (sdx_scenes_scene2d_ui_label_label_style_parent_class)->finalize (obj);
}


GType sdx_scenes_scene2d_ui_label_label_style_get_type (void) {
	static volatile gsize sdx_scenes_scene2d_ui_label_label_style_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_scenes_scene2d_ui_label_label_style_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxscenesscene2duiLabelLabelStyleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_scenes_scene2d_ui_label_label_style_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxscenesscene2duiLabelLabelStyle), 0, (GInstanceInitFunc) sdx_scenes_scene2d_ui_label_label_style_instance_init, NULL };
		GType sdx_scenes_scene2d_ui_label_label_style_type_id;
		sdx_scenes_scene2d_ui_label_label_style_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxscenesscene2duiLabelLabelStyle", &g_define_type_info, 0);
		g_once_init_leave (&sdx_scenes_scene2d_ui_label_label_style_type_id__volatile, sdx_scenes_scene2d_ui_label_label_style_type_id);
	}
	return sdx_scenes_scene2d_ui_label_label_style_type_id__volatile;
}


static void sdx_scenes_scene2d_ui_label_class_init (sdxscenesscene2duiLabelClass * klass) {
	sdx_scenes_scene2d_ui_label_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (sdxscenesscene2duiLabelPrivate));
	G_OBJECT_CLASS (klass)->finalize = sdx_scenes_scene2d_ui_label_finalize;
}


static void sdx_scenes_scene2d_ui_label_instance_init (sdxscenesscene2duiLabel * self) {
	self->priv = SDX_SCENES_SCENE2D_UI_LABEL_GET_PRIVATE (self);
	self->labelAlign = (gint) SDX_UTILS_ALIGN_left;
	self->lineAlign = (gint) SDX_UTILS_ALIGN_left;
}


static void sdx_scenes_scene2d_ui_label_finalize (GObject * obj) {
	sdxscenesscene2duiLabel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_SCENES_SCENE2D_UI_TYPE_LABEL, sdxscenesscene2duiLabel);
	_g_free0 (self->text);
	_g_object_unref0 (self->priv->_style);
	G_OBJECT_CLASS (sdx_scenes_scene2d_ui_label_parent_class)->finalize (obj);
}


GType sdx_scenes_scene2d_ui_label_get_type (void) {
	static volatile gsize sdx_scenes_scene2d_ui_label_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_scenes_scene2d_ui_label_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxscenesscene2duiLabelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_scenes_scene2d_ui_label_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxscenesscene2duiLabel), 0, (GInstanceInitFunc) sdx_scenes_scene2d_ui_label_instance_init, NULL };
		GType sdx_scenes_scene2d_ui_label_type_id;
		sdx_scenes_scene2d_ui_label_type_id = g_type_register_static (SDX_SCENES_SCENE2D_UI_TYPE_WIDGET, "sdxscenesscene2duiLabel", &g_define_type_info, 0);
		g_once_init_leave (&sdx_scenes_scene2d_ui_label_type_id__volatile, sdx_scenes_scene2d_ui_label_type_id);
	}
	return sdx_scenes_scene2d_ui_label_type_id__volatile;
}



