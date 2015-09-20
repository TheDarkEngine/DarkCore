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
import darkcore

# Note: This will not always be hard-coded into the plugin.
#       It will be populated on the C++ side of darkcore,
#       after parsing the JSON into Python values.
__info__ = {
	"patches": {
		"Hude Hide": {
			"author": "DARKC0DE",
			"description": "This patch will allow you to hide the HUD",
			"pattern": "F0 3F D9 5D 93 A8 E2 DD 83 3F 00",
			"match": "xxxxxxxxxxx",
			"offset": 6,
			"patch": "C3 F5 48 40",
			"recursive": True,
			"patchOnStartup": False,
			"patchBeforeStartup": False
		},
		"Hud Show": {
			"author": "DARKC0DE",
			"description": "This patch will allow you to show the HUD",
			"pattern": "F0 3F D9 5D 93 A8 C3 F5 48 40 00",
			"match": "xxxxxxxxxxx",
			"offset": 6,
			"patch": "E2 DD 83 3F",
			"recursive": True,
			"patchOnStartup": False,
			"patchBeforeStartup": False
		}
	},
	"hooks": {
		"Player Death": {
			"author": "DARKC0DE",
			"description": "This pattern finds the Player Death Hook",
			"pattern": "00 00 00 00 00 00 00",
			"match": "xxxxxxx",
			"offset": 0,
			"type": "pre"
		}
	},
	"title": "DarkPlugin Test",
	"description": "This plugin demonstrates hooking and patching",
	"author": "DARKC0DE",
	"version": "1.0.0.0",
	"url": "https://darkengine.org/"
}

# This is a reserved function that gets called when the plugin is loaded 
def on_plugin_start():
	darkcore.debug_log("Starting " + __info__["title"])
	darkcore.hook_event("Player Death", on_player_death)

# This is a reserved function that gets called when the plugin is unloaded 
def on_plugin_exit():
	darkcore.debug_log("Exiting " + __info__["title"])

# This is an event function that gets called when a player dies
def on_player_death(**kwargs):
	# TODO: Determine which player died
	darkcore.debug_log("Player died.")

#
# TODO: Think of a good way to structure custom events...
#

# TODO: Call 'on_plugin_start' from DarkCore
on_plugin_start()
