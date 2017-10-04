/* Font.c generated by valac 0.34.9, the Vala compiler
 * generated from Font.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_rwops.h>
#include <gio/gio.h>
#include <SDL2/SDL_surface.h>


#define SDX_GRAPHICS_S2D_TYPE_FONT (sdx_graphics_s2d_font_get_type ())
#define SDX_GRAPHICS_S2D_FONT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFont))
#define SDX_GRAPHICS_S2D_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFontClass))
#define SDX_GRAPHICS_S2D_IS_FONT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_S2D_TYPE_FONT))
#define SDX_GRAPHICS_S2D_IS_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_S2D_TYPE_FONT))
#define SDX_GRAPHICS_S2D_FONT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFontClass))

typedef struct _sdxgraphicss2dFont sdxgraphicss2dFont;
typedef struct _sdxgraphicss2dFontClass sdxgraphicss2dFontClass;
typedef struct _sdxgraphicss2dFontPrivate sdxgraphicss2dFontPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _TTF_CloseFont0(var) ((var == NULL) ? NULL : (var = (TTF_CloseFont (var), NULL)))
#define _SDL_FreeRW0(var) ((var == NULL) ? NULL : (var = (SDL_FreeRW (var), NULL)))

#define SDX_FILES_TYPE_FILE_HANDLE (sdx_files_file_handle_get_type ())
#define SDX_FILES_FILE_HANDLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandle))
#define SDX_FILES_FILE_HANDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandleClass))
#define SDX_FILES_IS_FILE_HANDLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_FILES_TYPE_FILE_HANDLE))
#define SDX_FILES_IS_FILE_HANDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_FILES_TYPE_FILE_HANDLE))
#define SDX_FILES_FILE_HANDLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandleClass))

typedef struct _sdxfilesFileHandle sdxfilesFileHandle;
typedef struct _sdxfilesFileHandleClass sdxfilesFileHandleClass;

#define SDX_TYPE_FILES (sdx_files_get_type ())
#define SDX_FILES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_FILES, sdxFiles))
#define SDX_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_FILES, sdxFilesClass))
#define SDX_IS_FILES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_FILES))
#define SDX_IS_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_FILES))
#define SDX_FILES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_FILES, sdxFilesClass))

typedef struct _sdxFiles sdxFiles;
typedef struct _sdxFilesClass sdxFilesClass;
#define _g_bytes_unref0(var) ((var == NULL) ? NULL : (var = (g_bytes_unref (var), NULL)))

#define SDX_GRAPHICS_TYPE_COLOR (sdx_graphics_color_get_type ())
#define SDX_GRAPHICS_COLOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColor))
#define SDX_GRAPHICS_COLOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColorClass))
#define SDX_GRAPHICS_IS_COLOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_TYPE_COLOR))
#define SDX_GRAPHICS_IS_COLOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_TYPE_COLOR))
#define SDX_GRAPHICS_COLOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_TYPE_COLOR, sdxgraphicsColorClass))

typedef struct _sdxgraphicsColor sdxgraphicsColor;
typedef struct _sdxgraphicsColorClass sdxgraphicsColorClass;
typedef struct _sdxgraphicsColorPrivate sdxgraphicsColorPrivate;

struct _sdxgraphicss2dFont {
	GObject parent_instance;
	sdxgraphicss2dFontPrivate * priv;
	TTF_Font* innerFont;
};

struct _sdxgraphicss2dFontClass {
	GObjectClass parent_class;
};

struct _sdxgraphicss2dFontPrivate {
	gchar* _path;
	SDL_RWops* raw;
};

struct _sdxgraphicsColor {
	GObject parent_instance;
	sdxgraphicsColorPrivate * priv;
	guint8 r8;
	guint8 g8;
	guint8 b8;
	guint8 a8;
};

struct _sdxgraphicsColorClass {
	GObjectClass parent_class;
};


static gpointer sdx_graphics_s2d_font_parent_class = NULL;

GType sdx_graphics_s2d_font_get_type (void) G_GNUC_CONST;
#define SDX_GRAPHICS_S2D_FONT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFontPrivate))
enum  {
	SDX_GRAPHICS_S2D_FONT_DUMMY_PROPERTY,
	SDX_GRAPHICS_S2D_FONT_PATH
};
GType sdx_files_file_handle_get_type (void) G_GNUC_CONST;
sdxgraphicss2dFont* sdx_graphics_s2d_font_new (sdxfilesFileHandle* file, gint size);
sdxgraphicss2dFont* sdx_graphics_s2d_font_construct (GType object_type, sdxfilesFileHandle* file, gint size);
gchar* sdx_files_file_handle_getPath (sdxfilesFileHandle* self);
GType sdx_files_get_type (void) G_GNUC_CONST;
sdxFiles* sdx_sdx_get_files (void);
gboolean sdx_files_get_isResource (sdxFiles* self);
SDL_RWops* sdx_files_file_handle_getRWops (sdxfilesFileHandle* self);
GType sdx_graphics_color_get_type (void) G_GNUC_CONST;
SDL_Surface* sdx_graphics_s2d_font_render (sdxgraphicss2dFont* self, const gchar* text, sdxgraphicsColor* color);
const gchar* sdx_graphics_s2d_font_get_path (sdxgraphicss2dFont* self);
void sdx_graphics_s2d_font_set_path (sdxgraphicss2dFont* self, const gchar* value);
static void sdx_graphics_s2d_font_finalize (GObject* obj);
static void _vala_sdx_graphics_s2d_font_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_sdx_graphics_s2d_font_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


sdxgraphicss2dFont* sdx_graphics_s2d_font_construct (GType object_type, sdxfilesFileHandle* file, gint size) {
	sdxgraphicss2dFont * self = NULL;
	sdxfilesFileHandle* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	sdxFiles* _tmp2_ = NULL;
	sdxFiles* _tmp3_ = NULL;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp5_ = FALSE;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (file != NULL, NULL);
	self = (sdxgraphicss2dFont*) g_object_new (object_type, NULL);
	_tmp0_ = file;
	_tmp1_ = sdx_files_file_handle_getPath (_tmp0_);
	_g_free0 (self->priv->_path);
	self->priv->_path = _tmp1_;
	_tmp2_ = sdx_sdx_get_files ();
	_tmp3_ = _tmp2_;
	_tmp4_ = sdx_files_get_isResource (_tmp3_);
	_tmp5_ = _tmp4_;
	if (_tmp5_) {
		GBytes* ptr = NULL;
		const gchar* _tmp6_ = NULL;
		GBytes* _tmp7_ = NULL;
		GBytes* _tmp8_ = NULL;
		gsize _tmp9_;
		guint8* _tmp10_ = NULL;
		GBytes* _tmp11_ = NULL;
		gsize _tmp12_ = 0UL;
		SDL_RWops* _tmp13_ = NULL;
		SDL_RWops* _tmp14_ = NULL;
		gint _tmp15_ = 0;
		TTF_Font* _tmp16_ = NULL;
		_tmp6_ = self->priv->_path;
		_tmp7_ = g_resources_lookup_data (_tmp6_, 0, &_inner_error_);
		ptr = _tmp7_;
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp8_ = ptr;
		_tmp10_ = g_bytes_get_data (_tmp8_, &_tmp9_);
		_tmp11_ = ptr;
		_tmp12_ = g_bytes_get_size (_tmp11_);
		_tmp13_ = SDL_RWFromMem ((void*) _tmp10_, (gint) _tmp12_);
		_SDL_FreeRW0 (self->priv->raw);
		self->priv->raw = _tmp13_;
		_tmp14_ = self->priv->raw;
		_tmp15_ = size;
		_tmp16_ = TTF_OpenFontRW (_tmp14_, 0, _tmp15_);
		_TTF_CloseFont0 (self->innerFont);
		self->innerFont = _tmp16_;
		_g_bytes_unref0 (ptr);
	} else {
		sdxfilesFileHandle* _tmp17_ = NULL;
		SDL_RWops* _tmp18_ = NULL;
		SDL_RWops* _tmp19_ = NULL;
		gint _tmp20_ = 0;
		TTF_Font* _tmp21_ = NULL;
		_tmp17_ = file;
		_tmp18_ = sdx_files_file_handle_getRWops (_tmp17_);
		_SDL_FreeRW0 (self->priv->raw);
		self->priv->raw = _tmp18_;
		_tmp19_ = self->priv->raw;
		_tmp20_ = size;
		_tmp21_ = TTF_OpenFontRW (_tmp19_, 0, _tmp20_);
		_TTF_CloseFont0 (self->innerFont);
		self->innerFont = _tmp21_;
	}
	return self;
}


sdxgraphicss2dFont* sdx_graphics_s2d_font_new (sdxfilesFileHandle* file, gint size) {
	return sdx_graphics_s2d_font_construct (SDX_GRAPHICS_S2D_TYPE_FONT, file, size);
}


/**
         *  Render text for Sprite.fromRenderedText
         *
         * @param text to generate surface from
         * @param color foreground color of text
         * @return new Surface
         */
SDL_Surface* sdx_graphics_s2d_font_render (sdxgraphicss2dFont* self, const gchar* text, sdxgraphicsColor* color) {
	SDL_Surface* result = NULL;
	TTF_Font* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	sdxgraphicsColor* _tmp2_ = NULL;
	guint8 _tmp3_ = 0U;
	sdxgraphicsColor* _tmp4_ = NULL;
	guint8 _tmp5_ = 0U;
	sdxgraphicsColor* _tmp6_ = NULL;
	guint8 _tmp7_ = 0U;
	sdxgraphicsColor* _tmp8_ = NULL;
	guint8 _tmp9_ = 0U;
	SDL_Color _tmp10_ = {0};
	SDL_Surface* _tmp11_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (text != NULL, NULL);
	g_return_val_if_fail (color != NULL, NULL);
	_tmp0_ = self->innerFont;
	_tmp1_ = text;
	_tmp2_ = color;
	_tmp3_ = _tmp2_->r8;
	_tmp4_ = color;
	_tmp5_ = _tmp4_->g8;
	_tmp6_ = color;
	_tmp7_ = _tmp6_->b8;
	_tmp8_ = color;
	_tmp9_ = _tmp8_->a8;
	_tmp10_.r = _tmp3_;
	_tmp10_.g = _tmp5_;
	_tmp10_.b = _tmp7_;
	_tmp10_.a = _tmp9_;
	_tmp11_ = TTF_RenderUTF8_Solid (_tmp0_, _tmp1_, _tmp10_);
	result = _tmp11_;
	return result;
}


const gchar* sdx_graphics_s2d_font_get_path (sdxgraphicss2dFont* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_path;
	result = _tmp0_;
	return result;
}


void sdx_graphics_s2d_font_set_path (sdxgraphicss2dFont* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_path);
	self->priv->_path = _tmp1_;
	g_object_notify ((GObject *) self, "path");
}


static void sdx_graphics_s2d_font_class_init (sdxgraphicss2dFontClass * klass) {
	sdx_graphics_s2d_font_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (sdxgraphicss2dFontPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_sdx_graphics_s2d_font_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_sdx_graphics_s2d_font_set_property;
	G_OBJECT_CLASS (klass)->finalize = sdx_graphics_s2d_font_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_GRAPHICS_S2D_FONT_PATH, g_param_spec_string ("path", "path", "path", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void sdx_graphics_s2d_font_instance_init (sdxgraphicss2dFont * self) {
	self->priv = SDX_GRAPHICS_S2D_FONT_GET_PRIVATE (self);
}


static void sdx_graphics_s2d_font_finalize (GObject* obj) {
	sdxgraphicss2dFont * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFont);
	_g_free0 (self->priv->_path);
	_TTF_CloseFont0 (self->innerFont);
	_SDL_FreeRW0 (self->priv->raw);
	G_OBJECT_CLASS (sdx_graphics_s2d_font_parent_class)->finalize (obj);
}


GType sdx_graphics_s2d_font_get_type (void) {
	static volatile gsize sdx_graphics_s2d_font_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_graphics_s2d_font_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxgraphicss2dFontClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_graphics_s2d_font_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxgraphicss2dFont), 0, (GInstanceInitFunc) sdx_graphics_s2d_font_instance_init, NULL };
		GType sdx_graphics_s2d_font_type_id;
		sdx_graphics_s2d_font_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxgraphicss2dFont", &g_define_type_info, 0);
		g_once_init_leave (&sdx_graphics_s2d_font_type_id__volatile, sdx_graphics_s2d_font_type_id);
	}
	return sdx_graphics_s2d_font_type_id__volatile;
}


static void _vala_sdx_graphics_s2d_font_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	sdxgraphicss2dFont * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFont);
	switch (property_id) {
		case SDX_GRAPHICS_S2D_FONT_PATH:
		g_value_set_string (value, sdx_graphics_s2d_font_get_path (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_sdx_graphics_s2d_font_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	sdxgraphicss2dFont * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_GRAPHICS_S2D_TYPE_FONT, sdxgraphicss2dFont);
	switch (property_id) {
		case SDX_GRAPHICS_S2D_FONT_PATH:
		sdx_graphics_s2d_font_set_path (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



