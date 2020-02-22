##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Engine
ConfigurationName      :=Debug
WorkspacePath          :=/home/gordo/Code/EngiPixi
ProjectPath            :=/home/gordo/Code/EngiPixi/Engine
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Joaquín
Date                   :=22/02/20
CodeLitePath           :=/home/gordo/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Engine.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -s
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/include/ $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)SDL2 $(LibrarySwitch)SDL2_image $(LibrarySwitch)SDL2_ttf 
ArLibs                 :=  "SDL2" "SDL2_image" "SDL2_ttf" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++17 -O0 -Wall -lSDL2main -lSDL2 -lSDL2_image -lSDL2_image -lSDL2_ttf -g -DASSERTIONS_ENABLED  $(Preprocessors)
CFLAGS   := -g -O0 -Wall  $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_UILabel.cpp$(ObjectSuffix) $(IntermediateDirectory)/AssetManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Collision.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_TransformComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_SpriteComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Map.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_TileComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_JoystickController.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Vector2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/Helpers_FpsHelper.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_KeyboardController.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/ECS_ColliderComponent.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(ObjectSuffix): ECS/EntityComponentSystem.cpp $(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/EntityComponentSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(DependSuffix): ECS/EntityComponentSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(DependSuffix) -MM ECS/EntityComponentSystem.cpp

$(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(PreprocessSuffix): ECS/EntityComponentSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_EntityComponentSystem.cpp$(PreprocessSuffix) ECS/EntityComponentSystem.cpp

$(IntermediateDirectory)/ECS_UILabel.cpp$(ObjectSuffix): ECS/UILabel.cpp $(IntermediateDirectory)/ECS_UILabel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/UILabel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_UILabel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_UILabel.cpp$(DependSuffix): ECS/UILabel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_UILabel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_UILabel.cpp$(DependSuffix) -MM ECS/UILabel.cpp

$(IntermediateDirectory)/ECS_UILabel.cpp$(PreprocessSuffix): ECS/UILabel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_UILabel.cpp$(PreprocessSuffix) ECS/UILabel.cpp

$(IntermediateDirectory)/AssetManager.cpp$(ObjectSuffix): AssetManager.cpp $(IntermediateDirectory)/AssetManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/AssetManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AssetManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AssetManager.cpp$(DependSuffix): AssetManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AssetManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AssetManager.cpp$(DependSuffix) -MM AssetManager.cpp

$(IntermediateDirectory)/AssetManager.cpp$(PreprocessSuffix): AssetManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AssetManager.cpp$(PreprocessSuffix) AssetManager.cpp

$(IntermediateDirectory)/Collision.cpp$(ObjectSuffix): Collision.cpp $(IntermediateDirectory)/Collision.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/Collision.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Collision.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Collision.cpp$(DependSuffix): Collision.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Collision.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Collision.cpp$(DependSuffix) -MM Collision.cpp

$(IntermediateDirectory)/Collision.cpp$(PreprocessSuffix): Collision.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Collision.cpp$(PreprocessSuffix) Collision.cpp

$(IntermediateDirectory)/ECS_TransformComponent.cpp$(ObjectSuffix): ECS/TransformComponent.cpp $(IntermediateDirectory)/ECS_TransformComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/TransformComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_TransformComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_TransformComponent.cpp$(DependSuffix): ECS/TransformComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_TransformComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_TransformComponent.cpp$(DependSuffix) -MM ECS/TransformComponent.cpp

$(IntermediateDirectory)/ECS_TransformComponent.cpp$(PreprocessSuffix): ECS/TransformComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_TransformComponent.cpp$(PreprocessSuffix) ECS/TransformComponent.cpp

$(IntermediateDirectory)/ECS_SpriteComponent.cpp$(ObjectSuffix): ECS/SpriteComponent.cpp $(IntermediateDirectory)/ECS_SpriteComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/SpriteComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_SpriteComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_SpriteComponent.cpp$(DependSuffix): ECS/SpriteComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_SpriteComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_SpriteComponent.cpp$(DependSuffix) -MM ECS/SpriteComponent.cpp

$(IntermediateDirectory)/ECS_SpriteComponent.cpp$(PreprocessSuffix): ECS/SpriteComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_SpriteComponent.cpp$(PreprocessSuffix) ECS/SpriteComponent.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Map.cpp$(ObjectSuffix): Map.cpp $(IntermediateDirectory)/Map.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/Map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Map.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Map.cpp$(DependSuffix): Map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Map.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Map.cpp$(DependSuffix) -MM Map.cpp

$(IntermediateDirectory)/Map.cpp$(PreprocessSuffix): Map.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Map.cpp$(PreprocessSuffix) Map.cpp

$(IntermediateDirectory)/ECS_TileComponent.cpp$(ObjectSuffix): ECS/TileComponent.cpp $(IntermediateDirectory)/ECS_TileComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/TileComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_TileComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_TileComponent.cpp$(DependSuffix): ECS/TileComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_TileComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_TileComponent.cpp$(DependSuffix) -MM ECS/TileComponent.cpp

$(IntermediateDirectory)/ECS_TileComponent.cpp$(PreprocessSuffix): ECS/TileComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_TileComponent.cpp$(PreprocessSuffix) ECS/TileComponent.cpp

$(IntermediateDirectory)/ECS_JoystickController.cpp$(ObjectSuffix): ECS/JoystickController.cpp $(IntermediateDirectory)/ECS_JoystickController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/JoystickController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_JoystickController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_JoystickController.cpp$(DependSuffix): ECS/JoystickController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_JoystickController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_JoystickController.cpp$(DependSuffix) -MM ECS/JoystickController.cpp

$(IntermediateDirectory)/ECS_JoystickController.cpp$(PreprocessSuffix): ECS/JoystickController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_JoystickController.cpp$(PreprocessSuffix) ECS/JoystickController.cpp

$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix): Engine.cpp $(IntermediateDirectory)/Engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/Engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Engine.cpp$(DependSuffix): Engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Engine.cpp$(DependSuffix) -MM Engine.cpp

$(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix): Engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix) Engine.cpp

$(IntermediateDirectory)/Math_Vector2D.cpp$(ObjectSuffix): Math/Vector2D.cpp $(IntermediateDirectory)/Math_Vector2D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/Math/Vector2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Vector2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Vector2D.cpp$(DependSuffix): Math/Vector2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Vector2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Vector2D.cpp$(DependSuffix) -MM Math/Vector2D.cpp

$(IntermediateDirectory)/Math_Vector2D.cpp$(PreprocessSuffix): Math/Vector2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Vector2D.cpp$(PreprocessSuffix) Math/Vector2D.cpp

$(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(ObjectSuffix): Helpers/KeyboardHandler.cpp $(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/Helpers/KeyboardHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(DependSuffix): Helpers/KeyboardHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(DependSuffix) -MM Helpers/KeyboardHandler.cpp

$(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(PreprocessSuffix): Helpers/KeyboardHandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Helpers_KeyboardHandler.cpp$(PreprocessSuffix) Helpers/KeyboardHandler.cpp

$(IntermediateDirectory)/Helpers_FpsHelper.cpp$(ObjectSuffix): Helpers/FpsHelper.cpp $(IntermediateDirectory)/Helpers_FpsHelper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/Helpers/FpsHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Helpers_FpsHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Helpers_FpsHelper.cpp$(DependSuffix): Helpers/FpsHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Helpers_FpsHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Helpers_FpsHelper.cpp$(DependSuffix) -MM Helpers/FpsHelper.cpp

$(IntermediateDirectory)/Helpers_FpsHelper.cpp$(PreprocessSuffix): Helpers/FpsHelper.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Helpers_FpsHelper.cpp$(PreprocessSuffix) Helpers/FpsHelper.cpp

$(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(ObjectSuffix): ECS/PhysicsComponent.cpp $(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/PhysicsComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(DependSuffix): ECS/PhysicsComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(DependSuffix) -MM ECS/PhysicsComponent.cpp

$(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(PreprocessSuffix): ECS/PhysicsComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_PhysicsComponent.cpp$(PreprocessSuffix) ECS/PhysicsComponent.cpp

$(IntermediateDirectory)/ECS_KeyboardController.cpp$(ObjectSuffix): ECS/KeyboardController.cpp $(IntermediateDirectory)/ECS_KeyboardController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/KeyboardController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_KeyboardController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_KeyboardController.cpp$(DependSuffix): ECS/KeyboardController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_KeyboardController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_KeyboardController.cpp$(DependSuffix) -MM ECS/KeyboardController.cpp

$(IntermediateDirectory)/ECS_KeyboardController.cpp$(PreprocessSuffix): ECS/KeyboardController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_KeyboardController.cpp$(PreprocessSuffix) ECS/KeyboardController.cpp

$(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(ObjectSuffix): ECS/ProjectileComponent.cpp $(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/ProjectileComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(DependSuffix): ECS/ProjectileComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(DependSuffix) -MM ECS/ProjectileComponent.cpp

$(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(PreprocessSuffix): ECS/ProjectileComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_ProjectileComponent.cpp$(PreprocessSuffix) ECS/ProjectileComponent.cpp

$(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix): TextureManager.cpp $(IntermediateDirectory)/TextureManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/TextureManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextureManager.cpp$(DependSuffix): TextureManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TextureManager.cpp$(DependSuffix) -MM TextureManager.cpp

$(IntermediateDirectory)/TextureManager.cpp$(PreprocessSuffix): TextureManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextureManager.cpp$(PreprocessSuffix) TextureManager.cpp

$(IntermediateDirectory)/ECS_ColliderComponent.cpp$(ObjectSuffix): ECS/ColliderComponent.cpp $(IntermediateDirectory)/ECS_ColliderComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/EngiPixi/Engine/ECS/ColliderComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ECS_ColliderComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ECS_ColliderComponent.cpp$(DependSuffix): ECS/ColliderComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ECS_ColliderComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ECS_ColliderComponent.cpp$(DependSuffix) -MM ECS/ColliderComponent.cpp

$(IntermediateDirectory)/ECS_ColliderComponent.cpp$(PreprocessSuffix): ECS/ColliderComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ECS_ColliderComponent.cpp$(PreprocessSuffix) ECS/ColliderComponent.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


