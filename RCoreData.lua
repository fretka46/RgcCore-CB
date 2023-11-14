---@diagnostic disable: undefined-global

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

local DebugDATA = true

local PlayerTimeConnect = {}
local PlayerFirstConnect = {}
local PlayerPlayTime = {}
local PlayerHumanKills = {}
local PlayerScpKills = {}
local PlayerDeaths = {}
local PlayerEscapes = {}

function OnScriptLoaded()
  print("[RCore - DATA] Has been loaded!")
  if(DebugDATA) then
      print("[RCore - DATA] Debug active")
  else
      print("[RCore - DATA] Debug disabled")
  end
  return -1
end

function OnIncomingConnection()
  if (DebugDATA) then
    print("[RCore(DATA) - DEBUG] Registered player connection")
  end

  return -1
end

function OnPlayerConnect(playerId)

  local steamid = getplayersteamid(playerId)

  PlayerTimeConnect[playerId] 	= getunixtime()
  PlayerFirstConnect[playerId]	= tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "first_connect", "0"))
  PlayerPlayTime[playerId]	  	= tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "play_time", "0"))
  PlayerHumanKills[playerId]    = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "kills_human", "0"))
  PlayerScpKills[playerId]      = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "kills_scp", "0"))
  PlayerDeaths[playerId]		    = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "deaths", "0"))
  PlayerEscapes[playerId]		    = tonumber(getinivalue("../PlayerData/playerdata.ini", steamid, "escapes", "0"))

  return -1
end

function OnPlayerDisconnect(playerId, message)

  local steamid = getplayersteamid(playerId)
	local unixtime = getunixtime()

    putinivalue("../PlayerData/playerdata.ini", steamid, "nickname", getplayernickname(playerId))
    putinivalue("../PlayerData/playerdata.ini", steamid, "last_ip", getplayerip(playerId))
	
	if PlayerFirstConnect[playerId] == 0 then
        putinivalue("../PlayerData/playerdata.ini", steamid, "first_connect", PlayerTimeConnect[playerId])
	end
	
	putinivalue("../PlayerData/playerdata.ini", steamid, "last_connect", unixtime)
	
	local time = unixtime - PlayerTimeConnect[playerId]
	time = (time + PlayerPlayTime[playerId])
	putinivalue("../PlayerData/playerdata.ini", steamid, "play_time", time)

  putinivalue("../PlayerData/playerdata.ini", steamid, "kills_human", PlayerHumanKills[playerId])
  putinivalue("../PlayerData/playerdata.ini", steamid, "kills_scp", PlayerScpKills[playerId])
  putinivalue("../PlayerData/playerdata.ini", steamid, "deaths", PlayerDeaths[playerId])
  putinivalue("../PlayerData/playerdata.ini", steamid, "escapes", PlayerEscapes[playerId])

  updateinifile("../PlayerData/playerdata.ini")

  if(DebugDATA) then
    print("[RCore(DATA) - DEBUG] Succesfully saved SteamId - "..steamid)
  end

  return -1
end