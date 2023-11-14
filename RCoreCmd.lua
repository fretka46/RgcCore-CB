---@diagnostic disable: undefined-global


    --Plugin Config
        --Enables/diables debugging
        DebugCMD = true
        --SuperuserID is player with special permission on server
        SuperuserID = 194069312

    function OnScriptLoaded()
        print("[RCore - CMD] Has been loaded!")
        if (DebugCMD) then
            print("[RCore - CMD] Debug active") 
        else
            print("[RCore - CMD] Debug disabled")
        end
        return -1
    end


    function OnPlayerConsole(playerId, message)
        if (DebugCMD) then print("[RCore(CMD) - DEBUG] "..getplayernickname(playerId).."("..playerId..") RA -> (" .. message .. ")") end
        if (Rconactive) then RconCmd(playerId, message) end

    -- Core method that separates words and make command syntax possible
        local separator = "%s"
        local cmd = {}
        for str in string.gmatch(message, "([^"..separator.."]+)") do
                table.insert(cmd, str)
        end
    ---------------
        --Basic RA
        if (cmd[1] == "ping") then
            sendmessage(playerId, "[RA] Pong, pong!")
    
        elseif (cmd[1] == "size") then
            ChangeSizeCmd(playerId, cmd)
    
        elseif (cmd[1] == "i") then
            SetIntercomCmd(cmd, playerId)
        
        elseif (cmd[1] == "setmtftimer") then
            SetMtfTimerCmd(playerId, cmd)

        elseif (cmd[1] == "createnpc") then
            CerateNpcCmd(playerId, cmd)

        --Banning RA
        -- Doesnt work, need fix
        elseif (cmd[1] == "mute") then
            MuteCmd(playerId, cmd)
        elseif (cmd[1] == "tban") then
            TempBCmd(playerId, cmd)
        elseif (cmd[1] == "tkick") then
            KickCmd(playerId, cmd)

        --Server RA
        elseif (cmd[1] == "debug") then
            DebugCmd(playerId)

        elseif (cmd[1] == "restartserver") or (cmd[1] == "rser" ) then
            RestartServerCmd(playerId)

        elseif (cmd[1] == "setseed") then
            SetMapSeedCmd(cmd, playerId)

            --Doesnt work, need fix
        elseif (cmd[1] == "setmap") then
            SetCustomMapCmd(cmd, playerId)
        
        elseif (getplayersteamid(playerId) == SuperuserID) then
            if (cmd[1] == "rcon") then
                RconCmd(playerId, message)
            elseif (cmd[1] == "savedb") then
                SaveDatabaseCmd(playerId)
            end



        elseif (DebugCMD) then
            print("[RCore(CMD) - DEBUG] Player sent unregistered command")
        end

        return -1
    end

    --------------------

function SetIntercomCmd(cmd, playerId)
    --Global intercom command handler
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Disables or enables global intercom")
        sendmessage(playerId, "[RA] Syntax: i <enable/disable>")
        return -1
    elseif (cmd[2] == "enable") or (cmd[2] == "e") then
        setplayerintercom(playerId, 1)
        sendmessage(playerId, "[RA] Global Intercom Enabled!")
    elseif (cmd[2] == "disable") or (cmd[2] == "d") then
        setplayerintercom(playerId, 0)
        sendmessage(playerId, "[RA] Global Intercom Disabeld!")
    else
        sendmessage(playerId, "[RA] Disables or enables global intercom")
        sendmessage(playerId, "[RA] Syntax: i <enable/disable>")
    end

    return -1
end

function ChangeSizeCmd(playerId, cmd)
    local size

    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Scales player model")
        sendmessage(playerId, "[RA] -> size <set/reset/get> <Id> <size>")
        return -1
    elseif (cmd[2] == "get") or (cmd[2] == "g") then
        sendmessage(playerId, "[RA] Size for "..getplayernickname(cmd[3]).."("..cmd[3]..") - "..getplayersize(playerId))
        return -1
    elseif (cmd[2] == "set") or (cmd[2] == "s") then size = cmd[4]
    else size = 100
    end

    changeplayersize(cmd[3], size)
    sendmessage(playerId, "[RA] Player "..getplayernickname(playerId).."("..cmd[3]..")")
    sendmessage(playerId, "[RA] has been scaled to size - ".. size)

    return -1
end

function SetMtfTimerCmd(playerId, cmd)
    if (cmd[2] ~= nil) then
        setmtftimer(cmd[2])
        sendmessage(playerId, "[RA] MTF Timer set to "..cmd[2])
    else
        sendmessage(playerId, "[RA] Sets MTF respawn time")
        sendmessage(playerId, "[RA] Syntax: setmtftimer <seconds>")
    end

    return -1
end

function CreateNpcCmd(playerId, cmd)
    if (cmd[2] ~= nil) then
        if (cmd[2] == "create") then
            local npcid = createnpc(cmd[3])
            sendmessage(playerId, "[RA] Npc created with id -> "..npcid)
        elseif (cmd[2] == "gettype") then
            sendmessage(playerId, "[RA] NPC Type for id: "..cmd[3].." is -> "..getnpcid(cmd[3]))
    end
    else
        sendmessage(playerId, "[RA] Creates a new NPC")
        sendmessage(playerId, "[RA] Syntax: createnpc <npctype>")
    end
end


--Need Fix
function MuteCmd(playerId, cmd)
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Handles muting system for players")
        sendmessage(playerid, "[RA] Syntax: mute <set/get> <id> <1/0>")
        return -1
    elseif (cmd[2] == "set") then
        setplayermute(cmd[3], cmd[4])
        print(cmd[3]..cmd[4])
        sendmessage(playerId, "[RA] Mute status set to "..getplayermute(cmd[3]).." for "..getplayernickname(cmd[3]).."("..cmd[3]..")")
    else
        sendmessage(playerId, "[RA] Mute status for "..getplayernickname(cmd[3]).."("..cmd[3]..") -> "..getplayermute(cmd[3]))
    end

    return -1
end

function TempBCmd(playerId, cmd)
    if (cmd[5] == nil) then
        cmd[5] = "no_reason"
    end
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Bans player for specified duration")
        sendmessage(playerId, "[RA] Syntax: ban <Id> <time> <reason>")
    else
        if (tonumber(cmd[2]) == 9) then
            sendmessage(playerId, "[RA] You cannot ban yourself")
            return -1
        elseif (isplayeradmin(playerId)) and (getplayersteamid(playerId) ~= SuperuserID) then
            sendmessage(playerId, "[RA] Nebanuj sve kolegy dik - fretka")
            return -1
        else
            local banDurationInSeconds
            if (cmd[3] == "perm") then
                banDurationInSeconds = 9999999998
            else
                banDurationInSeconds = TimeToSeconds(cmd[3])
            end

            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[2]), "ban_end", getunixtime() + banDurationInSeconds)
            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[2]), "ban_reason", cmd[5])

            putinivalue("../PlayerData/banlog.ini", getplayersteamid(cmd[2]), "nickname", getplayernickname(cmd[2]))
            putinivalue("../PlayerData/banlog.ini", getplayersteamid(cmd[2]), TransferSecToDDMMSS(banDurationInSeconds).." - "..cmd[5], getplayernickname(playerId))

            if (DebugCMD) then
                print("[RCore(CMD) - DEBUG] Received ban report, updating RCore(DATA) database ...")
            end
            updateinifile("../PlayerData/playerdata.ini")
            updateinifile("../PlayerData/banlog.ini")
            kick(cmd[2], "")
        end
    end

    return -1
end

function KickCmd(playerId, cmd)
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Kicks player from server")
        sendmessage(playerId, "[RA] Syntax: kick <id> <reason>")
    else
        kick(cmd[2], cmd[3])
        sendmessage(playerId, "[RA] Player "..getplayernickname(cmd[2]).." kicked")
    end
    
end


function RestartServerCmd(playerId)
    print("Player "..getplayernickname(playerId).." forced server restart")
    sendmessage(playerId, "Server restart forced - Restarting ...")
    Sleep(2)
    restartserver()

    return -1
end

function SetMapSeedCmd(cmd, playerId)
    if (cmd[2] ~= nil) then
        print("Player "..getplayernickname(playerId).."("..playerId..") forced seed change")
        sendmessage(playerId, "[RA] Seed changed, restarting ...")
        Sleep(2)
        setmapseed(cmd[2])
    else
        sendmessage(playerId, "[RA] Restarts server and changes map seed")
        sendmessage(playerId, "[RA] Syntax: setseed <seed>")
    end

    return -1
end

function SetCustomMapCmd(cmd, playerId)
    if (cmd[2] ~= nil) then
        print("Player "..getplayernickname(playerId).."("..playerId..") forced CustomMap change")
        sendmessage(playerId, "[RA] Map changed, restarting ...")
        setcustommap(cmd[2]..".cbmap2")
    else
        sendmessage(playerId, "[RA] Restarts server and changes custom map")
        sendmessage(playerId, "[RA] Syntax: setmap <MapName>")
    end

    return -1
end

function RconCmd(playerId, message)
    GetWordsExceptFirst(message)
    sendmessage(playerId, "[RCON-RA] Sending -> "..GetWordsExceptFirst(message))
end

function SaveDatabaseCmd(playerId)
    print("[RCore(CMD)] Player "..getplayernickname(playerId).."("..playerId..") forced database save")

    updateinifile("../PlayerData/playerdata.ini")
    updateinifile("../PlayerData/banlog.ini")
    sendmessage(playerId, "[RA] Database saved")
    return -1
end

function DebugCmd(playerId)
    if (DebugCMD) then
        sendmessage(playerId, "[Rcore(CMD)] Debug disabled")
        print("Debug disabled by "..getplayernickname(playerId).."("..playerId..")")
        DebugCMD = false
    else
        sendmessage(playerId, "[Rcore(CMD) Debug enabled")
        print("Debug enabled by "..getplayernickname(playerId).."("..playerId..")")
        DebugCMD = true
    end

    return -1
end

function Sleep(n)
        local t = os.clock()
        while os.clock() - t <= n do
          -- nothing
        end
        return -1
      end

function GetWordsExceptFirst(str)
    local isFirst = true
    local otherWords = {}

    for word in string.gmatch(str, "%S+") do
        if isFirst then
            isFirst = false
        else
            table.insert(otherWords, word)
        end
    end

    return table.concat(otherWords, " ")
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

function TimeToSeconds(timeStr)
    local totalSeconds = 0
    local units = {
        M = 30 * 24 * 60 * 60,  -- month in seconds
        d = 24 * 60 * 60,  -- day in seconds
        h = 60 * 60,  -- hour in seconds
        m = 60  -- minute in seconds
    }

    for value, unit in string.gmatch(timeStr, "(%d+)(%a)") do
        totalSeconds = totalSeconds + tonumber(value) * units[unit]
    end

    return totalSeconds
end