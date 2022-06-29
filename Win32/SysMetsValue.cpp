#include "SysMetsValue.h"

SysMetsValue::SysMetsValue(int index, const FW::String& label, const FW::String& description)
{
    Index = index;
    Label = label;
    Description = description;
    Value = GetSystemMetrics(index);
}