"""
  _____             _    _____  _             _       
 |  __ \           | |  |  __ \| |           (_)      
 | |  | | __ _ _ __| | _| |__) | |_   _  __ _ _ _ __  
 | |  | |/ _` | "__| |/ /  ___/| | | | |/ _` | | "_ \ 
 | |__| | (_| | |  |   <| |    | | |_| | (_| | | | | |
 |_____/ \__,_|_|  |_|\_\_|    |_|\__,_|\__, |_|_| |_|
                                         __/ |        
                                        |___/         
"""
DarkPlugin = {
    "title": "DarkPlugin Test",
    "description": "This plugin demonstrates hooking and patching",
    "author": "DARKC0DE",
    "version": "1.0.0.0",
    "url": "https://darkengine.org/"
}

#This is what the plugin will use to pull the patterns it needs
# For now this is hardcoded, but this will pull from a Web API in the future 
DarkPlugin['Patches'] = [{
    "title": "Hud Hide",
    "author": "DARKC0DE",
    "description": "This patch will allow you to hide the HUD",
    "pattern": "F0 3F D9 5D 93 A8 E2 DD 83 3F 00",
    "match": "xxxxxxxxxxx",
    "offset": 6,
    "patch": "C3 F5 48 40",
    "recursivePatch": True,
    "patchOnStartup": False,
    "patchBeforeStartup": False
}, {
    "title": "Hud Show",
    "author": "DARKC0DE",
    "description": "This patch will allow you to show the HUD",
    "pattern": "F0 3F D9 5D 93 A8 C3 F5 48 40 00",
    "match": "xxxxxxxxxxx",
    "offset": 6,
    "patch": "E2 DD 83 3F",
    "recursivePatch": True,
    "patchOnStartup": False,
    "patchBeforeStartup": False
}] 

#hooks
# For now this is hardcoded, but this will pull from a Web API in the future 
DarkPlugin['Hooks'] = [{
    "title": "Player Death Hook",
    "author": "DARKC0DE",
    "description": "This pattern finds the Player Death Hook",
    "pattern": "00 00 00 00 00 00 00",
    "match": "xxxxxxx",
    "offset": 0,
    "hookType": "pre"
}]

# This is a reserved function that gets called when the plugin is loaded 
def DarkPluginStart():
    Logging.Debug.WriteToLog("Hit OnPluginStart()") 
    HookEvent("Player Death Hook", Event_PlayerDeath);

#This is a reserved function that gets called when the plugin is unloaded 
def DarkPluginExit():
    Logging.Debug.WriteToLog("Hit OnPluginExit()")

# somehow we need to be able to support arguments to find what player died, etc.
def Event_PlayerDeath():
    Logging.Debug.WriteToLog("Player died.")

# this is a custom command, see DarkEventHandler 
def MyCommandTest():
    Logging.Debug.WriteToLog("MyCommandTest")

"""
This is a reserved

function that gets called when our plugin gets an event We will pass events directly to plugins using the WebSocket API This is totally optional to include in a plugin and is only needed
if events need to be called from the WebSocket API

An example an event could be 
{
    "command": "Run Patch",
    "patch": "Hide Hud"
}

This event will get ran regardless
if the DarkEventHandler exists.If DarkEventHandler, you can prevent the previous event from happening and do something
else instead

"""
def DarkEventHandler(e):
    Logging.Debug.WriteToLog("Hit DarkEventHandler(): " + e) 
    if e.command == "MyCommandTest":
    	MyCommandTest();