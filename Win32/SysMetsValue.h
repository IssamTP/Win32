#pragma once

#include <headers/FrameWork.h>

#include <vector>

struct SysMetsValue
{
    int Index;
    int Value;
    FW::String Label;
    FW::String Description;
public:
    SysMetsValue(int index, const FW::String& label, const FW::String& description);
};

typedef std::vector<SysMetsValue> CSysMetsValues;