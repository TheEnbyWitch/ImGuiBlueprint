# ImGui Blueprint
This is a wrapper around [Dear ImGui](https://github.com/ocornut/imgui) designed specifically for Unreal Blueprints.  
It should work with any ImGui plugin for Unreal (I use [IDI-Systems' UnrealImGui](https://github.com/IDI-Systems/UnrealImGui/) since it's the most up-to-date one).

![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/8b8405fb-a4fe-468a-abd6-717ae50ac1c1)
![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/933427ba-d7e5-44db-8c0b-bb1c3deae5bb)
![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/cd2da498-5ce4-4752-9303-ba496b236964)
![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/8f2040ab-08d5-4408-85c3-8e9dc6f4e2d7)


## Possibly Frequently Asked Questions
### What is the state of this project?
Very very very early. You can support me on [Ko-Fi](https://ko-fi.com/vivitheheinouswitch) if you'd like me to continue working on it!

### Why are there no Begin and End nodes?
I've decided to make those a single K2 Node that handles calling Begin and End functions automatically, since they can clutter up Blueprint Graphs pretty easily.  
I find that they are also much more convenient to use.

## Credits
- [rtm223](https://github.com/rtm223) and [Ryan-DowlingSoka](https://github.com/Ryan-DowlingSoka) - helping me out with K2 Nodes
- [MagForceSeven](https://github.com/MagForceSeven/UE-K2-Nodes) - K2 Node examples and utility code
