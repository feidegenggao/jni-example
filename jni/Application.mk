#APP_ABI := armeabi-v7a
APP_ABI:=armeabi
APP_STL := gnustl_shared
APP_CPPFLAGS += -frtti  
APP_CPPFLAGS += -fexceptions 
APP_GNUSTL_FORCE_CPP_FEATURES := exceptions rtti 
APP_PLATFORM := android-14 
#APP_CPPFLAGS += -fpermissive
#APP_MODULES := App