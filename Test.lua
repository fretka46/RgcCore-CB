---@diagnostic disable: undefined-global



-- First plugin

function OnScriptLoaded()
    print("[RGC-RP Core] for Containment Breach by fretka46 - has been enabled!")
    return -1
end

-- Command handling

-- Main command event handler
function OnPlayerConsole(playerId, message)
    print("Player message is(" .. message .. ")")

    playerconsolecommand(playerId, "Command Feedback done!", true)
end