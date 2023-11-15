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

    function OnPlayerChat(playerId, message)
        if (message == ": /stats") then
            PlayerStats(playerId)

            if (DebugCMD) then
                print("[RCore(CMD) - DEBUG] Registered /stats command")
            end
        end

        return -1
    end

    function OnPlayerConsole(playerId, message)
    -- Wrap the body of the function in a pcall to catch errors
    local status, err = pcall(function()
        if (DebugCMD) then print("[RCore(CMD) - DEBUG] "..getplayernickname(playerId).."("..playerId..") RA -> (" .. message .. ")") end

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

        --Banning RA
        elseif (cmd[1] == "tmute") then
            MuteCmd(playerId, cmd)
        elseif (cmd[1] == "tban") then
            TempBCmd(playerId, cmd)
        elseif (cmd[1] == "tkick") then
            KickCmd(playerId, cmd)
        elseif (cmd[1] == "pinfo") then
            PlayerInfoCmd(playerId, cmd)
        elseif (cmd[1] == "pstats") then
            AdminPlayerStatsCmd(playerId, cmd)

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
            elseif (cmd[1] == "test") then
                sendmessage(playerId, "[RA] Test\n line command")

            elseif (DebugCMD) then
                print("[RCore(CMD) - DEBUG] SuperUser sent unregistered command")
            end


        elseif (DebugCMD) then
            print("[RCore(CMD) - DEBUG] Player sent unregistered command")
        end
    end)


    -- If pcall returned false, an error occurred
    if not status then
        -- Log the error
        print("[RCore(CMD) - ERROR] An error occurred: " .. err)

                -- Send a message to the player
                sendmessage(playerId, "[RA] Wrong command syntax")
                sendmessage(playerId, "[RA] 100% sure? DM Fretka with error below")
                sendmessage(playerId, "[ERR] "..err)
                sendmessage(playerId, "[ERR] In: "..message)
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


--Need Fix
function MuteCmd(playerId, cmd)
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Handles global muting system for players")
        sendmessage(playerId, "[RA] Syntax: tmute <set/remove> <steamid/id> <steamid/id> <time> <reason>")
        sendmessage(playerId, "[RA] Example: tmute set id 9 1d shut_up")
        return -1
    elseif (cmd[2] == "set") then
        if (cmd[4] == playerId) or (isplayeradmin(cmd[4]) and (getplayersteamid(playerId) ~= SuperuserID)) then
            sendmessage(playerId, "[RA] You cannot mute yourself or other admins")
            return -1
        end
        if (cmd[3] == "id") then
            if (isplayerconnected(cmd[4]) == 0) then
                sendmessage(playerId, "[RA] Player is not connected")
                return -1
            end
            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[4]), "mute_end", getunixtime() + TimeToSeconds(cmd[5]))
            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[4]), "mute_reason", cmd[6])
            sendmessage(playerId, "[RA] Player "..getplayernickname(cmd[4]).."("..cmd[4]..")")
            sendmessage(playerId, "[RA] has been muted for "..cmd[5].." - Reason: "..cmd[6])
            setplayermute(0, cmd[4])
            sendmessage(cmd[4], "[SERVER] You have been muted for "..cmd[5].." - Reason: "..cmd[6])

        elseif (cmd[3] == "steamid") then
            putinivalue("../PlayerData/playerdata.ini", cmd[4], "mute_end", getunixtime() + TimeToSeconds(cmd[5]))
            putinivalue("../PlayerData/playerdata.ini", cmd[4], "mute_reason", cmd[6])
            sendmessage(playerId, "[RA] Player "..getinivalue("../PlayerData/playerdata.ini", cmd[4], "nickname", "(Never connected)").."("..cmd[4]..")")
            sendmessage(playerId, "[RA] has been muted for "..cmd[5].." - Reason: "..cmd[6])
            sendmessage(playerId, "[RA] Note: You muted offline player")
        end
        updateinifile("../PlayerData/playerdata.ini")
    elseif (cmd[2] == "remove") then
        if (cmd[3] == "id") then
            if (isplayerconnected(cmd[4]) == 0) then
                sendmessage(playerId, "[RA] Player is not connected")
                return -1
            end
            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[4]), "mute_end", 0)
            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[4]), "mute_reason", "0")
            sendmessage(playerId, "[RA] Player "..getplayernickname(cmd[4]).."("..cmd[4]..")")
            sendmessage(playerId, "[RA] has been unmuted")
            setplayermute(1, cmd[4])
            sendmessage(cmd[4], "[SERVER] You have been unmuted")

        elseif (cmd[3] == "steamid") then
            putinivalue("../PlayerData/playerdata.ini", cmd[4], "mute_end", 0)
            putinivalue("../PlayerData/playerdata.ini", cmd[4], "mute_reason", "Mute removed by "..getplayernickname(playerId))
            sendmessage(playerId, "[RA] Player "..getinivalue("../PlayerData/playerdata.ini", cmd[4], "nickname", "(Never connected)").."("..cmd[4]..")")
            sendmessage(playerId, "[RA] has been unmuted")
        end
        updateinifile("../PlayerData/playerdata.ini")
    else
        sendmessage(playerId, "[RA] Handles global muting system for players")
        sendmessage(playerId, "[RA] Syntax: tmute <set/remove> <steamid/id> <steamid/id> <time> <reason>")
        sendmessage(playerId, "[RA] Example: tmute set id 9 1d shut_up")
    end

    return -1
end

function TempBCmd(playerId, cmd)
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Bans player for specified duration")
        sendmessage(playerId, "[RA] Syntax: tban <Id> <time> <reason>")
    elseif (isplayerconnected(cmd[2]) == 0) then
        sendmessage(playerId, "[RA] Player is not connected")
        return -1
    else
        if (tonumber(cmd[2]) == 9) then
            sendmessage(playerId, "[RA] You cannot ban yourself")
            return -1
        elseif (isplayeradmin(playerId)) and (getplayersteamid(playerId) ~= SuperuserID) then
            sendmessage(playerId, "[RA] Nebanuj sve kolegy dik - fretka")
            return -1
        else
            if (cmd[4] == nil) then
                cmd[4] = "no_reason"
            end

            local banDurationInSeconds
            if (cmd[3] == "perm") then
                banDurationInSeconds = 9999999998
            else
                banDurationInSeconds = TimeToSeconds(cmd[3])
            end

            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[2]), "ban_end", getunixtime() + banDurationInSeconds)
            putinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[2]), "ban_reason", cmd[4])

            putinivalue("../PlayerData/banlog.ini", getplayersteamid(cmd[2]), "nickname", getplayernickname(cmd[2]))
            putinivalue("../PlayerData/banlog.ini", getplayersteamid(cmd[2]), TimeToSeconds(banDurationInSeconds).." - "..cmd[4], getplayernickname(playerId))

            if (DebugCMD) then
                print("[RCore(CMD) - DEBUG] Received ban report, updating RCore(DATA) database ...")
            end
            updateinifile("../PlayerData/playerdata.ini")
            updateinifile("../PlayerData/banlog.ini")
            kick(cmd[2], "")

            sendmessage(playerId, "[RA] Sucessfully banned a player")
            sendmessage(playerId, "[RA] "..getplayernickname(cmd[2]).."("..cmd[2]..") banned for "..cmd[3].." - Reason: "..cmd[4])
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

function PlayerInfoCmd(playerId, cmd)
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Shows admin player info")
        sendmessage(playerId, "[RA] Syntax: pinfo <id/steamdid> <id/steamdid>")
        sendmessage(playerId, "[RA] Example: pinfo id 9")
    else
        local unixtime = getunixtime()
        if (cmd[2] == "id") then
                local steamid = getplayersteamid(cmd[3])
                local banend = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "ban_end", "0"))
                local muteend = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "mute_end", "0"))
                sendmessage(playerId, "-------------------------------")
                sendmessage(playerId, "[RA] Player "..getplayernickname(cmd[3]).."("..cmd[3]..")")
                sendmessage(playerId, "[RA] SteamID: "..getplayersteamid(cmd[3]))

                -- Shows IP only to Superuser
                if (getplayersteamid(playerId) == SuperuserID) then
                    sendmessage(playerId, "[RA] IP: "..getplayerip(cmd[3]))
                end
                
                --Outputs ban information
                if (banend > unixtime) then
                    sendmessage(playerId, "[RA] Banned: Yes")
                    sendmessage(playerId, "[RA] Ban reason: "..getinivalue("../PlayerData/playerdata.ini", steamid, "ban_reason", "0"))
                    sendmessage(playerId, "[RA] Ban expires in: "..FormatTransfer(banend-unixtime))
                else
                    sendmessage(playerId, "[RA] Banned: No")
                end

                --Outputs mute information
                if (muteend > unixtime) then
                    sendmessage(playerId, "[RA] Global muted: Yes")
                    sendmessage(playerId, "[RA] Global mute expires in: "..FormatTransfer(muteend-unixtime))
                else
                    sendmessage(playerId, "[RA] Global muted: No")
                end

                sendmessage(playerId, "[RA] Current Mute status: "..getplayermute(cmd[3]))
                sendmessage(playerId, "[RA] First connect: "..TransferUnixToDate(getinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[3]), "first_connect", "0")))
                sendmessage(playerId, "[RA] Last connect: "..TransferUnixToDate(getinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[3]), "last_connect", "0")))
                sendmessage(playerId, "[RA] Play time: "..FormatTransfer(getinivalue("../PlayerData/playerdata.ini", getplayersteamid(cmd[3]), "play_time", "0")))
                sendmessage(playerId, "-------------------------------")

        elseif (cmd[2] == "steamid") then
                local banend = tonumber(getinivalue("../PlayerData/playerdata.ini", cmd[3], "ban_end", "0"))
                local muteend = tonumber(getinivalue("../PlayerData/playerdata.ini", cmd[3], "mute_end", "0"))
                sendmessage(playerId, "-------------------------------")
                sendmessage(playerId, "[RA] Player "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "nickname", "0").."("..cmd[3]..")")
                sendmessage(playerId, "[RA] SteamID: "..cmd[3])

                -- Shows IP only to Superuser
                if (getplayersteamid(playerId) == SuperuserID) then
                    sendmessage(playerId, "[RA] Last IP: "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "last_ip", "0"))
                end

                --Outputs ban information
                if (banend > unixtime) then
                    sendmessage(playerId, "[RA] Banned: Yes")
                    sendmessage(playerId, "[RA] Ban reason: "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "ban_reason", "0"))
                    sendmessage(playerId, "[RA] Ban expires in: "..FormatTransfer(banend-unixtime))
                else
                    sendmessage(playerId, "[RA] Banned: No")
                end

                --Outputs mute information
                if (muteend > unixtime) then
                    sendmessage(playerId, "[RA] Global muted: Yes")
                    sendmessage(playerId, "[RA] Global mute expires in: "..FormatTransfer(muteend-unixtime))
                else
                    sendmessage(playerId, "[RA] Global muted: No")
                end

                sendmessage(playerId, "[RA] First connect: "..TransferUnixToDate(getinivalue("../PlayerData/playerdata.ini", cmd[3], "first_connect", "0")))
                sendmessage(playerId, "[RA] Last connect: "..TransferUnixToDate(getinivalue("../PlayerData/playerdata.ini", cmd[3], "last_connect", "0")))
                sendmessage(playerId, "[RA] Play time: "..FormatTransfer(getinivalue("../PlayerData/playerdata.ini", cmd[3], "play_time", "0")))
                sendmessage(playerId, "Note: This is offline player info, some data may be outdated")
                sendmessage(playerId, "-------------------------------")
        end
    end
end

function AdminPlayerStatsCmd(playerId, cmd)
    if (cmd[2] == nil) then
        sendmessage(playerId, "[RA] Shows player stats")
        sendmessage(playerId, "[RA] Syntax: pstats <id/steamdid> <id/steamdid>")
        sendmessage(playerId, "[RA] Example: pstats id 9")
    else
        if (cmd[2] == "id") then
            local steamid = getplayersteamid(cmd[3])
            sendmessage(playerId, "-------------------------------")
            sendmessage(playerId, "[RA] Player "..getplayernickname(cmd[3]).."("..cmd[3]..")")
            sendmessage(playerId, "[RA] SteamID: "..getplayersteamid(cmd[3]))
            sendmessage(playerId, "[RA] Human kills: "..getinivalue("../PlayerData/playerdata.ini", steamid, "kills_human", "0"))
            sendmessage(playerId, "[RA] SCP kills: "..getinivalue("../PlayerData/playerdata.ini", steamid, "kills_scp", "0"))
            sendmessage(playerId, "[RA] Deaths: "..getinivalue("../PlayerData/playerdata.ini", steamid, "deaths", "0"))
            sendmessage(playerId, "[RA] Escapes: "..getinivalue("../PlayerData/playerdata.ini", steamid, "escapes", "0"))
            sendmessage(playerId, "-------------------------------")
        elseif (cmd[2] == "steamid") then
            sendmessage(playerId, "-------------------------------")
            sendmessage(playerId, "[RA] Player "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "nickname", "0").."("..cmd[3]..")")
            sendmessage(playerId, "[RA] SteamID: "..cmd[3])
            sendmessage(playerId, "[RA] Human kills: "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "kills_human", "0"))
            sendmessage(playerId, "[RA] SCP kills: "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "kills_scp", "0"))
            sendmessage(playerId, "[RA] Deaths: "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "deaths", "0"))
            sendmessage(playerId, "[RA] Escapes: "..getinivalue("../PlayerData/playerdata.ini", cmd[3], "escapes", "0"))
            sendmessage(playerId, "-------------------------------")
        end
    end

    return -1
end

function PlayerStats(playerId)
    sendmessage(playerId, "-------------------------------")
    sendmessage(playerId, "[SERVER] Showing your stats:")
    sendmessage(playerId, "[SERVER] Player "..getplayernickname(playerId).."("..playerId..")")
    sendmessage(playerId, "[SERVER] Human kills: "..getinivalue("../PlayerData/playerdata.ini", getplayersteamid(playerId), "kills_human", "0"))
    sendmessage(playerId, "[SERVER] SCP kills: "..getinivalue("../PlayerData/playerdata.ini", getplayersteamid(playerId), "kills_scp", "0"))
    sendmessage(playerId, "[SERVER] Deaths: "..getinivalue("../PlayerData/playerdata.ini", getplayersteamid(playerId), "deaths", "0"))
    sendmessage(playerId, "[SERVER] Escapes: "..getinivalue("../PlayerData/playerdata.ini", getplayersteamid(playerId), "escapes", "0"))
    sendmessage(playerId, "-------------------------------")

    return -1
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
        setcustommap("../Maps/rpmap.cbmap2")
    else
        sendmessage(playerId, "[RA] Restarts server and changes custom map")
        sendmessage(playerId, "[RA] Syntax: setmap <map>")
        sendmessage(playerId, "[RA] Example: setmap rpmap")
    end

    return -1
end

function RconCmd(playerId, message)
    rconcommand(GetWordsExceptFirst(message))
    sendmessage(playerId, "[RCON-RA] Command sent -> "..GetWordsExceptFirst(message))
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

function TransferUnixToDate(unixtime)
    local date = os.date("%d/%m/%y %H:%M:%S", unixtime)
    return date
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