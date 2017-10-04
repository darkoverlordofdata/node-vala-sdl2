/* StringTokenizer.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from StringTokenizer.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define SDX_UTILS_TYPE_STRING_TOKENIZER (sdx_utils_string_tokenizer_get_type ())
#define SDX_UTILS_STRING_TOKENIZER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_UTILS_TYPE_STRING_TOKENIZER, sdxutilsStringTokenizer))
#define SDX_UTILS_STRING_TOKENIZER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_UTILS_TYPE_STRING_TOKENIZER, sdxutilsStringTokenizerClass))
#define SDX_UTILS_IS_STRING_TOKENIZER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_UTILS_TYPE_STRING_TOKENIZER))
#define SDX_UTILS_IS_STRING_TOKENIZER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_UTILS_TYPE_STRING_TOKENIZER))
#define SDX_UTILS_STRING_TOKENIZER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_UTILS_TYPE_STRING_TOKENIZER, sdxutilsStringTokenizerClass))

typedef struct _sdxutilsStringTokenizer sdxutilsStringTokenizer;
typedef struct _sdxutilsStringTokenizerClass sdxutilsStringTokenizerClass;
typedef struct _sdxutilsStringTokenizerPrivate sdxutilsStringTokenizerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _sdxutilsParamSpecStringTokenizer sdxutilsParamSpecStringTokenizer;

struct _sdxutilsStringTokenizer {
	GTypeInstance parent_instance;
	volatile int ref_count;
	sdxutilsStringTokenizerPrivate * priv;
	gboolean hasSurrogates;
	gint* delimiterCodePoints;
	gint delimiterCodePoints_length1;
};

struct _sdxutilsStringTokenizerClass {
	GTypeClass parent_class;
	void (*finalize) (sdxutilsStringTokenizer *self);
};

struct _sdxutilsStringTokenizerPrivate {
	gint currentPosition;
	gint newPosition;
	gint maxPosition;
	gchar* str;
	gchar* delimiters;
	gboolean retDelims;
	gboolean delimsChanged;
	gint maxDelimCodePoint;
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
struct _sdxutilsParamSpecStringTokenizer {
	GParamSpec parent_instance;
};


static gpointer sdx_utils_string_tokenizer_parent_class = NULL;

gpointer sdx_utils_string_tokenizer_ref (gpointer instance);
void sdx_utils_string_tokenizer_unref (gpointer instance);
GParamSpec* sdx_utils_param_spec_string_tokenizer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void sdx_utils_value_set_string_tokenizer (GValue* value, gpointer v_object);
void sdx_utils_value_take_string_tokenizer (GValue* value, gpointer v_object);
gpointer sdx_utils_value_get_string_tokenizer (const GValue* value);
GType sdx_utils_string_tokenizer_get_type (void) G_GNUC_CONST;
#define SDX_UTILS_STRING_TOKENIZER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_UTILS_TYPE_STRING_TOKENIZER, sdxutilsStringTokenizerPrivate))
enum  {
	SDX_UTILS_STRING_TOKENIZER_DUMMY_PROPERTY
};
sdxutilsStringTokenizer* sdx_utils_string_tokenizer_new (const gchar* str, const gchar* delim, gboolean returnDelims);
sdxutilsStringTokenizer* sdx_utils_string_tokenizer_construct (GType object_type, const gchar* str, const gchar* delim, gboolean returnDelims);
static void sdx_utils_string_tokenizer_setMaxDelimCodePoint (sdxutilsStringTokenizer* self);
gint sdx_utils_string_tokenizer_skipDelimiters (sdxutilsStringTokenizer* self, gint startPos);
GQuark sdx_exception_quark (void);
gboolean sdx_utils_string_tokenizer_isDelimiter (sdxutilsStringTokenizer* self, gchar c);
gint sdx_utils_string_tokenizer_scanToken (sdxutilsStringTokenizer* self, gint startPos);
gboolean sdx_utils_string_tokenizer_hasMoreTokens (sdxutilsStringTokenizer* self);
gchar* sdx_utils_string_tokenizer_nextToken (sdxutilsStringTokenizer* self, const gchar* delim);
gboolean sdx_utils_string_tokenizer_hasMoreElements (sdxutilsStringTokenizer* self);
GObject* sdx_utils_string_tokenizer_nextElement (sdxutilsStringTokenizer* self);
gint sdx_utils_string_tokenizer_countTokens (sdxutilsStringTokenizer* self);
static void sdx_utils_string_tokenizer_finalize (sdxutilsStringTokenizer * obj);


sdxutilsStringTokenizer* sdx_utils_string_tokenizer_construct (GType object_type, const gchar* str, const gchar* delim, gboolean returnDelims) {
	sdxutilsStringTokenizer* self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	const gchar* _tmp5_;
	gchar* _tmp6_;
	gboolean _tmp7_;
	g_return_val_if_fail (str != NULL, NULL);
	g_return_val_if_fail (delim != NULL, NULL);
	self = (sdxutilsStringTokenizer*) g_type_create_instance (object_type);
	self->priv->currentPosition = 0;
	self->priv->newPosition = -1;
	self->priv->delimsChanged = FALSE;
	_tmp0_ = str;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->str);
	self->priv->str = _tmp1_;
	_tmp2_ = str;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	self->priv->maxPosition = _tmp4_;
	_tmp5_ = delim;
	_tmp6_ = g_strdup (_tmp5_);
	_g_free0 (self->priv->delimiters);
	self->priv->delimiters = _tmp6_;
	_tmp7_ = returnDelims;
	self->priv->retDelims = _tmp7_;
	sdx_utils_string_tokenizer_setMaxDelimCodePoint (self);
	return self;
}


sdxutilsStringTokenizer* sdx_utils_string_tokenizer_new (const gchar* str, const gchar* delim, gboolean returnDelims) {
	return sdx_utils_string_tokenizer_construct (SDX_UTILS_TYPE_STRING_TOKENIZER, str, delim, returnDelims);
}


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


static void sdx_utils_string_tokenizer_setMaxDelimCodePoint (sdxutilsStringTokenizer* self) {
	const gchar* _tmp0_;
	gint m = 0;
	gint c = 0;
	gint count = 0;
	gint _tmp13_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->delimiters;
	if (_tmp0_ == NULL) {
		self->priv->maxDelimCodePoint = 0;
		return;
	}
	m = 0;
	c = 0;
	count = 0;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp1_ = FALSE;
			_tmp1_ = TRUE;
			while (TRUE) {
				const gchar* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				const gchar* _tmp6_;
				gint _tmp7_;
				gchar _tmp8_;
				gint _tmp9_;
				gint _tmp10_;
				gint _tmp12_;
				if (!_tmp1_) {
					gint _tmp2_;
					_tmp2_ = i;
					i = _tmp2_ + 1;
				}
				_tmp1_ = FALSE;
				_tmp3_ = self->priv->delimiters;
				_tmp4_ = strlen (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(i <= (_tmp5_ - 1))) {
					break;
				}
				_tmp6_ = self->priv->delimiters;
				_tmp7_ = i;
				_tmp8_ = string_get (_tmp6_, (glong) _tmp7_);
				c = (gint) _tmp8_;
				_tmp9_ = m;
				_tmp10_ = c;
				if (_tmp9_ < _tmp10_) {
					gint _tmp11_;
					_tmp11_ = c;
					m = _tmp11_;
				}
				_tmp12_ = count;
				count = _tmp12_ + 1;
			}
		}
	}
	_tmp13_ = m;
	self->priv->maxDelimCodePoint = _tmp13_;
}


gint sdx_utils_string_tokenizer_skipDelimiters (sdxutilsStringTokenizer* self, gint startPos) {
	gint result = 0;
	const gchar* _tmp0_;
	gint position = 0;
	gint _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->delimiters;
	if (_tmp0_ == NULL) {
		GError* _tmp1_;
		gint _tmp2_ = 0;
		_tmp1_ = g_error_new_literal (SDX_EXCEPTION, SDX_EXCEPTION_NullPointerException, "delimiters");
		_inner_error_ = _tmp1_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return _tmp2_;
	}
	_tmp3_ = startPos;
	position = _tmp3_;
	while (TRUE) {
		gboolean _tmp4_ = FALSE;
		gboolean _tmp5_;
		gchar c = '\0';
		const gchar* _tmp8_;
		gint _tmp9_;
		gchar _tmp10_;
		gboolean _tmp11_ = FALSE;
		gchar _tmp12_;
		gint _tmp13_;
		gint _tmp16_;
		_tmp5_ = self->priv->retDelims;
		if (!_tmp5_) {
			gint _tmp6_;
			gint _tmp7_;
			_tmp6_ = position;
			_tmp7_ = self->priv->maxPosition;
			_tmp4_ = _tmp6_ < _tmp7_;
		} else {
			_tmp4_ = FALSE;
		}
		if (!_tmp4_) {
			break;
		}
		_tmp8_ = self->priv->str;
		_tmp9_ = position;
		_tmp10_ = string_get (_tmp8_, (glong) _tmp9_);
		c = _tmp10_;
		_tmp12_ = c;
		_tmp13_ = self->priv->maxDelimCodePoint;
		if (((gint) _tmp12_) > _tmp13_) {
			_tmp11_ = TRUE;
		} else {
			gchar _tmp14_;
			gboolean _tmp15_;
			_tmp14_ = c;
			_tmp15_ = sdx_utils_string_tokenizer_isDelimiter (self, _tmp14_);
			_tmp11_ = _tmp15_;
		}
		if (_tmp11_) {
			break;
		}
		_tmp16_ = position;
		position = _tmp16_ + 1;
	}
	result = position;
	return result;
}


gint sdx_utils_string_tokenizer_scanToken (sdxutilsStringTokenizer* self, gint startPos) {
	gint result = 0;
	gint position = 0;
	gint _tmp0_;
	gboolean _tmp12_ = FALSE;
	gboolean _tmp13_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = startPos;
	position = _tmp0_;
	while (TRUE) {
		gint _tmp1_;
		gint _tmp2_;
		gchar c = '\0';
		const gchar* _tmp3_;
		gint _tmp4_;
		gchar _tmp5_;
		gboolean _tmp6_ = FALSE;
		gchar _tmp7_;
		gint _tmp8_;
		gint _tmp11_;
		_tmp1_ = position;
		_tmp2_ = self->priv->maxPosition;
		if (!(_tmp1_ < _tmp2_)) {
			break;
		}
		_tmp3_ = self->priv->str;
		_tmp4_ = position;
		_tmp5_ = string_get (_tmp3_, (glong) _tmp4_);
		c = _tmp5_;
		_tmp7_ = c;
		_tmp8_ = self->priv->maxDelimCodePoint;
		if (((gint) _tmp7_) <= _tmp8_) {
			gchar _tmp9_;
			gboolean _tmp10_;
			_tmp9_ = c;
			_tmp10_ = sdx_utils_string_tokenizer_isDelimiter (self, _tmp9_);
			_tmp6_ = _tmp10_;
		} else {
			_tmp6_ = FALSE;
		}
		if (_tmp6_) {
			break;
		}
		_tmp11_ = position;
		position = _tmp11_ + 1;
	}
	_tmp13_ = self->priv->retDelims;
	if (_tmp13_) {
		gint _tmp14_;
		gint _tmp15_;
		_tmp14_ = startPos;
		_tmp15_ = position;
		_tmp12_ = _tmp14_ == _tmp15_;
	} else {
		_tmp12_ = FALSE;
	}
	if (_tmp12_) {
		gchar c = '\0';
		const gchar* _tmp16_;
		gint _tmp17_;
		gchar _tmp18_;
		gboolean _tmp19_ = FALSE;
		gchar _tmp20_;
		gint _tmp21_;
		_tmp16_ = self->priv->str;
		_tmp17_ = position;
		_tmp18_ = string_get (_tmp16_, (glong) _tmp17_);
		c = _tmp18_;
		_tmp20_ = c;
		_tmp21_ = self->priv->maxDelimCodePoint;
		if (((gint) _tmp20_) <= _tmp21_) {
			gchar _tmp22_;
			gboolean _tmp23_;
			_tmp22_ = c;
			_tmp23_ = sdx_utils_string_tokenizer_isDelimiter (self, _tmp22_);
			_tmp19_ = _tmp23_;
		} else {
			_tmp19_ = FALSE;
		}
		if (_tmp19_) {
			gint _tmp24_;
			_tmp24_ = position;
			position = _tmp24_ + 1;
		}
	}
	result = position;
	return result;
}


gboolean sdx_utils_string_tokenizer_isDelimiter (sdxutilsStringTokenizer* self, gchar c) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				const gchar* _tmp2_;
				gint _tmp3_;
				gint _tmp4_;
				const gchar* _tmp5_;
				gint _tmp6_;
				gchar _tmp7_;
				gchar _tmp8_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = self->priv->delimiters;
				_tmp3_ = strlen (_tmp2_);
				_tmp4_ = _tmp3_;
				if (!(i <= (_tmp4_ - 1))) {
					break;
				}
				_tmp5_ = self->priv->delimiters;
				_tmp6_ = i;
				_tmp7_ = string_get (_tmp5_, (glong) _tmp6_);
				_tmp8_ = c;
				if (_tmp7_ == _tmp8_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_utils_string_tokenizer_hasMoreTokens (sdxutilsStringTokenizer* self) {
	gboolean result = FALSE;
	gint _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->currentPosition;
	_tmp1_ = sdx_utils_string_tokenizer_skipDelimiters (self, _tmp0_);
	self->priv->newPosition = _tmp1_;
	_tmp2_ = self->priv->newPosition;
	_tmp3_ = self->priv->maxPosition;
	result = _tmp2_ < _tmp3_;
	return result;
}


static glong string_strnlen (gchar* str, glong maxlen) {
	glong result = 0L;
	gchar* end = NULL;
	gchar* _tmp0_;
	glong _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	_tmp0_ = str;
	_tmp1_ = maxlen;
	_tmp2_ = memchr (_tmp0_, 0, (gsize) _tmp1_);
	end = _tmp2_;
	_tmp3_ = end;
	if (_tmp3_ == NULL) {
		glong _tmp4_;
		_tmp4_ = maxlen;
		result = _tmp4_;
		return result;
	} else {
		gchar* _tmp5_;
		gchar* _tmp6_;
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
	glong _tmp1_;
	glong _tmp8_;
	glong _tmp14_;
	glong _tmp17_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	gchar* _tmp22_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = offset;
	if (_tmp1_ >= ((glong) 0)) {
		glong _tmp2_;
		_tmp2_ = len;
		_tmp0_ = _tmp2_ >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		glong _tmp3_;
		glong _tmp4_;
		glong _tmp5_;
		_tmp3_ = offset;
		_tmp4_ = len;
		_tmp5_ = string_strnlen ((gchar*) self, _tmp3_ + _tmp4_);
		string_length = _tmp5_;
	} else {
		gint _tmp6_;
		gint _tmp7_;
		_tmp6_ = strlen (self);
		_tmp7_ = _tmp6_;
		string_length = (glong) _tmp7_;
	}
	_tmp8_ = offset;
	if (_tmp8_ < ((glong) 0)) {
		glong _tmp9_;
		glong _tmp10_;
		glong _tmp11_;
		_tmp9_ = string_length;
		_tmp10_ = offset;
		offset = _tmp9_ + _tmp10_;
		_tmp11_ = offset;
		g_return_val_if_fail (_tmp11_ >= ((glong) 0), NULL);
	} else {
		glong _tmp12_;
		glong _tmp13_;
		_tmp12_ = offset;
		_tmp13_ = string_length;
		g_return_val_if_fail (_tmp12_ <= _tmp13_, NULL);
	}
	_tmp14_ = len;
	if (_tmp14_ < ((glong) 0)) {
		glong _tmp15_;
		glong _tmp16_;
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


gchar* sdx_utils_string_tokenizer_nextToken (sdxutilsStringTokenizer* self, const gchar* delim) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gint _tmp3_ = 0;
	gboolean _tmp4_ = FALSE;
	gint _tmp5_;
	gint _tmp10_;
	gint _tmp11_;
	gint start = 0;
	gint _tmp13_;
	gint _tmp14_;
	gint _tmp15_;
	const gchar* _tmp16_;
	gint _tmp17_;
	gchar* _tmp18_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (delim != NULL, NULL);
	_tmp0_ = delim;
	if (g_strcmp0 (_tmp0_, "") > 0) {
		const gchar* _tmp1_;
		gchar* _tmp2_;
		_tmp1_ = delim;
		_tmp2_ = g_strdup (_tmp1_);
		_g_free0 (self->priv->delimiters);
		self->priv->delimiters = _tmp2_;
		self->priv->delimsChanged = TRUE;
	}
	_tmp5_ = self->priv->newPosition;
	if (_tmp5_ >= 0) {
		gboolean _tmp6_;
		_tmp6_ = self->priv->delimsChanged;
		_tmp4_ = !_tmp6_;
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		gint _tmp7_;
		_tmp7_ = self->priv->newPosition;
		_tmp3_ = _tmp7_;
	} else {
		gint _tmp8_;
		gint _tmp9_;
		_tmp8_ = self->priv->currentPosition;
		_tmp9_ = sdx_utils_string_tokenizer_skipDelimiters (self, _tmp8_);
		_tmp3_ = _tmp9_;
	}
	self->priv->currentPosition = _tmp3_;
	self->priv->delimsChanged = FALSE;
	self->priv->newPosition = -1;
	_tmp10_ = self->priv->currentPosition;
	_tmp11_ = self->priv->maxPosition;
	if (_tmp10_ >= _tmp11_) {
		GError* _tmp12_;
		_tmp12_ = g_error_new_literal (SDX_EXCEPTION, SDX_EXCEPTION_NoSuchElementException, "");
		_inner_error_ = _tmp12_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp13_ = self->priv->currentPosition;
	start = _tmp13_;
	_tmp14_ = self->priv->currentPosition;
	_tmp15_ = sdx_utils_string_tokenizer_scanToken (self, _tmp14_);
	self->priv->currentPosition = _tmp15_;
	_tmp16_ = self->priv->str;
	_tmp17_ = self->priv->currentPosition;
	_tmp18_ = string_substring (_tmp16_, (glong) start, (glong) _tmp17_);
	result = _tmp18_;
	return result;
}


gboolean sdx_utils_string_tokenizer_hasMoreElements (sdxutilsStringTokenizer* self) {
	gboolean result = FALSE;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = sdx_utils_string_tokenizer_hasMoreTokens (self);
	result = _tmp0_;
	return result;
}


GObject* sdx_utils_string_tokenizer_nextElement (sdxutilsStringTokenizer* self) {
	GObject* result = NULL;
	gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = sdx_utils_string_tokenizer_nextToken (self, "");
	result = G_TYPE_CHECK_INSTANCE_CAST (_tmp0_, G_TYPE_OBJECT, GObject);
	return result;
}


gint sdx_utils_string_tokenizer_countTokens (sdxutilsStringTokenizer* self) {
	gint result = 0;
	gint count = 0;
	gint currpos = 0;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	count = 0;
	_tmp0_ = self->priv->currentPosition;
	currpos = _tmp0_;
	while (TRUE) {
		gint _tmp1_;
		gint _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _tmp6_;
		gint _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		_tmp1_ = currpos;
		_tmp2_ = self->priv->maxPosition;
		if (!(_tmp1_ < _tmp2_)) {
			break;
		}
		_tmp3_ = currpos;
		_tmp4_ = sdx_utils_string_tokenizer_skipDelimiters (self, _tmp3_);
		currpos = _tmp4_;
		_tmp5_ = currpos;
		_tmp6_ = self->priv->maxPosition;
		if (_tmp5_ >= _tmp6_) {
			break;
		}
		_tmp7_ = currpos;
		_tmp8_ = sdx_utils_string_tokenizer_scanToken (self, _tmp7_);
		currpos = _tmp8_;
		_tmp9_ = count;
		count = _tmp9_ + 1;
	}
	result = count;
	return result;
}


static void sdx_utils_value_string_tokenizer_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void sdx_utils_value_string_tokenizer_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		sdx_utils_string_tokenizer_unref (value->data[0].v_pointer);
	}
}


static void sdx_utils_value_string_tokenizer_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = sdx_utils_string_tokenizer_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer sdx_utils_value_string_tokenizer_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* sdx_utils_value_string_tokenizer_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		sdxutilsStringTokenizer * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = sdx_utils_string_tokenizer_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* sdx_utils_value_string_tokenizer_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	sdxutilsStringTokenizer ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = sdx_utils_string_tokenizer_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* sdx_utils_param_spec_string_tokenizer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	sdxutilsParamSpecStringTokenizer* spec;
	g_return_val_if_fail (g_type_is_a (object_type, SDX_UTILS_TYPE_STRING_TOKENIZER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer sdx_utils_value_get_string_tokenizer (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SDX_UTILS_TYPE_STRING_TOKENIZER), NULL);
	return value->data[0].v_pointer;
}


void sdx_utils_value_set_string_tokenizer (GValue* value, gpointer v_object) {
	sdxutilsStringTokenizer * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SDX_UTILS_TYPE_STRING_TOKENIZER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SDX_UTILS_TYPE_STRING_TOKENIZER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		sdx_utils_string_tokenizer_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		sdx_utils_string_tokenizer_unref (old);
	}
}


void sdx_utils_value_take_string_tokenizer (GValue* value, gpointer v_object) {
	sdxutilsStringTokenizer * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SDX_UTILS_TYPE_STRING_TOKENIZER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SDX_UTILS_TYPE_STRING_TOKENIZER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		sdx_utils_string_tokenizer_unref (old);
	}
}


static void sdx_utils_string_tokenizer_class_init (sdxutilsStringTokenizerClass * klass) {
	sdx_utils_string_tokenizer_parent_class = g_type_class_peek_parent (klass);
	((sdxutilsStringTokenizerClass *) klass)->finalize = sdx_utils_string_tokenizer_finalize;
	g_type_class_add_private (klass, sizeof (sdxutilsStringTokenizerPrivate));
}


static void sdx_utils_string_tokenizer_instance_init (sdxutilsStringTokenizer * self) {
	self->priv = SDX_UTILS_STRING_TOKENIZER_GET_PRIVATE (self);
	self->hasSurrogates = FALSE;
	self->ref_count = 1;
}


static void sdx_utils_string_tokenizer_finalize (sdxutilsStringTokenizer * obj) {
	sdxutilsStringTokenizer * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_UTILS_TYPE_STRING_TOKENIZER, sdxutilsStringTokenizer);
	g_signal_handlers_destroy (self);
	_g_free0 (self->priv->str);
	_g_free0 (self->priv->delimiters);
	self->delimiterCodePoints = (g_free (self->delimiterCodePoints), NULL);
}


GType sdx_utils_string_tokenizer_get_type (void) {
	static volatile gsize sdx_utils_string_tokenizer_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_utils_string_tokenizer_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { sdx_utils_value_string_tokenizer_init, sdx_utils_value_string_tokenizer_free_value, sdx_utils_value_string_tokenizer_copy_value, sdx_utils_value_string_tokenizer_peek_pointer, "p", sdx_utils_value_string_tokenizer_collect_value, "p", sdx_utils_value_string_tokenizer_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (sdxutilsStringTokenizerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_utils_string_tokenizer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxutilsStringTokenizer), 0, (GInstanceInitFunc) sdx_utils_string_tokenizer_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType sdx_utils_string_tokenizer_type_id;
		sdx_utils_string_tokenizer_type_id = g_type_register_fundamental (g_type_fundamental_next (), "sdxutilsStringTokenizer", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&sdx_utils_string_tokenizer_type_id__volatile, sdx_utils_string_tokenizer_type_id);
	}
	return sdx_utils_string_tokenizer_type_id__volatile;
}


gpointer sdx_utils_string_tokenizer_ref (gpointer instance) {
	sdxutilsStringTokenizer * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void sdx_utils_string_tokenizer_unref (gpointer instance) {
	sdxutilsStringTokenizer * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SDX_UTILS_STRING_TOKENIZER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



