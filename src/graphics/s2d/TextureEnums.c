/* TextureEnums.c generated by valac 0.34.9, the Vala compiler
 * generated from TextureEnums.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define SDX_GRAPHICS_S2D_TYPE_TEXTURE_FILTER (sdx_graphics_s2d_texture_filter_get_type ())

#define SDX_GRAPHICS_S2D_TYPE_TEXTURE_WRAP (sdx_graphics_s2d_texture_wrap_get_type ())

#define SDX_GRAPHICS_S2D_TYPE_FORMAT (sdx_graphics_s2d_format_get_type ())

typedef enum  {
	SDX_GRAPHICS_S2D_TEXTURE_FILTER_Nearest,
	SDX_GRAPHICS_S2D_TEXTURE_FILTER_Linear,
	SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMap,
	SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestNearest,
	SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearNearest,
	SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestLinear,
	SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearLinear
} sdxgraphicss2dTextureFilter;

typedef enum  {
	SDX_GRAPHICS_S2D_TEXTURE_WRAP_ClampToEdge = 1,
	SDX_GRAPHICS_S2D_TEXTURE_WRAP_Repeat = 2
} sdxgraphicss2dTextureWrap;

typedef enum  {
	SDX_GRAPHICS_S2D_FORMAT_Alpha,
	SDX_GRAPHICS_S2D_FORMAT_Intensity,
	SDX_GRAPHICS_S2D_FORMAT_LuminanceAlpha,
	SDX_GRAPHICS_S2D_FORMAT_RGB565,
	SDX_GRAPHICS_S2D_FORMAT_RGBA4444,
	SDX_GRAPHICS_S2D_FORMAT_RGB888,
	SDX_GRAPHICS_S2D_FORMAT_RGBA8888
} sdxgraphicss2dFormat;



GType sdx_graphics_s2d_texture_filter_get_type (void) G_GNUC_CONST;
sdxgraphicss2dTextureFilter sdx_graphics_s2d_texture_filter_from (const gchar* value);
gboolean sdx_graphics_s2d_texture_filter_isMipMap (sdxgraphicss2dTextureFilter self);
gchar* sdx_graphics_s2d_texture_filter_to_string (sdxgraphicss2dTextureFilter self);
GType sdx_graphics_s2d_texture_wrap_get_type (void) G_GNUC_CONST;
sdxgraphicss2dTextureWrap sdx_graphics_s2d_texture_wrap_from (const gchar* value);
gchar* sdx_graphics_s2d_texture_wrap_to_string (sdxgraphicss2dTextureWrap self);
GType sdx_graphics_s2d_format_get_type (void) G_GNUC_CONST;
sdxgraphicss2dFormat sdx_graphics_s2d_format_from (const gchar* value);
gchar* sdx_graphics_s2d_format_to_string (sdxgraphicss2dFormat self);


sdxgraphicss2dTextureFilter sdx_graphics_s2d_texture_filter_from (const gchar* value) {
	sdxgraphicss2dTextureFilter result = 0;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GQuark _tmp3_ = 0U;
	static GQuark _tmp2_label0 = 0;
	static GQuark _tmp2_label1 = 0;
	static GQuark _tmp2_label2 = 0;
	static GQuark _tmp2_label3 = 0;
	static GQuark _tmp2_label4 = 0;
	static GQuark _tmp2_label5 = 0;
	static GQuark _tmp2_label6 = 0;
	g_return_val_if_fail (value != NULL, 0);
	_tmp0_ = value;
	_tmp1_ = _tmp0_;
	_tmp3_ = (NULL == _tmp1_) ? 0 : g_quark_from_string (_tmp1_);
	if (_tmp3_ == ((0 != _tmp2_label0) ? _tmp2_label0 : (_tmp2_label0 = g_quark_from_static_string ("Nearest")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_FILTER_Nearest;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label1) ? _tmp2_label1 : (_tmp2_label1 = g_quark_from_static_string ("Linear")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_FILTER_Linear;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label2) ? _tmp2_label2 : (_tmp2_label2 = g_quark_from_static_string ("MipMap")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMap;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label3) ? _tmp2_label3 : (_tmp2_label3 = g_quark_from_static_string ("MipMapNearestNearest")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestNearest;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label4) ? _tmp2_label4 : (_tmp2_label4 = g_quark_from_static_string ("MipMapLinearNearest")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearNearest;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label5) ? _tmp2_label5 : (_tmp2_label5 = g_quark_from_static_string ("MipMapNearestLinear")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestLinear;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label6) ? _tmp2_label6 : (_tmp2_label6 = g_quark_from_static_string ("MipMapLinearLinear")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearLinear;
				return result;
			}
		}
	} else {
		switch (0) {
			default:
			{
				g_assert_not_reached ();
			}
		}
	}
}


gboolean sdx_graphics_s2d_texture_filter_isMipMap (sdxgraphicss2dTextureFilter self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	if (self != SDX_GRAPHICS_S2D_TEXTURE_FILTER_Nearest) {
		_tmp0_ = self != SDX_GRAPHICS_S2D_TEXTURE_FILTER_Linear;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}


gchar* sdx_graphics_s2d_texture_filter_to_string (sdxgraphicss2dTextureFilter self) {
	gchar* result = NULL;
	switch (self) {
		case SDX_GRAPHICS_S2D_TEXTURE_FILTER_Nearest:
		{
			gchar* _tmp0_ = NULL;
			_tmp0_ = g_strdup ("Nearest");
			result = _tmp0_;
			return result;
		}
		case SDX_GRAPHICS_S2D_TEXTURE_FILTER_Linear:
		{
			gchar* _tmp1_ = NULL;
			_tmp1_ = g_strdup ("Linear");
			result = _tmp1_;
			return result;
		}
		case SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMap:
		{
			gchar* _tmp2_ = NULL;
			_tmp2_ = g_strdup ("MipMap");
			result = _tmp2_;
			return result;
		}
		case SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestNearest:
		{
			gchar* _tmp3_ = NULL;
			_tmp3_ = g_strdup ("MipMapNearestNearest");
			result = _tmp3_;
			return result;
		}
		case SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearNearest:
		{
			gchar* _tmp4_ = NULL;
			_tmp4_ = g_strdup ("MipMapLinearNearest");
			result = _tmp4_;
			return result;
		}
		case SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestLinear:
		{
			gchar* _tmp5_ = NULL;
			_tmp5_ = g_strdup ("MipMapNearestLinear");
			result = _tmp5_;
			return result;
		}
		case SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearLinear:
		{
			gchar* _tmp6_ = NULL;
			_tmp6_ = g_strdup ("MipMapLinearLinear");
			result = _tmp6_;
			return result;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
}


GType sdx_graphics_s2d_texture_filter_get_type (void) {
	static volatile gsize sdx_graphics_s2d_texture_filter_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_graphics_s2d_texture_filter_type_id__volatile)) {
		static const GEnumValue values[] = {{SDX_GRAPHICS_S2D_TEXTURE_FILTER_Nearest, "SDX_GRAPHICS_S2D_TEXTURE_FILTER_Nearest", "nearest"}, {SDX_GRAPHICS_S2D_TEXTURE_FILTER_Linear, "SDX_GRAPHICS_S2D_TEXTURE_FILTER_Linear", "linear"}, {SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMap, "SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMap", "mipmap"}, {SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestNearest, "SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestNearest", "mipmapnearestnearest"}, {SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearNearest, "SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearNearest", "mipmaplinearnearest"}, {SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestLinear, "SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapNearestLinear", "mipmapnearestlinear"}, {SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearLinear, "SDX_GRAPHICS_S2D_TEXTURE_FILTER_MipMapLinearLinear", "mipmaplinearlinear"}, {0, NULL, NULL}};
		GType sdx_graphics_s2d_texture_filter_type_id;
		sdx_graphics_s2d_texture_filter_type_id = g_enum_register_static ("sdxgraphicss2dTextureFilter", values);
		g_once_init_leave (&sdx_graphics_s2d_texture_filter_type_id__volatile, sdx_graphics_s2d_texture_filter_type_id);
	}
	return sdx_graphics_s2d_texture_filter_type_id__volatile;
}


sdxgraphicss2dTextureWrap sdx_graphics_s2d_texture_wrap_from (const gchar* value) {
	sdxgraphicss2dTextureWrap result = 0;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GQuark _tmp3_ = 0U;
	static GQuark _tmp2_label0 = 0;
	static GQuark _tmp2_label1 = 0;
	g_return_val_if_fail (value != NULL, 0);
	_tmp0_ = value;
	_tmp1_ = _tmp0_;
	_tmp3_ = (NULL == _tmp1_) ? 0 : g_quark_from_string (_tmp1_);
	if (_tmp3_ == ((0 != _tmp2_label0) ? _tmp2_label0 : (_tmp2_label0 = g_quark_from_static_string ("ClampToEdge")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_WRAP_ClampToEdge;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label1) ? _tmp2_label1 : (_tmp2_label1 = g_quark_from_static_string ("Repeat")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_TEXTURE_WRAP_Repeat;
				return result;
			}
		}
	} else {
		switch (0) {
			default:
			{
				g_assert_not_reached ();
			}
		}
	}
}


gchar* sdx_graphics_s2d_texture_wrap_to_string (sdxgraphicss2dTextureWrap self) {
	gchar* result = NULL;
	switch (self) {
		case SDX_GRAPHICS_S2D_TEXTURE_WRAP_ClampToEdge:
		{
			gchar* _tmp0_ = NULL;
			_tmp0_ = g_strdup ("ClampToEdge");
			result = _tmp0_;
			return result;
		}
		case SDX_GRAPHICS_S2D_TEXTURE_WRAP_Repeat:
		{
			gchar* _tmp1_ = NULL;
			_tmp1_ = g_strdup ("Repeat");
			result = _tmp1_;
			return result;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
}


GType sdx_graphics_s2d_texture_wrap_get_type (void) {
	static volatile gsize sdx_graphics_s2d_texture_wrap_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_graphics_s2d_texture_wrap_type_id__volatile)) {
		static const GEnumValue values[] = {{SDX_GRAPHICS_S2D_TEXTURE_WRAP_ClampToEdge, "SDX_GRAPHICS_S2D_TEXTURE_WRAP_ClampToEdge", "clamptoedge"}, {SDX_GRAPHICS_S2D_TEXTURE_WRAP_Repeat, "SDX_GRAPHICS_S2D_TEXTURE_WRAP_Repeat", "repeat"}, {0, NULL, NULL}};
		GType sdx_graphics_s2d_texture_wrap_type_id;
		sdx_graphics_s2d_texture_wrap_type_id = g_enum_register_static ("sdxgraphicss2dTextureWrap", values);
		g_once_init_leave (&sdx_graphics_s2d_texture_wrap_type_id__volatile, sdx_graphics_s2d_texture_wrap_type_id);
	}
	return sdx_graphics_s2d_texture_wrap_type_id__volatile;
}


sdxgraphicss2dFormat sdx_graphics_s2d_format_from (const gchar* value) {
	sdxgraphicss2dFormat result = 0;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GQuark _tmp3_ = 0U;
	static GQuark _tmp2_label0 = 0;
	static GQuark _tmp2_label1 = 0;
	static GQuark _tmp2_label2 = 0;
	static GQuark _tmp2_label3 = 0;
	static GQuark _tmp2_label4 = 0;
	static GQuark _tmp2_label5 = 0;
	static GQuark _tmp2_label6 = 0;
	g_return_val_if_fail (value != NULL, 0);
	_tmp0_ = value;
	_tmp1_ = _tmp0_;
	_tmp3_ = (NULL == _tmp1_) ? 0 : g_quark_from_string (_tmp1_);
	if (_tmp3_ == ((0 != _tmp2_label0) ? _tmp2_label0 : (_tmp2_label0 = g_quark_from_static_string ("Alpha")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_FORMAT_Alpha;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label1) ? _tmp2_label1 : (_tmp2_label1 = g_quark_from_static_string ("Intensity")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_FORMAT_Intensity;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label2) ? _tmp2_label2 : (_tmp2_label2 = g_quark_from_static_string ("LuminanceAlpha")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_FORMAT_LuminanceAlpha;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label3) ? _tmp2_label3 : (_tmp2_label3 = g_quark_from_static_string ("RGB565")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_FORMAT_RGB565;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label4) ? _tmp2_label4 : (_tmp2_label4 = g_quark_from_static_string ("RGBA4444")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_FORMAT_RGBA4444;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label5) ? _tmp2_label5 : (_tmp2_label5 = g_quark_from_static_string ("RGB888")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_FORMAT_RGB888;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label6) ? _tmp2_label6 : (_tmp2_label6 = g_quark_from_static_string ("RGBA8888")))) {
		switch (0) {
			default:
			{
				result = SDX_GRAPHICS_S2D_FORMAT_RGBA8888;
				return result;
			}
		}
	} else {
		switch (0) {
			default:
			{
				g_assert_not_reached ();
			}
		}
	}
}


gchar* sdx_graphics_s2d_format_to_string (sdxgraphicss2dFormat self) {
	gchar* result = NULL;
	switch (self) {
		case SDX_GRAPHICS_S2D_FORMAT_Alpha:
		{
			gchar* _tmp0_ = NULL;
			_tmp0_ = g_strdup ("Alpha");
			result = _tmp0_;
			return result;
		}
		case SDX_GRAPHICS_S2D_FORMAT_Intensity:
		{
			gchar* _tmp1_ = NULL;
			_tmp1_ = g_strdup ("Intensity");
			result = _tmp1_;
			return result;
		}
		case SDX_GRAPHICS_S2D_FORMAT_LuminanceAlpha:
		{
			gchar* _tmp2_ = NULL;
			_tmp2_ = g_strdup ("LuminanceAlpha");
			result = _tmp2_;
			return result;
		}
		case SDX_GRAPHICS_S2D_FORMAT_RGB565:
		{
			gchar* _tmp3_ = NULL;
			_tmp3_ = g_strdup ("RGB565");
			result = _tmp3_;
			return result;
		}
		case SDX_GRAPHICS_S2D_FORMAT_RGBA4444:
		{
			gchar* _tmp4_ = NULL;
			_tmp4_ = g_strdup ("RGBA4444");
			result = _tmp4_;
			return result;
		}
		case SDX_GRAPHICS_S2D_FORMAT_RGB888:
		{
			gchar* _tmp5_ = NULL;
			_tmp5_ = g_strdup ("RGB888");
			result = _tmp5_;
			return result;
		}
		case SDX_GRAPHICS_S2D_FORMAT_RGBA8888:
		{
			gchar* _tmp6_ = NULL;
			_tmp6_ = g_strdup ("RGBA8888");
			result = _tmp6_;
			return result;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
}


GType sdx_graphics_s2d_format_get_type (void) {
	static volatile gsize sdx_graphics_s2d_format_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_graphics_s2d_format_type_id__volatile)) {
		static const GEnumValue values[] = {{SDX_GRAPHICS_S2D_FORMAT_Alpha, "SDX_GRAPHICS_S2D_FORMAT_Alpha", "alpha"}, {SDX_GRAPHICS_S2D_FORMAT_Intensity, "SDX_GRAPHICS_S2D_FORMAT_Intensity", "intensity"}, {SDX_GRAPHICS_S2D_FORMAT_LuminanceAlpha, "SDX_GRAPHICS_S2D_FORMAT_LuminanceAlpha", "luminancealpha"}, {SDX_GRAPHICS_S2D_FORMAT_RGB565, "SDX_GRAPHICS_S2D_FORMAT_RGB565", "rgb565"}, {SDX_GRAPHICS_S2D_FORMAT_RGBA4444, "SDX_GRAPHICS_S2D_FORMAT_RGBA4444", "rgba4444"}, {SDX_GRAPHICS_S2D_FORMAT_RGB888, "SDX_GRAPHICS_S2D_FORMAT_RGB888", "rgb888"}, {SDX_GRAPHICS_S2D_FORMAT_RGBA8888, "SDX_GRAPHICS_S2D_FORMAT_RGBA8888", "rgba8888"}, {0, NULL, NULL}};
		GType sdx_graphics_s2d_format_type_id;
		sdx_graphics_s2d_format_type_id = g_enum_register_static ("sdxgraphicss2dFormat", values);
		g_once_init_leave (&sdx_graphics_s2d_format_type_id__volatile, sdx_graphics_s2d_format_type_id);
	}
	return sdx_graphics_s2d_format_type_id__volatile;
}



