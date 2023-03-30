#ifndef MODULE_HARDMODE_MODE_H
#define MODULE_HARDMODE_MODE_H

#include "ScriptMgr.h"

enum DifficultyModes
{
    DIFFICULTY_MODE_SELF_CRAFTED = 0,
    DIFFICULTY_MODE_COUNT = 1
};

class DifficultyMode
{
public:
    virtual bool CanSendAuctionHello(WorldSession const* session, ObjectGuid guid, Creature* creature) { return true; }
    virtual bool CanEquipItem(Player* player, uint8 slot, uint16& dest, Item* pItem, bool swap, bool notLoading) { return true; }
};

#endif // MODULE_HARDMODE_MODE_H
