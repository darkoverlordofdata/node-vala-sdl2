/* Application.c generated by valac 0.34.7, the Vala compiler
 * generated from Application.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_video.h>
#include <gee.h>
#include <SDL2/SDL_keyboard.h>
#include <float.h>
#include <math.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_audio.h>


#define SDX_TYPE_IAPPLICATION (sdx_iapplication_get_type ())
#define SDX_IAPPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_IAPPLICATION, sdxIApplication))
#define SDX_IS_IAPPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_IAPPLICATION))
#define SDX_IAPPLICATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_IAPPLICATION, sdxIApplicationIface))

typedef struct _sdxIApplication sdxIApplication;
typedef struct _sdxIApplicationIface sdxIApplicationIface;

#define SDX_TYPE_APPLICATION (sdx_application_get_type ())
#define SDX_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_APPLICATION, sdxApplication))
#define SDX_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_APPLICATION, sdxApplicationClass))
#define SDX_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_APPLICATION))
#define SDX_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_APPLICATION))
#define SDX_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_APPLICATION, sdxApplicationClass))

typedef struct _sdxApplication sdxApplication;
typedef struct _sdxApplicationClass sdxApplicationClass;
typedef struct _sdxApplicationPrivate sdxApplicationPrivate;

#define SDX_GRAPHICS_S2D_TYPE_FONT (sdx_graphics_s2d_font_get_type ())
#define SDX_GRAPHICS_S2D_FONT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFont))
#define SDX_GRAPHICS_S2D_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFontClass))
#define SDX_GRAPHICS_S2D_IS_FONT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_S2D_TYPE_FONT))
#define SDX_GRAPHICS_S2D_IS_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_S2D_TYPE_FONT))
#define SDX_GRAPHICS_S2D_FONT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFontClass))

typedef struct _sdxgraphicss2dFont sdxgraphicss2dFont;
typedef struct _sdxgraphicss2dFontClass sdxgraphicss2dFontClass;

#define SDX_GRAPHICS_S2D_TYPE_SPRITE (sdx_graphics_s2d_sprite_get_type ())
#define SDX_GRAPHICS_S2D_SPRITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_S2D_TYPE_SPRITE, sdxgraphicss2dSprite))
#define SDX_GRAPHICS_S2D_SPRITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_S2D_TYPE_SPRITE, sdxgraphicss2dSpriteClass))
#define SDX_GRAPHICS_S2D_IS_SPRITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_S2D_TYPE_SPRITE))
#define SDX_GRAPHICS_S2D_IS_SPRITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_S2D_TYPE_SPRITE))
#define SDX_GRAPHICS_S2D_SPRITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_S2D_TYPE_SPRITE, sdxgraphicss2dSpriteClass))

typedef struct _sdxgraphicss2dSprite sdxgraphicss2dSprite;
typedef struct _sdxgraphicss2dSpriteClass sdxgraphicss2dSpriteClass;

#define SDX_TYPE_APPLICATION_LISTENER (sdx_application_listener_get_type ())
#define SDX_APPLICATION_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_APPLICATION_LISTENER, sdxApplicationListener))
#define SDX_IS_APPLICATION_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_APPLICATION_LISTENER))
#define SDX_APPLICATION_LISTENER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_APPLICATION_LISTENER, sdxApplicationListenerIface))

typedef struct _sdxApplicationListener sdxApplicationListener;
typedef struct _sdxApplicationListenerIface sdxApplicationListenerIface;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _SDL_DestroyWindow0(var) ((var == NULL) ? NULL : (var = (SDL_DestroyWindow (var), NULL)))
#define _SDL_DestroyRenderer0(var) ((var == NULL) ? NULL : (var = (SDL_DestroyRenderer (var), NULL)))

#define SDX_TYPE_SDX (sdx_sdx_get_type ())
#define SDX_SDX(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_SDX, sdxSdx))
#define SDX_SDX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_SDX, sdxSdxClass))
#define SDX_IS_SDX(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_SDX))
#define SDX_IS_SDX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_SDX))
#define SDX_SDX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_SDX, sdxSdxClass))

typedef struct _sdxSdx sdxSdx;
typedef struct _sdxSdxClass sdxSdxClass;

#define SDX_TYPE_INPUT (sdx_input_get_type ())
#define SDX_INPUT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_INPUT, sdxInput))
#define SDX_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_INPUT, sdxInputClass))
#define SDX_IS_INPUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_INPUT))
#define SDX_IS_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_INPUT))
#define SDX_INPUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_INPUT, sdxInputClass))

typedef struct _sdxInput sdxInput;
typedef struct _sdxInputClass sdxInputClass;

#define SDX_INPUT_TYPE_KEYS (sdx_input_keys_get_type ())

#define SDX_TYPE_GRAPHICS (sdx_graphics_get_type ())
#define SDX_GRAPHICS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_GRAPHICS, sdxGraphics))
#define SDX_GRAPHICS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_GRAPHICS, sdxGraphicsClass))
#define SDX_IS_GRAPHICS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_GRAPHICS))
#define SDX_IS_GRAPHICS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_GRAPHICS))
#define SDX_GRAPHICS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_GRAPHICS, sdxGraphicsClass))

typedef struct _sdxGraphics sdxGraphics;
typedef struct _sdxGraphicsClass sdxGraphicsClass;

#define SDX_GRAPHICS_TYPE_COLOR (sdx_graphics_color_get_type ())
#define SDX_GRAPHICS_COLOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColor))
#define SDX_GRAPHICS_COLOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColorClass))
#define SDX_GRAPHICS_IS_COLOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_TYPE_COLOR))
#define SDX_GRAPHICS_IS_COLOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_TYPE_COLOR))
#define SDX_GRAPHICS_COLOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColorClass))

typedef struct _sdxgraphicsColor sdxgraphicsColor;
typedef struct _sdxgraphicsColorClass sdxgraphicsColorClass;

#define SDX_TYPE_FILES (sdx_files_get_type ())
#define SDX_FILES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_FILES, sdxFiles))
#define SDX_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_FILES, sdxFilesClass))
#define SDX_IS_FILES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_FILES))
#define SDX_IS_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_FILES))
#define SDX_FILES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_FILES, sdxFilesClass))

typedef struct _sdxFiles sdxFiles;
typedef struct _sdxFilesClass sdxFilesClass;

#define SDX_FILES_TYPE_FILE_HANDLE (sdx_files_file_handle_get_type ())
#define SDX_FILES_FILE_HANDLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandle))
#define SDX_FILES_FILE_HANDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandleClass))
#define SDX_FILES_IS_FILE_HANDLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_FILES_TYPE_FILE_HANDLE))
#define SDX_FILES_IS_FILE_HANDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_FILES_TYPE_FILE_HANDLE))
#define SDX_FILES_FILE_HANDLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandleClass))

typedef struct _sdxfilesFileHandle sdxfilesFileHandle;
typedef struct _sdxfilesFileHandleClass sdxfilesFileHandleClass;

struct _sdxIApplicationIface {
	GTypeInterface parent_iface;
	gint (*get_width) (sdxIApplication* self);
	void (*set_width) (sdxIApplication* self, gint value);
	gint (*get_height) (sdxIApplication* self);
	void (*set_height) (sdxIApplication* self, gint value);
	SDL_Renderer* (*get_renderer) (sdxIApplication* self);
};

struct _sdxApplication {
	GObject parent_instance;
	sdxApplicationPrivate * priv;
	gchar* name;
	gchar* defaultFont;
	sdxgraphicss2dFont* font;
	gboolean running;
	SDL_Window* window;
	GeeArrayList* sprites;
	GeeArrayList* onetime;
	gboolean showFps;
};

struct _sdxApplicationClass {
	GObjectClass parent_class;
	void (*draw) (sdxApplication* self);
	void (*dispose) (sdxApplication* self);
	gboolean (*initialize) (sdxApplication* self);
};

struct _sdxApplicationListenerIface {
	GTypeInterface parent_iface;
	void (*create) (sdxApplicationListener* self);
	void (*resize) (sdxApplicationListener* self, gint width, gint height);
	void (*render) (sdxApplicationListener* self);
	void (*pause) (sdxApplicationListener* self);
	void (*resume) (sdxApplicationListener* self);
	void (*dispose) (sdxApplicationListener* self);
};

struct _sdxApplicationPrivate {
	gint _width;
	gint _height;
	SDL_Renderer* _renderer;
	sdxgraphicss2dSprite* fpsSprite;
	sdxApplicationListener* app;
};

typedef enum  {
	SDX_INPUT_KEYS_Esc = SDLK_ESCAPE,
	SDX_INPUT_KEYS_a = SDLK_a,
	SDX_INPUT_KEYS_b = SDLK_b,
	SDX_INPUT_KEYS_c = SDLK_c,
	SDX_INPUT_KEYS_d = SDLK_d,
	SDX_INPUT_KEYS_e = SDLK_e,
	SDX_INPUT_KEYS_f = SDLK_f,
	SDX_INPUT_KEYS_g = SDLK_g,
	SDX_INPUT_KEYS_h = SDLK_h,
	SDX_INPUT_KEYS_i = SDLK_i,
	SDX_INPUT_KEYS_j = SDLK_j,
	SDX_INPUT_KEYS_k = SDLK_k,
	SDX_INPUT_KEYS_l = SDLK_l,
	SDX_INPUT_KEYS_m = SDLK_m,
	SDX_INPUT_KEYS_n = SDLK_n,
	SDX_INPUT_KEYS_o = SDLK_o,
	SDX_INPUT_KEYS_p = SDLK_p,
	SDX_INPUT_KEYS_q = SDLK_q,
	SDX_INPUT_KEYS_r = SDLK_r,
	SDX_INPUT_KEYS_s = SDLK_s,
	SDX_INPUT_KEYS_t = SDLK_t,
	SDX_INPUT_KEYS_u = SDLK_u,
	SDX_INPUT_KEYS_v = SDLK_v,
	SDX_INPUT_KEYS_w = SDLK_w,
	SDX_INPUT_KEYS_x = SDLK_x,
	SDX_INPUT_KEYS_y = SDLK_y,
	SDX_INPUT_KEYS_z = SDLK_z
} sdxInputKeys;


static gpointer sdx_application_parent_class = NULL;
static sdxIApplicationIface* sdx_application_sdx_iapplication_parent_iface = NULL;

GType sdx_iapplication_get_type (void) G_GNUC_CONST;
GType sdx_application_get_type (void) G_GNUC_CONST;
GType sdx_graphics_s2d_font_get_type (void) G_GNUC_CONST;
GType sdx_graphics_s2d_sprite_get_type (void) G_GNUC_CONST;
GType sdx_application_listener_get_type (void) G_GNUC_CONST;
#define SDX_APPLICATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_TYPE_APPLICATION, sdxApplicationPrivate))
enum  {
	SDX_APPLICATION_DUMMY_PROPERTY,
	SDX_APPLICATION_WIDTH,
	SDX_APPLICATION_HEIGHT,
	SDX_APPLICATION_RENDERER
};
#define SDX_APPLICATION_YieldForEventsMS 1000
sdxApplication* sdx_application_new (gint width, gint height, const gchar* base);
sdxApplication* sdx_application_construct (GType object_type, gint width, gint height, const gchar* base);
sdxSdx* sdx_sdx_new (sdxIApplication* app, gint width, gint height, const gchar* base);
sdxSdx* sdx_sdx_construct (GType object_type, sdxIApplication* app, gint width, gint height, const gchar* base);
GType sdx_sdx_get_type (void) G_GNUC_CONST;
void sdx_application_setApplicationListener (sdxApplication* self, sdxApplicationListener* listener);
gint sdx_application_run (sdxApplication* self);
gboolean sdx_application_initialize (sdxApplication* self);
void sdx_application_listener_create (sdxApplicationListener* self);
GType sdx_input_get_type (void) G_GNUC_CONST;
sdxInput* sdx_sdx_get_input (void);
gboolean sdx_input_processEvents (sdxInput* self);
guint8* sdx_input_get_keys (sdxInput* self, int* result_length1);
GType sdx_input_keys_get_type (void) G_GNUC_CONST;
GType sdx_graphics_get_type (void) G_GNUC_CONST;
sdxGraphics* sdx_sdx_get_graphics (void);
void sdx_graphics_updateTime (sdxGraphics* self);
void sdx_application_listener_render (sdxApplicationListener* self);
void sdx_application_draw (sdxApplication* self);
gint sdx_graphics_get_fps (sdxGraphics* self);
GType sdx_graphics_color_get_type (void) G_GNUC_CONST;
sdxgraphicsColor* sdx_graphics_color_get_AntiqueWhite (void);
sdxgraphicss2dSprite* sdx_graphics_s2d_sprite_new_text (const gchar* text, sdxgraphicss2dFont* font, sdxgraphicsColor* color);
sdxgraphicss2dSprite* sdx_graphics_s2d_sprite_construct_text (GType object_type, const gchar* text, sdxgraphicss2dFont* font, sdxgraphicsColor* color);
void sdx_graphics_s2d_sprite_set_centered (sdxgraphicss2dSprite* self, gboolean value);
void sdx_application_dispose (sdxApplication* self);
static void sdx_application_real_draw (sdxApplication* self);
void sdx_graphics_s2d_sprite_render (sdxgraphicss2dSprite* self, SDL_Renderer* renderer, gint x, gint y, SDL_Rect* clip);
gint sdx_graphics_s2d_sprite_get_x (sdxgraphicss2dSprite* self);
gint sdx_graphics_s2d_sprite_get_y (sdxgraphicss2dSprite* self);
static void sdx_application_real_dispose (sdxApplication* self);
static gboolean sdx_application_real_initialize (sdxApplication* self);
void sdx_sdlFailIf (gboolean cond, const gchar* reason);
gint sdx_iapplication_get_width (sdxIApplication* self);
gint sdx_iapplication_get_height (sdxIApplication* self);
GType sdx_files_get_type (void) G_GNUC_CONST;
sdxFiles* sdx_sdx_get_files (void);
GType sdx_files_file_handle_get_type (void) G_GNUC_CONST;
sdxfilesFileHandle* sdx_files_resource (sdxFiles* self, const gchar* path);
sdxgraphicss2dFont* sdx_graphics_s2d_font_new (sdxfilesFileHandle* file, gint size);
sdxgraphicss2dFont* sdx_graphics_s2d_font_construct (GType object_type, sdxfilesFileHandle* file, gint size);
static void sdx_application_finalize (GObject* obj);
SDL_Renderer* sdx_iapplication_get_renderer (sdxIApplication* self);
static void _vala_sdx_application_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
void sdx_iapplication_set_width (sdxIApplication* self, gint value);
void sdx_iapplication_set_height (sdxIApplication* self, gint value);
static void _vala_sdx_application_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


sdxApplication* sdx_application_construct (GType object_type, gint width, gint height, const gchar* base) {
	sdxApplication * self = NULL;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	const gchar* _tmp2_ = NULL;
	sdxSdx* _tmp3_ = NULL;
	sdxSdx* _tmp4_ = NULL;
	g_return_val_if_fail (base != NULL, NULL);
	self = (sdxApplication*) g_object_new (object_type, NULL);
	_tmp0_ = width;
	_tmp1_ = height;
	_tmp2_ = base;
	_tmp3_ = sdx_sdx_new ((sdxIApplication*) self, _tmp0_, _tmp1_, _tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp4_);
	return self;
}


sdxApplication* sdx_application_new (gint width, gint height, const gchar* base) {
	return sdx_application_construct (SDX_TYPE_APPLICATION, width, height, base);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void sdx_application_setApplicationListener (sdxApplication* self, sdxApplicationListener* listener) {
	sdxApplicationListener* _tmp0_ = NULL;
	sdxApplicationListener* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (listener != NULL);
	_tmp0_ = listener;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->app);
	self->priv->app = _tmp1_;
}


/**
         * Run - start the game loop
         */
gint sdx_application_run (sdxApplication* self) {
	gint result = 0;
	gboolean _tmp0_ = FALSE;
	sdxApplicationListener* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = sdx_application_initialize (self);
	if (_tmp0_ == FALSE) {
		result = -1;
		return result;
	}
	_tmp1_ = self->priv->app;
	sdx_application_listener_create (_tmp1_);
	while (TRUE) {
		gboolean _tmp2_ = FALSE;
		sdxInput* _tmp3_ = NULL;
		sdxInput* _tmp4_ = NULL;
		gboolean _tmp5_ = FALSE;
		sdxGraphics* _tmp11_ = NULL;
		sdxGraphics* _tmp12_ = NULL;
		sdxApplicationListener* _tmp13_ = NULL;
		gboolean _tmp14_ = FALSE;
		_tmp3_ = sdx_sdx_get_input ();
		_tmp4_ = _tmp3_;
		_tmp5_ = sdx_input_processEvents (_tmp4_);
		if (_tmp5_) {
			sdxInput* _tmp6_ = NULL;
			sdxInput* _tmp7_ = NULL;
			guint8* _tmp8_ = NULL;
			gint _tmp8__length1 = 0;
			guint8* _tmp9_ = NULL;
			gint _tmp9__length1 = 0;
			guint8 _tmp10_ = 0U;
			_tmp6_ = sdx_sdx_get_input ();
			_tmp7_ = _tmp6_;
			_tmp8_ = sdx_input_get_keys (_tmp7_, &_tmp8__length1);
			_tmp9_ = _tmp8_;
			_tmp9__length1 = _tmp8__length1;
			_tmp10_ = _tmp9_[SDX_INPUT_KEYS_Esc];
			_tmp2_ = ((gint) _tmp10_) != 1;
		} else {
			_tmp2_ = FALSE;
		}
		if (!_tmp2_) {
			break;
		}
		_tmp11_ = sdx_sdx_get_graphics ();
		_tmp12_ = _tmp11_;
		sdx_graphics_updateTime (_tmp12_);
		_tmp13_ = self->priv->app;
		sdx_application_listener_render (_tmp13_);
		sdx_application_draw (self);
		_tmp14_ = self->showFps;
		if (_tmp14_) {
			sdxgraphicss2dSprite* _tmp15_ = NULL;
			sdxGraphics* _tmp16_ = NULL;
			sdxGraphics* _tmp17_ = NULL;
			gint _tmp18_ = 0;
			gint _tmp19_ = 0;
			gchar* _tmp20_ = NULL;
			gchar* _tmp21_ = NULL;
			sdxgraphicss2dFont* _tmp22_ = NULL;
			sdxgraphicsColor* _tmp23_ = NULL;
			sdxgraphicsColor* _tmp24_ = NULL;
			sdxgraphicss2dSprite* _tmp25_ = NULL;
			sdxgraphicss2dSprite* _tmp26_ = NULL;
			_tmp15_ = self->priv->fpsSprite;
			if (_tmp15_ != NULL) {
				_g_object_unref0 (self->priv->fpsSprite);
				self->priv->fpsSprite = NULL;
			}
			_tmp16_ = sdx_sdx_get_graphics ();
			_tmp17_ = _tmp16_;
			_tmp18_ = sdx_graphics_get_fps (_tmp17_);
			_tmp19_ = _tmp18_;
			_tmp20_ = g_strdup_printf ("%2.2f", (gdouble) _tmp19_);
			_tmp21_ = _tmp20_;
			_tmp22_ = self->font;
			_tmp23_ = sdx_graphics_color_get_AntiqueWhite ();
			_tmp24_ = _tmp23_;
			_tmp25_ = sdx_graphics_s2d_sprite_new_text (_tmp21_, _tmp22_, _tmp24_);
			_g_object_unref0 (self->priv->fpsSprite);
			self->priv->fpsSprite = _tmp25_;
			_g_free0 (_tmp21_);
			_tmp26_ = self->priv->fpsSprite;
			sdx_graphics_s2d_sprite_set_centered (_tmp26_, FALSE);
		}
	}
	sdx_application_dispose (self);
	result = 0;
	return result;
}


/**
         * Draw the current frame
         *
         * @param delta ms
         */
static void sdx_application_real_draw (sdxApplication* self) {
	SDL_Renderer* _tmp0_ = NULL;
	SDL_Renderer* _tmp1_ = NULL;
	gboolean _tmp21_ = FALSE;
	gboolean _tmp22_ = FALSE;
	GeeArrayList* _tmp45_ = NULL;
	SDL_Renderer* _tmp46_ = NULL;
	_tmp0_ = self->priv->_renderer;
	SDL_SetRenderDrawColor (_tmp0_, (guint8) 0x0, (guint8) 0x0, (guint8) 0x0, (guint8) 0x0);
	_tmp1_ = self->priv->_renderer;
	SDL_RenderClear (_tmp1_);
	{
		GeeArrayList* _sprite_list = NULL;
		GeeArrayList* _tmp2_ = NULL;
		GeeArrayList* _tmp3_ = NULL;
		gint _sprite_size = 0;
		GeeArrayList* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		gint _tmp6_ = 0;
		gint _sprite_index = 0;
		_tmp2_ = self->sprites;
		_tmp3_ = _g_object_ref0 (_tmp2_);
		_sprite_list = _tmp3_;
		_tmp4_ = _sprite_list;
		_tmp5_ = gee_abstract_collection_get_size ((GeeAbstractCollection*) _tmp4_);
		_tmp6_ = _tmp5_;
		_sprite_size = _tmp6_;
		_sprite_index = -1;
		while (TRUE) {
			gint _tmp7_ = 0;
			gint _tmp8_ = 0;
			gint _tmp9_ = 0;
			sdxgraphicss2dSprite* sprite = NULL;
			GeeArrayList* _tmp10_ = NULL;
			gint _tmp11_ = 0;
			gpointer _tmp12_ = NULL;
			sdxgraphicss2dSprite* _tmp13_ = NULL;
			SDL_Renderer* _tmp14_ = NULL;
			sdxgraphicss2dSprite* _tmp15_ = NULL;
			gint _tmp16_ = 0;
			gint _tmp17_ = 0;
			sdxgraphicss2dSprite* _tmp18_ = NULL;
			gint _tmp19_ = 0;
			gint _tmp20_ = 0;
			_tmp7_ = _sprite_index;
			_sprite_index = _tmp7_ + 1;
			_tmp8_ = _sprite_index;
			_tmp9_ = _sprite_size;
			if (!(_tmp8_ < _tmp9_)) {
				break;
			}
			_tmp10_ = _sprite_list;
			_tmp11_ = _sprite_index;
			_tmp12_ = gee_abstract_list_get ((GeeAbstractList*) _tmp10_, _tmp11_);
			sprite = (sdxgraphicss2dSprite*) _tmp12_;
			_tmp13_ = sprite;
			_tmp14_ = self->priv->_renderer;
			_tmp15_ = sprite;
			_tmp16_ = sdx_graphics_s2d_sprite_get_x (_tmp15_);
			_tmp17_ = _tmp16_;
			_tmp18_ = sprite;
			_tmp19_ = sdx_graphics_s2d_sprite_get_y (_tmp18_);
			_tmp20_ = _tmp19_;
			sdx_graphics_s2d_sprite_render (_tmp13_, _tmp14_, _tmp17_, _tmp20_, NULL);
			_g_object_unref0 (sprite);
		}
		_g_object_unref0 (_sprite_list);
	}
	_tmp22_ = self->showFps;
	if (_tmp22_) {
		sdxgraphicss2dSprite* _tmp23_ = NULL;
		_tmp23_ = self->priv->fpsSprite;
		_tmp21_ = _tmp23_ != NULL;
	} else {
		_tmp21_ = FALSE;
	}
	if (_tmp21_) {
		sdxgraphicss2dSprite* _tmp24_ = NULL;
		SDL_Renderer* _tmp25_ = NULL;
		_tmp24_ = self->priv->fpsSprite;
		_tmp25_ = self->priv->_renderer;
		sdx_graphics_s2d_sprite_render (_tmp24_, _tmp25_, 0, 0, NULL);
	}
	{
		GeeArrayList* _sprite_list = NULL;
		GeeArrayList* _tmp26_ = NULL;
		GeeArrayList* _tmp27_ = NULL;
		gint _sprite_size = 0;
		GeeArrayList* _tmp28_ = NULL;
		gint _tmp29_ = 0;
		gint _tmp30_ = 0;
		gint _sprite_index = 0;
		_tmp26_ = self->onetime;
		_tmp27_ = _g_object_ref0 (_tmp26_);
		_sprite_list = _tmp27_;
		_tmp28_ = _sprite_list;
		_tmp29_ = gee_abstract_collection_get_size ((GeeAbstractCollection*) _tmp28_);
		_tmp30_ = _tmp29_;
		_sprite_size = _tmp30_;
		_sprite_index = -1;
		while (TRUE) {
			gint _tmp31_ = 0;
			gint _tmp32_ = 0;
			gint _tmp33_ = 0;
			sdxgraphicss2dSprite* sprite = NULL;
			GeeArrayList* _tmp34_ = NULL;
			gint _tmp35_ = 0;
			gpointer _tmp36_ = NULL;
			sdxgraphicss2dSprite* _tmp37_ = NULL;
			SDL_Renderer* _tmp38_ = NULL;
			sdxgraphicss2dSprite* _tmp39_ = NULL;
			gint _tmp40_ = 0;
			gint _tmp41_ = 0;
			sdxgraphicss2dSprite* _tmp42_ = NULL;
			gint _tmp43_ = 0;
			gint _tmp44_ = 0;
			_tmp31_ = _sprite_index;
			_sprite_index = _tmp31_ + 1;
			_tmp32_ = _sprite_index;
			_tmp33_ = _sprite_size;
			if (!(_tmp32_ < _tmp33_)) {
				break;
			}
			_tmp34_ = _sprite_list;
			_tmp35_ = _sprite_index;
			_tmp36_ = gee_abstract_list_get ((GeeAbstractList*) _tmp34_, _tmp35_);
			sprite = (sdxgraphicss2dSprite*) _tmp36_;
			_tmp37_ = sprite;
			_tmp38_ = self->priv->_renderer;
			_tmp39_ = sprite;
			_tmp40_ = sdx_graphics_s2d_sprite_get_x (_tmp39_);
			_tmp41_ = _tmp40_;
			_tmp42_ = sprite;
			_tmp43_ = sdx_graphics_s2d_sprite_get_y (_tmp42_);
			_tmp44_ = _tmp43_;
			sdx_graphics_s2d_sprite_render (_tmp37_, _tmp38_, _tmp41_, _tmp44_, NULL);
			_g_object_unref0 (sprite);
		}
		_g_object_unref0 (_sprite_list);
	}
	_tmp45_ = gee_array_list_new (SDX_GRAPHICS_S2D_TYPE_SPRITE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, NULL, NULL, NULL);
	_g_object_unref0 (self->onetime);
	self->onetime = _tmp45_;
	if (SDX_APPLICATION_YieldForEventsMS > 0) {
		g_usleep ((gulong) SDX_APPLICATION_YieldForEventsMS);
	}
	_tmp46_ = self->priv->_renderer;
	SDL_RenderPresent (_tmp46_);
}


void sdx_application_draw (sdxApplication* self) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_GET_CLASS (self)->draw (self);
}


/**
         * Do the cleanup callback
         */
static void sdx_application_real_dispose (sdxApplication* self) {
}


void sdx_application_dispose (sdxApplication* self) {
	g_return_if_fail (self != NULL);
	SDX_APPLICATION_GET_CLASS (self)->dispose (self);
}


/**
         * Initialize SDL
         */
static gboolean sdx_application_real_initialize (sdxApplication* self) {
	gboolean result = FALSE;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	gboolean _tmp2_ = FALSE;
	const gchar* _tmp3_ = NULL;
	gint _tmp4_ = 0;
	gint _tmp5_ = 0;
	gint _tmp6_ = 0;
	gint _tmp7_ = 0;
	SDL_Window* _tmp8_ = NULL;
	SDL_Window* _tmp9_ = NULL;
	SDL_Window* _tmp10_ = NULL;
	SDL_Renderer* _tmp11_ = NULL;
	SDL_Renderer* _tmp12_ = NULL;
	SDL_Renderer* _tmp13_ = NULL;
	gint _tmp14_ = 0;
	const gchar* _tmp15_ = NULL;
	const gchar* _tmp16_ = NULL;
	gint _tmp25_ = 0;
	_tmp0_ = SDL_Init ((guint32) ((SDL_INIT_VIDEO | SDL_INIT_TIMER) | SDL_INIT_EVENTS));
	sdx_sdlFailIf (_tmp0_ < 0, "SDL could not initialize! SDL Error: %s");
	_tmp1_ = IMG_Init ((gint) IMG_INIT_PNG);
	sdx_sdlFailIf (_tmp1_ < 0, "SDL_image could not initialize!");
	_tmp2_ = SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, "1");
	sdx_sdlFailIf (!_tmp2_, "Warning: Linear texture filtering not enabled!!");
	_tmp3_ = self->name;
	_tmp4_ = sdx_iapplication_get_width ((sdxIApplication*) self);
	_tmp5_ = _tmp4_;
	_tmp6_ = sdx_iapplication_get_height ((sdxIApplication*) self);
	_tmp7_ = _tmp6_;
	_tmp8_ = SDL_CreateWindow (_tmp3_, (gint) SDL_WINDOWPOS_CENTERED_MASK, (gint) SDL_WINDOWPOS_CENTERED_MASK, _tmp5_, _tmp7_, (guint32) SDL_WINDOW_SHOWN);
	_SDL_DestroyWindow0 (self->window);
	self->window = _tmp8_;
	_tmp9_ = self->window;
	sdx_sdlFailIf (_tmp9_ == NULL, "Window could not be created!");
	_tmp10_ = self->window;
	_tmp11_ = SDL_CreateRenderer (_tmp10_, -1, (guint32) (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	_SDL_DestroyRenderer0 (self->priv->_renderer);
	self->priv->_renderer = _tmp11_;
	_tmp12_ = self->priv->_renderer;
	sdx_sdlFailIf (_tmp12_ == NULL, "Renderer could not be created!");
	_tmp13_ = self->priv->_renderer;
	SDL_SetRenderDrawColor (_tmp13_, (guint8) 0xFF, (guint8) 0xFF, (guint8) 0xFF, (guint8) 0);
	_tmp14_ = TTF_Init ();
	sdx_sdlFailIf (_tmp14_ == (-1), "SDL_ttf could not initialize!");
	_tmp15_ = self->defaultFont;
	g_print ("Initialize defaultFont = %s\n", _tmp15_);
	_tmp16_ = self->defaultFont;
	if (g_strcmp0 (_tmp16_, "") != 0) {
		sdxFiles* _tmp17_ = NULL;
		sdxFiles* _tmp18_ = NULL;
		const gchar* _tmp19_ = NULL;
		sdxfilesFileHandle* _tmp20_ = NULL;
		sdxfilesFileHandle* _tmp21_ = NULL;
		sdxgraphicss2dFont* _tmp22_ = NULL;
		sdxgraphicss2dFont* _tmp23_ = NULL;
		_tmp17_ = sdx_sdx_get_files ();
		_tmp18_ = _tmp17_;
		_tmp19_ = self->defaultFont;
		_tmp20_ = sdx_files_resource (_tmp18_, _tmp19_);
		_tmp21_ = _tmp20_;
		_tmp22_ = sdx_graphics_s2d_font_new (_tmp21_, 16);
		_g_object_unref0 (self->font);
		self->font = _tmp22_;
		_g_object_unref0 (_tmp21_);
		_tmp23_ = self->font;
		if (_tmp23_ == NULL) {
			const gchar* _tmp24_ = NULL;
			self->showFps = FALSE;
			_tmp24_ = SDL_GetError ();
			g_print ("Failed to load font, showFps set to false. SDL Error: %s\n", _tmp24_);
		} else {
			self->showFps = TRUE;
		}
	}
	g_print ("Initialized \n");
	_tmp25_ = Mix_OpenAudio (22050, AUDIO_S16LSB, 2, 4096);
	sdx_sdlFailIf (_tmp25_ == (-1), "SDL_mixer unagle to initialize!");
	result = TRUE;
	return result;
}


gboolean sdx_application_initialize (sdxApplication* self) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SDX_APPLICATION_GET_CLASS (self)->initialize (self);
}


static gint sdx_application_real_get_width (sdxIApplication* base) {
	gint result;
	sdxApplication* self;
	gint _tmp0_ = 0;
	self = (sdxApplication*) base;
	_tmp0_ = self->priv->_width;
	result = _tmp0_;
	return result;
}


static void sdx_application_real_set_width (sdxIApplication* base, gint value) {
	sdxApplication* self;
	gint _tmp0_ = 0;
	self = (sdxApplication*) base;
	_tmp0_ = value;
	self->priv->_width = _tmp0_;
	g_object_notify ((GObject *) self, "width");
}


static gint sdx_application_real_get_height (sdxIApplication* base) {
	gint result;
	sdxApplication* self;
	gint _tmp0_ = 0;
	self = (sdxApplication*) base;
	_tmp0_ = self->priv->_height;
	result = _tmp0_;
	return result;
}


static void sdx_application_real_set_height (sdxIApplication* base, gint value) {
	sdxApplication* self;
	gint _tmp0_ = 0;
	self = (sdxApplication*) base;
	_tmp0_ = value;
	self->priv->_height = _tmp0_;
	g_object_notify ((GObject *) self, "height");
}


static SDL_Renderer* sdx_application_real_get_renderer (sdxIApplication* base) {
	SDL_Renderer* result;
	sdxApplication* self;
	SDL_Renderer* _tmp0_ = NULL;
	self = (sdxApplication*) base;
	_tmp0_ = self->priv->_renderer;
	result = _tmp0_;
	return result;
}


static void sdx_application_class_init (sdxApplicationClass * klass) {
	sdx_application_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (sdxApplicationPrivate));
	((sdxApplicationClass *) klass)->draw = (void (*)(sdxApplication*)) sdx_application_real_draw;
	((sdxApplicationClass *) klass)->dispose = (void (*)(sdxApplication*)) sdx_application_real_dispose;
	((sdxApplicationClass *) klass)->initialize = (gboolean (*)(sdxApplication*)) sdx_application_real_initialize;
	G_OBJECT_CLASS (klass)->get_property = _vala_sdx_application_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_sdx_application_set_property;
	G_OBJECT_CLASS (klass)->finalize = sdx_application_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_APPLICATION_WIDTH, g_param_spec_int ("width", "width", "width", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_APPLICATION_HEIGHT, g_param_spec_int ("height", "height", "height", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_APPLICATION_RENDERER, g_param_spec_pointer ("renderer", "renderer", "renderer", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void sdx_application_sdx_iapplication_interface_init (sdxIApplicationIface * iface) {
	sdx_application_sdx_iapplication_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_width = sdx_application_real_get_width;
	iface->set_width = sdx_application_real_set_width;
	iface->get_height = sdx_application_real_get_height;
	iface->set_height = sdx_application_real_set_height;
	iface->get_renderer = sdx_application_real_get_renderer;
}


static void sdx_application_instance_init (sdxApplication * self) {
	GeeArrayList* _tmp0_ = NULL;
	GeeArrayList* _tmp1_ = NULL;
	self->priv = SDX_APPLICATION_GET_PRIVATE (self);
	_tmp0_ = gee_array_list_new (SDX_GRAPHICS_S2D_TYPE_SPRITE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, NULL, NULL, NULL);
	self->sprites = _tmp0_;
	_tmp1_ = gee_array_list_new (SDX_GRAPHICS_S2D_TYPE_SPRITE, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, NULL, NULL, NULL);
	self->onetime = _tmp1_;
	self->showFps = FALSE;
}


static void sdx_application_finalize (GObject* obj) {
	sdxApplication * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_TYPE_APPLICATION, sdxApplication);
	_g_free0 (self->name);
	_g_free0 (self->defaultFont);
	_g_object_unref0 (self->font);
	_SDL_DestroyWindow0 (self->window);
	_SDL_DestroyRenderer0 (self->priv->_renderer);
	_g_object_unref0 (self->sprites);
	_g_object_unref0 (self->onetime);
	_g_object_unref0 (self->priv->fpsSprite);
	_g_object_unref0 (self->priv->app);
	G_OBJECT_CLASS (sdx_application_parent_class)->finalize (obj);
}


/**
     * Core SDL Application
     */
GType sdx_application_get_type (void) {
	static volatile gsize sdx_application_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxApplication), 0, (GInstanceInitFunc) sdx_application_instance_init, NULL };
		static const GInterfaceInfo sdx_iapplication_info = { (GInterfaceInitFunc) sdx_application_sdx_iapplication_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType sdx_application_type_id;
		sdx_application_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxApplication", &g_define_type_info, 0);
		g_type_add_interface_static (sdx_application_type_id, SDX_TYPE_IAPPLICATION, &sdx_iapplication_info);
		g_once_init_leave (&sdx_application_type_id__volatile, sdx_application_type_id);
	}
	return sdx_application_type_id__volatile;
}


static void _vala_sdx_application_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	sdxApplication * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_TYPE_APPLICATION, sdxApplication);
	switch (property_id) {
		case SDX_APPLICATION_WIDTH:
		g_value_set_int (value, sdx_iapplication_get_width ((sdxIApplication*) self));
		break;
		case SDX_APPLICATION_HEIGHT:
		g_value_set_int (value, sdx_iapplication_get_height ((sdxIApplication*) self));
		break;
		case SDX_APPLICATION_RENDERER:
		g_value_set_pointer (value, sdx_iapplication_get_renderer ((sdxIApplication*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_sdx_application_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	sdxApplication * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_TYPE_APPLICATION, sdxApplication);
	switch (property_id) {
		case SDX_APPLICATION_WIDTH:
		sdx_iapplication_set_width ((sdxIApplication*) self, g_value_get_int (value));
		break;
		case SDX_APPLICATION_HEIGHT:
		sdx_iapplication_set_height ((sdxIApplication*) self, g_value_get_int (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


