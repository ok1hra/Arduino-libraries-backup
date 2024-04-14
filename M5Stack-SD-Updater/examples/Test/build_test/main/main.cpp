


//#include <stddef.h>

#if defined TEST_LGFX
  #include "../../../LGFX-SDLoader-Snippet/LGFX-SDLoader-Snippet.ino"
#elif defined TEST_M5Core2
  #include "../../../M5Core2-SDLoader-Snippet/M5Core2-SDLoader-Snippet.ino"
#elif defined TEST_M5Stack || defined TEST_S3Box
  #include "../../../M5Stack-SDLoader-Snippet/M5Stack-SDLoader-Snippet.ino"
#elif defined TEST_M5StickC
  #include "../../../M5StickC-SPIFFS-Loader-Snippet/M5StickC-SPIFFS-Loader-Snippet.ino"
#elif defined TEST_M5Unified || defined TestM5CoreS3 || defined ARDUINO_M5STACK_ATOM_AND_TFCARD
  #include "../../../M5Unified/M5Unified.ino"
#elif defined TEST_SdFat
    #include "../../../SdFatUpdater/SdFatUpdater.ino"
#else
  #error "No device to test"
#endif


