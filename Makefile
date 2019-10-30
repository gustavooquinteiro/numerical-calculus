DIRS = ./*
GREEN=\033[0;32m
NC=\033[0m

all: 
	@ $(foreach f, $(wildcard $(DIRS)/*.cpp), g++ $(f) -o $(subst .cpp,,$(f)) | echo -e -n "[${GREEN} OK ${NC}]\tCompilado $(f) em $(subst .cpp,,$(f))\n";)
clean:
	@ $(foreach f, $(wildcard $(DIRS)/*.cpp), rm $(subst .cpp,,$(f)) | echo -e -n "[${GREEN} OK ${NC}]\tRemovido $(subst .cpp,,$(f))\n"; )
