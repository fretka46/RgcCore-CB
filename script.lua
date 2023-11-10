---@diagnostic disable: undefined-global
-- Always return -1 in lua if you doesn't have a return value, or you will have "Memory Access Violation"
function OnScriptLoaded()
	print("Loaded first lua script in SCP:CB")
	setlightvolume(2)
	print("Setting tickets... "..tostring(getlightvolume()))
	return -1
end