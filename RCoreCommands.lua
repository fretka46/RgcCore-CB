---@diagnostic disable: undefined-global



    --Enables/diables debugging
    debug = true

    function OnScriptLoaded()
        print("[RCore - CMD] has been enabled!")
        if (debug) then
            print("[RCore - CMD] Debug active") 
        else
            print("[RCore - CMD] Debug disabled")
        end
        return -1
    end


    function OnPlayerConsole(playerId, message)
        if (debug) then print("[RCore(CMD) - DEBUG] PlayerId "..playerId.." RA -> (" .. message .. ")") end

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
            ChangeSizeCmd(cmd)
    
        elseif (cmd[1] == "i") then
            SetIntercomCmd(cmd, playerId)
        
        elseif (cmd[1] == "setmtftimer") then
            SetMtfTimerCmd(playerId, cmd)

        --Server RA
        elseif (cmd[1] == "debug") then
            DebugCmd(playerId)

        elseif (cmd[1] == "restartserver" or "rser" ) then
            RestartServerCmd(playerId)

        elseif (cmd[1] == "setseed") then
            SetMapSeedCmd(cmd, playerId)

        elseif (cmd[1] = "setmap") then
            SetCustomMapCmd(cmd, playerId)
        end

    
        return -1
    end

    --------------------

    function SetIntercomCmd(cmd, playerId)
        --Global intercom command handler
        if (cmd[2] == "enable" or "e") then
            setplayerintercom(playerId, 1)
            sendmessage(Id, "[RA] Global Intercom Enabled!")
        elseif (cmd[2] == "disable" or "d") then
            setplayerintercom(playerId, 0)
            sendmessage(Id, "[RA] Global Intercom Disabeld!")
        else
            sendmessage(Id, "[RA] Disables or enables global intercom")
            sendmessage(Id, "[RA] Syntax: i <enable/disable>")
        end

        return -1
    end

    function ChangeSizeCmd(cmd)
        local size

        if (cmd[2] == nil) then
            sendmessage(playerId, "[RA] Scales player model")
            sendmessage(playerId, "[RA] -> size <set/reset/get> <Id> <size>")
            return -1
        elseif (cmd[2] == "get" or "g") then
            sendmessage(playerId, "[RA] Size for Id ".. cmd[3] .." - "..getplayersize(playerId))
            return -1
        elseif (cmd[2] == "set" or "s") then size = cmd[4]
        else size = 100
        end
    
        changeplayersize(cmd[3], size)
        sendmessage(playerId, "[RA] Player with Id ".. cmd[3])
        sendmessage(playerId, "[RA] has been scaled to size ".. size)
    
        return -1
    end

    function SetMtfTimerCmd(playerId, cmd)
        if (cmd[2] != nil) then
            setmtftimer(cmd[2])
            sendmessage(playerId, "[RA] MTF Timer set to "..cmd[2])
        else
            sendmessage(playerId, "[RA] Sets MTF respawn time")
            sendmessage(playerId, "[RA] Syntax: setmtftimer <seconds>")
        end

        return -1
    end

    function RestartServerCmd(playerId)
        print("Player " ..playerId.." forced server restart")
        restartserver()

        return -1
    end

    function SetMapSeedCmd(cmd, playerId)
        if (cmd[2] ~= nil) then
            print("Player "..playerId.." forced seed change")
            snedmessage(playerId, "[RA] Seed changed, restarting ...")
            setmapseed(cmd[2])
        else
            sendmessage(playerId, "[RA] Restarts server and changes map seed")
            sendmessage(playerId, "[RA] Syntax: setseed <seed>")
        end

        return -1
    end

    function SetCustomMapCmd(cmd, playerId)
        if (cmd[2] ~= nil) then
            print("Player " ..playerId.." forced CustomMap change")
            sendmessage(playerId, "[RA] Map changed, restarting ...")
            setcustommap(cmd[2]..".cbmap2")
        else
            sendmessage(playerId, "[RA] Restarts server and changes custom map")
            sendmessage(playerId, "[RA] Syntax: setmap <MapName>")
        end

        return -1
        
    end

    function DebugCmd(playerId)
        if (debug) then
            sendmessage(playerId, "[RA] Debug disabled")
            print("Debug disabled by Id "..playerId)
            debug = false
        else
            sendmessage(playerId, "[RA] Debug enabled")
            print("Debug enabled by Id "..playerId)
            debug = true
        end

        return -1
    end