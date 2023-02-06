#--- Global variables -------------------------------------------------------------------
include ../Makefile.common
COMMON_MAKEFILE = ../Makefile.common
OUTPUT_DIR      = ../lib
CXX             = g++
CXXFLAGS        = -O3 -Wall -g -fPIC
LDFLAGS         = -shared -fPIC
INC_DIR         = include
INCS            = -I$(INC_DIR)
LIBS            = -L$(OUTPUT_DIR) -lcln
SRC_DIR         = src
OBJ_DIR         = ../obj
SRC_FILES_EXT   = cpp
SRC             = $(notdir $(wildcard $(SRC_DIR)/*.$(SRC_FILES_EXT)))
OBJ             = $(SRC:%.$(SRC_FILES_EXT)=$(OBJ_DIR)/%.o)

#--- Rules ------------------------------------------------------------------------------
all: header depend $(OUTPUT_DIR)/lib$(GLOBAL_TARGET).a $(OUTPUT_DIR)/lib$(GLOBAL_TARGET).so footer

header:
	@echo "[ Core ]"

depend:
ifeq ("$(wildcard $(OBJ_DIR))","")
	@mkdir $(OBJ_DIR)
	@mkdir $(OUTPUT_DIR)
endif
	@echo -n "  + Generate dependencies : "
ifneq ($(strip $(SRC)),)
	@$(CXX) $(INCS) -MM $(SRC:%=$(SRC_DIR)/%) \
	| sed -e 's:^[^ ]:$(OBJ_DIR)/&:' > Makefile.depend
endif
	@echo "OK"

$(OUTPUT_DIR)/lib$(GLOBAL_TARGET).a: $(OBJ)
	@echo -n "  + Build $(notdir $@) : "
	@rm -rf $@
	@ar rc $@ $(OBJ)
	@echo "OK"

$(OUTPUT_DIR)/lib$(GLOBAL_TARGET).so: $(OBJ)
	@echo -n "  + Build $(notdir $@) : "
	@rm -rf $@
	@$(CXX) $(LDFLAGS) $(OBJ) $(LIBS) -o $@
	@echo "OK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_FILES_EXT)
	@echo -n "  + Compile $(notdir $@) : "
	@$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@
	@echo "OK"

clean: header
	@echo -n "  + Delete objects and libraries : "
	@\rm -rf $(OBJ_DIR) $(OUTPUT_DIR)
	@echo "OK"

footer:

.PHONY: clean

include Makefile.depend
