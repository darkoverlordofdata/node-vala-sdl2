### CMakeLists automatically created with AutoVala
### Do not edit

set (DATADIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}")
set (PKGDATADIR "${DATADIR}/libsdx")
set (GETTEXT_PACKAGE "libsdx")
set (RELEASE_NAME "libsdx")
set (CMAKE_C_FLAGS "")
set (PREFIX ${CMAKE_INSTALL_PREFIX})
set (VERSION "0.0.1")
set (TESTSRCDIR "${CMAKE_SOURCE_DIR}")
set (DOLLAR "$")

configure_file (${CMAKE_SOURCE_DIR}/src/Config.vala.cmake ${CMAKE_BINARY_DIR}/src/Config.vala)
add_definitions(-DGETTEXT_PACKAGE=\"${GETTEXT_PACKAGE}\")
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/sdx.pc ${CMAKE_CURRENT_BINARY_DIR}/sdx.pc)
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/sdx.deps ${CMAKE_CURRENT_BINARY_DIR}/sdx.deps)
set (VERSION "0.0.1")
add_definitions (${DEPS_CFLAGS})
link_libraries ( ${DEPS_LIBRARIES} )
link_directories ( ${DEPS_LIBRARY_DIRS} )
find_package (Vala REQUIRED)
include (ValaVersion)
ensure_vala_version ("0.30" MINIMUM)
include (ValaPrecompile)

set (VALA_PACKAGES ${VALA_PACKAGES} SDL2_image)
set (VALA_PACKAGES ${VALA_PACKAGES} SDL2_mixer)
set (VALA_PACKAGES ${VALA_PACKAGES} SDL2_ttf)
set (VALA_PACKAGES ${VALA_PACKAGES} gee-0.8)
set (VALA_PACKAGES ${VALA_PACKAGES} json-glib-1.0)
set (VALA_PACKAGES ${VALA_PACKAGES} sdl2)
set (VALA_PACKAGES ${VALA_PACKAGES} gio-2.0)
set (VALA_PACKAGES ${VALA_PACKAGES} glib-2.0)
set (VALA_PACKAGES ${VALA_PACKAGES} gobject-2.0)

set (APP_SOURCES ${APP_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/Config.vala)
set (APP_SOURCES ${APP_SOURCES} Application.gs)
set (APP_SOURCES ${APP_SOURCES} ApplicationListener.gs)
set (APP_SOURCES ${APP_SOURCES} Audio.gs)
set (APP_SOURCES ${APP_SOURCES} Exceptions.gs)
set (APP_SOURCES ${APP_SOURCES} Files.gs)
set (APP_SOURCES ${APP_SOURCES} Game.gs)
set (APP_SOURCES ${APP_SOURCES} Graphics.gs)
set (APP_SOURCES ${APP_SOURCES} Input.gs)
set (APP_SOURCES ${APP_SOURCES} InputAdapter.gs)
set (APP_SOURCES ${APP_SOURCES} InputProcessor.gs)
set (APP_SOURCES ${APP_SOURCES} Net.gs)
set (APP_SOURCES ${APP_SOURCES} Screen.gs)
set (APP_SOURCES ${APP_SOURCES} Sdx.gs)
set (APP_SOURCES ${APP_SOURCES} Version.gs)
set (APP_SOURCES ${APP_SOURCES} audio/Sound.gs)
set (APP_SOURCES ${APP_SOURCES} files/FileHandle.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/Color.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/Texture.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/Batch.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/BitmapFont.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/Font.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/GlyphLayout.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/NinePatch.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/Sprite.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/TextureAtlas.gs)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/TextureEnums.vala)
set (APP_SOURCES ${APP_SOURCES} graphics/s2d/TextureRegion.gs)
set (APP_SOURCES ${APP_SOURCES} libsdx.vala)
set (APP_SOURCES ${APP_SOURCES} math/Rectangle.gs)
set (APP_SOURCES ${APP_SOURCES} math/Vector2.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/Action.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/Actor.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/Event.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/Group.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/InputEvent.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/InputListener.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/Stage.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/ui/Image.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/ui/Label.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/ui/Scaling.vala)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/ui/Widget.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/BaseDrawable.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/ClickListener.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/Drawable.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/FocusEvent.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/FocusListener.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/Layout.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/NinePatchDrawable.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/TextureRegionDrawable.gs)
set (APP_SOURCES ${APP_SOURCES} scenes/scene2d/utils/TransformDrawable.gs)
set (APP_SOURCES ${APP_SOURCES} utils/Align.gs)
set (APP_SOURCES ${APP_SOURCES} utils/Json.gs)
set (APP_SOURCES ${APP_SOURCES} utils/Pool.gs)
set (APP_SOURCES ${APP_SOURCES} utils/Pools.gs)
set (APP_SOURCES ${APP_SOURCES} utils/StringTokenizer.gs)
set (APP_SOURCES ${APP_SOURCES} utils/viewport/Viewport.gs)

set (COMPILE_OPTIONS ${COMPILE_OPTIONS} --vapidir=${CMAKE_SOURCE_DIR}/src/vapis )

if ((${CMAKE_BUILD_TYPE} STREQUAL "Debug") OR (${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo"))
	set(COMPILE_OPTIONS ${COMPILE_OPTIONS} "-g")
endif()

set (COMPILE_OPTIONS ${COMPILE_OPTIONS} --library=sdx --gir sdx-0.0.gir )
set (COMPILE_OPTIONS ${COMPILE_OPTIONS} --disable-warnings --gir )

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3" )

vala_precompile(VALA_C sdx
	${APP_SOURCES}
PACKAGES
	${VALA_PACKAGES}
OPTIONS
	${COMPILE_OPTIONS}
GENERATE_VAPI
	sdx
GENERATE_HEADER
	sdx
)

add_library(sdx SHARED ${VALA_C})

target_link_libraries( sdx m )
set_target_properties( sdx PROPERTIES
VERSION
	0.0.1
SOVERSION
	0 )


install(TARGETS
	sdx
LIBRARY DESTINATION
	${CMAKE_INSTALL_LIBDIR}/
)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/sdx.h
DESTINATION
	${CMAKE_INSTALL_INCLUDEDIR}/
)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/sdx.vapi
DESTINATION
	${CMAKE_INSTALL_DATAROOTDIR}/vala/vapi/
)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/sdx.deps
DESTINATION
	${CMAKE_INSTALL_DATAROOTDIR}/vala/vapi/
)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/sdx-0.0.gir
DESTINATION
	${CMAKE_INSTALL_DATAROOTDIR}/gir-1.0/
)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/sdx.pc
DESTINATION
	${CMAKE_INSTALL_LIBDIR}/pkgconfig/
)
if(HAVE_VALADOC)
	valadoc(sdx
		${CMAKE_BINARY_DIR}/valadoc/sdx
		${APP_SOURCES}
	PACKAGES
		${VALA_PACKAGES}
	CUSTOM_VAPIS
		${CUSTOM_VAPIS_LIST}
	)
	install(DIRECTORY
		${CMAKE_BINARY_DIR}/valadoc
	DESTINATION
		${CMAKE_INSTALL_DATAROOTDIR}/doc/libsdx
	)
endif()

install(CODE "MESSAGE (\"
************************************************
* Run 'sudo ldconfig' to complete installation *
************************************************

\") " )