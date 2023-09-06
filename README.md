# ImGui Blueprint
This is a wrapper around [Dear ImGui](https://github.com/ocornut/imgui) designed specifically for Unreal Blueprints.  
It should work with any ImGui plugin for Unreal (I use [IDI-Systems' UnrealImGui](https://github.com/IDI-Systems/UnrealImGui/) since it's the most up-to-date one).

![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/3c7bd15c-f8fd-4c2d-8331-e8d5dc822458)
![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/6a173fdb-fb8f-428c-8393-6895ef55fc69)
![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/c56ab04b-c0d6-4322-b864-d1e6d3fea662)
![image](https://github.com/TheEnbyWitch/ImGuiBlueprint/assets/10626859/facce471-f9c3-4df6-b156-557ec6bdf806)

## Possibly Frequently Asked Questions
### What is the state of this project?
Very very very early. You can support me on [Ko-Fi](https://ko-fi.com/vivitheheinouswitch) if you'd like me to continue working on it!

### Why are there no Begin and End nodes?
I've decided to make those a single K2 Node that handles calling Begin and End functions automatically, since they can clutter up Blueprint Graphs pretty easily.  
I find that they are also much more convenient to use.
