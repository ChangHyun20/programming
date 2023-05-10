#include "FC.h"
FC::FC(float cc) { c = cc; f = getF(); };
float FC::getF() { return (c * 9. / 5. + 32.0); }
float FC::getC() { return ((f - 32.0) * 5. / 9.); }