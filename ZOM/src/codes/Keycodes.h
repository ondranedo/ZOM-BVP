#pragma once


#define ZOM_KEY_SPACE              32
#define ZOM_KEY_APOSTROPHE         39  /* ' */
#define ZOM_KEY_COMMA              44  /* , */
#define ZOM_KEY_MINUS              45  /* - */
#define ZOM_KEY_PERIOD             46  /* . */
#define ZOM_KEY_SLASH              47  /* / */
#define ZOM_KEY_0                  48 
#define ZOM_KEY_1                  49
#define ZOM_KEY_2                  50
#define ZOM_KEY_3                  51
#define ZOM_KEY_4                  52
#define ZOM_KEY_5                  53
#define ZOM_KEY_6                  54
#define ZOM_KEY_7                  55
#define ZOM_KEY_8                  56
#define ZOM_KEY_9                  57
#define ZOM_KEY_SEMICOLON          59  /* ; */
#define ZOM_KEY_EQUAL              61  /* = */
#define ZOM_KEY_A                  65
#define ZOM_KEY_B                  66
#define ZOM_KEY_C                  67
#define ZOM_KEY_D                  68
#define ZOM_KEY_E                  69
#define ZOM_KEY_F                  70
#define ZOM_KEY_G                  71
#define ZOM_KEY_H                  72
#define ZOM_KEY_I                  73
#define ZOM_KEY_J                  74
#define ZOM_KEY_K                  75
#define ZOM_KEY_L                  76
#define ZOM_KEY_M                  77
#define ZOM_KEY_N                  78
#define ZOM_KEY_O                  79
#define ZOM_KEY_P                  80
#define ZOM_KEY_Q                  81
#define ZOM_KEY_R                  82
#define ZOM_KEY_S                  83
#define ZOM_KEY_T                  84
#define ZOM_KEY_U                  85
#define ZOM_KEY_V                  86
#define ZOM_KEY_W                  87
#define ZOM_KEY_X                  88
#define ZOM_KEY_Y                  89
#define ZOM_KEY_Z                  90
#define ZOM_KEY_LEFT_BRACKET       91  /* [ */
#define ZOM_KEY_BACKSLASH          92  /* \ */
#define ZOM_KEY_RIGHT_BRACKET      93  /* ] */
#define ZOM_KEY_GRAVE_ACCENT       96  /* ` */
#define ZOM_KEY_ESCAPE             256
#define ZOM_KEY_ENTER              257
#define ZOM_KEY_TAB                258
#define ZOM_KEY_BACKSPACE          259
#define ZOM_KEY_INSERT             260
#define ZOM_KEY_DELETE             261
#define ZOM_KEY_RIGHT              262
#define ZOM_KEY_LEFT               263
#define ZOM_KEY_DOWN               264
#define ZOM_KEY_UP                 265
#define ZOM_KEY_PAGE_UP            266
#define ZOM_KEY_PAGE_DOWN          267
#define ZOM_KEY_HOME               268
#define ZOM_KEY_END                269
#define ZOM_KEY_CAPS_LOCK          280
#define ZOM_KEY_SCROLL_LOCK        281
#define ZOM_KEY_NUM_LOCK           282
#define ZOM_KEY_PRINT_SCREEN       283
#define ZOM_KEY_PAUSE              284
#define ZOM_KEY_F1                 290
#define ZOM_KEY_F2                 291
#define ZOM_KEY_F3                 292
#define ZOM_KEY_F4                 293
#define ZOM_KEY_F5                 294
#define ZOM_KEY_F6                 295
#define ZOM_KEY_F7                 296
#define ZOM_KEY_F8                 297
#define ZOM_KEY_F9                 298
#define ZOM_KEY_F10                299
#define ZOM_KEY_F11                300
#define ZOM_KEY_F12                301
#define ZOM_KEY_F13                302
#define ZOM_KEY_F14                303
#define ZOM_KEY_F15                304
#define ZOM_KEY_F16                305
#define ZOM_KEY_F17                306
#define ZOM_KEY_F18                307
#define ZOM_KEY_F19                308
#define ZOM_KEY_F20                309
#define ZOM_KEY_F21                310
#define ZOM_KEY_F22                311
#define ZOM_KEY_F23                312
#define ZOM_KEY_F24                313
#define ZOM_KEY_F25                314
#define ZOM_KEY_KP_0               320
#define ZOM_KEY_KP_1               321
#define ZOM_KEY_KP_2               322
#define ZOM_KEY_KP_3               323
#define ZOM_KEY_KP_4               324
#define ZOM_KEY_KP_5               325
#define ZOM_KEY_KP_6               326
#define ZOM_KEY_KP_7               327
#define ZOM_KEY_KP_8               328
#define ZOM_KEY_KP_9               329
#define ZOM_KEY_KP_DECIMAL         330
#define ZOM_KEY_KP_DIVIDE          331
#define ZOM_KEY_KP_MULTIPLY        332
#define ZOM_KEY_KP_SUBTRACT        333
#define ZOM_KEY_KP_ADD             334
#define ZOM_KEY_KP_ENTER           335
#define ZOM_KEY_KP_EQUAL           336
#define ZOM_KEY_LEFT_SHIFT         340
#define ZOM_KEY_LEFT_CONTROL       341
#define ZOM_KEY_LEFT_ALT           342
#define ZOM_KEY_LEFT_SUPER         343
#define ZOM_KEY_RIGHT_SHIFT        344
#define ZOM_KEY_RIGHT_CONTROL      345
#define ZOM_KEY_RIGHT_ALT          346
#define ZOM_KEY_RIGHT_SUPER        347
#define ZOM_KEY_MENU               348

namespace ZOM {

	extern int glfwToZOMKeyCode(int code);

	extern std::string ZOM_API ZOMKeyCodeToString(int code);
}