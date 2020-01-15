##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Engine
ConfigurationName      :=Debug
WorkspacePath          :=/home/gordo/Code/C++/EngiPixi
ProjectPath            :=/home/gordo/Code/C++/EngiPixi/Engine
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Joaquin
Date                   :=15/01/20
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
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/include/ $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)SDL2 $(LibrarySwitch)SDL2_image 
ArLibs                 :=  "SDL2" "SDL2_image" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++17 -O0 -Wall -lSDL2main -lSDL2 -lSDL2_image -lSDL_image  $(Preprocessors)
CFLAGS   := -g -O0 -Wall  $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/EntityComponentSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/Tile.cpp$(ObjectSuffix) $(IntermediateDirectory)/Map.cpp$(ObjectSuffix) $(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix): GameObject.cpp $(IntermediateDirectory)/GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/C++/EngiPixi/Engine/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameObject.cpp$(DependSuffix): GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameObject.cpp$(DependSuffix) -MM GameObject.cpp

$(IntermediateDirectory)/GameObject.cpp$(PreprocessSuffix): GameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameObject.cpp$(PreprocessSuffix) GameObject.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/C++/EngiPixi/Engine/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/EntityComponentSystem.cpp$(ObjectSuffix): EntityComponentSystem.cpp $(IntermediateDirectory)/EntityComponentSystem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/C++/EngiPixi/Engine/EntityComponentSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EntityComponentSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EntityComponentSystem.cpp$(DependSuffix): EntityComponentSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EntityComponentSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EntityComponentSystem.cpp$(DependSuffix) -MM EntityComponentSystem.cpp

$(IntermediateDirectory)/EntityComponentSystem.cpp$(PreprocessSuffix): EntityComponentSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EntityComponentSystem.cpp$(PreprocessSuffix) EntityComponentSystem.cpp

$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix): Engine.cpp $(IntermediateDirectory)/Engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/C++/EngiPixi/Engine/Engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Engine.cpp$(DependSuffix): Engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Engine.cpp$(DependSuffix) -MM Engine.cpp

$(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix): Engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix) Engine.cpp

$(IntermediateDirectory)/Tile.cpp$(ObjectSuffix): Tile.cpp $(IntermediateDirectory)/Tile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/C++/EngiPixi/Engine/Tile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tile.cpp$(DependSuffix): Tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tile.cpp$(DependSuffix) -MM Tile.cpp

$(IntermediateDirectory)/Tile.cpp$(PreprocessSuffix): Tile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tile.cpp$(PreprocessSuffix) Tile.cpp

$(IntermediateDirectory)/Map.cpp$(ObjectSuffix): Map.cpp $(IntermediateDirectory)/Map.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/C++/EngiPixi/Engine/Map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Map.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Map.cpp$(DependSuffix): Map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Map.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Map.cpp$(DependSuffix) -MM Map.cpp

$(IntermediateDirectory)/Map.cpp$(PreprocessSuffix): Map.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Map.cpp$(PreprocessSuffix) Map.cpp

$(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix): TextureManager.cpp $(IntermediateDirectory)/TextureManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gordo/Code/C++/EngiPixi/Engine/TextureManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextureManager.cpp$(DependSuffix): TextureManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextureManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TextureManager.cpp$(DependSuffix) -MM TextureManager.cpp

$(IntermediateDirectory)/TextureManager.cpp$(PreprocessSuffix): TextureManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextureManager.cpp$(PreprocessSuffix) TextureManager.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


