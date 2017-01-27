#include "test.h"
#include <metaenum.h>
template<>
int ACT::MetaEnumData<ACT::LogMessageType>::countKeys = 3;
template<>
const char* ACT::MetaEnumData<ACT::LogMessageType>::name = "LogMessageType";
template<>
ACT::LogMessageType ACT::MetaEnumData<ACT::LogMessageType>::values[] = {
ACT::LogMessageType::Note,
ACT::LogMessageType::Warning,
ACT::LogMessageType::Error,
};
template<>
const char* ACT::MetaEnumData<ACT::LogMessageType>::keys[] = {
"Note",
"Warning",
"Error",
};

