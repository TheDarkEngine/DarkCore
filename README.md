# DarkCore 
[![Build status](https://ci.appveyor.com/api/projects/status/g22b2lcowj66v7if?retina=true)](https://ci.appveyor.com/project/dark-c0de/darkcore/history/branch/master)

Static DLL Patching and Hooking System

### Getting Started:
* [Compiling From Source](https://github.com/TheDarkEngine/DarkCore/wiki/Compiling-From-Source)

### Timeline
#### September 20, 2015:
* Memory Scanning of Patterns
* File patching using pattern match \ replace
* Memory Editing using pattern match \ replace
* Load Patches that need done from a .json file on disk and run them
* Add Command System for calling functions from WebSocket API (Example: "plugins load my_plugin", "plugins unload my_plugin"
* Create a basic interface for DarkPlugins
* D3D hooks for common d3d stuff like endscene, beginscene, reset, etc.
