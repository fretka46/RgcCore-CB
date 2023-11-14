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
        local banduration = FormatTransfer(banend-getunixtime())
        return "You are banned             Reason: [ "..banreason.." ] Ban expires in: "..banduration.." - for questions, contact us on discord"

    else return -1
    end
end

function FormatTransfer(sec)
    local sec = tonumber(sec)
    local M = math.floor(sec / (30 * 86400))
    sec = sec - (M * 30 * 86400)
    local d = math.floor(sec / 86400)
    sec = sec - (d * 86400)
    local h = math.floor(sec / 3600)
    sec = sec - (h * 3600)
    local m = math.floor(sec / 60)
    local s = sec - (m * 60)
    local str = ""
    if M > 0 then str = str .. M .. "M " end
    if d > 0 then str = str .. d .. "d " end
    if h > 0 then str = str .. h .. "h " end
    if m > 0 then str = str .. m .. "m " end
    if s > 0 then str = str .. s .. "s" end
    return str
end