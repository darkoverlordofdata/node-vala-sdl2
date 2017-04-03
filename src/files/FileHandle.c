/* FileHandle.c generated by valac 0.34.7, the Vala compiler
 * generated from FileHandle.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_rwops.h>


#define SDX_FILES_TYPE_FILE_HANDLE (sdx_files_file_handle_get_type ())
#define SDX_FILES_FILE_HANDLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandle))
#define SDX_FILES_FILE_HANDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandleClass))
#define SDX_FILES_IS_FILE_HANDLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_FILES_TYPE_FILE_HANDLE))
#define SDX_FILES_IS_FILE_HANDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_FILES_TYPE_FILE_HANDLE))
#define SDX_FILES_FILE_HANDLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandleClass))

typedef struct _sdxfilesFileHandle sdxfilesFileHandle;
typedef struct _sdxfilesFileHandleClass sdxfilesFileHandleClass;
typedef struct _sdxfilesFileHandlePrivate sdxfilesFileHandlePrivate;

#define SDX_TYPE_FILE_TYPE (sdx_file_type_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define SDX_TYPE_FILES (sdx_files_get_type ())
#define SDX_FILES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_FILES, sdxFiles))
#define SDX_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_FILES, sdxFilesClass))
#define SDX_IS_FILES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_FILES))
#define SDX_IS_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_FILES))
#define SDX_FILES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_FILES, sdxFilesClass))

typedef struct _sdxFiles sdxFiles;
typedef struct _sdxFilesClass sdxFilesClass;
#define _g_bytes_unref0(var) ((var == NULL) ? NULL : (var = (g_bytes_unref (var), NULL)))
#define _SDL_FreeRW0(var) ((var == NULL) ? NULL : (var = (SDL_FreeRW (var), NULL)))

struct _sdxfilesFileHandle {
	GObject parent_instance;
	sdxfilesFileHandlePrivate * priv;
};

struct _sdxfilesFileHandleClass {
	GObjectClass parent_class;
};

typedef enum  {
	SDX_FILE_TYPE_Internal,
	SDX_FILE_TYPE_Resource,
	SDX_FILE_TYPE_External,
	SDX_FILE_TYPE_Absolute,
	SDX_FILE_TYPE_Local
} sdxFileType;

struct _sdxfilesFileHandlePrivate {
	GFile* _file;
	gchar* _path;
	sdxFileType _type;
};


static gpointer sdx_files_file_handle_parent_class = NULL;

GType sdx_files_file_handle_get_type (void) G_GNUC_CONST;
GType sdx_file_type_get_type (void) G_GNUC_CONST;
#define SDX_FILES_FILE_HANDLE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandlePrivate))
enum  {
	SDX_FILES_FILE_HANDLE_DUMMY_PROPERTY,
	SDX_FILES_FILE_HANDLE_FILE,
	SDX_FILES_FILE_HANDLE_PATH
};
sdxfilesFileHandle* sdx_files_file_handle_new (const gchar* fileName, sdxFileType type);
sdxfilesFileHandle* sdx_files_file_handle_construct (GType object_type, const gchar* fileName, sdxFileType type);
GType sdx_files_get_type (void) G_GNUC_CONST;
sdxFiles* sdx_sdx_get_files (void);
gboolean sdx_files_get_isResource (sdxFiles* self);
const gchar* sdx_files_get_resourcePath (sdxFiles* self);
#define SDX_FILES_separator "/"
SDL_RWops* sdx_files_file_handle_getRWops (sdxfilesFileHandle* self);
gchar* sdx_files_file_handle_getPath (sdxfilesFileHandle* self);
void sdx_sdlFailIf (gboolean cond, const gchar* reason);
sdxFileType sdx_files_file_handle_getType (sdxfilesFileHandle* self);
gchar* sdx_files_file_handle_getName (sdxfilesFileHandle* self);
GFile* sdx_files_file_handle_get_file (sdxfilesFileHandle* self);
gchar* sdx_files_file_handle_getExt (sdxfilesFileHandle* self);
sdxfilesFileHandle* sdx_files_file_handle_getParent (sdxfilesFileHandle* self);
gboolean sdx_files_file_handle_exists (sdxfilesFileHandle* self);
sdxfilesFileHandle* sdx_files_file_handle_child (sdxfilesFileHandle* self, const gchar* name);
GInputStream* sdx_files_file_handle_read (sdxfilesFileHandle* self);
GBytes* sdx_files_file_handle_bytes (sdxfilesFileHandle* self);
const gchar* sdx_files_file_handle_get_path (sdxfilesFileHandle* self);
static void sdx_files_file_handle_finalize (GObject* obj);
static void _vala_sdx_files_file_handle_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);


static glong string_strnlen (gchar* str, glong maxlen) {
	glong result = 0L;
	gchar* end = NULL;
	gchar* _tmp0_ = NULL;
	glong _tmp1_ = 0L;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	_tmp0_ = str;
	_tmp1_ = maxlen;
	_tmp2_ = memchr (_tmp0_, 0, (gsize) _tmp1_);
	end = _tmp2_;
	_tmp3_ = end;
	if (_tmp3_ == NULL) {
		glong _tmp4_ = 0L;
		_tmp4_ = maxlen;
		result = _tmp4_;
		return result;
	} else {
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		_tmp5_ = end;
		_tmp6_ = str;
		result = (glong) (_tmp5_ - _tmp6_);
		return result;
	}
}


static gchar* string_substring (const gchar* self, glong offset, glong len) {
	gchar* result = NULL;
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	glong _tmp1_ = 0L;
	glong _tmp8_ = 0L;
	glong _tmp14_ = 0L;
	glong _tmp17_ = 0L;
	glong _tmp18_ = 0L;
	glong _tmp19_ = 0L;
	glong _tmp20_ = 0L;
	glong _tmp21_ = 0L;
	gchar* _tmp22_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = offset;
	if (_tmp1_ >= ((glong) 0)) {
		glong _tmp2_ = 0L;
		_tmp2_ = len;
		_tmp0_ = _tmp2_ >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		glong _tmp3_ = 0L;
		glong _tmp4_ = 0L;
		glong _tmp5_ = 0L;
		_tmp3_ = offset;
		_tmp4_ = len;
		_tmp5_ = string_strnlen ((gchar*) self, _tmp3_ + _tmp4_);
		string_length = _tmp5_;
	} else {
		gint _tmp6_ = 0;
		gint _tmp7_ = 0;
		_tmp6_ = strlen (self);
		_tmp7_ = _tmp6_;
		string_length = (glong) _tmp7_;
	}
	_tmp8_ = offset;
	if (_tmp8_ < ((glong) 0)) {
		glong _tmp9_ = 0L;
		glong _tmp10_ = 0L;
		glong _tmp11_ = 0L;
		_tmp9_ = string_length;
		_tmp10_ = offset;
		offset = _tmp9_ + _tmp10_;
		_tmp11_ = offset;
		g_return_val_if_fail (_tmp11_ >= ((glong) 0), NULL);
	} else {
		glong _tmp12_ = 0L;
		glong _tmp13_ = 0L;
		_tmp12_ = offset;
		_tmp13_ = string_length;
		g_return_val_if_fail (_tmp12_ <= _tmp13_, NULL);
	}
	_tmp14_ = len;
	if (_tmp14_ < ((glong) 0)) {
		glong _tmp15_ = 0L;
		glong _tmp16_ = 0L;
		_tmp15_ = string_length;
		_tmp16_ = offset;
		len = _tmp15_ - _tmp16_;
	}
	_tmp17_ = offset;
	_tmp18_ = len;
	_tmp19_ = string_length;
	g_return_val_if_fail ((_tmp17_ + _tmp18_) <= _tmp19_, NULL);
	_tmp20_ = offset;
	_tmp21_ = len;
	_tmp22_ = g_strndup (((gchar*) self) + _tmp20_, (gsize) _tmp21_);
	result = _tmp22_;
	return result;
}


sdxfilesFileHandle* sdx_files_file_handle_construct (GType object_type, const gchar* fileName, sdxFileType type) {
	sdxfilesFileHandle * self = NULL;
	sdxFileType _tmp0_ = 0;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	sdxFiles* _tmp5_ = NULL;
	sdxFiles* _tmp6_ = NULL;
	gboolean _tmp7_ = FALSE;
	gboolean _tmp8_ = FALSE;
	g_return_val_if_fail (fileName != NULL, NULL);
	self = (sdxfilesFileHandle*) g_object_new (object_type, NULL);
	_tmp0_ = type;
	self->priv->_type = _tmp0_;
	_tmp1_ = fileName;
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 (self->priv->_path);
	self->priv->_path = _tmp2_;
	_tmp5_ = sdx_sdx_get_files ();
	_tmp6_ = _tmp5_;
	_tmp7_ = sdx_files_get_isResource (_tmp6_);
	_tmp8_ = _tmp7_;
	if (_tmp8_) {
		sdxFileType _tmp9_ = 0;
		_tmp9_ = type;
		_tmp4_ = _tmp9_ == SDX_FILE_TYPE_Resource;
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		_tmp10_ = fileName;
		_tmp11_ = string_substring (_tmp10_, (glong) 0, (glong) 1);
		_tmp12_ = _tmp11_;
		_tmp3_ = g_strcmp0 (_tmp12_, "/") != 0;
		_g_free0 (_tmp12_);
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		sdxFiles* _tmp13_ = NULL;
		sdxFiles* _tmp14_ = NULL;
		const gchar* _tmp15_ = NULL;
		const gchar* _tmp16_ = NULL;
		sdxFiles* _tmp17_ = NULL;
		sdxFiles* _tmp18_ = NULL;
		gchar* _tmp19_ = NULL;
		gchar* _tmp20_ = NULL;
		const gchar* _tmp21_ = NULL;
		gchar* _tmp22_ = NULL;
		gchar* _tmp23_ = NULL;
		GFile* _tmp24_ = NULL;
		_tmp13_ = sdx_sdx_get_files ();
		_tmp14_ = _tmp13_;
		_tmp15_ = sdx_files_get_resourcePath (_tmp14_);
		_tmp16_ = _tmp15_;
		_tmp17_ = sdx_sdx_get_files ();
		_tmp18_ = _tmp17_;
		_tmp19_ = g_strconcat (_tmp16_, SDX_FILES_separator, NULL);
		_tmp20_ = _tmp19_;
		_tmp21_ = fileName;
		_tmp22_ = g_strconcat (_tmp20_, _tmp21_, NULL);
		_tmp23_ = _tmp22_;
		_tmp24_ = g_file_new_for_path (_tmp23_);
		_g_object_unref0 (self->priv->_file);
		self->priv->_file = _tmp24_;
		_g_free0 (_tmp23_);
		_g_free0 (_tmp20_);
	} else {
		const gchar* _tmp25_ = NULL;
		gchar* _tmp26_ = NULL;
		gchar* _tmp27_ = NULL;
		gboolean _tmp28_ = FALSE;
		_tmp25_ = fileName;
		_tmp26_ = string_substring (_tmp25_, (glong) 0, (glong) 1);
		_tmp27_ = _tmp26_;
		_tmp28_ = g_strcmp0 (_tmp27_, "/") == 0;
		_g_free0 (_tmp27_);
		if (_tmp28_) {
			const gchar* _tmp29_ = NULL;
			GFile* _tmp30_ = NULL;
			_tmp29_ = fileName;
			_tmp30_ = g_file_new_for_path (_tmp29_);
			_g_object_unref0 (self->priv->_file);
			self->priv->_file = _tmp30_;
		} else {
			sdxFiles* _tmp31_ = NULL;
			sdxFiles* _tmp32_ = NULL;
			const gchar* _tmp33_ = NULL;
			const gchar* _tmp34_ = NULL;
			sdxFiles* _tmp35_ = NULL;
			sdxFiles* _tmp36_ = NULL;
			gchar* _tmp37_ = NULL;
			gchar* _tmp38_ = NULL;
			const gchar* _tmp39_ = NULL;
			gchar* _tmp40_ = NULL;
			gchar* _tmp41_ = NULL;
			GFile* _tmp42_ = NULL;
			_tmp31_ = sdx_sdx_get_files ();
			_tmp32_ = _tmp31_;
			_tmp33_ = sdx_files_get_resourcePath (_tmp32_);
			_tmp34_ = _tmp33_;
			_tmp35_ = sdx_sdx_get_files ();
			_tmp36_ = _tmp35_;
			_tmp37_ = g_strconcat (_tmp34_, SDX_FILES_separator, NULL);
			_tmp38_ = _tmp37_;
			_tmp39_ = fileName;
			_tmp40_ = g_strconcat (_tmp38_, _tmp39_, NULL);
			_tmp41_ = _tmp40_;
			_tmp42_ = g_file_new_for_path (_tmp41_);
			_g_object_unref0 (self->priv->_file);
			self->priv->_file = _tmp42_;
			_g_free0 (_tmp41_);
			_g_free0 (_tmp38_);
		}
	}
	return self;
}


sdxfilesFileHandle* sdx_files_file_handle_new (const gchar* fileName, sdxFileType type) {
	return sdx_files_file_handle_construct (SDX_FILES_TYPE_FILE_HANDLE, fileName, type);
}


/**
         * getRWops
         *
         * get the raw memory content of the underlying file
         */
SDL_RWops* sdx_files_file_handle_getRWops (sdxfilesFileHandle* self) {
	SDL_RWops* result = NULL;
	sdxFiles* _tmp0_ = NULL;
	sdxFiles* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = sdx_sdx_get_files ();
	_tmp1_ = _tmp0_;
	_tmp2_ = sdx_files_get_isResource (_tmp1_);
	_tmp3_ = _tmp2_;
	if (_tmp3_) {
		GBytes* ptr = NULL;
		gchar* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		GBytes* _tmp6_ = NULL;
		GBytes* _tmp7_ = NULL;
		SDL_RWops* raw = NULL;
		GBytes* _tmp8_ = NULL;
		gsize _tmp9_;
		guint8* _tmp10_ = NULL;
		GBytes* _tmp11_ = NULL;
		gsize _tmp12_ = 0UL;
		SDL_RWops* _tmp13_ = NULL;
		SDL_RWops* _tmp14_ = NULL;
		gchar* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_ = NULL;
		gchar* _tmp18_ = NULL;
		_tmp4_ = sdx_files_file_handle_getPath (self);
		_tmp5_ = _tmp4_;
		_tmp6_ = g_resources_lookup_data (_tmp5_, 0, &_inner_error_);
		_tmp7_ = _tmp6_;
		_g_free0 (_tmp5_);
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
		raw = _tmp13_;
		_tmp14_ = raw;
		_tmp15_ = sdx_files_file_handle_getPath (self);
		_tmp16_ = _tmp15_;
		_tmp17_ = g_strconcat ("Unable to get resource ", _tmp16_, NULL);
		_tmp18_ = _tmp17_;
		sdx_sdlFailIf (_tmp14_ == NULL, _tmp18_);
		_g_free0 (_tmp18_);
		_g_free0 (_tmp16_);
		result = raw;
		_g_bytes_unref0 (ptr);
		return result;
	} else {
		SDL_RWops* raw = NULL;
		gchar* _tmp19_ = NULL;
		gchar* _tmp20_ = NULL;
		SDL_RWops* _tmp21_ = NULL;
		SDL_RWops* _tmp22_ = NULL;
		SDL_RWops* _tmp23_ = NULL;
		gchar* _tmp24_ = NULL;
		gchar* _tmp25_ = NULL;
		gchar* _tmp26_ = NULL;
		gchar* _tmp27_ = NULL;
		_tmp19_ = sdx_files_file_handle_getPath (self);
		_tmp20_ = _tmp19_;
		_tmp21_ = SDL_RWFromFile (_tmp20_, "rb");
		_tmp22_ = _tmp21_;
		_g_free0 (_tmp20_);
		raw = _tmp22_;
		_tmp23_ = raw;
		_tmp24_ = sdx_files_file_handle_getPath (self);
		_tmp25_ = _tmp24_;
		_tmp26_ = g_strconcat ("Unable to get file ", _tmp25_, NULL);
		_tmp27_ = _tmp26_;
		sdx_sdlFailIf (_tmp23_ == NULL, _tmp27_);
		_g_free0 (_tmp27_);
		_g_free0 (_tmp25_);
		result = raw;
		return result;
	}
}


sdxFileType sdx_files_file_handle_getType (sdxfilesFileHandle* self) {
	sdxFileType result = 0;
	sdxFileType _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_type;
	result = _tmp0_;
	return result;
}


gchar* sdx_files_file_handle_getName (sdxfilesFileHandle* self) {
	gchar* result = NULL;
	GFile* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_file;
	_tmp1_ = g_file_get_basename (_tmp0_);
	result = _tmp1_;
	return result;
}


static gint string_last_index_of (const gchar* self, const gchar* needle, gint start_index) {
	gint result = 0;
	gchar* _result_ = NULL;
	gint _tmp0_ = 0;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (needle != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = needle;
	_tmp2_ = g_strrstr (((gchar*) self) + _tmp0_, (gchar*) _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_ = NULL;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


gchar* sdx_files_file_handle_getExt (sdxfilesFileHandle* self) {
	gchar* result = NULL;
	gchar* name = NULL;
	gchar* _tmp0_ = NULL;
	gint i = 0;
	const gchar* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	const gchar* _tmp5_ = NULL;
	gint _tmp6_ = 0;
	gchar* _tmp7_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = sdx_files_file_handle_getName (self);
	name = _tmp0_;
	_tmp1_ = name;
	_tmp2_ = string_last_index_of (_tmp1_, ".", 0);
	i = _tmp2_;
	_tmp3_ = i;
	if (_tmp3_ < 0) {
		gchar* _tmp4_ = NULL;
		_tmp4_ = g_strdup ("");
		result = _tmp4_;
		_g_free0 (name);
		return result;
	}
	_tmp5_ = name;
	_tmp6_ = i;
	_tmp7_ = string_substring (_tmp5_, (glong) _tmp6_, (glong) -1);
	result = _tmp7_;
	_g_free0 (name);
	return result;
}


gchar* sdx_files_file_handle_getPath (sdxfilesFileHandle* self) {
	gchar* result = NULL;
	GFile* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_file;
	_tmp1_ = g_file_get_path (_tmp0_);
	result = _tmp1_;
	return result;
}


sdxfilesFileHandle* sdx_files_file_handle_getParent (sdxfilesFileHandle* self) {
	sdxfilesFileHandle* result = NULL;
	GFile* _tmp0_ = NULL;
	GFile* _tmp1_ = NULL;
	GFile* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	sdxFileType _tmp5_ = 0;
	sdxfilesFileHandle* _tmp6_ = NULL;
	sdxfilesFileHandle* _tmp7_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_file;
	_tmp1_ = g_file_get_parent (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_file_get_path (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = self->priv->_type;
	_tmp6_ = sdx_files_file_handle_new (_tmp4_, _tmp5_);
	_tmp7_ = _tmp6_;
	_g_free0 (_tmp4_);
	_g_object_unref0 (_tmp2_);
	result = _tmp7_;
	return result;
}


gboolean sdx_files_file_handle_exists (sdxfilesFileHandle* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	sdxFiles* _tmp1_ = NULL;
	sdxFiles* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp1_ = sdx_sdx_get_files ();
	_tmp2_ = _tmp1_;
	_tmp3_ = sdx_files_get_isResource (_tmp2_);
	_tmp4_ = _tmp3_;
	if (_tmp4_) {
		sdxFileType _tmp5_ = 0;
		_tmp5_ = self->priv->_type;
		_tmp0_ = _tmp5_ == SDX_FILE_TYPE_Resource;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		result = TRUE;
		return result;
	} else {
		GFile* _tmp6_ = NULL;
		gboolean _tmp7_ = FALSE;
		_tmp6_ = self->priv->_file;
		_tmp7_ = g_file_query_exists (_tmp6_, NULL);
		result = _tmp7_;
		return result;
	}
}


sdxfilesFileHandle* sdx_files_file_handle_child (sdxfilesFileHandle* self, const gchar* name) {
	sdxfilesFileHandle* result = NULL;
	GFile* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	sdxFiles* _tmp3_ = NULL;
	sdxFiles* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	const gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_ = NULL;
	sdxFileType _tmp10_ = 0;
	sdxfilesFileHandle* _tmp11_ = NULL;
	sdxfilesFileHandle* _tmp12_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = self->priv->_file;
	_tmp1_ = g_file_get_path (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = sdx_sdx_get_files ();
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strconcat (_tmp2_, SDX_FILES_separator, NULL);
	_tmp6_ = _tmp5_;
	_tmp7_ = name;
	_tmp8_ = g_strconcat (_tmp6_, _tmp7_, NULL);
	_tmp9_ = _tmp8_;
	_tmp10_ = self->priv->_type;
	_tmp11_ = sdx_files_file_handle_new (_tmp9_, _tmp10_);
	_tmp12_ = _tmp11_;
	_g_free0 (_tmp9_);
	_g_free0 (_tmp6_);
	_g_free0 (_tmp2_);
	result = _tmp12_;
	return result;
}


GInputStream* sdx_files_file_handle_read (sdxfilesFileHandle* self) {
	GInputStream* result = NULL;
	gboolean _tmp0_ = FALSE;
	sdxFiles* _tmp1_ = NULL;
	sdxFiles* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = sdx_sdx_get_files ();
	_tmp2_ = _tmp1_;
	_tmp3_ = sdx_files_get_isResource (_tmp2_);
	_tmp4_ = _tmp3_;
	if (_tmp4_) {
		sdxFileType _tmp5_ = 0;
		_tmp5_ = self->priv->_type;
		_tmp0_ = _tmp5_ == SDX_FILE_TYPE_Resource;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GInputStream* _tmp6_ = NULL;
		GFile* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		GInputStream* _tmp10_ = NULL;
		GInputStream* _tmp11_ = NULL;
		GInputStream* _tmp12_ = NULL;
		_tmp7_ = self->priv->_file;
		_tmp8_ = g_file_get_path (_tmp7_);
		_tmp9_ = _tmp8_;
		_tmp10_ = g_resources_open_stream (_tmp9_, 0, &_inner_error_);
		_tmp11_ = _tmp10_;
		_g_free0 (_tmp9_);
		_tmp6_ = _tmp11_;
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp12_ = _tmp6_;
		_tmp6_ = NULL;
		result = _tmp12_;
		_g_object_unref0 (_tmp6_);
		return result;
	} else {
		GFile* project = NULL;
		GFile* _tmp13_ = NULL;
		gchar* _tmp14_ = NULL;
		gchar* _tmp15_ = NULL;
		GFile* _tmp16_ = NULL;
		GFile* _tmp17_ = NULL;
		GFile* _tmp18_ = NULL;
		gboolean _tmp19_ = FALSE;
		_tmp13_ = self->priv->_file;
		_tmp14_ = g_file_get_path (_tmp13_);
		_tmp15_ = _tmp14_;
		_tmp16_ = g_file_new_for_path (_tmp15_);
		_tmp17_ = _tmp16_;
		_g_free0 (_tmp15_);
		project = _tmp17_;
		_tmp18_ = project;
		_tmp19_ = g_file_query_exists (_tmp18_, NULL);
		if (_tmp19_) {
			GFileInputStream* _tmp20_ = NULL;
			GFile* _tmp21_ = NULL;
			GFileInputStream* _tmp22_ = NULL;
			GFileInputStream* _tmp23_ = NULL;
			_tmp21_ = project;
			_tmp22_ = g_file_read (_tmp21_, NULL, &_inner_error_);
			_tmp20_ = _tmp22_;
			if (G_UNLIKELY (_inner_error_ != NULL)) {
				_g_object_unref0 (project);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			_tmp23_ = _tmp20_;
			_tmp20_ = NULL;
			result = (GInputStream*) _tmp23_;
			_g_object_unref0 (_tmp20_);
			_g_object_unref0 (project);
			return result;
		} else {
			GFile* _tmp24_ = NULL;
			gchar* _tmp25_ = NULL;
			gchar* _tmp26_ = NULL;
			_tmp24_ = self->priv->_file;
			_tmp25_ = g_file_get_path (_tmp24_);
			_tmp26_ = _tmp25_;
			g_print ("file %s not found\n", _tmp26_);
			_g_free0 (_tmp26_);
			result = NULL;
			_g_object_unref0 (project);
			return result;
		}
		_g_object_unref0 (project);
	}
}


GBytes* sdx_files_file_handle_bytes (sdxfilesFileHandle* self) {
	GBytes* result = NULL;
	GBytes* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	GBytes* _tmp3_ = NULL;
	GBytes* _tmp4_ = NULL;
	GBytes* _tmp5_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = sdx_files_file_handle_getPath (self);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_resources_lookup_data (_tmp2_, 0, &_inner_error_);
	_tmp4_ = _tmp3_;
	_g_free0 (_tmp2_);
	_tmp0_ = _tmp4_;
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp5_ = _tmp0_;
	_tmp0_ = NULL;
	result = _tmp5_;
	_g_bytes_unref0 (_tmp0_);
	return result;
}


GFile* sdx_files_file_handle_get_file (sdxfilesFileHandle* self) {
	GFile* result;
	GFile* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_file;
	result = _tmp0_;
	return result;
}


const gchar* sdx_files_file_handle_get_path (sdxfilesFileHandle* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_path;
	result = _tmp0_;
	return result;
}


static void sdx_files_file_handle_class_init (sdxfilesFileHandleClass * klass) {
	sdx_files_file_handle_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (sdxfilesFileHandlePrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_sdx_files_file_handle_get_property;
	G_OBJECT_CLASS (klass)->finalize = sdx_files_file_handle_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_FILES_FILE_HANDLE_FILE, g_param_spec_object ("file", "file", "file", g_file_get_type (), G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SDX_FILES_FILE_HANDLE_PATH, g_param_spec_string ("path", "path", "path", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void sdx_files_file_handle_instance_init (sdxfilesFileHandle * self) {
	self->priv = SDX_FILES_FILE_HANDLE_GET_PRIVATE (self);
}


static void sdx_files_file_handle_finalize (GObject* obj) {
	sdxfilesFileHandle * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandle);
	_g_object_unref0 (self->priv->_file);
	_g_free0 (self->priv->_path);
	G_OBJECT_CLASS (sdx_files_file_handle_parent_class)->finalize (obj);
}


GType sdx_files_file_handle_get_type (void) {
	static volatile gsize sdx_files_file_handle_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_files_file_handle_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxfilesFileHandleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_files_file_handle_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxfilesFileHandle), 0, (GInstanceInitFunc) sdx_files_file_handle_instance_init, NULL };
		GType sdx_files_file_handle_type_id;
		sdx_files_file_handle_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxfilesFileHandle", &g_define_type_info, 0);
		g_once_init_leave (&sdx_files_file_handle_type_id__volatile, sdx_files_file_handle_type_id);
	}
	return sdx_files_file_handle_type_id__volatile;
}


static void _vala_sdx_files_file_handle_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	sdxfilesFileHandle * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_FILES_TYPE_FILE_HANDLE, sdxfilesFileHandle);
	switch (property_id) {
		case SDX_FILES_FILE_HANDLE_FILE:
		g_value_set_object (value, sdx_files_file_handle_get_file (self));
		break;
		case SDX_FILES_FILE_HANDLE_PATH:
		g_value_set_string (value, sdx_files_file_handle_get_path (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


