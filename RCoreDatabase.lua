--[[

    RGC CORE FOR CONTAINEMNT BREACH (Database)

    Scirpt for handling player database, leaderboard and time banning
    Created by fretka46 for Resurrection GC - EU-CENTRAL Server

    EULA
    ------
    Copying withnout owner permission is prohibited
    Creating copies of player database withnout permission is also prohibited

    Making sensitive player data (Ip, etc..) from dabatase public is prohibited
    ------

    INFO
    ------
    Every date and time is handled with UnixTime
    ------

]]--

debug = true


PlayerTimeConnect = {}
PlayerFirstConnect = {}
PlayerPlayTime = {}
PlayerHumanKills = {}
PlayerScpKills = {}
PlayerDeaths = {}
PlayerEscapes = {}

function OnScriptLoaded()
    print("[RCore - DATA] Has been loaded!")
    if(debug) then
        print("[RCore - DATA] Debug active")
    else
        print("[RCore - DATA] Debug disabled")
    end

    return -1
end


function OnIncomingConnection(nickname, ip, steamid)
    local banend = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "ban_end", 0))

    if (banend > getunixtime()) then

        print("[RCore - DATA] Banned player tried connection - "..nickname.." ("..ip..") dropping ...")

        local banreason = getinivalue("../PlayerData/playerdata.ini", steamid, "ban_reason", 0)
        local banduration = (banend-getunixtime())/60/60
        return "You are banned - Reason: [ "..banreason.." ] Ban expires in: "..banduration.." hours - for questions, contact us on discord"

    else return -1
    end
end

function OnPlayerConnect(playerId)

    local steamid = getplayersteamid(playerId)

    PlayerTimeConnect[playerId] 	= getunixtime()
	PlayerFirstConnect[playerId]	= tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "first_connect", "0"))
	PlayerPlayTime[playerId]		= tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "play_time", "0"))
	PlayerHumanKills[playerId]      = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "kills_human", "0"))
    PlayerScpKills[playerId]        = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "kills_scp", "0"))
	PlayerDeaths[playerId]		    = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "deaths", "0"))
	PlayerEscapes[playerId]		    = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "escapes", "0"))

    putinivalue("../PlayerData/playerdata.ini", steamid, "last_ip", getplayerip(playerId))

    return-1
end

function OnPlayerDisconnect(playerId)
    local steamid = getplayersteamid(playerId)
	local unixtime = getunixtime()

    putinivalue("../PlayerData/playerdata.ini", steamid, "nickname", getplayernickname(playerId))
	
	if PlayerFirstConnect[playerId] == 0 then
        putinivalue("../PlayerData/playerdata.ini", steamid, "first_connect", PlayerTimeConnect[playerId])
	end
	
	putinivalue("../PlayerData/playerdata.ini", steamid, "last_connect", unixtime)
	
	--local time = unixtime - PlayerTimeConnect[playerId]
	--time = (time + PlayerPlayTime[playerId])
    local time = 0
	putinivalue("../PlayerData/playerdata.ini", steamid, "play_time", time)
	
	putinivalue("../PlayerData/playerdata.ini", steamid, "kills_human", PlayerHumanKills[playerId])
    putinivalue("../PlayerData/playerdata.ini", steamid, "kills_scp", PlayerScpKills[playerId])
	putinivalue("../PlayerData/playerdata.ini", steamid, "deaths", PlayerDeaths[playerId])
	putinivalue("../PlayerData/playerdata.ini", steamid, "escapes", PlayerEscapes[playerId])
	
	updateinifile("../PlayerData/playerdata.ini")

    if(debug) then
        print("[RCore(DATA) - DEBUG] Succesfully saved SteamId - "..steamid)
    end

    return -1
end