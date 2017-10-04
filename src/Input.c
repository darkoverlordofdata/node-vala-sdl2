/* Input.c generated by valac 0.34.9, the Vala compiler
 * generated from Input.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>


#define SDX_TYPE_INPUT (sdx_input_get_type ())
#define SDX_INPUT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_INPUT, sdxInput))
#define SDX_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_INPUT, sdxInputClass))
#define SDX_IS_INPUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_INPUT))
#define SDX_IS_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_INPUT))
#define SDX_INPUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_INPUT, sdxInputClass))

typedef struct _sdxInput sdxInput;
typedef struct _sdxInputClass sdxInputClass;
typedef struct _sdxInputPrivate sdxInputPrivate;

#define SDX_TYPE_INPUT_PROCESSOR (sdx_input_processor_get_type ())
#define SDX_INPUT_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_INPUT_PROCESSOR, sdxInputProcessor))
#define SDX_IS_INPUT_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_INPUT_PROCESSOR))
#define SDX_INPUT_PROCESSOR_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SDX_TYPE_INPUT_PROCESSOR, sdxInputProcessorIface))

typedef struct _sdxInputProcessor sdxInputProcessor;
typedef struct _sdxInputProcessorIface sdxInputProcessorIface;

#define SDX_INPUT_TYPE_BUTTONS (sdx_input_buttons_get_type ())

#define SDX_INPUT_TYPE_KEYS (sdx_input_keys_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _sdxInput {
	GObject parent_instance;
	sdxInputPrivate * priv;
};

struct _sdxInputClass {
	GObjectClass parent_class;
};

struct _sdxInputProcessorIface {
	GTypeInterface parent_iface;
	gboolean (*keyDown) (sdxInputProcessor* self, gint keycode);
	gboolean (*keyUp) (sdxInputProcessor* self, gint keycode);
	gboolean (*keyTyped) (sdxInputProcessor* self, gchar character);
	gboolean (*touchDown) (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
	gboolean (*touchUp) (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
	gboolean (*touchDragged) (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer);
	gboolean (*mouseMoved) (sdxInputProcessor* self, gint screenX, gint screenY);
	gboolean (*scrolled) (sdxInputProcessor* self, gint amount);
};

struct _sdxInputPrivate {
	guint8* _keys;
	gint _keys_length1;
	gint __keys_size_;
	sdxInputProcessor* processor;
	SDL_Event evt;
};

typedef enum  {
	SDX_INPUT_BUTTONS_LEFT,
	SDX_INPUT_BUTTONS_RIGHT,
	SDX_INPUT_BUTTONS_MIDDLE,
	SDX_INPUT_BUTTONS_BACK,
	SDX_INPUT_BUTTONS_FORWARD
} sdxInputButtons;

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


static gpointer sdx_input_parent_class = NULL;

GType sdx_input_get_type (void) G_GNUC_CONST;
GType sdx_input_processor_get_type (void) G_GNUC_CONST;
#define SDX_INPUT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SDX_TYPE_INPUT, sdxInputPrivate))
enum  {
	SDX_INPUT_DUMMY_PROPERTY
};
GType sdx_input_buttons_get_type (void) G_GNUC_CONST;
GType sdx_input_keys_get_type (void) G_GNUC_CONST;
void sdx_input_setInputProcessor (sdxInput* self, sdxInputProcessor* processor);
gboolean sdx_input_processEvents (sdxInput* self);
guint8* sdx_input_get_keys (sdxInput* self, int* result_length1);
gboolean sdx_input_processor_keyDown (sdxInputProcessor* self, gint keycode);
gboolean sdx_input_processor_keyUp (sdxInputProcessor* self, gint keycode);
gboolean sdx_input_processor_touchDragged (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer);
gboolean sdx_input_processor_mouseMoved (sdxInputProcessor* self, gint screenX, gint screenY);
gboolean sdx_input_processor_touchDown (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
gboolean sdx_input_processor_touchUp (sdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
sdxInput* sdx_input_new (void);
sdxInput* sdx_input_construct (GType object_type);
static void sdx_input_finalize (GObject* obj);
static void _vala_sdx_input_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);


GType sdx_input_buttons_get_type (void) {
	static volatile gsize sdx_input_buttons_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_input_buttons_type_id__volatile)) {
		static const GEnumValue values[] = {{SDX_INPUT_BUTTONS_LEFT, "SDX_INPUT_BUTTONS_LEFT", "left"}, {SDX_INPUT_BUTTONS_RIGHT, "SDX_INPUT_BUTTONS_RIGHT", "right"}, {SDX_INPUT_BUTTONS_MIDDLE, "SDX_INPUT_BUTTONS_MIDDLE", "middle"}, {SDX_INPUT_BUTTONS_BACK, "SDX_INPUT_BUTTONS_BACK", "back"}, {SDX_INPUT_BUTTONS_FORWARD, "SDX_INPUT_BUTTONS_FORWARD", "forward"}, {0, NULL, NULL}};
		GType sdx_input_buttons_type_id;
		sdx_input_buttons_type_id = g_enum_register_static ("sdxInputButtons", values);
		g_once_init_leave (&sdx_input_buttons_type_id__volatile, sdx_input_buttons_type_id);
	}
	return sdx_input_buttons_type_id__volatile;
}


GType sdx_input_keys_get_type (void) {
	static volatile gsize sdx_input_keys_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_input_keys_type_id__volatile)) {
		static const GEnumValue values[] = {{SDX_INPUT_KEYS_Esc, "SDX_INPUT_KEYS_Esc", "esc"}, {SDX_INPUT_KEYS_a, "SDX_INPUT_KEYS_a", "a"}, {SDX_INPUT_KEYS_b, "SDX_INPUT_KEYS_b", "b"}, {SDX_INPUT_KEYS_c, "SDX_INPUT_KEYS_c", "c"}, {SDX_INPUT_KEYS_d, "SDX_INPUT_KEYS_d", "d"}, {SDX_INPUT_KEYS_e, "SDX_INPUT_KEYS_e", "e"}, {SDX_INPUT_KEYS_f, "SDX_INPUT_KEYS_f", "f"}, {SDX_INPUT_KEYS_g, "SDX_INPUT_KEYS_g", "g"}, {SDX_INPUT_KEYS_h, "SDX_INPUT_KEYS_h", "h"}, {SDX_INPUT_KEYS_i, "SDX_INPUT_KEYS_i", "i"}, {SDX_INPUT_KEYS_j, "SDX_INPUT_KEYS_j", "j"}, {SDX_INPUT_KEYS_k, "SDX_INPUT_KEYS_k", "k"}, {SDX_INPUT_KEYS_l, "SDX_INPUT_KEYS_l", "l"}, {SDX_INPUT_KEYS_m, "SDX_INPUT_KEYS_m", "m"}, {SDX_INPUT_KEYS_n, "SDX_INPUT_KEYS_n", "n"}, {SDX_INPUT_KEYS_o, "SDX_INPUT_KEYS_o", "o"}, {SDX_INPUT_KEYS_p, "SDX_INPUT_KEYS_p", "p"}, {SDX_INPUT_KEYS_q, "SDX_INPUT_KEYS_q", "q"}, {SDX_INPUT_KEYS_r, "SDX_INPUT_KEYS_r", "r"}, {SDX_INPUT_KEYS_s, "SDX_INPUT_KEYS_s", "s"}, {SDX_INPUT_KEYS_t, "SDX_INPUT_KEYS_t", "t"}, {SDX_INPUT_KEYS_u, "SDX_INPUT_KEYS_u", "u"}, {SDX_INPUT_KEYS_v, "SDX_INPUT_KEYS_v", "v"}, {SDX_INPUT_KEYS_w, "SDX_INPUT_KEYS_w", "w"}, {SDX_INPUT_KEYS_x, "SDX_INPUT_KEYS_x", "x"}, {SDX_INPUT_KEYS_y, "SDX_INPUT_KEYS_y", "y"}, {SDX_INPUT_KEYS_z, "SDX_INPUT_KEYS_z", "z"}, {0, NULL, NULL}};
		GType sdx_input_keys_type_id;
		sdx_input_keys_type_id = g_enum_register_static ("sdxInputKeys", values);
		g_once_init_leave (&sdx_input_keys_type_id__volatile, sdx_input_keys_type_id);
	}
	return sdx_input_keys_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void sdx_input_setInputProcessor (sdxInput* self, sdxInputProcessor* processor) {
	sdxInputProcessor* _tmp0_ = NULL;
	sdxInputProcessor* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (processor != NULL);
	_tmp0_ = processor;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->processor);
	self->priv->processor = _tmp1_;
}


gboolean sdx_input_processEvents (sdxInput* self) {
	gboolean result = FALSE;
	sdxInputProcessor* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->processor;
	if (_tmp0_ != NULL) {
		while (TRUE) {
			SDL_Event _tmp1_ = {0};
			gint _tmp2_ = 0;
			SDL_Event _tmp3_ = {0};
			SDL_EventType _tmp4_ = 0;
			_tmp2_ = SDL_PollEvent (&_tmp1_);
			 (self->priv->evt);
			self->priv->evt = _tmp1_;
			if (!(_tmp2_ != 0)) {
				break;
			}
			_tmp3_ = self->priv->evt;
			_tmp4_ = _tmp3_.type;
			switch (_tmp4_) {
				case SDL_KEYDOWN:
				{
					{
						SDL_Event _tmp5_ = {0};
						SDL_KeyboardEvent _tmp6_ = {0};
						SDL_Keysym _tmp7_ = {0};
						SDL_Keycode _tmp8_ = 0;
						_tmp5_ = self->priv->evt;
						_tmp6_ = _tmp5_.key;
						_tmp7_ = _tmp6_.keysym;
						_tmp8_ = _tmp7_.sym;
						if (_tmp8_ <= 255) {
							guint8* _tmp9_ = NULL;
							gint _tmp9__length1 = 0;
							guint8* _tmp10_ = NULL;
							gint _tmp10__length1 = 0;
							SDL_Event _tmp11_ = {0};
							SDL_KeyboardEvent _tmp12_ = {0};
							SDL_Keysym _tmp13_ = {0};
							SDL_Keycode _tmp14_ = 0;
							guint8 _tmp15_ = 0U;
							sdxInputProcessor* _tmp16_ = NULL;
							SDL_Event _tmp17_ = {0};
							SDL_KeyboardEvent _tmp18_ = {0};
							SDL_Keysym _tmp19_ = {0};
							SDL_Keycode _tmp20_ = 0;
							_tmp9_ = sdx_input_get_keys (self, &_tmp9__length1);
							_tmp10_ = _tmp9_;
							_tmp10__length1 = _tmp9__length1;
							_tmp11_ = self->priv->evt;
							_tmp12_ = _tmp11_.key;
							_tmp13_ = _tmp12_.keysym;
							_tmp14_ = _tmp13_.sym;
							_tmp10_[_tmp14_] = (guint8) 1;
							_tmp15_ = _tmp10_[_tmp14_];
							_tmp16_ = self->priv->processor;
							_tmp17_ = self->priv->evt;
							_tmp18_ = _tmp17_.key;
							_tmp19_ = _tmp18_.keysym;
							_tmp20_ = _tmp19_.sym;
							sdx_input_processor_keyDown (_tmp16_, (gint) _tmp20_);
						}
					}
					break;
				}
				case SDL_KEYUP:
				{
					{
						SDL_Event _tmp21_ = {0};
						SDL_KeyboardEvent _tmp22_ = {0};
						SDL_Keysym _tmp23_ = {0};
						SDL_Keycode _tmp24_ = 0;
						_tmp21_ = self->priv->evt;
						_tmp22_ = _tmp21_.key;
						_tmp23_ = _tmp22_.keysym;
						_tmp24_ = _tmp23_.sym;
						if (_tmp24_ <= 255) {
							guint8* _tmp25_ = NULL;
							gint _tmp25__length1 = 0;
							guint8* _tmp26_ = NULL;
							gint _tmp26__length1 = 0;
							SDL_Event _tmp27_ = {0};
							SDL_KeyboardEvent _tmp28_ = {0};
							SDL_Keysym _tmp29_ = {0};
							SDL_Keycode _tmp30_ = 0;
							guint8 _tmp31_ = 0U;
							sdxInputProcessor* _tmp32_ = NULL;
							SDL_Event _tmp33_ = {0};
							SDL_KeyboardEvent _tmp34_ = {0};
							SDL_Keysym _tmp35_ = {0};
							SDL_Keycode _tmp36_ = 0;
							_tmp25_ = sdx_input_get_keys (self, &_tmp25__length1);
							_tmp26_ = _tmp25_;
							_tmp26__length1 = _tmp25__length1;
							_tmp27_ = self->priv->evt;
							_tmp28_ = _tmp27_.key;
							_tmp29_ = _tmp28_.keysym;
							_tmp30_ = _tmp29_.sym;
							_tmp26_[_tmp30_] = (guint8) 0;
							_tmp31_ = _tmp26_[_tmp30_];
							_tmp32_ = self->priv->processor;
							_tmp33_ = self->priv->evt;
							_tmp34_ = _tmp33_.key;
							_tmp35_ = _tmp34_.keysym;
							_tmp36_ = _tmp35_.sym;
							sdx_input_processor_keyUp (_tmp32_, (gint) _tmp36_);
						}
					}
					break;
				}
				case SDL_MOUSEMOTION:
				{
					{
						sdxInputProcessor* _tmp37_ = NULL;
						SDL_Event _tmp38_ = {0};
						SDL_MouseMotionEvent _tmp39_ = {0};
						gint32 _tmp40_ = 0;
						SDL_Event _tmp41_ = {0};
						SDL_MouseMotionEvent _tmp42_ = {0};
						gint32 _tmp43_ = 0;
						sdxInputProcessor* _tmp44_ = NULL;
						SDL_Event _tmp45_ = {0};
						SDL_MouseMotionEvent _tmp46_ = {0};
						gint32 _tmp47_ = 0;
						SDL_Event _tmp48_ = {0};
						SDL_MouseMotionEvent _tmp49_ = {0};
						gint32 _tmp50_ = 0;
						_tmp37_ = self->priv->processor;
						_tmp38_ = self->priv->evt;
						_tmp39_ = _tmp38_.motion;
						_tmp40_ = _tmp39_.x;
						_tmp41_ = self->priv->evt;
						_tmp42_ = _tmp41_.motion;
						_tmp43_ = _tmp42_.y;
						sdx_input_processor_touchDragged (_tmp37_, (gint) _tmp40_, (gint) _tmp43_, 0);
						_tmp44_ = self->priv->processor;
						_tmp45_ = self->priv->evt;
						_tmp46_ = _tmp45_.motion;
						_tmp47_ = _tmp46_.x;
						_tmp48_ = self->priv->evt;
						_tmp49_ = _tmp48_.motion;
						_tmp50_ = _tmp49_.y;
						sdx_input_processor_mouseMoved (_tmp44_, (gint) _tmp47_, (gint) _tmp50_);
					}
					break;
				}
				case SDL_MOUSEBUTTONDOWN:
				{
					{
						sdxInputProcessor* _tmp51_ = NULL;
						SDL_Event _tmp52_ = {0};
						SDL_MouseMotionEvent _tmp53_ = {0};
						gint32 _tmp54_ = 0;
						SDL_Event _tmp55_ = {0};
						SDL_MouseMotionEvent _tmp56_ = {0};
						gint32 _tmp57_ = 0;
						_tmp51_ = self->priv->processor;
						_tmp52_ = self->priv->evt;
						_tmp53_ = _tmp52_.motion;
						_tmp54_ = _tmp53_.x;
						_tmp55_ = self->priv->evt;
						_tmp56_ = _tmp55_.motion;
						_tmp57_ = _tmp56_.y;
						sdx_input_processor_touchDown (_tmp51_, (gint) _tmp54_, (gint) _tmp57_, 0, 0);
					}
					break;
				}
				case SDL_MOUSEBUTTONUP:
				{
					{
						sdxInputProcessor* _tmp58_ = NULL;
						SDL_Event _tmp59_ = {0};
						SDL_MouseMotionEvent _tmp60_ = {0};
						gint32 _tmp61_ = 0;
						SDL_Event _tmp62_ = {0};
						SDL_MouseMotionEvent _tmp63_ = {0};
						gint32 _tmp64_ = 0;
						_tmp58_ = self->priv->processor;
						_tmp59_ = self->priv->evt;
						_tmp60_ = _tmp59_.motion;
						_tmp61_ = _tmp60_.x;
						_tmp62_ = self->priv->evt;
						_tmp63_ = _tmp62_.motion;
						_tmp64_ = _tmp63_.y;
						sdx_input_processor_touchUp (_tmp58_, (gint) _tmp61_, (gint) _tmp64_, 0, 0);
					}
					break;
				}
				case SDL_QUIT:
				{
					{
						result = FALSE;
						return result;
					}
					break;
				}
				default:
				break;
			}
		}
	}
	result = TRUE;
	return result;
}


sdxInput* sdx_input_construct (GType object_type) {
	sdxInput * self = NULL;
	self = (sdxInput*) g_object_new (object_type, NULL);
	return self;
}


sdxInput* sdx_input_new (void) {
	return sdx_input_construct (SDX_TYPE_INPUT);
}


guint8* sdx_input_get_keys (sdxInput* self, int* result_length1) {
	guint8* result;
	guint8* _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	guint8* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_keys;
	_tmp0__length1 = self->priv->_keys_length1;
	_tmp1_ = _tmp0_;
	_tmp1__length1 = _tmp0__length1;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


static void sdx_input_class_init (sdxInputClass * klass) {
	sdx_input_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (sdxInputPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_sdx_input_get_property;
	G_OBJECT_CLASS (klass)->finalize = sdx_input_finalize;
}


static void sdx_input_instance_init (sdxInput * self) {
	guint8* _tmp0_ = NULL;
	self->priv = SDX_INPUT_GET_PRIVATE (self);
	_tmp0_ = g_new0 (guint8, 255);
	self->priv->_keys = _tmp0_;
	self->priv->_keys_length1 = 255;
	self->priv->__keys_size_ = self->priv->_keys_length1;
}


static void sdx_input_finalize (GObject* obj) {
	sdxInput * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_TYPE_INPUT, sdxInput);
	self->priv->_keys = (g_free (self->priv->_keys), NULL);
	_g_object_unref0 (self->priv->processor);
	 (self->priv->evt);
	G_OBJECT_CLASS (sdx_input_parent_class)->finalize (obj);
}


GType sdx_input_get_type (void) {
	static volatile gsize sdx_input_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_input_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxInputClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_input_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxInput), 0, (GInstanceInitFunc) sdx_input_instance_init, NULL };
		GType sdx_input_type_id;
		sdx_input_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxInput", &g_define_type_info, 0);
		g_once_init_leave (&sdx_input_type_id__volatile, sdx_input_type_id);
	}
	return sdx_input_type_id__volatile;
}


static void _vala_sdx_input_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	sdxInput * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SDX_TYPE_INPUT, sdxInput);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



