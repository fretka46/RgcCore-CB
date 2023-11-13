---@diagnostic disable: undefined-global



--Rgc Core script for checking banned players connection

DebugBANC = true

function OnScriptLoaded()
    print("[RCore - BANC] Has been loaded!")
    if (DebugBANC) then
        print("[RCore - BANC] Debug active") 
    else
        print("[RCore - BANC] Debug disabled")
    end

    return -1
end

function OnIncomingConnection(nickname, ip, steamid)
    if (DebugBANC) then
    print("[RCore(BANC) - DEBUG] Player trying connection, checking for bans ...")
    end

    local banend = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "ban_end", 0))

    if (banend > getunixtime()) then

        print("[RCore - BANC] Banned player tried connection - "..nickname.." ("..ip..") dropping ...")

        local banreason = getinivalue("../PlayerData/playerdata.ini", steamid, "ban_reason", 0)
        local banduration = (banend-getunixtime())/60/60
        return "You are banned - Reason: [ "..banreason.." ] Ban expires in: "..banduration.." hours - for questions, contact us on discord"

    else return -1
    end
end