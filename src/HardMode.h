#ifndef MODULE_HARDMODE_H
#define MODULE_HARDMODE_H

#include "ChatCommand.h"
#include "ScriptMgr.h"

using namespace Acore::ChatCommands;

class HardModeMiscScript : MiscScript
{
public:
    HardModeMiscScript() : MiscScript("HardModeMiscScript") { }

private:
    bool CanSendAuctionHello(WorldSession const* session, ObjectGuid guid, Creature* creature) override;
};

class HardModePlayerScript : PlayerScript
{
public:
    HardModePlayerScript() : PlayerScript("HardModePlayerScript") { }

private:
    void OnGiveXP(Player* player, uint32& amount, Unit* victim) override;
    void OnMoneyChanged(Player* player, int32& amount) override;
    bool CanSendMail(Player* player, ObjectGuid receiverGuid, ObjectGuid mailbox, std::string& subject, std::string& body, uint32 money, uint32 COD, Item* item) override;
    bool CanEquipItem(Player* player, uint8 slot, uint16& dest, Item* pItem, bool swap, bool notLoading) override;
};

class HardModeCommandScript : public CommandScript
{
public:
    HardModeCommandScript() : CommandScript("HardModeCommandScript") { }

    ChatCommandTable GetCommands() const override;
    static bool HandleHardModeInfoCommand(ChatHandler* handler, Optional<PlayerIdentifier> target);
    static bool HandleHardModeSetModeCommand(ChatHandler* handler, Optional<PlayerIdentifier> target, uint8 mode, uint8 value);
    static bool HandleHardModeSetTaintCommand(ChatHandler* handler, Optional<PlayerIdentifier> target, uint8 value);
};

class HardModeGameObjectScript : GameObjectScript
{
public:
    HardModeGameObjectScript() : GameObjectScript("HardModeGameObjectScript") { }

private:
    bool OnGossipHello(Player* player, GameObject* go) override;
    bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) override;

private:
    enum
    {
        HARDMODE_GOSSIP_NPCTEXT_ID = 441101,
        HARDMODE_GOSSIP_NPCTEXT_ID_TAINTED = 441102
    };
};


#endif // MODULE_HARDMODE_H
