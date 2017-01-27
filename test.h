#ifndef LOGMESSAGETYPE_H
#define LOGMESSAGETYPE_H
#include <QMetaType>

namespace ACT { 
enum class LogMessageType {
Note,
Warning,
Error
};
}
Q_DECLARE_METATYPE(ACT::LogMessageType)
#endif
