#include "stdafx.h"

#include "MemoryCell.h"

MemoryValue MemoryCell::read()
{
    MemoryValue val = value;
    //for (auto& cb : readCallbacks)
    //    val = cb(*this, address, value);

    return val;
}

bool MemoryCell::write(MemoryValue newValue)
{
    //using permissions = MemoryCellWritePermissions;
    //switch (writePermission)
    //{
    //case permissions::allow:
    //    setValue(newValue);
    //case permissions::ignore:
    //    break;
    //case permissions::forbid:
    //    assert(false);
    //}
    //for (auto& cb : writeCallbacks)
    //    res = cb(*this, address, newValue);

    return setValue(newValue);
}
//
//bool memorycell::setreadcallback(readcallback& callback)
//{
//    readcallbacks.push_back(callback);
//    return true;
//}
//
//bool memorycell::setwritecallback(writecallback& callback)
//{
//    writecallbacks.push_back(callback);
//    return true;
//}

//bool MemoryCell::setPermission(MemoryCellWritePermissions newPerms)
//{
//    writePermission = newPerms;
//    return true;
//}
