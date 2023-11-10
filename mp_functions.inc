// NOTE: def, declare executing functions works only in def, public def declarations (example)
//UseFunction() // Doesn't work // will work only global, local declarations
//public def Func()
//		UseFunction() // Will Work
//end
//

// NOTE: YOU CAN CREATE GLOBALS IN FUNCTIONS
// NOTE: NEVER USE () IN KEYWORDS!
// NOTE: 
//		Never use  functions in using function, example: SetInfo(3, Function(1), 1) // if you do this, then you can get MAV or something else (Skynet++ Compiler Bug)
//		Use: .recommend
//			local result = Function(1)
//			SetInfo(3, result, 1)
//
// 		The compiler skips a function in function using and counts arguments only for the function which using
// 		def SetInfo(variable, result, var)
//			print(variable+ " "+ result + " " + var) // Will return "1 4 1" but must "3 4 1", but using .recommend will return "3 4 1"
//		end
//		def Function(val)
//		return val+3
//		end

// NOTE:
// PREDIRECTIVE #PLAYERSCRIPT // REMOVE ERROR ABOUT EXECUTING FUNCTIONS IN MAIN BLOCK
// you need add this to first line of script
// #PLAYERSCRIPT
// or
// #playerscript


// ALL PUBLICS HAVE A RETURN 0 (ITS CANCEL ACTION IN SOME PUBLICS), ALL PUBLICS THAT DIDN'T HAVE IT BEFORE VERSION 1.2.4.1 HAVE IT
// =========================================================== SERVER
declare public OnLostConnectionWithCentralServer()
declare public OnScriptLoaded() // Execute when a script send a "loaded successfully" message
declare public OnServerUpdate()
declare public OnServerStart(port:Int)
declare public OnPlayerChat(playerid:Int, text:String)
declare public OnPlayerConnect(playerid:Int)
declare public OnIncomingConnection(nickname:String, IP:String, SteamID:Int, version:String, ispatron:Int) // return value returns connecting error to client ( Chr(13)+Chr(10) creating \n )
declare public OnBadIncomingConnection(nickname:String, IP:String, SteamID:Int, version:String, ispatron:Int, EBeginAuthSessionResult:Int) // called when the auth ticket is bad // client can't join to server // return 0 does not send a "bad authorization ticket" message to the console 
declare public OnPlayerDisconnect(playerid:Int, message:String)
declare public OnPlayerUpdate(playerid:Int)
declare public OnPlayerRconIncorrect(playerid:Int)
declare public OnPlayerRconAuthorized(playerid:Int)
declare public OnServerRestart(playerid:Int)
declare public OnPlayerMouseHit(playerid:Int, x:Int, y:Int)
declare public OnPlayerBotConnect(playerid:Int, botid:Int)
declare public OnMapUpdate(delta:Float) // Calling every map update (npcs, doors, events, players, etc...)
declare public OnConnectionResponse(IP:String, Port:String)
declare public OnPlayerDownloadFile(playerid:Int, filename:String, result:Int)
declare public OnPlayerConsole(playerid:Int, text:String)
declare public OnPlayerRequestFiles(playerid)
declare public OnReceiveRawPacket(playerid:Int, bank:Bnk) // bank removing after public execute
// =========================================================== GAME
declare public OnPlayerSpeaking(playerid:Int, data:Bank, radio:Int)
declare public OnPlayerTriggered096(playerid:Int, npcid:Int)
declare public OnPlayerShoot(playerid:Int, x:Float, y:Float, z:Float, angle:Float, pitch:Float)
declare public OnPlayerShootRocket(playerid, x:Float, y:Float, z:Float, angle:Float, pitch:Float)
declare public OnPlayerRequestNewRole(playerid:Int, playertype:Int)
declare public OnPlayerHitPlayer(playerid:Int, hitid:Int, damage:Float, weaponid:Int)
declare public OnPlayerKillPlayer(playerid:Int, killid:Int, weaponid:Int)
declare public OnPlayerActivateFemurBreaker(playerid:Int)
declare public OnPlayerRequestExplosion(playerid:Int, timer:Int)
declare public OnPlayAnnouncement(announcementfile:String)
declare public OnPlayerRequestUnlockExits(playerid:Int)
declare public OnPlayerSpawnItem(playerid:Int, itemid:Int)
declare public OnPlayerTakeItem(playerid:Int, itemid:Int, itemtemplateid:Int)
declare public OnPlayerDropItem(playerid:Int, itemid:Int, itemtemplateid:Int)
declare public OnPlayerClickButton(playerid:Int, doorid:Int, open:Int, locked:Int, UseWithItem:Int=0, code:String="")
declare public OnPlayerRotateLever(playerid:Int, objectid:Int, pitch:Float, yaw:Float, roll:Float)
declare public OnPlayerReleaseSound(playerid:Int, filename:String, volume:Float, dist:Float)
declare public OnPlayerUseItem(playerid:Int, itemid:Int)
declare public OnPlayerUse1162(playerid:Int, itemid:Int, triedtocreatetempid:Int)
declare public OnPlayerRequestNoTarget(playerid:Int)
declare public OnPlayerCreateDecal(playerid:Int)
declare public OnPlayerDropGrenade(playerid:Int, x:Float, y:Float, z:Float, angle:Float, pitch:Float, grenadeType:Int, throwType:int) // grenadetype = weaponid
declare public OnPlayerGetNewRole(playerid, previoustype, newtype)
declare public OnPlayerEscape(playerid, currenttype, previoustype)
declare public OnPlayerEscapeButDead(playerid, currenttype, previoustype)
declare public OnPlayerCuffPlayer(playerid, cuffplayerid)
declare public OnPlayerDeactivateWarheads(playerid)
declare public OnPlayerActivateWarheads(playerid)
declare public OnPlayerSCPContained(playerid, previoustype, newtype) // the return value will replace the sound sent to the players (example: return "SFX\Character\MTF\Announc.ogg") // return "0" won't send anything sound
declare public OnSpawnMTF() // Return value 1 not sending sound to players
declare public OnSpawnChaos() // Return value 1 not sending sound to players
declare public OnActivateWarheads(playerid) // Return value 1 not sending sound to players // If player activate the warheads then playerid != 0
declare public OnDeactivateWarheads(playerid) // If player deactivate the warheads then playerid != 0
declare public OnCreateNPC(npcid:Int)
declare public OnCreateItem(itemid:Int)
declare public OnGenerateWorld() // Return value set map seed while server is starting or restarting*
declare public OnWarheadsExplosion()
declare public OnRoundStarted()
declare public OnItemRefine(setting:String, outputX:Float, outputY:Float, outputZ:Float, itemid:Int, playerid:Int = 0) // Return 0 won't refine item or teleport player // The player also can be refined
declare public OnFillingRoom(roomid, x:Float, y:Float, z:Float, currentroomscale:Float)
//central server
declare ConnectToCentralServer(IP:String, Port:Int) // Adding a central server
declare ReconnectToCentralServer()
// timers
declare CreateTimer(callback:String, interval, loop, params...) // return id
declare RemoveTimer(id)
// rooms
declare GetRoomName:String(roomid:Int)
declare GetRoomEntity:Int(roomid:Int)
declare GetRoomDoor:Int(roomid:Int, doorid:Int)
declare IsValidRoomDoor:Int(roomid:Int, doorid:Int)
declare IsValidRoom:Int(roomid:Int)
// levers
declare GetRoomObjectEntity(roomid:Int, index:Int)
// doors
declare SetDoorCode(doorid:Int, code:String) // code must be in 0000 format
declare GetDoorCode:String(doorid:Int)
declare SetDoorKeycard(doorid:Int, keycard:Int)
declare GetDoorKeycard(doorid:Int)
declare SetDoorOpenState(doorid:Int, bool:Int)
declare SetDoorLock(doorid:Int, bool:Int)
declare GetDoorLock(doorid:Int)
declare GetDoorOpenState(doorid:Int)
declare GetDoorType:Int(doorid:Int) // return d\dir
declare GetDoorEntity:Int(doorid:Int)
declare IsValidDoor:Int(doorid:Int)
// Events
declare CreateEvent(eventname, roomname, id, prob:Float)
declare GetEventState1:Float(eventid:Int)
declare GetEventState2:Float(eventid:Int)
declare GetEventState3:Float(eventid:Int)
declare GetEventStr:String(eventid:Int)
declare SetEventState(eventid:Int, state1:Float, state2:Float, state3:Float)
declare SetEventStr(eventid:Int, str:String)
declare GetEventIndex(eventname:String) // Old (not recommended)
declare GetEventName:String(eventid:Int)
declare GetEventRoomID:Int(eventid:Int)
declare RemoveEvent(eventid:Int)
declare IsValidEvent(eventid:Int)
// NPCs
declare CreateNPC:Int(type:Int) // return id
declare GetNPCState1:Float(npcid:Int)
declare GetNPCState2:Float(npcid:Int)
declare GetNPCState3:Float(npcid:Int)
declare SetNPCState(npcid:Int, state1:Float, state2:Float, state3:Float)
declare GetNPCEvent:Int(npcid:Int)
declare GetNPCEntity:Int(npcid:Int)
declare GetNPCType:Int(npcid:iInt)
declare IsValidNPC(npcid:Int)
// Items
declare CreateItem:Int(itemname:String, itemtempname:String) // return id
declare RemoveItem(itemid:Int)
declare GetItemEntity(itemid:Int)
declare GetItemPicker(itemid:Int)
declare IsValidItem(itemid:Int)
declare GetItemTemplate(itemid:Int)
declare SetItemPicker(playerid:Int, itemid:Int)
declare GetItemTemplateName:String(itemtemplate:Int)
declare GetItemTemplateTempName:String(itemtemplate:Int)
declare CreateItemTemplate(name:String, tempname:String, objpath:String, invimgpath:String, imgpath:String, scale:Float, sound:Int) 
// players
declare IsAFakePlayer:Int(playerid:Int)
declare CreateFakePlayer:Int(name:String) //- return playerid - Tip (You can storage game data by this player)
declare SetPlayerFakeHoldingGun(playerid:Int, HOLDING_GUN:Int)
declare SetPlayerFakeAnimation(playerid:Int, PLAYER_ANIM:Int)
declare SetPlayerFakeHazmat(playerid:Int, hazmat:Int)
declare SetPlayerFakeNVG(playerid:Int, nvg:Int)
declare SetPlayerFakeGasMask(playerid:Int, gasmask:Int)
declare SetPlayerFakeVest(playerid:Int, vest:Int)
declare SetPlayerFakeDeadState(playerid:Int, bool:Int)
declare SetPlayerFakeBlinkTimer(playerid:Int, timer:Float)
declare SetPlayerFakeRadioWave(playerid:Int, bool:Int)
declare SetPlayerFakeHealth(playerid:Int, health:Int)
declare SetPlayerFakeRoom(playerid:Int, roomid:Int)
declare SetPlayerFogRange(playerid:Int, range:Float)
declare SetPlayerPing(playerid:Int, ping:Int)
declare SetPlayerAFK(playerid:Int, AFK:Int)
declare SetPlayerPosition(playerid:Int, roomname:String, X:Float, Y:Float, Z:Float)
declare SetPlayerPositionID(playerid:Int, roomid:Int, X:Float, Y:Float, Z:Float)
declare SetPlayersSpawnPosition(roomname:String, X:Float, Y:Float, Z:Float) // teleporting on client-side
declare SetPlayerMessage(playerid:Int, text:String, delay:Int) //- set Msg for players (text in the middle of the screen)
declare SetPlayerHeadPitch:Float(playerid:Int)
declare SetPlayerVelocity(playerid:int, velocity:Float)
declare SetPlayerSpeedMult(playerid:Int, speedmult:Float)
declare SetPlayerHandcuff(playerid:Int, bool:Int)
declare SetPlayerInjuries(playerid:Int, inj:Float) // works only with fullsynchronization 1
declare SetPlayerMute(playerid, bool:int)

declare SetPlayerSpeedhackMult(playerid, mult:Float) // This will multiple the speedhack_rate
declare GetPlayerSpeedhackMult:Float(playerid) // This will multiple the speedhack_rate
declare SetPlayerNoclip(playerid, bool) // Player won't noclip, but noclip anticheat won't work
declare GetPlayerNoclip(playerid)

declare AddPlayerSpawnPosition(playerid, roomname:String, X:Float, Y:Float, Z:Float) // create spawnpoint for player // return spawnpointer // Removing on player disconnecting
declare AddClassSpawnPosition(RoleType:Int, roomname:String, X:Float, Y:Float, Z:Float) // create spawnpoint for classes // return spawnpointer
declare RemoveSpawnPosition(spawnpointer)
declare IsValidSpawnPosition(spawnpointer)

declare GetPlayerAFK:Int(playerid:Int)
declare GetPlayerNickname:String(playerid:Int)
declare GetPlayerIP:String(playerid:Int)
declare GetPlayerPing:Int(playerid:Int)
declare SetPlayerType(playerid:Int, TYPE_PLAYER:Int) //- set role for player (mp_types.inc)
declare GetPlayerType:Int(playerid:Int) //- get role from player (mp_types.inc)
declare GetPlayerLoadState:Int(playerid:Int)
declare GetPlayerDeadState:Int(playerid:Int)
declare GetPlayerHoldingGun:Int(playerid:Int)
declare GetPlayerRadioWave:Int(playerid:Int)
declare GetPlayerVest:Int(playerid:Int)
declare GetPlayerHazmat:Int(playerid:Int)
declare GetPlayerAnimation:Int(playerid:Int)
declare GetPlayerNVG:Int(playerid:Int)
declare GetPlayerBlinkTimer:Float(playerid:Int)
declare GetPlayerHealth:Int(playerid:Int)
declare GetPlayerRoomID:Int(playerid:Int)
declare GetPlayerReadyState:Int(playerid:Int)
declare GetPlayerVersion:String(playerid:Int)
declare GetPlayerMonitorWidth:int(playerid:Int)
declare GetPlayerMonitorHeight:int(playerid:Int)
declare GetPlayerEntity:Int(playerid:Int)
declare GetPlayerCamera:Int(playerid:Int)
declare GetPlayerHitbox:Int(playerid:Int)
declare GetPlayerHeadPitch:Float(playerid:Int)
declare GetPlayerVelocity:Float(playerid:Int)
declare GetPlayerSteamID(playerid:Int)
declare GetPlayerInjuries(playerid:Int) // works only with fullsynchronization 1
declare GetPlayerZone(playerid)
declare GetPlayerMute(playerid)
declare GetPlayerSpeedMult:Float(playerid:Int)
declare GetPlayerHandcuff:Int(playerid:Int)

declare SetPlayerIntercom:Int(playerid:Int, bool:Int)
declare SetPlayerIntercomUsingTime:Int(playerid:Int, usingTime:Int) // usingtime must be for example: usingtime = MilliSecs()+10000 = 10 seconds // This function change current intercom values in real-time
declare SetPlayerIntercomTimeout:Int(playerid:Int, Timeout:Int) // Timeout must be for example: timeout = MilliSecs()+10000 = 10 seconds // This function change current intercom values in real-time
declare IsPlayerUsingIntercom:Int(playerid:Int)

declare IsPlayerAdmin:Int(playerid:Int) // get admin access
declare IsPlayerConnected:Int(playerid:Int)
declare IsPlayerPatron(playerid:Int)

declare CreatePlayerSound(playerid:Int, filename:String, X:Float, Y:Float, Z:Float, distance:Float, volume:Float)
declare PlaySound(playerid:Int, filename:String) //- playing local sound for player
declare PlayPlayerSound(playerid:Int, filename:String, distance:Float, volume:Float) //- playing sound on player for all players
declare GiveAdmin(playerid:Int) //- give rcon access
declare RemoveAdmin(playerid:Int) //- remove rcon access

declare Kick(playerid:Int, reason:String)
declare BanIP(ip:String)
declare SendMessage(playerid:Int, text:String)
declare PlayerConsoleCommand(playerid:Int, text:String, consolecallback:bool=False) //- execute console command for players ( you can see all commands in SCP CB 1.3.11 source code ) // consolecallback - is player using OnPlayerConsole when get sended console command

declare SendBlinkTimerForPlayer(playerid:Int, timer:Float)
declare ChangePlayerTag(playerid:Int, tag:String, R:Int, G:Int, B:Int) // Max len 255 // Also change color in voice list // Send this to all players so do not abuse
declare ChangePlayerName(playerid:Int, name:String) // Max len 255 // Also change color in voice list // Send this to all players so do not abuse
declare AddVersionAccess(string:Version) // cant work for <0.96 versions
declare public OnCheatDetected(playerid:Int, cheatid:Int)

declare ChangePlayerSize(playerid:Int, size:int) // size must be in 0-65535
declare GetPlayerSize:Float(playerid:Int) // if size = 100 then will return 1.0, if size = 150 then will return 1.5, if size in float = 1.0 then size in int = 100

declare ShouldPlayerAnnouncement(playerid:Int, bool:Int)
declare ChangePlayerSteamID(playerid:Int, steamid:Int)

declare GetPlayerDownloadingCount(playerid) // Get player current SendFile() or SendScript() processes
declare IsPlayerDownloadingFile(playerid, filename:String)
// server

declare ActivateWarheads()
declare DeactivateWarheads()
declare GetBreachTimer()
declare SpawnMTF()
declare SpawnChaos()
declare SetGameState(state:String)
declare SetServerName(name:String)
declare SetServerDescription(name:String)
declare SetServerCurrentBreachTimer(millisecs:Int)
declare SetServerPassword(pass:String)
declare SetServerNocheat(bool:Int)
declare SetNoTarget(bool:Int)
declare SetMTFtimer(value:Float)
declare SetContained106(bool:Int)
declare SetRemoteDoorOn(bool:Int)
declare SetMTFTickets(tickets:Float)
declare SetChaosTickets(tickets:Float)
declare GetMTFTickets:Float()
declare GetChaosTickets:Float()
declare ActivateFilesSending(bool) // Not let players exit from loading menu while files is loading
declare SetServerExplodeTimeout(millisecs:Int)
declare SetServerSpawnTimeout(millisecs:Int) // chaos or mtf
declare GetServerExplodeTimeout()
declare GetServerSpawnTimeout() // chaos or mtf

declare GetIncomingConnectionVersion() // Works only in OnIncomingConnection
declare GetIncomingConnectionPatron() // Works only in OnIncomingConnection

declare SetLightVolume(force:Float)
declare GetLightVolume:Float()

declare CreateSound(filename:String, X:Float, Y:Float, Z:Float, distance:Float, volume:Float)
declare Shoot(X:Float, Y:Float, Z:Float, pitch:Float, yaw:Float, gunID:Int)
declare CreateRocket(X:Float, Y:Float, Z:Float, pitch:Float, yaw:Float)

declare SetMapSeed(seed:String) //- change map seed and restart server
declare RestartServer()
declare DisableAutoKick()
declare DisableLobby() // starting game and never enable lobby (if server restart then enabled DisableLobby() starting game again)
declare RCONCommand(command:String) // Example: RCONCommand("rcon banid steamid")
declare GetServerVersion:String()
declare ServerMessage(text:String)

declare EnableAuthKeyOnConnect(bool) // use auth key for steam client on connect (It's checking for invalid client) (Calling OnBadIncomingConnection if auth key is invalid)
declare EnableOldResponse(bool) // in newer versions when you click on the server, certain data is sent, and in older versions, all data about the server is constantly sent, this function turns on the old system (all data is sent) 

declare SetMaxSpawnPlayers(count) // Set maximum count of players on spawn MTF or Chaos
declare GetMaxSpawnPlayers()

declare SetDescriptionLine(DescriptionId, Text:String) // advanced description // max DescriptionId is 19 (< 0 or > 19 = Memory Access Violation)
declare GetDescriptionLine(DescriptionId)

declare SetCustomMap(filename:String) // Set new custom map, also restarting server


declare EnableNoclipAnticheat(bool)
declare EnableCameraShakeOnDamage(bool)

declare EnableIntercom(bool)
declare SetIntercomTimeout(millisecs)
declare SetIntercomUsingTime(millisecs)

declare SetHalloweenMode(bool)
declare SetChristmasMode(bool)
// Steam
declare CreateSteamInstance(SteamID:Int, Tag:String, R:Int, G:Int, B:Int) // which tag player get on connect
declare RemoveSteamInstance(SteamID:Int) // remove all steam instances for this steamid
declare GetSteamInstanceTag:String(SteamID:Int)
//3D
declare PointAt(x:Float, y:Float, z:Float, xAt:Float, yAt:Float, zAt:Float)
declare PointPitch:Float()
declare PointAngle:Float()

declare Move(x:Float, y:Float, z:Float, xV:Float, yV:Float, zV:Float, angle:Float, pitch:Float) //- (xV = velocity)
declare MoveX:Float()
declare MoveY:Float()
declare MoveZ:Float()

// draws
declare CreatePlayerDraw:Int(playerid:Int, X:Int, Y:Int, width:Int, height:Int, TYPE_DRAW:Int, color:Int, filename:String) //- return DRAW pointer for draw for players - COLOR = HEX VALUE! (mp_gui.inc)
declare SetPlayerDrawPos(playerid:Int, drawpointer:Int, X:Int, Y:Int)
declare SetPlayerDrawColor(playerid:Int, drawpointer:Int, color:Int)
declare RemovePlayerDraw(playerid:Int, drawpointer:Int)
// text
declare CreatePlayerText:Int(playerid:Int, txt:String, X:Int, Y:Int, color:Int, fontname:String, fontsize:Float) //- create TEXT pointer for text draw for players - COLOR = HEX VALUE! (mp_gui.inc)
declare SetPlayerTextPos(playerid:Int, textpointer:Int, X:Int, Y:Int)
declare SetPlayerTextString(playerid:Int, textpointer:Int, txt:String)
declare SetPlayerTextColor(playerid:Int, textpointer:Int, color:Int)
declare RemovePlayerText(playerid:Int, textpointer:Int)
// objects (Removed after restart)
declare CreateObject:Int(modelid:Int, X:Float, Y:Float, Z:Float, range:Float, rawMesh:Int, rawMeshAnimFrames:Int) //- you can edit objects in game - returned object pointer // if range = 0 then objects sending to player always // if you use rawmesh, then you don't need PrepareModelIdentifier for CreateObject in Server scripts (Only player scripts), this also optimize memory using, but some Entity functions won't work properly
declare SetObjectVisibleForPlayer(objectPointer:int, playerid:Int, value:Int)
declare SetObjectInterpolation(objectPointer:Int, Smooth:Int) // smooth 1-255, apply for position and rotate
declare RemoveObject(objectPointer:Int)
declare GetObjectEntity(objectPointer:Int)

declare CreateObjectSound(objectid, filename:String, distance:Float, volume:Float)
declare CreateObjectSoundForPlayer(playerid, objectid, filename:String, distance:Float, volume:Float)

declare PrepareModelIdentifier(ID, filename:String) // Using for CreateObject // Use this also in player scripts 
// Entities edit
declare CreateEntityCamera:Int()
// entities
declare EntityInView:Int(entity, camera)
declare EntityVisible:Int(entity1, entity2)
declare EntityX:Float(entity)
declare EntityY:Float(entity)
declare EntityZ:Float(entity)
declare EntityPitch:Float(entity)
declare EntityYaw:Float(entity)
declare EntityRoll:Float(entity)
declare EntityPick(entity, radius:Float)
declare EntityDistance:Float(entity1, entity2)
declare PointEntity(entity1, entity2) // Rotate entity1 to entity2

declare PositionEntity(entity, x:Float, y:Float, z:float,global=0) // resetentity is required if you dont want collision check
declare RotateEntity(entity, pitch:Float, yaw:Float, roll:float,global=0)
declare MoveEntity(entity, vx:Float, vy:float, vz:Float, IgnoreRotation=False) // velocity
declare ScaleEntity(entity, xyz:Float)
declare RemoveEntity(entity)
declare SetAnimTime(entity, value:Float)
declare SetEntityCollision(entity, bool:Int) // Setting HIT_PLAYER collision type
declare TurnEntity(entity, pitch:Float, yaw:Float, roll:Float)

declare EntityScaleX:Float(entity)
declare EntityScaleY:Float(entity)
declare EntityScaleZ:Float(entity)

//
declare MeshWidth:Float(mesh)
declare MeshHeight:Float(mesh)
declare MeshDepth:Float(mesh)

declare CreateCube:Int()
declare CreateSphere:Int()
declare CreateCylinder:Int()
declare CreateCone:Int()
// entities collision
declare ResetEntity(entity)
declare EntityRadius(entity, x_radius:Float)
declare EntityBox(entity, x:Float, y:Float, z:Float, width:Float, height:Float, depth:Float)
declare EntityCollisionType(entity, collision_type:int, recursive:Int = False) // Collision types in multiplayer_core.inc
declare EntityPickMode(entity, pick_geometry, obscurer:Int) // obscurer default is true
declare EntityCollided(entity, collision_type:int)
declare CountCollisions(entity)
declare CollisionX:Float(entity, index)
declare CollisionY:Float(entity, index)
declare CollisionZ:Float(entity, index)
declare CollisionNX:Float(entity, index)
declare CollisionNY:Float(entity, index)
declare CollisionNZ:Float(entity, index)
declare CollisionEntity:Int(entity, index)
declare GetEntityCollisionType:Int(entity)
//
declare EntityFX(entity, fx)
declare EntityBlend(entity, blend)
declare ShowEntity(entity)
declare HideEntity(entity)
declare GetParent(entity)
declare EntityAutoFade(entity, near:Float, far:Float)
declare EntityColor(entity, Red:Float, Green:Float, Blue:Float)
declare EntityShininess(entity, shininess:Float)
declare EntityAlpha(entity, alpha:Float)
declare EntityTexture(entity, texture, frame = 0, index = 0)
declare EntityParent(entity, parententity)
//texture
declare CreateTexture(width, height, flags, frames) // flags optional = 1 | frames optional = 1
declare LoadTexture(filename:String, flags) // flags optional 1
declare ScaleTexture(texture, u_scale:Float, v_scale:Float) // 
declare TextureWidth:Int(texture)
declare TextureHeight:Int(texture)
//
declare DeltaYaw:Float(entity1, entity2)
declare DeltaPitch:Float(entity1, entity2)
// sprites
declare CreateSprite()
declare LoadSprite(filename:String, tex_flag)
declare SpriteViewMode(sprite, view_mode)
declare ScaleSprite(sprite, x_scale:Float, y_scale:Float)
//

// advanced
declare SendFile(playerid:Int, filepath:String, savepath:String, compresspower=0) // Sending a file to player. // compresspower can be 1-9
declare SendRawData:Int(playerid:Int, data:Packet, bnk:Bank, offset, count) // you can send only GetPacketIndex()
declare SendRawPacket:Int(playerid:Int, bnk:Bank) // sending to player and player receive it in "OnPlayerReceiveRawPacket" (limit 8189 bytes)
declare GetPacketIndex(packet:String) // return packet index for SendRawData() : "voice"

declare ServerWriteByte(value:Int)
declare ServerWriteShort(value:Int)
declare ServerWriteInt(value:Int)
declare ServerWriteFloat(value:Float)

declare CreateError(Error:String) // Adding error to server error messages (Detected error)
declare hexstring:Int(s:String) // Convert String to hex strings
declare plugin_load:Int(pluginname:String)
declare plugin_call:Int(pluginid, functionname:String, returntype:Int) // Execute function from plugin (.dll) and return function returned value
declare plugin_poke(pluginid, value:String, valuetype:Int) // Poke values for function execution // Strings put only information, no final bytes like Chr(13) or byte = 0

// IF YOU DONT WANT USE PLUGIN_LOAD FUNCTIONS
// i use this functions because blitz3d doesn't support loadlibrary
// you can write wrapper and use this functions from wrapper (wrapper library name must be ScriptLib.dll and functions must be B3DPlugin_paramscount)
// using blitz3d decls
LibName:"ScriptLib.dll";FunctionName:_B3DPlugin_0@0 : EXPORT_DLL(const char*) B3DPluginString_0() // For example
LibName:"ScriptLib.dll";FunctionName:_B3DPlugin_1@4 : EXPORT_DLL(const char*) B3DPluginString_1(const char* param1) // For example
LibName:"ScriptLib.dll";FunctionName:_B3DPlugin_2@8 : EXPORT_DLL(const char*) B3DPluginString_2(const char* param1, const char* param2) // For example
etc..
.
// decls in blitz3d source code:
DllFunctionVoid_0():"_B3DPluginVoid_0@0"
DllFunctionVoid_1(param1$):"_B3DPluginVoid_1@4"

// your export name inside .dll must be _B3DPluginVoid_1@4 for example

// C++ Example:
 #define CMDLIB(x) extern "C" __declspec(dllexport) x _stdcall
 //FROM:
CMDLIB(int) ConsoleMessage(const char* message, int color)
{
    SetConsoleTextAttribute(stdhandle, color);
    std::cout << message << "\n";
    return 8;
}
 //TO:
CMDLIB(int) B3DPluginInt_2(const char* message, const char* color)
{
    SetConsoleTextAttribute(stdhandle, atoi(color));
    std::cout << message << "\n";
    return 8;
}

declare DllFunctionVoid_0() // then export_dll(void) b3dpluginstring_ . . .
declare DllFunctionVoid_1(param1:String = "")
declare DllFunctionVoid_2(param1:String = "",param2:String = "")
declare DllFunctionVoid_3(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionVoid_4(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionVoid_5(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionVoid_6(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionVoid_7(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionVoid_8(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionVoid_9(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")

declare DllFunctionInt_0:Int() // then export_dll(int) b3dpluginint_ . . .
declare DllFunctionInt_1:Int(param1:String = "")
declare DllFunctionInt_2:Int(param1:String = "",param2:String = "")
declare DllFunctionInt_3:Int(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionInt_4:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionInt_5:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionInt_6:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionInt_7:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionInt_8:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionInt_9:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")

declare DllFunctionFloat_0:Float() // then export_dll(float) b3dpluginfloat_ . . .
declare DllFunctionFloat_1:Float(param1:String = "")
declare DllFunctionFloat_2:Float(param1:String = "",param2:String = "")
declare DllFunctionFloat_3:Float(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionFloat_4:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionFloat_5:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionFloat_6:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionFloat_7:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionFloat_8:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionFloat_9:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")

declare DllFunctionString_0:String() // then export_dll(const char*) b3dpluginstring_ . . .
declare DllFunctionString_1:String(param1:String = "")
declare DllFunctionString_2:String(param1:String = "",param2:String = "")
declare DllFunctionString_3:String(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionString_4:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionString_5:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionString_6:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionString_7:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionString_8:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionString_9:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")


declare getunixtime:Int()
declare getdate:String()
declare gettime:String()

declare Zlib_Compress(bnk:Bank, PackPower:Int) // return new bank // PackPower 1-7, default and fast is 1
declare Zlib_UnCompress(bnk:Bank, fullsize:Int) // return new bank

declare ReloadApp() // Closed server app and starting again.
declare CloseApp() // Closed server app

// INI
declare GetINIValue:String(file:String, section:String, key:String, defaultreturnvalue:String)
declare PutINIValue(file:String, section:String, key:String, value:String)
declare UpdateINIFile(file:String) // Recommended to use after PutINIValue

	//example:
		//local USPDamage = int(GetINIString("ServerConfig\game.ini", "usp", "damage", "1"))
		//print("USP damage: "+USPDamage)
		//PutINIValue("ServerConfig\game.ini", "usp", "damage", "20") // change usp damage value to 20
		//UpdateINIFile("ServerConfig\game.ini")
		
// mysql
		// Return StreamID
		// 	hostname - IP-address or domain of SQL server
		// 	port - port of SQL Server (default is 3306)
		// 	user - username for access to SQL server
		//	password - password for access to SQL server
		// 	database - database name
		// 	flag - type of SQL server (default is 1)
		declare OpenSQLStream:Int(hostname:String, port:Int, user:String, password:String, database:String, flag:Int)
		//
		declare SQLConnected:Int(streamId:Int)
		declare SQLQuery:Int(streamId:Int, query:String) // return queryId
		declare SQLRowCount:Int(queryId:Int)
		declare SQLFetchRow:Int(queryId:Int)
		declare SQLFieldCount:Int(queryId:Int)
		declare ReadSQLField:String(rowId:Int, fieldName:String)
		declare ReadSQLFieldIndex:String(rowId:Int, fieldIndex:Int)
		declare FreeSQLQuery(queryId:Int)
		declare FreeSQLRow(rowId:Int)
		declare CloseSQLStream(streamId:Int) // Closing streamid
		
// sqlite3
	
		declare OpenDatabase(Filename:String, OpenMode, MakeCurrent, ErrorsAreFatal)

		// The database will fail to close if there are SQL statements that
		// have been prepared but not finalised.
		declare CloseDatabase(DatabaseHandle, ErrorsAreFatal)

		// Not required for single user use - TimeOutInMilliSecs = 0 removes timeout
		declare SetDatabaseTimeout(TimeOutInMilliSecs, DatabaseHandle, ErrorsAreFatal)

		declare DatabaseVersion:String()

		// Gets the ID (either the value of the primary key column if there is
		// one, or the internal ID) of the last row inserted into the database.
		declare LastRowIDInserted(DatabaseHandle)

		// Gets the number of rows changed by the last SQL statement run.
		declare RowsChangedByLastStatement(DatabaseHandle)

		// Gets the number of rows changed since the database was opened.
		declare RowsChangedThisSession(DatabaseHandle)

		// The database is always in AutoCommitMode unless you're in the middle of a
		// SQL statement that defines it's own transactions with BEGIN, COMMIT and ROLLBACK.
		declare AutoCommitIsOn(DatabaseHandle)

		// Begins a new transaction.
		declare BeginTransaction(DatabaseHandle, ErrorsAreFatal)

		// Commits the current transaction.
		// If KeepTransactionOpen then it immediately begins a new transaction
		// for you. This is handy if you're commiting in the middle of a large batch
		// of updates but you're not finished yet.
		declare CommitTransaction(KeepTransactionOpen, DatabaseHandle, ErrorsAreFatal)

		// Rolls back the current transaction.
		declare RollbackTransaction(DatabaseHandle, ErrorsAreFatal)

		// If you call any of the declares with ErrorsAreFatal = false and
		// they fail (return 0, "" or false) you can find out what the error
		// code and error message were by calling LastDatabaseErrorCode and
		// LastDatabaseErrorMessage.

		declare LastDatabaseErrorCode(DatabaseHandle)

		declare LastDatabaseErrorMessage:String(DatabaseHandle)

		// Cancels the currently executing SQL. I'd imaging it also rolls back
		// transactions, but the SQLite documentation doesn't say.
		// Note that any prepared SQL will be unusable after this.
		declare InterruptDatabase(DatabaseHandle)

		// Executes the supplied SQL statement but cannot return any results
		// Handy for things like CREATE TABLE, INSERT, UPDATE and DELETE
		declare ExecuteSQL(SQL:String, DatabaseHandle, ErrorsAreFatal)

		// Prepares a SQL statement ready for you to retrieve the data.
		declare PrepareSQL(SQL:String, DatabaseHandle, MakeCurrent, ErrorsAreFatal)

		// Moves to the next row (or first if it's not been called yet for the
		// SQL statement) in the result set of the SQL statement. You can then
		// use the GetColumn???? declares to retrieve the values.
		// If AutomaticallyFinalise is true (the default) then the SQL statement
		// will be automatically finalised when the end of the result set is
		// reached, otherwise you'll have to call FinaliseSQL yourself.
		declare GetNextDataRow(StatementHandle, AutomaticallyFinalise, ErrorsAreFatal)

		// Closes a prepared SQL statement - the database won't close if there
		// are un-finalised SQL statements.
		declare FinaliseSQL(StatementHandle, ErrorsAreFatal)

		// Resets the SQL statement so that data reading (with
		// GetNextDataRow) starts back at the beginning again of the
		// result set.
		// Shouldn't really be combined with the AutomaticallyFinalise
		// parameter of GetNextDataRow as resetting a finalised
		// statement doesn't work.
		declare ResetSQL(StatementHandle, ErrorsAreFatal)

		// Checks to see if the SQL statement has expired (needs to be
		// re-prepared). According to the SQLite docs expiration only usually
		// occurs in circumstances which aren't allowed by this wrapper
		// (ie. some of the more advanced declares which Blitz can't use)
		// so this shouldn't really be required.
		declare SQLHasExpired(StatementHandle)

		// Returns the handle of the database that was used to prepare the
		// SQL statement.
		declare GetDatabaseHandleFromStatementHandle(StatementHandle)

		// Returns the number of columns in the SQL statement's result set.
		declare GetColumnCount(StatementHandle)

		// In the following declares ColumnIndex is zero based.
		// Ie. the first column is 0, the second is 1, etc.

		// Returns the name of the specified of column in the SQL statement's result set.
		declare GetColumnName:String(ColumnIndex, StatementHandle)

		// Returns the type of the specified column in the SQL statement's result set.
		// Returns the type as an integer which you can then compare to the SQLITE_INTEGER,
		// SQLITE_FLOAT, SQLITE_STRING constants.
		declare GetColumnType(ColumnIndex, StatementHandle)

		// Returns the type of the specified column in the SQL statement's result set.
		// Returns the type as a string.
		declare GetColumnDeclaredType:String(ColumnIndex, StatementHandle)

		// Returns the amount of space used to store the column's contents (in bytes).
		declare GetColumnSize(ColumnIndex, StatementHandle)
			
		// In the following declares if the column is actually of a different
		// type to that requested SQLite does its best to convert the contents.

		// Returns the column's contents as an integer.
		declare GetColumnValueAsInteger(ColumnIndex, StatementHandle)

		// Returns the column's contents as a float.
		declare GetColumnValueAsFloat:Float(ColumnIndex, StatementHandle)


		// Returns the column's contents as a string.
		declare GetColumnValueAsString:String(ColumnIndex, StatementHandle)


		// Never tried this - should return the handle to the blob, no idea how to use it though
		declare GetColumnValueAsBlob(ColumnIndex, StatementHandle)

		// SQLite support paramaterised SQL. Parameters can be specified as "?",
		// ":Example" or ":StringExample".
		// See: http://www.sqlite.org/capi3ref.html#sqlite3_bind_blob
		// for more details on parameter naming and binding.

		// Returns the number of parameters in the SQL statement.
		declare SQLParameterCount(StatementHandle)


		// Returns the name of the specified parameter in the SQL statement.
		// Parameters defined as "?" don't have names.
		declare SQLParameterName:String(ParameterIndex, StatementHandle)

		// Returns the index of the parameter with the specified name in the SQL statement.
		declare SQLParameterIndex(ParameterName:String, StatementHandle)

		// Set the specified parameter to null.
		declare BindSQLParameterAsNull(ParameterIndex, StatementHandle)
			

		// Set the specified parameter to the supplied integer value.
		declare BindSQLParameterAsInteger(ParameterIndex, Value, StatementHandle)

		// Should set the specified parameter to the supplied float value.
		// Unfortunately it doesn't seem to work.
		declare BindSQLParameterAsFloat(ParameterIndex, Value:Float, StatementHandle)

		// Set the specified parameter to the supplied string value.
		declare BindSQLParameterAsString(ParameterIndex, Value:String, StatementHandle)

		// Never tried this - no idea if it works or not
		declare BindSQLParameterAsBlob(ParameterIndex, BlobHandle, LengthOfBlob, StatementHandle)


		// Transfers the bindings from one SQL statement to another.
		// Useful I guess if you want to run multiple SQL statements with
		// the same bindings.
		declare TransferSQLBindings(StatementHandle1, StatementHandle2)

		// Just a declare used internally to handle fatal errors.
		declare SQLite3_ErrorHasOccurred(declareName:String, ErrorsAreFatal, Message:String)
//=============================================================================================================



//	plugins:
//		you have to write a ".dll" for these plugins yourself, because the "Blitz3D" doesnt support LoadLibrary()
//		this plugins using CallDLL Blitz3D function
//
//
		plugin_load:Int(pluginname:String) - Init plugin and return integer plugin value
		plugin_call:Int(pluginid, functionname:String, returnType) - 
// 		
//			pluginid - plugin id, returned by plugin_load()
//			functionname:String - plugin function name
//			returnType - P_TYPE Consts - type which plugin function return (byte, short...)
//		Example:
			local console = plugin_load("ConsoleLib.dll")
			plugin_call(console, "_CreateConsole@4", 0) // creating
			plugin_poke(console, "just message", P_TYPE_STRING) // add message
			plugin_poke(console, "just message", P_TYPE_STRING) // add color
/			plugin_call(console, "_ConsoleLog@8", 0) // call function with added poke data without return type

// ====================================================================================================================================================== PLAYERS SCRIPT

// In-game scripts transmitted to the player via the server and activated on player PC and delete script file. (Not recommended to use this, because it wastes fps in the game, but full recommended for full synchronization)
// You cant use Server functions in Player scripts

// server
declare SendScript(playerid, filename:String, savepath:String) // You need compiled script to use this. // callback - OnPlayerReceiveFile

// game

// NOTE:
// PREDIRECTIVE #PLAYERSCRIPT // ACCESS TO ALLOW EXECUTING FUNCTIONS IN MAIN BLOCK
// you need add this to first line of script
// #PLAYERSCRIPT
// or
// #playerscript

//blitz3d functions
declare OpenFile:Int(filename:String) //- return stream (open only in "multiplayer" folder)
declare WriteFile:Int(filename:String) //- return stream (writing only in "multiplayer" folder)
declare ReadFile:Int(filename:String) //- return stream (reading only in "multiplayer" folder)
declare CloseFile(stream:Int)
declare WriteLine(stream:Int, text:String)
declare WriteFloat(stream:Int, value:Float)
declare WriteInt(stream:Int, value:Int)
declare WriteShort(stream:Int, value:Int)
declare WriteByte(stream:Int, value:Int)
declare ReadLine:String(stream:Int)
declare ReadFloat:Float(stream:Int)
declare ReadInt:Int(stream:Int)
declare ReadShort:Int(stream:Int)
declare ReadByte:Int(stream:Int)
declare Chr:String(asc)
declare Asc:Int(chr:String)

declare FileType:Int(filename:String) // Checking only in "multiplayer" folder
declare FileSize:int(filename:String) // Checking only in "multiplayer" folder

declare SeekFile(filehandle, pos)
declare FilePos:Int(filehandle)
declare WriteBytes(bank,stream,offset,count)
declare ReadBytes(bank,stream,offset,count)

declare MilliSecs:Int()
declare Delay:Int()
declare Left:String(str:String, offset:Int)
declare Right:String(str:String, offset:Int)
declare Instr:Int(str:String, strcheck:String, offset:Int)
declare Len:Int str:String // without () its a keyword
declare Int:Int(value:String)
declare Str:Str(value:String)
declare Float:Float(value:String)

#define :Bank :Int

declare CreateBank:Int(size)
declare FreeBank(bank)
declare BankSize:Int(bankHandle)
declare ResizeBank(bankhandle,new_size)
declare CopyBank(src_bank,src_offset,dest_bank,dest_offset,count)
declare PeekByte:Int(bank,offset)
declare PeekShort:Int(bank,offset)
declare PeekInt:Int(bank,offset)
declare PeekFloat:Float(bank,offset)

declare PokeByte(bank,offset,value)
declare PokeShort(bank,offset,value)
declare PokeInt(bank,offset,value)
declare PokeFloat(bank,offset,value:Float)
//
declare public OnUpdate() // activated per frame
declare public OnRenderWorld() //
declare public OnDead()
declare public OnSpawn()
declare public OnSendMessage(message:String)
declare public OnConsole(message:String)
declare public OnDisconnect(message:String)
declare public OnPressUIButton(x, y, width, height, txt:String) // Doesn't work with DrawUIButton(...) // Only works with original game buttons // return 0 will block pressing
declare public OnReceivedFile(filename) // in multiplayer\serversdata\
// timers
declare CreateTimer(callback:String, interval, loop, params...) // return id
declare RemoveTimer(id)
//
declare SetRadio(wave)
declare SetAmbientLight(r,g,b)
declare CameraFogColor(r,g,b)
declare CameraClsColor(r,g,b)
declare CameraRange(camera, near, far)
declare CameraFogRange(camera, near, far)
declare HideScreenOcclusion()
declare ShowScreenOcclusion()
declare GetSelectedScreen() // bool
declare ResetSelectedScreen()
declare HideSky()
declare ShowSky()
declare GetRoomName:String()
declare SetCameraShake(shake:Float)
declare ShowPointer()
declare HidePointer()

declare ChangeRoomMesh(roomname:String, newpath:String) // use this ONLY in started game.


declare SendMessage(message:String, local:Int)
declare SendConsoleCommand(message:String)
declare LoadAnimMesh(filename:String) // return entity
declare LoadMesh(filename:String) // return entity
declare CreatePivot() // return entity
// float
declare PointAt(x:Float, y:Float, z:Float, xAt:Float, yAt:Float, zAt:Float)
declare PointPitch:Float()
declare PointAngle:Float()

declare Move(x:Float, y:Float, z:Float, xV:Float, yV:Float, zV:Float, angle:Float, pitch:Float) //- (xV = velocity)
declare MoveX:Float()
declare MoveY:Float()
declare MoveZ:Float()
//players
declare IsPlayerConnected(playerid)
// player
declare GetPlayerCollider()
declare GetPlayerCamera()
declare SetPlayerRoom:Int(roomname:String) // return id
// entities
declare EntityInView:Int(entity, camera)
declare EntityVisible:Int(entity1, entity2)
declare EntityX:Float(entity)
declare EntityY:Float(entity)
declare EntityZ:Float(entity)
declare EntityPitch:Float(entity)
declare EntityYaw:Float(entity)
declare EntityRoll:Float(entity)
declare EntityPick(entity, radius:Float)
declare EntityDistance:Float(entity1, entity2)
declare PointEntity(entity1, entity2) // Rotate entity1 to entity2

declare PositionEntity(entity, x:Float, y:Float, z:float,global=0) // resetentity is required if you dont want collision check
declare RotateEntity(entity, pitch:Float, yaw:Float, roll:float,global=0)
declare MoveEntity(entity, vx:Float, vy:float, vz:Float, IgnoreRotation=False) // velocity
declare ScaleEntity(entity, xyz:Float)
declare RemoveEntity(entity)
declare SetAnimTime(entity, value:Float)
declare SetEntityCollision(entity, bool:Int) // Setting HIT_PLAYER collision type
declare TurnEntity(entity, pitch:Float, yaw:Float, roll:Float)

declare EntityScaleX:Float(entity)
declare EntityScaleY:Float(entity)
declare EntityScaleZ:Float(entity)


//
declare MeshWidth:Float(mesh)
declare MeshHeight:Float(mesh)
declare MeshDepth:Float(mesh)

declare CreateCube:Int()
declare CreateSphere:Int()
declare CreateCylinder:Int()
declare CreateCone:Int()
// entities collision
declare ResetEntity(entity)
declare EntityRadius(entity, x_radius:Float)
declare EntityBox(entity, x:Float, y:Float, z:Float, width:Float, height:Float, depth:Float)
declare EntityCollisionType(entity, collision_type:int, recursive:Int = False) // Collision types in multiplayer_core.inc
declare EntityPickMode(entity, pick_geometry, obscurer:Int) // obscurer default is true
declare EntityCollided(entity, collision_type:int)
declare CountCollisions(entity)
declare CollisionX:Float(entity, index)
declare CollisionY:Float(entity, index)
declare CollisionZ:Float(entity, index)
declare CollisionNX:Float(entity, index)
declare CollisionNY:Float(entity, index)
declare CollisionNZ:Float(entity, index)
declare CollisionEntity:Int(entity, index)
declare GetEntityCollisionType:Int(entity)
//
declare EntityFX(entity, fx)
declare EntityBlend(entity, blend)
declare ShowEntity(entity)
declare HideEntity(entity)
declare GetParent(entity)
declare EntityAutoFade(entity, near:Float, far:Float)
declare EntityColor(entity, Red:Float, Green:Float, Blue:Float)
declare EntityShininess(entity, shininess:Float)
declare EntityAlpha(entity, alpha:Float)
declare EntityTexture(entity, texture, frame = 0, index = 0)
declare EntityParent(entity, parententity)
//texture
declare CreateTexture(width, height, flags, frames) // flags optional = 1 | frames optional = 1
declare LoadTexture(filename:String, flags) // flags optional 1
declare ScaleTexture(texture, u_scale:Float, v_scale:Float) // 
declare TextureWidth:Int(texture)
declare TextureHeight:Int(texture)
//
declare DeltaYaw:Float(entity1, entity2)
declare DeltaPitch:Float(entity1, entity2)
// sprites
declare CreateSprite()
declare LoadSprite(filename:String, tex_flag)
declare SpriteViewMode(sprite, view_mode)
declare ScaleSprite(sprite, x_scale:Float, y_scale:Float)
// Chromium
declare browser_Create(width, height, url:String)
declare browser_Destroy(browserid) // Use this in OnDisconnect please
declare browser_GetImage(browserid) // you need use drawimage(browser_GetImage(browserid)) everytime
declare browser_GetTexture(browserid) // you need use EntityTexture(entity, browser_GetTexture(browserid)) everytime
declare browser_SetMousePos(browserid, x, y)
declare browser_MouseDown(browserid)
declare browser_MouseUp(browserid)
declare browser_LoadURL(browserid, URL:String, postData:String)

declare PrepareModelIdentifier(ID, filename:String) // Using for CreateObject in server scripts

// sounds
declare CreateSound3D(filename:String, X:Float, Y:Float, Z:Float, distance:Float, volume:Float)
declare CreateLocalSound(filename:String, volume:Float)
declare Stop3DSounds()
declare StopChannel(channel)
declare ResumeChannel(channel)
declare PauseChannel(channel)
declare ChannelPlaying(channel)
declare ChannelVolume(Channel, volume:Float)
declare ChannelPan(Channel, pan:Float)
declare ChannelPitch(channel, pitch)

// mouse
declare MouseX()
declare MouseY()
declare MouseHit1()
declare MouseHit2()
declare MouseDown1()
declare MouseDown2()

declare SetMouseHit1(bool)
declare SetMouseDown1(bool)
// keys
declare KeyDown(id)
declare KeyHit(id)
declare GetKey() // get pressed key // For Chr or Hex
// drawing // you have to use drawing in OnUpdate(), because each frame erases what was drawn
declare color(r,g,b)
declare loadimage(filename:String)
declare copyimage(image)
declare loadanimimage(filename:String, width, height, first, count)
declare drawimage(img:Int, x, y, frame) // frame for anim image (default is 0)
declare drawblock(img:Int, x, y, frame) // frame for anim image (default is 0) // black pixels drawing
declare rotateimage(image,value:Float) // 0-360 degress in value:Float
declare handleimage(image,x,y) // image offset
declare resizeimage(image, width, height)
declare scaleimage(image, x:Float, y:Float) // 100% = 1.0, 200% = 2.0, 50% = 0.5
declare imagewidth(image)
declare imageheight(image)
declare oval(x, y, width, height, solid)
declare rect(x, y, width, height, solid)
declare loadfont(fontname:String,size:Int,bold,italic,underlined)
declare setfont(font)
declare text(x, y, txt, centerx, centery)
declare formattext(x, y, txt, centerx, centery, alpha:Float, withshadow=0) // take % functions from advanceddescription (not all)
declare stringwidth(txt)
declare stringheight(txt)
declare DrawUIButton(x, y, width, height, txt:String, bigFont:Int, waitForMouseUp:Int)
declare DrawUIInputBox:String(x, y, width, height, currentinputboxtext:String, InputBoxID:Int) // return current inputbox text
// please delete everything you created in the "OnDisconnect" callback
declare freefont(font)
declare freeimage(img)
// states
declare Get427Timer:Float()
declare GetBlurTimer:Float()
declare GetStamina:Float()
declare GetBlinkTimer:Float()
declare GetCurrentWeapon:Int()
declare GetCurrentWeaponMagazines()
declare GetCurrentWeaponAmmo()
declare GetCurrentSpectatePlayer() // return -1 if not spectating
// events
declare CreateEvent(eventname, roomname, id, prob:Float)
//items (MAX_ITEMS = 1000)
declare IsValidItem(itemid:Int)
declare GetItemTemplate:Int(itemid) // ID
declare GetSelectedItem:Int() // ID
declare GetItemName:String(itemid:Int)
declare GetItemTempName:String(itemid:Int)
declare GetItemState:Float(itemid:Int)
declare GetInventorySlotItemName:String(slot)
declare SetSelectedItemFromInventory(slot)
declare CreateItemTemplate(name:String, tempname:String, objpath:String, invimgpath:String, imgpath:String, scale:Float, sound:Int) // return template id // THIS MUST BE IN OnInitItemTemplates() if this is a workshop script, or in first line of script if this is a player script sended by SendScript()
declare public OnInitItemTemplates()
declare public OnUsingItem(itemid) // return 1 will allow you to hold the item in your hands, return 0 will not.
// objects
declare IsValidObject:Int(objectid)
declare GetObjectEntity:Int(objectid)
// other
declare disconnect(message:String)
declare connect(ip:String, port, password:String)
declare setgamemessage(msg:String, interval:int) // in seconds
declare getversion:String()
declare getping:Int()
declare getname:String()
declare getdelta:Float()
declare getmonitorwidth:Int()
declare getmonitorheight:Int()
declare getvolume:Float()
declare getfov:Float()
declare getservertimeout:Int() // If this value is < 1 then server is not responding
declare caninteract:Int() // if esc menu or hand icon or inventory or keypad etc... not opened
declare ismenuopen:Int()
declare isinventoryopen:Int()
declare isotherinventoryopen:Int()
declare getoptionsmenu:Int()
declare getachievementsmenu:Int()
declare iskeypadopen:Int() 
declare isconsoleopen:Int()
declare iscoffeemachineopen:Int() // scp-294
declare ismainmenuopen:Int() // if game started then returned 0 else returned 1
declare gettabmenu:Int()

declare lerp:Float(ToValue:Float, CurrentValue:Float, Smooth:Float, IgnoreSmoothing = False) // Using only every frame like in OnUpdate callback
declare lerpangle:Float(ToAngle:Float, CurrentAngle:Float, Smooth:Float, IgnoreSmoothing = False) // Using only every frame like in OnUpdate callback

declare lockmouse(bool) // blocking moving and mouse moving // better using with ShowPointer()

// call functions and example
	declare callfunction:String(callback:String, params...) // Calling functions in current script
	declare callglobalfunction:String(scriptfilename:String, callback:String, params...) // Finding and call functions in selected script (Can't call in not loaded)

//	Example:
		public def somepublic(c, c2)
			//code
			print(message)
			return int(c)+int(c2)
		end
		result = callfunction("somepublic", 23, 1)
		print(result)
	
// --------------------------------------------------------------------

// advanced (Plugins is removed due to insecurity)
declare plugin_load:Int(pluginname:String)
declare plugin_call:Int(pluginid, functionname:String, returntype:Int) // Execute function from plugin (.dll) and return function returned value
declare plugin_poke(pluginid, value:String, valuetype:Int) // Poke values for function execution

declare CatchError:String() // return current error
//
declare public OnReceiveRawPacket(bank) // bank removing after public execute
declare SendRawPacket(bnk:Bank) // sending to server and server receive it in "OnReceiveRawPacket" (limit 8189 bytes)

// -------------------------------------------------------------------- For workshop

// Instruction for workshop:
// The scripts files must be in workshop folder with script folder, example: workshop\yourscript\file.gs. You can put as many scripts as you like in the yourscript folder. They will all load
//
declare RedirectSound(file:String, newfile:String, killonexit:bool) // use killonexit if script isn't a workshop script // better use for player scripts sended by server.
declare RedirectFont(OriginalFile:String, WorkshopFont:String) // More comfort // Example: RedirectFont("GFX\fonts\cour\Courier New Rus.ttf", "Tahoma")
declare RedirectFile(OriginalFile:String, WorkshopFile:String) // Example: RedirectFile("SFX\General\BodyFall.ogg", "workshop\yourscript\sounds\BillyHerrington.ogg") // Redirecting original sound to your sound.
declare RedirectText(OriginalText:String, WorkshopText:String) // Example: RedirectText("MULTIPLAYER", "МУЛЬТИПЛЕЕР") // Changing source text to your text (use to translate) // NEED ANSI ENCODER
declare StopRedirectText(OriginalText:String) // Removing RedirectText, use in ondisconnect()
declare StopAllRedirectText()
declare InitLoadingScreens(loadingscreensfile:String)
declare InitInfoClues(cluesfile:String)
declare public OnClickWorkshopLanguage()
declare ReloadFonts()

// All this functions ^^^ return true if successfull, return false is not successfull
declare public OnLoadingFonts() // CALLING ONE TIME!!!
declare public OnLaunchGame() // Some functions doesnt work before this public, example get monitor heights

// for servers:
declare DisableAllWorkshopScripts()

// ================================================================================================================ Overall functions between player and server scripts (Not all)

//blitz3d function
declare OpenFile:Int(filename:String) //- return stream
declare WriteFile:Int(filename:String) //- return stream
declare ReadFile:Int(filename:String) //- return stream
declare CloseFile(stream:Int)
declare WriteLine(stream:Int, text:String)
declare WriteFloat(stream:Int, value:Float)
declare WriteInt(stream:Int, value:Int)
declare WriteShort(stream:Int, value:Int)
declare WriteByte(stream:Int, value:Int)
declare ReadLine:String(stream:Int)
declare ReadFloat:Float(stream:Int)
declare ReadInt:Int(stream:Int)
declare ReadShort:Int(stream:Int)
declare ReadByte:Int(stream:Int)
declare Chr:String(asc)
declare Asc:Int(chr:String)

declare FileType:Int(filename:String)
declare FileSize:int(filename:String)

declare SeekFile(filehandle, pos)
declare FilePos:Int(filehandle)
declare WriteBytes(bank,stream,offset,count)
declare ReadBytes(bank,stream,offset,count)

declare MilliSecs:Int()
declare Delay:Int()
declare Left:String(str:String, offset:Int)
declare Right:String(str:String, offset:Int)
declare Instr:Int(str:String, strcheck:String, offset:Int)
declare Len:Int(str:String)
declare Int:Int(value:String)
declare Str:Str(value:String)
declare Float:Float(value:String)

#define :Bank :Int

declare CreateBank:Int(size)
declare FreeBank(bank)
declare BankSize:Int(bankHandle)
declare ResizeBank(bankhandle,new_size)
declare CopyBank(src_bank,src_offset,dest_bank,dest_offset,count)
declare PeekByte:Int(bank,offset)
declare PeekShort:Int(bank,offset)
declare PeekInt:Int(bank,offset)
declare PeekFloat:Float(bank,offset)

declare PokeByte(bank,offset,value)
declare PokeShort(bank,offset,value)
declare PokeInt(bank,offset,value)
declare PokeFloat(bank,offset,value:Float)
declare CatchError:String() // return current error

// call functions and example
	declare callfunction:String(callback:String, params...) // Calling functions in current script
	declare callglobalfunction:String(scriptfilename:String, callback:String, params...) // Finding and call functions in selected script (Can't call in not loaded)
//	Example:
		public def somepublic(c, c2)
			//code
			print(message)
			return int(c)+int(c2)
		end
		result = callfunction("somepublic", 23, 1)
		print(result)

//

declare TCP_Get(webFile:String) // Return TCPhandle where you can read by ReadLine(tcphandle), ReadInt, float . . .
declare TCP_Close(tcphandle)
	//example:
		def GetInformation()
			tcphandle = TCP_Get("http://host.com/File.txt")
			if tcphandle != 0 then
				local info = ReadLine(tcphandle)
				TCP_Close(tcphandle) // Closing TCP stream
				return info
			end
		end
	//
// ====================================================================== Custom roles (Very hard)

// In player scripts you can put this in first lines of script
// In server scripts you need to put this in OnServerRestart() and OnServerStart()

declare breachrole_CreatePlayerRole:Int(name:String, model:Int, modelscale:Float, texture:String, r, g, b, hp=0) // model(loadanimmesh), model and modelscale can be 0.0 in server scripts, because server using only hitboxes
declare breachrole_GetRoleName:String(roleid)
declare breachrole_SetRoleSettings(roleid, allowupdate, attacktype, attackinterval, attackradius:Float, haveattacksound, sound:String, soundinterval, randomsounds=0) // allowupdate(allow role to use SCP updating), attacktype(1- damage, 2-force kill), sound(RMB sound), randomsounds( if a sound has few sounds, then randomize from 0 to selected value, (Example0.ogg, Example1.ogg. . .) )
declare breachrole_SetRoleEffects(roleid, cameraoffset:Float, boneheadrolloffset:Float, boneheadyawoffset:Float, flipboneheadpitch, allowjump, usualsprint, disablecrouch, disablegodmode, disableinjuries, disablesprint) // cameraoffset(the player camera Y axis offset), usualsprint(zombies have usual sprint, but other scps have short sprint)
declare breachrole_SetRoleAmbientSound(roleid, animationid, sound:String) // If a player playing selected animationid, then players hearing a selected sound
declare breachrole_SetRoleInstruction(roleid, txt:String)
declare breachrole_SetRoleDeadAnimation(roleid, FirstFrame, EndFrame)
declare breachrole_SetRoleBone(roleid, boneid, name:String)
declare breachrole_SetRoleAnimation(roleid, animationid, FirstFrame, EndFrame, Speed:Float)
declare breachrole_SetRoleArmedAnimation(roleid, animationid, FirstFrame, EndFrame, Speed:Float) // Animation while holding a gun
declare breachrole_MarkAsFriend(roleid, friendrole, bool)
declare breachrole_RoleTakeRoleSpawn(myrole, roleid)
declare breachrole_SetRolePositionsOffset(roleid, FixPivot:Float, FixRotate:Float, FixPitch:Float) // FixPivot(ClassD model needs 0.32 fixpivot to stay on ground), FixRotate(ClassD models is rotating on 180, you can rotate player models by this), FixPitch(The MTF models is incorrect, they have -90 model pitch, you can rotate a pitch by this)
declare breachrole_SetRoleHoldingGrenade(roleid, bonename:String, bonex:Float, boney:Float) // How player model will holding a grenade (VERY HARD)
declare breachrole_SetRoleHoldingItem(roleid, bonex:Float, boney:Float) // How player model will holding an item (VERY HARD)
declare breachrole_SetRoleHandcuff(roleid, bone1:String, bonex1:Float, boney1:Float, bonez1:Float, bone2:String, bonex2:Float, boney2:Float, bonez2:Float) // How player model will handcuffed (VERY HARD)
declare breachrole_AllowRoleWeaponAttaches(roleid, bool) // Will the role have a weapon in hands?
declare breachrole_AllowItemsAttaches(roleid, bool) // Will the role have an item in hands?
declare breachrole_MarkRoleAsSCP(roleid, bool)
declare breachrole_MarkAs035(roleid, bool) // This role will be a SCP, but it can take items and interact with more things like an usual player. (If you use this, then role automatically removed as SCP, but in other things this role will be a SCP)
declare breachrole_MarkAs049(roleid, bool) // Can use an intercoms?
declare breachrole_IsA049(roleid)
declare breachrole_IsA035(roleid)
declare breachrole_GetRoleScale:Float(roleid)
declare breachrole_IsAFriend(myrole, roleid)
declare breachrole_SetRoleHitboxScales(roleid, x:Float, y:Float, z:Float) // ClassD have (0.15, 0.52, 0.15), SCP-939 have (0.5, 0.3, 0.5)
declare breachrole_GetMaxHP(roleid)
declare breachrole_SetMaxRoleCount(roleid, count) // For example, SCPs have 1 count
declare breachrole_SetRoleCategory(roleid, category) // category, for example for winner text when round is over
declare multiplayer_breach_CreateViewmodelForRole(role, viewmodelfile:String, yoffset:Float, zoffset:Float, scale:Float, zscale:Float=0.0)
declare multiplayer_breach_SetRoleViewmodelAnimation(role, animationid, FirstFrame, EndFrame, Speed:Float)
// Example:

CLASSD_MODEL = breachrole_CreatePlayerRole("Class D", ClassDObj, 0.5 / MeshWidth(ClassDObj), "", 212, 113, 0, 100)
breachrole_SetRoleHitboxScales(CLASSD_MODEL, 0.15, 0.52, 0.15)
breachrole_SetRoleInstruction(CLASSD_MODEL, "Escape from the facility") 
breachrole_SetRoleCateogry(CLASSD_MODEL, CATEGORY_CHAOS)

breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_SITTING_IDLING, 357, 381, 0.1)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_IDLING, 210, 235, 0.1)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_RUNNING, 301, 319, 0.3)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_WALKING, 236, 260, 0.1)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_FORWARD, 382, 406, 0.3)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_BACK, 382, 406, -0.3)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_JUMPING, 834, 894, 1)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_LEFT, 261, 280, 0.3)
breachrole_SetRoleAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_RIGHT, 281, 300, 0.3)

breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_SITTING_IDLING, 733, 757, 0.1)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_IDLING, 573, 595, 0.1)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_RUNNING, 664, 682, 0.3)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_WALKING, 599, 623, 0.3)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_FORWARD, 758, 782, 0.3)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_BACK, 758, 782, 0.3)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_JUMPING, 834, 894, 1)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_LEFT, 758, 782, 0.3)
breachrole_SetRoleArmedAnimation(CLASSD_MODEL, PLAYER_SITTING_WALKING_RIGHT, 758, 782, 0.3)

breachrole_SetRoleDeadAnimation(CLASSD_MODEL, 0, 19)

breachrole_SetRoleHoldingGrenade(CLASSD_MODEL, "Bip01_R_UpperArm", 65.5855, -4.02472)
breachrole_SetRoleHoldingGrenade(CLASSD_MODEL, "Bip01_R_UpperArm", 65.5855, -4.02472)
breachrole_SetRoleHoldingGrenade(CLASSD_MODEL, "Bip01_R_UpperArm", 65.5855, -4.02472)
breachrole_SetRoleHoldingGrenade(CLASSD_MODEL, "Bip01_R_UpperArm", 65.5855, -4.02472)
breachrole_SetRoleHoldingGrenade(CLASSD_MODEL, "Bip01_R_UpperArm", 65.5855, -4.02472)

breachrole_SetRoleHoldingItem(CLASSD_MODEL, 100.5855, 20.02472)
breachrole_SetRoleHoldingItem(CLASSD_MODEL, 100.5855, 20.02472)
breachrole_SetRoleHoldingItem(CLASSD_MODEL, 100.5855, 20.02472)
breachrole_SetRoleHoldingItem(CLASSD_MODEL, 100.5855, 20.02472)
breachrole_SetRoleHoldingItem(CLASSD_MODEL, 100.5855, 20.02472)

breachrole_SetRoleHandcuff(CLASSD_MODEL, "Bip01_L_UpperArm", -13.3971, 58.1681, 135.2683, "Bip01_R_UpperArm", -13.3971, -50.1686, 48.732)
breachrole_SetRoleHandcuff(CLASSD_MODEL, "Bip01_L_UpperArm", -13.3971, 58.1681, 135.2683, "Bip01_R_UpperArm", -13.3971, -50.1686, 48.732)
breachrole_SetRoleHandcuff(CLASSD_MODEL, "Bip01_L_UpperArm", -13.3971, 58.1681, 135.2683, "Bip01_R_UpperArm", -13.3971, -50.1686, 48.732)
breachrole_SetRoleHandcuff(CLASSD_MODEL, "Bip01_L_UpperArm", -13.3971, 58.1681, 135.2683, "Bip01_R_UpperArm", -13.3971, -50.1686, 48.732)
breachrole_SetRoleHandcuff(CLASSD_MODEL, "Bip01_L_UpperArm", -13.3971, 58.1681, 135.2683, "Bip01_R_UpperArm", -13.3971, -50.1686, 48.732)
breachrole_SetRoleHandcuff(CLASSD_MODEL, "Bip01_L_UpperArm", -13.3971, 58.1681, 135.2683, "Bip01_R_UpperArm", -13.3971, -50.1686, 48.732)

breachrole_AllowRoleWeaponAttaches(CLASSD_MODEL, True)
breachrole_AllowItemsAttaches(CLASSD_MODEL, True)

breachrole_MarkAsFriend(CLASSD_MODEL, CHAOS, True)
. . .

; === These are settings which have original roles

multiplayer_breach_SetMaxRoleCount(TYPE_173, 1)
multiplayer_breach_SetMaxRoleCount(TYPE_049, 1)
multiplayer_breach_SetMaxRoleCount(TYPE_939, 1)
multiplayer_breach_SetMaxRoleCount(TYPE_966, 1)
multiplayer_breach_SetMaxRoleCount(TYPE_106, 1)
multiplayer_breach_SetMaxRoleCount(TYPE_096, 1)
multiplayer_breach_SetMaxRoleCount(TYPE_860, 1)

multiplayer_breach_SetMaxRoleCount(TYPE_GUARD, 4)
multiplayer_breach_SetMaxRoleCount(TYPE_CLASSD, 9999)
multiplayer_breach_SetMaxRoleCount(TYPE_JANITOR, 3)
multiplayer_breach_SetMaxRoleCount(TYPE_WORKER, 3)
multiplayer_breach_SetMaxRoleCount(TYPE_SCIENTIST, 4)

multiplayer_breach_SetRoleCategory(TYPE_173, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_049, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_106, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_939, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_966, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_ZOMBIE, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_096, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_860, CATEGORY_ANOMALY)
multiplayer_breach_SetRoleCategory(TYPE_035, CATEGORY_ANOMALY)

multiplayer_breach_SetRoleCategory(TYPE_GUARD, CATEGORY_NTF)
multiplayer_breach_SetRoleCategory(TYPE_SCIENTIST, CATEGORY_NTF)
multiplayer_breach_SetRoleCategory(TYPE_JANITOR, CATEGORY_NTF)
multiplayer_breach_SetRoleCategory(TYPE_WORKER, CATEGORY_NTF)
multiplayer_breach_SetRoleCategory(TYPE_CLASSD, CATEGORY_CHAOS)

multiplayer_breach_SetRoleCategory(0,CATEGORY_NULL)
multiplayer_breach_SetRoleCategory(TYPE_NTF, CATEGORY_NTF)
multiplayer_breach_SetRoleCategory(TYPE_CHAOS, CATEGORY_CHAOS)
multiplayer_breach_SetRoleCategory(17, CATEGORY_STALEMATE)

; ===================================================================================